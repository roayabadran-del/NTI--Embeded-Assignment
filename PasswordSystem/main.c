/**
 * @file main.c
 * @author Team -- Password-Protected Motor Control System
 * @brief Application entry point. Password entry runs first; once
 *        unlocked, the motor/LED-animation control task is registered
 *        with the Scheduler for the first time so it never competes with
 *        password entry for keypad input.
 * @version 1.0
 * @date 2026-08-29
 *
 * @copyright Copyright (c) 2026
 *
 */

#include "Mcal/GIE/GIE_Interface.h"
#include "App/Scheduler/Scheduler_Interface.h"
#include "App/PasswordLock/PasswordLock_Interface.h"
#include "App/DeviceControl/DeviceControl_Interface.h"
#include "Hal/LCD/LCD_Interface.h"
#include "Hal/KeyPad/KeyPad_Interface.h"

int main(void)
{
    uint8_t Local_u8DeviceControlStarted = 0U;

    /* ---- 1. MCAL / HAL initialisation ---- */
    SCHED_Init();      /* starts the Timer0 1ms system tick */
    KPD_Init();
    LCD_Init();

    /* ---- 2. APP initialisation ---- */
    PWD_Init();         /* shows the initial "Enter Password" prompt */
    DEV_Init();          /* motor stopped, animation LEDs off, ready to go once unlocked */

    /* ---- 3. Enable global interrupts exactly once, after every
     *         module's Init() has configured its own interrupt sources.
     */
    GIE_Enable();

    /* ---- 4. Register password-entry work. DeviceControl's tasks are
     *         NOT registered yet -- see the loop below -- so its keypad
     *         scanning cannot race with password entry.
     */
    SCHED_RegisterTask(PWD_MainFunction,50UL);
    SCHED_RegisterTask(PWD_BlockedTick,PWD_BlinkPeriodMs);

    /* ---- 5. Real-time loop. No _delay_ms() anywhere in this file or in
     *         any registered task -- everything is driven by the 1ms
     *         Timer0 tick through the Scheduler.
     */
    while(1)
    {
        SCHED_MainFunction();

        if((PWD_IsUnlocked()==1U) && (Local_u8DeviceControlStarted==0U))
        {
            /* One-time hand-off, the moment the correct password lands:
             * from here on, DeviceControl owns keypad interpretation.
             */
            Local_u8DeviceControlStarted = 1U;
            SCHED_RegisterTask(DEV_MainFunction,50UL);
            SCHED_RegisterTask(DEV_AnimationTick,DEV_AnimationPeriodMs);
        }
        else
        {
            // still locked, or DeviceControl tasks already registered
        }
    }

    return 0;
}
