/**
 * @file PasswordLock_Private.h
 * @author Team -- Password-Protected Motor Control System
 * @brief
 * @version 0.1
 * @date 2026-08-29
 *
 * @copyright Copyright (c) 2026
 *
 */
#ifndef PASSWORDLOCK_PRIVATE
#define PASSWORDLOCK_PRIVATE

#include <stdint.h>

typedef enum
{
    PWD_StateEntering,
    PWD_StateUnlocked,
    PWD_StateBlocked,
}PWD_State_t;

#endif /* PASSWORDLOCK_PRIVATE */
