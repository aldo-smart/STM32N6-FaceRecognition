/**
  ******************************************************************************
  * @file    weed_detection.h
  * @author  STEdgeAI
  * @date    2025-08-04 13:45:14
  * @brief   Minimal description of the generated c-implemention of the network
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  ******************************************************************************
  */
#ifndef LL_ATON_WEED_DETECTION_H
#define LL_ATON_WEED_DETECTION_H

/******************************************************************************/
#define LL_ATON_WEED_DETECTION_C_MODEL_NAME        "weed_detection"
#define LL_ATON_WEED_DETECTION_ORIGIN_MODEL_NAME   "YOLOV5_WEEDS_STM_640"

/************************** USER ALLOCATED IOs ********************************/
// No user allocated inputs
// No user allocated outputs

/************************** INPUTS ********************************************/
#define LL_ATON_WEED_DETECTION_IN_NUM        (1)    // Total number of input buffers
// Input buffer 1 -- Input_12_out_0
#define LL_ATON_WEED_DETECTION_IN_1_ALIGNMENT   (32)
#define LL_ATON_WEED_DETECTION_IN_1_SIZE_BYTES  (4915200)

/************************** OUTPUTS *******************************************/
#define LL_ATON_WEED_DETECTION_OUT_NUM        (1)    // Total number of output buffers
// Output buffer 1 -- Concat_254_out_0
#define LL_ATON_WEED_DETECTION_OUT_1_ALIGNMENT   (32)
#define LL_ATON_WEED_DETECTION_OUT_1_SIZE_BYTES  (1612800)

#endif /* LL_ATON_WEED_DETECTION_H */
