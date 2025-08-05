# Tutorial Completo: Treinamento e Deploy de Modelos para STM32N6

Este tutorial fornece um guia passo a passo para treinar modelos de detecção de objetos e classificação de imagens no projeto STM32N6, com opções para usar apenas detecção, apenas classificação, ou ambos integrados.

## Índice

1. [Visão Geral do Sistema](#1-visão-geral-do-sistema)
2. [Preparação do Ambiente](#2-preparação-do-ambiente)
3. [Treinamento de Modelo de Detecção de Objetos](#3-treinamento-de-modelo-de-detecção-de-objetos)
4. [Treinamento de Modelo de Classificação](#4-treinamento-de-modelo-de-classificação)
5. [Conversão de Modelos para STM32](#5-conversão-de-modelos-para-stm32)
6. [Deploy no Hardware](#6-deploy-no-hardware)
7. [Configurações de Uso](#7-configurações-de-uso)
   - [7.1 Apenas Detecção](#71-apenas-detecção)
   - [7.2 Apenas Classificação](#72-apenas-classificação)
   - [7.3 Detecção + Classificação](#73-detecção--classificação)
8. [Arquivos que Precisam ser Alterados](#8-arquivos-que-precisam-ser-alterados)
9. [Debugging e Otimização](#9-debugging-e-otimização)

## 1. Visão Geral do Sistema

O sistema STM32N6 pode ser configurado com dois tipos de modelos:

### Modelo de Detecção de Objetos
- **Entrada**: Imagem RGB (224x224, 320x320, ou 416x416)
- **Saída**: Bounding boxes, classes e scores de confiança
- **Endereço de memória**: 0x71000000
- **Performance**: 15-50ms por inferência (dependendo do modelo)
- **Modelos suportados**: YOLOv5, YOLOv8, SSD MobileNet, etc.

### Modelo de Classificação
- **Entrada**: Imagem RGB (224x224 padrão)
- **Saída**: Probabilidades de classes
- **Endereço de memória**: 0x72000000
- **Performance**: 5-20ms por inferência
- **Modelos suportados**: MobileNetV2, EfficientNet, ResNet, etc.

### Modos de Operação
1. **Apenas Detecção**: Detecta objetos na imagem completa
2. **Apenas Classificação**: Classifica a imagem inteira
3. **Detecção + Classificação**: Detecta objetos e classifica cada região detectada

## 2. Preparação do Ambiente

### 2.1. Ferramentas Necessárias

```bash
# Python e bibliotecas ML
pip install tensorflow==2.15.0
pip install pytorch torchvision
pip install onnx onnx-tf
pip install opencv-python
pip install scikit-learn
pip install matplotlib seaborn
pip install albumentations
```

### 2.2. Configuração das Ferramentas STM32

Edite o arquivo `stm32_tools_config.json` com os caminhos corretos:

```json
{
  "tools": {
    "stm32edgeai": {
      "path": "/caminho/para/stedgeai"
    },
    "stm32programmer": {
      "path": "/caminho/para/STM32_Programmer_CLI"
    }
  },
  "models": {
    "object_detection": {
      "name": "object_detection",
      "address": "0x71000000",
      "target": "stm32n6",
      "input_data_type": "float32",
      "stedgeai_options": "-O0 --all-buffers-info --mvei --cache-maintenance --Oalt-sched --enable-virtual-mem-pools --Omax-ca-pipe 4 --Ocache-opt --Os --enable-epoch-controller"
    },
    "classification": {
      "name": "classification",
      "address": "0x72000000", 
      "target": "stm32n6",
      "input_data_type": "float32",
      "stedgeai_options": "-O0 --all-buffers-info --mvei --cache-maintenance --Oalt-sched --enable-virtual-mem-pools --Omax-ca-pipe 4 --Ocache-opt --Os --enable-epoch-controller"
    }
  }
}
```

## 3. Treinamento de Modelo de Detecção de Objetos

### 3.1. Preparação dos Dados

```python
# script: prepare_detection_dataset.py
import os
import cv2
import json
import numpy as np
from sklearn.model_selection import train_test_split

def prepare_detection_data(dataset_path, classes_file, img_size=416):
    """
    Prepara dataset para treinamento de detecção de objetos
    Formato esperado: COCO, YOLO, ou Pascal VOC
    
    Estrutura do dataset:
    dataset_path/
    ├── images/
    │   ├── train/
    │   └── val/
    ├── labels/
    │   ├── train/
    │   └── val/
    └── classes.txt
    """
    
    # Carrega lista de classes 
    with open(classes_file, 'r') as f:
        classes = [line.strip() for line in f.readlines()]
    
    def load_split_data(split):
        images = []
        annotations = []
        
        img_dir = os.path.join(dataset_path, 'images', split)
        label_dir = os.path.join(dataset_path, 'labels', split)
        
        for img_file in os.listdir(img_dir):
            if img_file.endswith(('.jpg', '.png', '.jpeg')):
                img_path = os.path.join(img_dir, img_file)
                label_path = os.path.join(label_dir, 
                                        img_file.replace('.jpg', '.txt')
                                               .replace('.png', '.txt')
                                               .replace('.jpeg', '.txt'))
                
                if os.path.exists(label_path):
                    img = cv2.imread(img_path)
                    img = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
                    img_resized = cv2.resize(img, (img_size, img_size))
                    
                    # Lê anotações YOLO format: class_id center_x center_y width height
                    boxes = []
                    with open(label_path, 'r') as f:
                        for line in f.readlines():
                            parts = line.strip().split()
                            if len(parts) >= 5:
                                class_id = int(parts[0])
                                center_x = float(parts[1])
                                center_y = float(parts[2])
                                width = float(parts[3])
                                height = float(parts[4])
                                
                                boxes.append({
                                    'class_id': class_id,
                                    'center_x': center_x,
                                    'center_y': center_y,
                                    'width': width,
                                    'height': height
                                })
                    
                    if boxes:  # Só adiciona se tem anotações
                        images.append(img_resized)
                        annotations.append(boxes)
        
        return np.array(images), annotations
    
    return load_split_data('train'), load_split_data('val'), classes

# Criação de dataset YOLO format
def create_yolo_dataset_yaml(dataset_path, classes):
    """Cria arquivo dataset.yaml para YOLOv5/v8"""
    
    dataset_config = {
        'path': os.path.abspath(dataset_path),
        'train': 'images/train',
        'val': 'images/val',
        'nc': len(classes),
        'names': classes
    }
    
    with open(os.path.join(dataset_path, 'dataset.yaml'), 'w') as f:
        import yaml
        yaml.dump(dataset_config, f, default_flow_style=False)

# Execução
if __name__ == "__main__":
    # Exemplo para dataset personalizado
    dataset_path = 'datasets/custom_objects'
    classes_file = os.path.join(dataset_path, 'classes.txt')
    
    (train_images, train_annotations), (val_images, val_annotations), classes = prepare_detection_data(
        dataset_path, classes_file, img_size=416
    )
    
    print(f"Classes: {classes}")
    print(f"Train: {len(train_images)} images")
    print(f"Val: {len(val_images)} images")
    
    # Cria arquivo de configuração YOLO
    create_yolo_dataset_yaml(dataset_path, classes)
```

### 3.2. Modelo YOLOv5 (Recomendado)

```python
# script: train_yolov5_detection.py
import torch
from ultralytics import YOLO
import os

def train_yolov5_detection(dataset_yaml, img_size=416, epochs=100):
    """
    Treina modelo YOLOv5 para detecção de objetos
    """
    
    # Carrega modelo pré-treinado YOLOv5s (mais leve para embedded)
    model = YOLO('yolov5s.pt')
    
    # Treina no dataset customizado
    results = model.train(
        data=dataset_yaml,
        epochs=epochs,
        imgsz=img_size,
        batch=16,  # Ajuste conforme GPU disponível
        save_period=10,
        patience=20,
        device='0' if torch.cuda.is_available() else 'cpu'
    )
    
    # Exporta para ONNX (melhor compatibilidade com STEdgeAI)
    model.export(
        format='onnx',
        imgsz=img_size,
        int8=True,  # Quantização INT8
        dynamic=False,
        simplify=True
    )
    
    return model

def train_custom_yolo_tensorflow():
    """
    Alternativa usando TensorFlow/Keras para maior controle
    """
    import tensorflow as tf
    from tensorflow.keras import layers, Model
    
    def yolo_conv_block(inputs, filters, kernel_size=3, strides=1):
        x = layers.Conv2D(filters, kernel_size, strides=strides, 
                         padding='same', use_bias=False)(inputs)
        x = layers.BatchNormalization()(x)
        x = layers.LeakyReLU(alpha=0.1)(x)
        return x
    
    def create_yolo_model(input_shape, num_classes):
        inputs = layers.Input(shape=input_shape)
        
        # Backbone - MobileNetV2 modificado para YOLO
        backbone = tf.keras.applications.MobileNetV2(
            input_tensor=inputs,
            include_top=False,
            weights='imagenet'
        )
        
        # Neck - Feature Pyramid Network
        c3 = backbone.get_layer('block_6_expand_relu').output  # 52x52
        c4 = backbone.get_layer('block_13_expand_relu').output # 26x26
        c5 = backbone.output  # 13x13
        
        # Head - Detection layers
        anchors_per_scale = 3
        outputs_per_anchor = 5 + num_classes  # x,y,w,h,conf + classes
        
        # Large objects (13x13)
        p5 = yolo_conv_block(c5, 512, 3)
        p5 = layers.Conv2D(anchors_per_scale * outputs_per_anchor, 1)(p5)
        
        # Medium objects (26x26)
        p4 = yolo_conv_block(c4, 256, 3)
        p4 = layers.Conv2D(anchors_per_scale * outputs_per_anchor, 1)(p4)
        
        # Small objects (52x52)
        p3 = yolo_conv_block(c3, 128, 3)
        p3 = layers.Conv2D(anchors_per_scale * outputs_per_anchor, 1)(p3)
        
        model = Model(inputs, [p3, p4, p5])
        return model
    
    # Criar e treinar modelo
    model = create_yolo_model((416, 416, 3), num_classes=len(classes))
    
    # Compilação com loss customizada para YOLO
    model.compile(
        optimizer=tf.keras.optimizers.Adam(1e-4),
        loss=yolo_loss  # Implementar loss YOLO
    )
    
    return model

if __name__ == "__main__":
    # Método 1: YOLOv5 (Recomendado)
    dataset_yaml = 'datasets/custom_objects/dataset.yaml'
    model = train_yolov5_detection(dataset_yaml, img_size=416, epochs=100)
    
    print("Modelo treinado! Arquivos gerados:")
    print("- best.pt: Modelo PyTorch")
    print("- best.onnx: Modelo ONNX para STM32")
```

### 3.3. Alternativa: SSD MobileNet

```python
# script: train_ssd_mobilenet.py
import tensorflow as tf
from tensorflow.keras import layers, Model

def create_ssd_mobilenet(num_classes, input_shape=(320, 320, 3)):
    """
    Cria modelo SSD com backbone MobileNetV2
    Mais leve que YOLO para aplicações embedded
    """
    
    # Backbone MobileNetV2
    backbone = tf.keras.applications.MobileNetV2(
        input_shape=input_shape,
        include_top=False,
        weights='imagenet'
    )
    
    # Feature maps de diferentes escalas
    feature_maps = []
    for layer_name in ['block_6_expand_relu', 'block_13_expand_relu', 'out_relu']:
        feature_maps.append(backbone.get_layer(layer_name).output)
    
    # SSD heads
    predictions = []
    for i, fm in enumerate(feature_maps):
        # Classificação
        cls = layers.Conv2D(num_classes * 4, 3, padding='same')(fm)  # 4 default boxes
        cls = layers.Reshape((-1, num_classes))(cls)
        
        # Localização
        loc = layers.Conv2D(4 * 4, 3, padding='same')(fm)  # 4 coords * 4 boxes
        loc = layers.Reshape((-1, 4))(loc)
        
        predictions.extend([cls, loc])
    
    model = Model(backbone.input, predictions)
    return model

if __name__ == "__main__":
    model = create_ssd_mobilenet(num_classes=10)  # Ajuste para suas classes
    
    # Compile e treine
    model.compile(
        optimizer='adam',
        loss=['categorical_crossentropy', 'mse'] * 3,  # 3 feature maps
        loss_weights=[1.0, 0.1] * 3
    )
```

## 4. Treinamento de Modelo de Classificação

### 4.1. Preparação dos Dados de Classificação

```python
# script: prepare_classification_dataset.py
import os
import cv2
import numpy as np
from sklearn.preprocessing import LabelEncoder
from sklearn.model_selection import train_test_split
import tensorflow as tf

def prepare_classification_data(dataset_path, img_size=224, validation_split=0.2):
    """
    Prepara dataset para classificação de imagens
    Estrutura esperada:
    dataset_path/
      ├── class1/
      │   ├── img1.jpg
      │   ├── img2.jpg
      │   └── ...
      ├── class2/
      │   ├── img1.jpg
      │   └── ...
      └── classN/
          └── ...
    """
    
    images = []
    labels = []
    class_names = []
    
    # Percorre todas as classes (pastas)
    for class_dir in sorted(os.listdir(dataset_path)):
        class_path = os.path.join(dataset_path, class_dir)
        if os.path.isdir(class_path):
            class_names.append(class_dir)
            
            # Carrega imagens da classe
            for img_file in os.listdir(class_path):
                if img_file.lower().endswith(('.jpg', '.jpeg', '.png', '.bmp')):
                    img_path = os.path.join(class_path, img_file)
                    
                    try:
                        # Carrega e preprocessa imagem
                        img = cv2.imread(img_path)
                        if img is not None:
                            img = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
                            img = cv2.resize(img, (img_size, img_size))
                            
                            # Normalização [0, 1]
                            img = img.astype(np.float32) / 255.0
                            
                            images.append(img)
                            labels.append(class_dir)
                    except Exception as e:
                        print(f"Erro ao carregar {img_path}: {e}")
    
    # Converte para numpy arrays
    images = np.array(images)
    
    # Codifica labels
    le = LabelEncoder()
    labels_encoded = le.fit_transform(labels)
    
    # Split train/validation
    X_train, X_val, y_train, y_val = train_test_split(
        images, labels_encoded, test_size=validation_split, 
        random_state=42, stratify=labels_encoded
    )
    
    print(f"Classes encontradas: {class_names}")
    print(f"Total de imagens: {len(images)}")
    print(f"Train: {len(X_train)}, Val: {len(X_val)}")
    print(f"Distribuição por classe:")
    
    unique, counts = np.unique(labels_encoded, return_counts=True)
    for class_idx, count in zip(unique, counts):
        print(f"  {class_names[class_idx]}: {count} imagens")
    
    return (X_train, y_train), (X_val, y_val), class_names, le

def create_data_augmentation():
    """Cria pipeline de data augmentation"""
    
    return tf.keras.Sequential([
        tf.keras.layers.RandomFlip("horizontal"),
        tf.keras.layers.RandomRotation(0.1),
        tf.keras.layers.RandomZoom(0.1),
        tf.keras.layers.RandomBrightness(0.1),
        tf.keras.layers.RandomContrast(0.1),
    ])

def load_imagenet_classes():
    """Carrega classes do ImageNet para transfer learning"""
    
    # Lista das 1000 classes do ImageNet (exemplo com algumas classes)
    imagenet_classes = [
        'person', 'bicycle', 'car', 'motorcycle', 'airplane',
        'bus', 'train', 'truck', 'boat', 'traffic_light',
        'fire_hydrant', 'stop_sign', 'parking_meter', 'bench', 'bird',
        'cat', 'dog', 'horse', 'sheep', 'cow',
        # ... adicionar todas as 1000 classes conforme necessário
    ]
    
    return imagenet_classes

# Execução
if __name__ == "__main__":
    # Exemplo de uso
    dataset_path = 'datasets/custom_classification'
    
    (X_train, y_train), (X_val, y_val), class_names, label_encoder = prepare_classification_data(
        dataset_path, img_size=224, validation_split=0.2
    )
    
    # Salva informações das classes
    import json
    with open('class_info.json', 'w') as f:
        json.dump({
            'class_names': class_names,
            'num_classes': len(class_names),
            'total_samples': len(X_train) + len(X_val)
        }, f, indent=2)
```

### 4.2. Modelo MobileNetV2 para Classificação

```python
# script: train_mobilefacenet.py
import tensorflow as tf
from tensorflow.keras import layers, models
import numpy as np

class MobileFaceNet(tf.keras.Model):
    def __init__(self, embedding_size=128):
        super(MobileFaceNet, self).__init__()
        
        self.conv1 = layers.Conv2D(64, 3, strides=2, padding='same')
        self.bn1 = layers.BatchNormalization()
        
        # Depthwise separable blocks
        self.dw_blocks = []
        channels = [64, 128, 128, 256, 256, 512]
        
        for i, out_channels in enumerate(channels):
            self.dw_blocks.append(self._make_dw_block(out_channels, stride=2 if i < 4 else 1))
        
        # Global average pooling
        self.gap = layers.GlobalAveragePooling2D()
        
        # Final embedding layer
        self.fc = layers.Dense(embedding_size)
        self.bn_fc = layers.BatchNormalization()
        
    def _make_dw_block(self, out_channels, stride=1):
        return tf.keras.Sequential([
            layers.DepthwiseConv2D(3, strides=stride, padding='same'),
            layers.BatchNormalization(),
            layers.ReLU(),
            layers.Conv2D(out_channels, 1, padding='same'),
            layers.BatchNormalization(),
            layers.ReLU()
        ])
    
    def call(self, inputs):
        x = self.conv1(inputs)
        x = self.bn1(x)
        x = tf.nn.relu(x)
        
        for block in self.dw_blocks:
            x = block(x)
        
        x = self.gap(x)
        x = self.fc(x)
        x = self.bn_fc(x)
        
        # L2 normalization para embeddings
        x = tf.nn.l2_normalize(x, axis=1)
        
        return x

def triplet_loss(y_true, y_pred, margin=0.2):
    """Triplet loss function"""
    anchor, positive, negative = tf.split(y_pred, 3, axis=0)
    
    pos_dist = tf.reduce_sum(tf.square(anchor - positive), axis=1)
    neg_dist = tf.reduce_sum(tf.square(anchor - negative), axis=1)
    
    loss = tf.maximum(0.0, margin + pos_dist - neg_dist)
    return tf.reduce_mean(loss)

def train_mobilefacenet():
    # Carrega dados
    images, labels, label_encoder = prepare_recognition_data('datasets/faces')
    triplets = create_triplets(images, labels)
    
    # Cria modelo
    model = MobileFaceNet(embedding_size=128)
    
    # Compilação
    model.compile(
        optimizer=tf.keras.optimizers.Adam(learning_rate=1e-4),
        loss=triplet_loss
    )
    
    # Preparação dos dados de treinamento
    def triplet_generator(images, triplets, batch_size=32):
        while True:
            batch_triplets = triplets[np.random.choice(len(triplets), batch_size)]
            
            anchors = images[batch_triplets[:, 0]]
            positives = images[batch_triplets[:, 1]]  
            negatives = images[batch_triplets[:, 2]]
            
            batch_x = np.vstack([anchors, positives, negatives])
            dummy_y = np.zeros((batch_size * 3, 1))  # Dummy target para triplet loss
            
            yield batch_x, dummy_y
    
    # Treinamento
    steps_per_epoch = len(triplets) // 32
    history = model.fit(
        triplet_generator(images, triplets),
        steps_per_epoch=steps_per_epoch,
        epochs=100,
        callbacks=[
            tf.keras.callbacks.ModelCheckpoint('best_mobilefacenet.h5', save_best_only=True)
        ]
    )
    
    return model

if __name__ == "__main__":
    model = train_mobilefacenet()
    
    # Conversão para ONNX
    import tf2onnx
    
    # Salva modelo em formato SavedModel primeiro
    model.save('mobilefacenet_saved_model')
    
    # Converte para ONNX
    os.system('python -m tf2onnx.convert --saved-model mobilefacenet_saved_model --output input_models/mobilefacenet_custom.onnx')
```

## 5. Conversão de Modelos para STM32

### 5.1. Usando o Script de Conversão

```bash
# Converte modelo de detecção
./scripts/compile_model.sh face_detection ./input_models/centerface_custom.tflite

# Converte modelo de reconhecimento
./scripts/compile_model.sh face_recognition ./input_models/mobilefacenet_custom.onnx
```

### 5.2. Verificação dos Arquivos Gerados

```bash
# Verifica arquivos gerados
ls -la converted_models/code/
ls -la converted_models/binaries/
ls -la embedded/Models/
ls -la embedded/Binary/
```

## 6. Deploy no Hardware

### 6.1. Build do Projeto

```bash
# Build usando Makefile
cd embedded
make clean && make -j$(nproc)

# Ou usando STM32CubeIDE
# Abrir projeto em embedded/STM32CubeIDE/ e fazer Clean + Build
```

### 6.2. Assinatura e Flash

```bash
# Assinar binário
./scripts/sign_binary.sh ./embedded/build/Project.bin

# Flash completo do sistema
./scripts/flash_firmware.sh all
```

## 7. Configurações de Uso

### 7.1. Apenas Detecção

Para usar apenas o modelo de detecção de objetos:

**Configuração em `stm32_tools_config.json`:**
```json
{
  "models": {
    "object_detection": {
      "name": "object_detection",
      "address": "0x71000000",
      "target": "stm32n6",
      "input_data_type": "float32",
      "stedgeai_options": "-O0 --all-buffers-info --mvei --cache-maintenance --Oalt-sched --enable-virtual-mem-pools --Omax-ca-pipe 4 --Ocache-opt --Os --enable-epoch-controller"
    }
  }
}
```

**Modificações necessárias:**
- `embedded/Inc/app_config.h`:
```c
// Habilita apenas detecção
#define USE_OBJECT_DETECTION    1
#define USE_CLASSIFICATION      0

// Configurações do modelo de detecção
#define AI_OD_MODEL_INPUT_WIDTH     416
#define AI_OD_MODEL_INPUT_HEIGHT    416
#define AI_OD_MODEL_INPUT_CHANNELS  3

// Post-processing
#define AI_OD_MODEL_PP_CONF_THRESHOLD (0.5f)
#define AI_OD_MODEL_PP_NMS_THRESHOLD  (0.4f)
#define AI_OD_MODEL_PP_MAX_BOXES_LIMIT (20)

// Classes do seu modelo (exemplo)
#define AI_OD_MODEL_NB_CLASSES (10)
static const char* od_classes_table[AI_OD_MODEL_NB_CLASSES] = {
    "person", "car", "bicycle", "dog", "cat",
    "bus", "truck", "motorcycle", "airplane", "boat"
};
```

**Pipeline de processamento (apenas detecção):**
```c
// embedded/Src/app_frame_processing.c
void process_frame_detection_only(uint8_t* frame_data) {
    // 1. Preprocessa imagem para o modelo
    preprocess_image_for_detection(frame_data);
    
    // 2. Executa detecção
    detection_results_t results = run_object_detection(frame_data);
    
    // 3. Pós-processamento (NMS, threshold)
    filter_detections(&results);
    
    // 4. Display ou envio via UART
    display_detection_results(&results);
}
```

### 7.2. Apenas Classificação

Para usar apenas o modelo de classificação:

**Configuração em `stm32_tools_config.json`:**
```json
{
  "models": {
    "classification": {
      "name": "classification",
      "address": "0x71000000",  // Usa o primeiro slot de memória
      "target": "stm32n6",
      "input_data_type": "float32",
      "stedgeai_options": "-O0 --all-buffers-info --mvei --cache-maintenance --Oalt-sched --enable-virtual-mem-pools --Omax-ca-pipe 4 --Ocache-opt --Os --enable-epoch-controller"
    }
  }
}
```

**Modificações necessárias:**
- `embedded/Inc/app_config.h`:
```c
// Habilita apenas classificação
#define USE_OBJECT_DETECTION    0
#define USE_CLASSIFICATION      1

// Configurações do modelo de classificação
#define AI_CLS_MODEL_INPUT_WIDTH     224
#define AI_CLS_MODEL_INPUT_HEIGHT    224
#define AI_CLS_MODEL_INPUT_CHANNELS  3

// Threshold de confiança
#define AI_CLS_MODEL_CONF_THRESHOLD (0.7f)

// Classes do seu modelo (exemplo)
#define AI_CLS_MODEL_NB_CLASSES (10)
static const char* cls_classes_table[AI_CLS_MODEL_NB_CLASSES] = {
    "animals", "vehicles", "people", "buildings", "nature",
    "food", "electronics", "furniture", "sports", "tools"
};
```

**Pipeline de processamento (apenas classificação):**
```c
// embedded/Src/app_frame_processing.c
void process_frame_classification_only(uint8_t* frame_data) {
    // 1. Preprocessa imagem inteira para classificação
    preprocess_image_for_classification(frame_data);
    
    // 2. Executa classificação
    classification_result_t result = run_classification(frame_data);
    
    // 3. Aplica threshold de confiança
    if (result.confidence > AI_CLS_MODEL_CONF_THRESHOLD) {
        // 4. Display ou envio via UART
        display_classification_result(&result);
    }
}
```

### 7.3. Detecção + Classificação

Para usar ambos os modelos de forma integrada:

**Configuração em `stm32_tools_config.json`:**
```json
{
  "models": {
    "object_detection": {
      "name": "object_detection",
      "address": "0x71000000",
      "target": "stm32n6",
      "input_data_type": "float32",
      "stedgeai_options": "-O0 --all-buffers-info --mvei --cache-maintenance --Oalt-sched --enable-virtual-mem-pools --Omax-ca-pipe 4 --Ocache-opt --Os --enable-epoch-controller"
    },
    "classification": {
      "name": "classification",
      "address": "0x72000000",
      "target": "stm32n6",
      "input_data_type": "float32",
      "stedgeai_options": "-O0 --all-buffers-info --mvei --cache-maintenance --Oalt-sched --enable-virtual-mem-pools --Omax-ca-pipe 4 --Ocache-opt --Os --enable-epoch-controller"
    }
  }
}
```

**Modificações necessárias:**
- `embedded/Inc/app_config.h`:
```c
// Habilita ambos os modelos
#define USE_OBJECT_DETECTION    1
#define USE_CLASSIFICATION      1

// Configurações detecção
#define AI_OD_MODEL_INPUT_WIDTH     416
#define AI_OD_MODEL_INPUT_HEIGHT    416
#define AI_OD_MODEL_INPUT_CHANNELS  3
#define AI_OD_MODEL_PP_CONF_THRESHOLD (0.5f)
#define AI_OD_MODEL_PP_MAX_BOXES_LIMIT (10)

// Configurações classificação
#define AI_CLS_MODEL_INPUT_WIDTH     224
#define AI_CLS_MODEL_INPUT_HEIGHT    224
#define AI_CLS_MODEL_INPUT_CHANNELS  3
#define AI_CLS_MODEL_CONF_THRESHOLD (0.7f)

// Modo de operação
#define PIPELINE_MODE DETECTION_THEN_CLASSIFICATION
// Alternativas:
// #define PIPELINE_MODE CLASSIFICATION_THEN_DETECTION
// #define PIPELINE_MODE PARALLEL_PROCESSING
```

**Pipeline integrado:**
```c
// embedded/Src/app_frame_processing.c
void process_frame_integrated(uint8_t* frame_data) {
    
    #if PIPELINE_MODE == DETECTION_THEN_CLASSIFICATION
    
    // 1. Detecção de objetos na imagem completa
    detection_results_t detections = run_object_detection(frame_data);
    
    // 2. Para cada objeto detectado, faz classificação
    for (int i = 0; i < detections.num_objects; i++) {
        // Crop da região detectada
        uint8_t* cropped_region = crop_detected_region(frame_data, &detections.objects[i]);
        
        // Classifica região cropada
        classification_result_t cls_result = run_classification(cropped_region);
        
        // Combina resultados
        integrated_result_t result = {
            .detection = detections.objects[i],
            .classification = cls_result,
            .combined_confidence = detections.objects[i].confidence * cls_result.confidence
        };
        
        // Display resultado integrado
        display_integrated_result(&result);
    }
    
    #elif PIPELINE_MODE == CLASSIFICATION_THEN_DETECTION
    
    // 1. Classificação geral da imagem
    classification_result_t global_cls = run_classification(frame_data);
    
    // 2. Se confiança alta, faz detecção específica
    if (global_cls.confidence > AI_CLS_MODEL_CONF_THRESHOLD) {
        detection_results_t detections = run_object_detection(frame_data);
        
        // Combina resultados
        for (int i = 0; i < detections.num_objects; i++) {
            integrated_result_t result = {
                .detection = detections.objects[i],
                .classification = global_cls,
                .context_classification = true
            };
            display_integrated_result(&result);
        }
    }
    
    #endif
}
```

### 7.4. Estrutura de Dados Integrada

```c
// embedded/Inc/integrated_ai.h
typedef struct {
    // Detecção
    bbox_t bbox;
    float detection_confidence;
    int detection_class_id;
    char detection_class_name[32];
    
    // Classificação
    float classification_confidence;
    int classification_class_id;
    char classification_class_name[32];
    
    // Resultado combinado
    float combined_confidence;
    bool is_valid;
    
} integrated_result_t;

typedef struct {
    integrated_result_t results[AI_MAX_DETECTIONS];
    int num_results;
    uint32_t processing_time_ms;
    
} integrated_results_t;
```

### 7.1. Pipeline de Processamento

O sistema integrado funciona da seguinte forma:

```
Camera → ISP → Face Detection → Face Cropping → Face Recognition → Display
```

### 7.2. Modificações para Classificação Adicional

Se você quiser adicionar um modelo de classificação após a detecção, precisa:

1. **Adicionar terceiro modelo na configuração**:

```json
// stm32_tools_config.json
"models": {
  "face_detection": { "address": "0x71000000" },
  "face_recognition": { "address": "0x72000000" },
  "face_classification": { "address": "0x73000000" }  // Novo modelo
}
```

2. **Criar estrutura de dados para classificação**:

```c
// embedded/Inc/face_classification.h
typedef struct {
    float confidence;
    int class_id;
    char class_name[32];
} face_class_result_t;
```

## 8. Arquivos que Precisam ser Alterados

### 8.1. Resumo dos Arquivos por Configuração

| Arquivo | Apenas Detecção | Apenas Classificação | Detecção + Classificação |
|---------|-----------------|---------------------|-------------------------|
| `stm32_tools_config.json` | ✅ | ✅ | ✅ |
| `embedded/Inc/app_config.h` | ✅ | ✅ | ✅ |
| `embedded/Src/app_frame_processing.c` | ✅ | ✅ | ✅ |
| `embedded/Src/nn_runner.c` | ✅ | ✅ | ✅ |
| `embedded/Inc/integrated_ai.h` | ❌ | ❌ | ✅ |
| `embedded/Src/object_detection.c` | ✅ | ❌ | ✅ |
| `embedded/Src/classification.c` | ❌ | ✅ | ✅ |
| `embedded/Models/object_detection.*` | ✅ | ❌ | ✅ |
| `embedded/Models/classification.*` | ❌ | ✅ | ✅ |

### 8.2. Para Novos Modelos de Detecção de Objetos

**Arquivos obrigatórios:**

1. **`stm32_tools_config.json`** - Configuração do modelo
2. **`embedded/Inc/app_config.h`** - Parâmetros do modelo  
3. **`embedded/Src/object_detection.c`** - Novo arquivo para lógica de detecção
4. **`embedded/Inc/object_detection.h`** - Novo header para detecção
5. **`embedded/Src/app_frame_processing.c`** - Pipeline de processamento
6. **`embedded/Src/nn_runner.c`** - Execução do modelo
7. **`embedded/Models/object_detection.*`** - Arquivos gerados pelo STEdgeAI

**Arquivo: `embedded/Inc/object_detection.h`**
```c
#ifndef OBJECT_DETECTION_H
#define OBJECT_DETECTION_H

#include <stdint.h>
#include <stdbool.h>

// Estruturas de dados
typedef struct {
    float x, y, width, height;  // Coordenadas normalizadas
    float confidence;
    int class_id;
    char class_name[32];
} detected_object_t;

typedef struct {
    detected_object_t objects[AI_OD_MODEL_PP_MAX_BOXES_LIMIT];
    int num_objects;
    uint32_t inference_time_ms;
} detection_results_t;

// Funções principais
detection_results_t run_object_detection(uint8_t* image_data);
void preprocess_image_for_detection(uint8_t* input, uint8_t* output);
void postprocess_detection_output(float* raw_output, detection_results_t* results);
void apply_nms(detection_results_t* results, float nms_threshold);

#endif // OBJECT_DETECTION_H
```

**Arquivo: `embedded/Src/object_detection.c`**
```c
#include "object_detection.h"
#include "object_detection.h"  // Arquivo gerado pelo STEdgeAI
#include "app_config.h"

detection_results_t run_object_detection(uint8_t* image_data) {
    detection_results_t results = {0};
    uint32_t start_time = HAL_GetTick();
    
    // 1. Preprocessamento
    static uint8_t preprocessed_data[AI_OD_MODEL_INPUT_WIDTH * AI_OD_MODEL_INPUT_HEIGHT * 3];
    preprocess_image_for_detection(image_data, preprocessed_data);
    
    // 2. Inferência
    ai_buffer input_buffer = AI_BUFFER_OBJ_INIT(
        AI_BUFFER_FORMAT_U8, 1, 1, 
        AI_OD_MODEL_INPUT_WIDTH * AI_OD_MODEL_INPUT_HEIGHT * 3,
        1, preprocessed_data
    );
    
    static float output_data[AI_OD_MODEL_OUTPUT_SIZE];
    ai_buffer output_buffer = AI_BUFFER_OBJ_INIT(
        AI_BUFFER_FORMAT_FLOAT, 1, 1, AI_OD_MODEL_OUTPUT_SIZE,
        1, output_data
    );
    
    // Executa modelo
    ai_object_detection_run(&input_buffer, &output_buffer);
    
    // 3. Pós-processamento
    postprocess_detection_output(output_data, &results);
    
    // 4. Non-Maximum Suppression
    apply_nms(&results, AI_OD_MODEL_PP_NMS_THRESHOLD);
    
    results.inference_time_ms = HAL_GetTick() - start_time;
    return results;
}

void preprocess_image_for_detection(uint8_t* input, uint8_t* output) {
    // Redimensiona imagem de câmera para tamanho do modelo
    // Implementar resize + normalização conforme necessário
    
    for (int i = 0; i < AI_OD_MODEL_INPUT_WIDTH * AI_OD_MODEL_INPUT_HEIGHT * 3; i++) {
        output[i] = input[i];  // Simplificado - adicionar resize real
    }
}

void postprocess_detection_output(float* raw_output, detection_results_t* results) {
    // Decodifica saída do modelo (específico para cada arquitetura)
    // Exemplo para YOLO:
    
    int output_idx = 0;
    results->num_objects = 0;
    
    for (int i = 0; i < AI_OD_MODEL_TOTAL_PREDICTIONS && results->num_objects < AI_OD_MODEL_PP_MAX_BOXES_LIMIT; i++) {
        float confidence = raw_output[output_idx + 4];  // Índice pode variar
        
        if (confidence > AI_OD_MODEL_PP_CONF_THRESHOLD) {
            detected_object_t* obj = &results->objects[results->num_objects];
            
            obj->x = raw_output[output_idx + 0];
            obj->y = raw_output[output_idx + 1]; 
            obj->width = raw_output[output_idx + 2];
            obj->height = raw_output[output_idx + 3];
            obj->confidence = confidence;
            
            // Encontra classe com maior probabilidade
            float max_class_prob = 0;
            int best_class = 0;
            for (int c = 0; c < AI_OD_MODEL_NB_CLASSES; c++) {
                float class_prob = raw_output[output_idx + 5 + c];
                if (class_prob > max_class_prob) {
                    max_class_prob = class_prob;
                    best_class = c;
                }
            }
            
            obj->class_id = best_class;
            strcpy(obj->class_name, od_classes_table[best_class]);
            
            results->num_objects++;
        }
        
        output_idx += (5 + AI_OD_MODEL_NB_CLASSES);  // Próxima predição
    }
}
```

### 8.3. Para Novos Modelos de Classificação

**Arquivos obrigatórios:**

1. **`stm32_tools_config.json`** - Configuração do modelo
2. **`embedded/Inc/app_config.h`** - Parâmetros do modelo
3. **`embedded/Src/classification.c`** - Novo arquivo para lógica de classificação
4. **`embedded/Inc/classification.h`** - Novo header para classificação
5. **`embedded/Models/classification.*`** - Arquivos gerados pelo STEdgeAI

**Arquivo: `embedded/Inc/classification.h`**
```c
#ifndef CLASSIFICATION_H
#define CLASSIFICATION_H

#include <stdint.h>
#include <stdbool.h>

// Estruturas de dados
typedef struct {
    int class_id;
    char class_name[32];
    float confidence;
} classification_result_t;

typedef struct {
    classification_result_t top_results[5];  // Top-5 predictions
    int num_results;
    uint32_t inference_time_ms;
} classification_results_t;

// Funções principais
classification_result_t run_classification(uint8_t* image_data);
classification_results_t run_classification_top_k(uint8_t* image_data, int k);
void preprocess_image_for_classification(uint8_t* input, uint8_t* output);
void postprocess_classification_output(float* raw_output, classification_results_t* results, int k);

#endif // CLASSIFICATION_H
```

**Arquivo: `embedded/Src/classification.c`**
```c
#include "classification.h"
#include "classification.h"  // Arquivo gerado pelo STEdgeAI
#include "app_config.h"

classification_result_t run_classification(uint8_t* image_data) {
    classification_results_t results = run_classification_top_k(image_data, 1);
    return results.top_results[0];
}

classification_results_t run_classification_top_k(uint8_t* image_data, int k) {
    classification_results_t results = {0};
    uint32_t start_time = HAL_GetTick();
    
    // 1. Preprocessamento
    static uint8_t preprocessed_data[AI_CLS_MODEL_INPUT_WIDTH * AI_CLS_MODEL_INPUT_HEIGHT * 3];
    preprocess_image_for_classification(image_data, preprocessed_data);
    
    // 2. Inferência
    ai_buffer input_buffer = AI_BUFFER_OBJ_INIT(
        AI_BUFFER_FORMAT_U8, 1, 1,
        AI_CLS_MODEL_INPUT_WIDTH * AI_CLS_MODEL_INPUT_HEIGHT * 3,
        1, preprocessed_data
    );
    
    static float output_data[AI_CLS_MODEL_NB_CLASSES];
    ai_buffer output_buffer = AI_BUFFER_OBJ_INIT(
        AI_BUFFER_FORMAT_FLOAT, 1, 1, AI_CLS_MODEL_NB_CLASSES,
        1, output_data
    );
    
    // Executa modelo
    ai_classification_run(&input_buffer, &output_buffer);
    
    // 3. Pós-processamento (Top-K)
    postprocess_classification_output(output_data, &results, k);
    
    results.inference_time_ms = HAL_GetTick() - start_time;
    return results;
}

void preprocess_image_for_classification(uint8_t* input, uint8_t* output) {
    // Redimensiona e normaliza imagem para classificação
    // Implementar resize + normalização [0,1] ou [-1,1] conforme modelo
    
    for (int i = 0; i < AI_CLS_MODEL_INPUT_WIDTH * AI_CLS_MODEL_INPUT_HEIGHT * 3; i++) {
        output[i] = input[i];  // Simplificado - adicionar resize e normalização real
    }
}

void postprocess_classification_output(float* raw_output, classification_results_t* results, int k) {
    // Aplica softmax e encontra top-k classes
    
    // 1. Aplica softmax
    float sum_exp = 0.0f;
    static float softmax_output[AI_CLS_MODEL_NB_CLASSES];
    
    for (int i = 0; i < AI_CLS_MODEL_NB_CLASSES; i++) {
        softmax_output[i] = expf(raw_output[i]);
        sum_exp += softmax_output[i];
    }
    
    for (int i = 0; i < AI_CLS_MODEL_NB_CLASSES; i++) {
        softmax_output[i] /= sum_exp;
    }
    
    // 2. Encontra top-k classes
    results->num_results = (k < AI_CLS_MODEL_NB_CLASSES) ? k : AI_CLS_MODEL_NB_CLASSES;
    
    for (int rank = 0; rank < results->num_results; rank++) {
        int best_idx = 0;
        float best_score = -1.0f;
        
        // Encontra próxima melhor classe (que ainda não foi selecionada)
        for (int i = 0; i < AI_CLS_MODEL_NB_CLASSES; i++) {
            if (softmax_output[i] > best_score) {
                // Verifica se já foi selecionada
                bool already_selected = false;
                for (int j = 0; j < rank; j++) {
                    if (results->top_results[j].class_id == i) {
                        already_selected = true;
                        break;
                    }
                }
                
                if (!already_selected) {
                    best_score = softmax_output[i];
                    best_idx = i;
                }
            }
        }
        
        results->top_results[rank].class_id = best_idx;
        results->top_results[rank].confidence = best_score;
        strcpy(results->top_results[rank].class_name, cls_classes_table[best_idx]);
    }
}
```

### 8.4. Scripts de Conversão e Build

**Script completo para conversão:**
```bash
#!/bin/bash
# convert_models.sh

# Converte modelo de detecção
./scripts/compile_model.sh object_detection ./input_models/yolov5s_custom.onnx

# Converte modelo de classificação  
./scripts/compile_model.sh classification ./input_models/mobilenetv2_custom.onnx

# Build do projeto
cd embedded
make clean && make -j$(nproc)

# Assina binários
cd ..
./scripts/sign_binary.sh ./embedded/build/Project.bin

# Flash firmware
./scripts/flash_firmware.sh all

echo "Deploy completo realizado!"
```

### 8.5. Makefile Personalizado

**Arquivo: `embedded/Makefile.custom`**
```makefile
# Configurações condicionais baseadas nos modelos ativos

# Definições baseadas em app_config.h
ifeq ($(USE_OBJECT_DETECTION), 1)
    SOURCES += Src/object_detection.c
    HEADERS += Inc/object_detection.h
    MODELS += Models/object_detection.c
endif

ifeq ($(USE_CLASSIFICATION), 1)
    SOURCES += Src/classification.c  
    HEADERS += Inc/classification.h
    MODELS += Models/classification.c
endif

ifeq ($(USE_INTEGRATED_AI), 1)
    SOURCES += Src/integrated_ai.c
    HEADERS += Inc/integrated_ai.h
endif

# Flags de compilação
CFLAGS += -DUSE_OBJECT_DETECTION=$(USE_OBJECT_DETECTION)
CFLAGS += -DUSE_CLASSIFICATION=$(USE_CLASSIFICATION)

# Targets específicos
.PHONY: detection-only classification-only integrated clean-models

detection-only:
	$(MAKE) USE_OBJECT_DETECTION=1 USE_CLASSIFICATION=0

classification-only:
	$(MAKE) USE_OBJECT_DETECTION=0 USE_CLASSIFICATION=1

integrated:
	$(MAKE) USE_OBJECT_DETECTION=1 USE_CLASSIFICATION=1 USE_INTEGRATED_AI=1

clean-models:
	rm -f Models/object_detection.*
	rm -f Models/classification.*
	rm -f converted_models/*
```

## 9. Debugging e Otimização

### 9.1. Verificação de Performance

```c
// embedded/Src/debug_performance.c
void measure_model_performance() {
    uint32_t start_time, end_time;
    
    // Medir detecção
    start_time = HAL_GetTick();
    run_face_detection(test_image);
    end_time = HAL_GetTick();
    printf("Detection time: %lu ms\n", end_time - start_time);
    
    // Medir reconhecimento
    start_time = HAL_GetTick();
    run_face_recognition(test_face);
    end_time = HAL_GetTick();
    printf("Recognition time: %lu ms\n", end_time - start_time);
}
```

### 9.2. Monitoramento de Memória

```c
// embedded/Src/debug_memory.c
void check_memory_usage() {
    extern uint32_t _heap_start, _heap_end;
    uint32_t heap_size = (uint32_t)&_heap_end - (uint32_t)&_heap_start;
    uint32_t heap_used = get_heap_usage();
    
    printf("Heap usage: %lu / %lu bytes (%.1f%%)\n", 
           heap_used, heap_size, (float)heap_used/heap_size*100);
}
```

### 9.3. Otimizações Comuns

1. **Quantização INT8**: Já configurada nos scripts
2. **Batch size = 1**: Para inferência em tempo real
3. **Memory pooling**: Configurado automaticamente
4. **NPU acceleration**: Habilitado por padrão

### 9.4. Troubleshooting

**Problema**: Modelo não carrega
```bash
# Verificar endereços de memória
STM32_Programmer_CLI -c port=SWD -r32 0x71000000 0x1000
```

**Problema**: Performance baixa
```c
// Verificar se NPU está sendo usado
if (ai_platform_get_device() != AI_DEVICE_TYPE_NPU) {
    printf("WARNING: NPU not being used!\n");
}
```

**Problema**: Acurácia baixa
- Verificar pré-processamento da imagem
- Conferir normalização dos dados
- Validar pós-processamento

## Conclusão

Este tutorial fornece um framework completo para treinar e deploy modelos customizados no STM32N6. O sistema é modular e permite fácil integração de novos modelos mantendo a performance otimizada.

Para suporte adicional, consulte:
- [Documentação STEdgeAI](https://www.st.com/en/development-tools/st-edge-ai.html)
- [STM32N6 Reference Manual](https://www.st.com/resource/en/reference_manual/rm0539-stm32n6xxxx-reference-manual-stmicroelectronics.pdf)
- Issues do projeto no GitHub