/**
 ******************************************************************************
 * @file    app_constants.h
 * @author  PeleAB
 * @brief   Application constants and configuration parameters
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#ifndef APP_CONSTANTS_H
#define APP_CONSTANTS_H

/* ========================================================================= */
/* TIMING CONSTANTS                                                          */
/* ========================================================================= */
/** @brief Duration for button long press detection (milliseconds) */
#define BUTTON_LONG_PRESS_DURATION_MS       1000

/** @brief UART communication timeout (milliseconds) */
#define UART_COMMUNICATION_TIMEOUT_MS       1000

/* ========================================================================= */
/* NEURAL NETWORK CONSTANTS                                                  */
/* ========================================================================= */
/** @brief Maximum number of neural network output buffers */
#define NN_MAX_OUTPUT_BUFFERS               5


/* ========================================================================= */
/* PROTOCOL CONSTANTS                                                        */
/* ========================================================================= */
/** @brief Maximum payload size for robust protocol */
#define PROTOCOL_MAX_PAYLOAD_SIZE           (64 * 1024)

/** @brief Display stream scale factor */
#define DISPLAY_STREAM_SCALE_FACTOR         2

/** @brief CRC32 polynomial for protocol validation */
#define PROTOCOL_CRC32_POLYNOMIAL           0xEDB88320

/* ========================================================================= */
/* MEMORY ALIGNMENT CONSTANTS                                                */
/* ========================================================================= */
/** @brief Memory alignment requirement for buffers */
#define MEMORY_ALIGNMENT_BYTES              32

/** @brief Cache line alignment requirement */
#define CACHE_LINE_ALIGNMENT                32

/* ========================================================================= */
/* PERFORMANCE CONSTANTS                                                     */
/* ========================================================================= */
/** @brief Target frames per second for display */
#define TARGET_DISPLAY_FPS                  60

/** @brief Target frames per second for camera capture */
#define TARGET_CAMERA_FPS                   30

/** @brief Performance monitoring update interval (frames) */
#define PERFORMANCE_UPDATE_INTERVAL         10

/* ========================================================================= */
/* UTILITY MACROS                                                           */
/* ========================================================================= */
/** @brief Align value to 16-byte boundary */
#define ALIGN_TO_16(value)                  (((value) + 15) & ~15)

/** @brief Align value to 32-byte boundary */
#define ALIGN_TO_32(value)                  (((value) + 31) & ~31)

/** @brief Calculate buffer size with alignment */
#define DCMIPP_OUT_NN_LEN                   (ALIGN_TO_16(NN_WIDTH * NN_BPP) * NN_HEIGHT)
#define DCMIPP_OUT_NN_BUFF_LEN              (DCMIPP_OUT_NN_LEN + MEMORY_ALIGNMENT_BYTES - DCMIPP_OUT_NN_LEN % MEMORY_ALIGNMENT_BYTES)

/** @brief Convert milliseconds to microseconds */
#define MS_TO_US(ms)                        ((ms) * 1000)

/** @brief Convert seconds to milliseconds */
#define SEC_TO_MS(sec)                      ((sec) * 1000)

#endif /* APP_CONSTANTS_H */
