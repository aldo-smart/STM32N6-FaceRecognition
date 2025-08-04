#include "app_postprocess.h"
#include "app_config.h"
#include "ll_aton_NN_interface.h"
#include <assert.h>
#include <string.h>

#if (POSTPROCESS_TYPE == POSTPROCESS_OD_YOLO_V5_UU)

static od_pp_outBuffer_t out_detections[AI_OD_YOLOV5_PP_MAX_BOXES_LIMIT];

int32_t app_postprocess_init(void *params_postprocess)
{
  yolov5_pp_static_param_t *params = (yolov5_pp_static_param_t *)params_postprocess;
  params->nb_classes = AI_OD_YOLOV5_PP_NB_CLASSES;
  params->conf_threshold = AI_OD_YOLOV5_PP_CONF_THRESHOLD;
  params->iou_threshold = AI_OD_YOLOV5_PP_IOU_THRESHOLD;
  params->nb_total_boxes = AI_OD_YOLOV5_PP_TOTAL_BOXES;
  params->max_boxes_limit = AI_OD_YOLOV5_PP_MAX_BOXES_LIMIT;
  params->raw_output_scale = 1.0f;
  params->raw_output_zero_point = 0;
  params->nb_detect = 0;
  return od_yolov5_pp_reset(params);
}

int32_t app_postprocess_run(void *pInput[], int nb_input, void *pOutput, void *pInput_param)
{
  assert(nb_input == 1);  // YOLOv5 centroid version expects 1 input
  od_pp_out_t *pOdOutput = (od_pp_out_t *)pOutput;
  yolov5_pp_in_centroid_uint8_t pp_input = {
      .pRaw_detections = (uint8_t *)pInput[0],
  };
  pOdOutput->pOutBuff = out_detections;
  return od_yolov5_pp_process_uint8(&pp_input, pOdOutput,
                                   (yolov5_pp_static_param_t *)pInput_param);
}

#else

// Keep original palm detection implementation for backward compatibility
static pd_pp_box_t out_detections[AI_PD_MODEL_PP_MAX_BOXES_LIMIT];
static pd_pp_point_t out_keyPoints[AI_PD_MODEL_PP_MAX_BOXES_LIMIT][AI_PD_MODEL_PP_NB_KEYPOINTS];

int32_t app_postprocess_init(void *params_postprocess)
{
  pd_model_pp_static_param_t *params = (pd_model_pp_static_param_t *)params_postprocess;
  params->width = AI_PD_MODEL_PP_WIDTH;
  params->height = AI_PD_MODEL_PP_HEIGHT;
  params->nb_keypoints = AI_PD_MODEL_PP_NB_KEYPOINTS;
  params->conf_threshold = AI_PD_MODEL_PP_CONF_THRESHOLD;
  params->iou_threshold = AI_PD_MODEL_PP_IOU_THRESHOLD;
  params->nb_total_boxes = AI_PD_MODEL_PP_TOTAL_DETECTIONS;
  params->max_boxes_limit = AI_PD_MODEL_PP_MAX_BOXES_LIMIT;
  params->pAnchors = NULL;
  for (int i = 0; i < AI_PD_MODEL_PP_MAX_BOXES_LIMIT; i++)
  {
    out_detections[i].pKps = &out_keyPoints[i][0];
  }
  return pd_model_pp_reset(params);
}

int32_t app_postprocess_run(void *pInput[], int nb_input, void *pOutput, void *pInput_param)
{
  assert(nb_input == 4);
  pd_postprocess_out_t *pPdOutput = (pd_postprocess_out_t *)pOutput;
  pd_model_pp_in_t pp_input = {
      .pScale   = (float32_t *)pInput[0],
      .pLms     = (float32_t *)pInput[1],
      .pHeatmap = (float32_t *)pInput[2],
      .pOffset  = (float32_t *)pInput[3],
  };
  pPdOutput->pOutData = out_detections;
  return pd_model_pp_process(&pp_input, pPdOutput,
                             (pd_model_pp_static_param_t *)pInput_param);
}

#endif