/**
 ******************************************************************************
 * @file    app_config_manager.c
 * @author  PeleAB
 * @brief   Configuration management system implementation
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

#include "app_config_manager.h"
#include <string.h>
#include <stdio.h>

/* ========================================================================= */
/* PRIVATE CONSTANTS                                                         */
/* ========================================================================= */
#define CONFIG_VERSION          0x00010000  /**< Configuration version */
#define CONFIG_MAGIC_NUMBER     0xDEADBEEF  /**< Configuration magic number */

/* ========================================================================= */
/* PRIVATE FUNCTION PROTOTYPES                                               */
/* ========================================================================= */
static void config_set_defaults(app_config_t *config);
static uint32_t crc32_calculate(const uint8_t *data, size_t length);

/* ========================================================================= */
/* PUBLIC FUNCTION IMPLEMENTATIONS                                           */
/* ========================================================================= */

/**
 * @brief Initialize configuration manager with default values
 * @param config Pointer to configuration structure
 * @return 0 on success, negative on error
 */
int config_manager_init(app_config_t *config)
{
    if (config == NULL) {
        return -1;
    }
    
    config_set_defaults(config);
    config->config_version = CONFIG_VERSION;
    config->config_crc = config_manager_calculate_crc(config);
    
    return 0;
}

/**
 * @brief Load configuration from persistent storage
 * @param config Pointer to configuration structure
 * @return 0 on success, negative on error
 */
int config_manager_load(app_config_t *config)
{
    if (config == NULL) {
        return -1;
    }
    
    /* TODO: Implement loading from flash/EEPROM */
    /* For now, just initialize with defaults */
    return config_manager_init(config);
}

/**
 * @brief Save configuration to persistent storage
 * @param config Pointer to configuration structure
 * @return 0 on success, negative on error
 */
int config_manager_save(const app_config_t *config)
{
    if (config == NULL) {
        return -1;
    }
    
    if (!config_manager_validate(config)) {
        return -2;
    }
    
    /* TODO: Implement saving to flash/EEPROM */
    /* For now, just return success */
    return 0;
}

/**
 * @brief Validate configuration parameters
 * @param config Pointer to configuration structure
 * @return true if valid, false otherwise
 */
bool config_manager_validate(const app_config_t *config)
{
    if (config == NULL) {
        return false;
    }
    
    /* Validate weed detection parameters */
    if (config->weed_detection.confidence_threshold < 0.0f || 
        config->weed_detection.confidence_threshold > 1.0f) {
        return false;
    }
    
    if (config->weed_detection.nms_threshold < 0.0f || 
        config->weed_detection.nms_threshold > 1.0f) {
        return false;
    }
    
    if (config->weed_detection.max_detections == 0 || 
        config->weed_detection.max_detections > 100) {
        return false;
    }
    
    /* Validate performance parameters */
    if (config->performance.target_fps == 0 || 
        config->performance.target_fps > 120) {
        return false;
    }
    
    if (config->performance.reverify_interval_ms == 0 || 
        config->performance.reverify_interval_ms > 10000) {
        return false;
    }
    
    /* Validate protocol parameters */
    if (config->protocol.max_payload_size == 0 || 
        config->protocol.max_payload_size > (1024 * 1024)) {
        return false;
    }
    
    if (config->protocol.uart_timeout_ms == 0 || 
        config->protocol.uart_timeout_ms > 10000) {
        return false;
    }
    
    /* Validate UI parameters */
    if (config->ui.button_long_press_ms == 0 || 
        config->ui.button_long_press_ms > 5000) {
        return false;
    }
    
    return true;
}

/**
 * @brief Reset configuration to default values
 * @param config Pointer to configuration structure
 * @return 0 on success, negative on error
 */
int config_manager_reset(app_config_t *config)
{
    if (config == NULL) {
        return -1;
    }
    
    return config_manager_init(config);
}

/**
 * @brief Calculate configuration checksum
 * @param config Pointer to configuration structure
 * @return CRC32 checksum value
 */
uint32_t config_manager_calculate_crc(const app_config_t *config)
{
    if (config == NULL) {
        return 0;
    }
    
    /* Calculate CRC32 of configuration excluding the CRC field itself */
    size_t crc_offset = offsetof(app_config_t, config_crc);
    return crc32_calculate((const uint8_t*)config, crc_offset);
}

/**
 * @brief Print configuration to debug output
 * @param config Pointer to configuration structure
 */
void config_manager_print(const app_config_t *config)
{
    if (config == NULL) {
        return;
    }
    
    printf("=== Application Configuration ===\n");
    printf("Version: 0x%08lX\n", (unsigned long)config->config_version);
    printf("CRC: 0x%08lX\n", (unsigned long)config->config_crc);
    
    printf("\n--- Weed Detection ---\n");
    printf("Confidence Threshold: %.3f\n", config->weed_detection.confidence_threshold);
    printf("NMS Threshold: %.3f\n", config->weed_detection.nms_threshold);
    printf("Max Detections: %lu\n", (unsigned long)config->weed_detection.max_detections);
    printf("Enable Preprocessing: %s\n", config->weed_detection.enable_preprocessing ? "Yes" : "No");
    
    printf("\n--- Performance ---\n");
    printf("Target FPS: %lu\n", (unsigned long)config->performance.target_fps);
    printf("Reverify Interval: %lu ms\n", (unsigned long)config->performance.reverify_interval_ms);
    printf("Update Interval: %lu\n", (unsigned long)config->performance.update_interval);
    printf("Enable Profiling: %s\n", config->performance.enable_profiling ? "Yes" : "No");
    
    printf("\n--- Protocol ---\n");
    printf("Max Payload Size: %lu bytes\n", (unsigned long)config->protocol.max_payload_size);
    printf("UART Timeout: %lu ms\n", (unsigned long)config->protocol.uart_timeout_ms);
    printf("Stream Scale Factor: %lu\n", (unsigned long)config->protocol.stream_scale_factor);
    printf("Enable CRC Validation: %s\n", config->protocol.enable_crc_validation ? "Yes" : "No");
    
    printf("\n--- User Interface ---\n");
    printf("Button Long Press: %lu ms\n", (unsigned long)config->ui.button_long_press_ms);
    printf("LED Timeout: %lu ms\n", (unsigned long)config->ui.led_timeout_ms);
    printf("Enable Button Feedback: %s\n", config->ui.enable_button_feedback ? "Yes" : "No");
    
    printf("================================\n");
}

/* ========================================================================= */
/* PRIVATE FUNCTION IMPLEMENTATIONS                                          */
/* ========================================================================= */

/**
 * @brief Set default configuration values
 * @param config Pointer to configuration structure
 */
static void config_set_defaults(app_config_t *config)
{
    /* Weed detection defaults */
    config->weed_detection.confidence_threshold = 0.5f;
    config->weed_detection.nms_threshold = 0.5f;
    config->weed_detection.max_detections = 10;
    config->weed_detection.enable_preprocessing = true;
    
    /* Performance defaults */
    config->performance.target_fps = TARGET_CAMERA_FPS;
    config->performance.reverify_interval_ms = 1000;
    config->performance.update_interval = PERFORMANCE_UPDATE_INTERVAL;
    config->performance.enable_profiling = false;
    
    /* Protocol defaults */
    config->protocol.max_payload_size = PROTOCOL_MAX_PAYLOAD_SIZE;
    config->protocol.uart_timeout_ms = UART_COMMUNICATION_TIMEOUT_MS;
    config->protocol.stream_scale_factor = DISPLAY_STREAM_SCALE_FACTOR;
    config->protocol.enable_crc_validation = true;
    
    /* UI defaults */
    config->ui.button_long_press_ms = BUTTON_LONG_PRESS_DURATION_MS;
    config->ui.led_timeout_ms = 1000;
    config->ui.enable_button_feedback = true;
}

/**
 * @brief Calculate CRC32 checksum
 * @param data Pointer to data buffer
 * @param length Length of data buffer
 * @return CRC32 checksum value
 */
static uint32_t crc32_calculate(const uint8_t *data, size_t length)
{
    uint32_t crc = 0xFFFFFFFF;
    
    for (size_t i = 0; i < length; i++) {
        crc ^= data[i];
        for (int j = 0; j < 8; j++) {
            if (crc & 1) {
                crc = (crc >> 1) ^ PROTOCOL_CRC32_POLYNOMIAL;
            } else {
                crc >>= 1;
            }
        }
    }
    
    return crc ^ 0xFFFFFFFF;
}