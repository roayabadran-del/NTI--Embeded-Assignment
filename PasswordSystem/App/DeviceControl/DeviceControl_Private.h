/**
 * @file DeviceControl_Private.h
 * @author Team -- Password-Protected Motor Control System
 * @brief
 * @version 0.1
 * @date 2026-08-29
 *
 * @copyright Copyright (c) 2026
 *
 */
#ifndef DEVICECONTROL_PRIVATE
#define DEVICECONTROL_PRIVATE

#include <stdint.h>

typedef enum
{
    DEV_ModeIdle,      /* motor stopped/running, no LED animation active */
    DEV_ModeAnimation, /* key '4' pressed -- 4 LEDs cycling pseudo-randomly */
}DEV_Mode_t;

#endif /* DEVICECONTROL_PRIVATE */
