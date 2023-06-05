/**************************************************************************//**
 * @file     best2300.h
 * @brief    CMSIS Core Peripheral Access Layer Header File for
 *           ARMCM4 Device Series
 * @version  V2.02
 * @date     10. September 2014
 *
 * @note     configured for CM4 with FPU
 *
 ******************************************************************************/
/* Copyright (c) 2011 - 2014 ARM LIMITED

   All rights reserved.
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:
   - Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.
   - Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in the
     documentation and/or other materials provided with the distribution.
   - Neither the name of ARM nor the names of its contributors may be used
     to endorse or promote products derived from this software without
     specific prior written permission.
   *
   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
   ARE DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDERS AND CONTRIBUTORS BE
   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
   POSSIBILITY OF SUCH DAMAGE.
   ---------------------------------------------------------------------------*/


#ifndef __BEST2300_H__
#define __BEST2300_H__

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __ASSEMBLER__
/* -------------------------  Interrupt Number Definition  ------------------------ */

typedef enum IRQn
{
/* -------------------  Cortex-M4 Processor Exceptions Numbers  ------------------- */
  NonMaskableInt_IRQn           = -14,      /*!<  2 Non Maskable Interrupt          */
  HardFault_IRQn                = -13,      /*!<  3 HardFault Interrupt             */
  MemoryManagement_IRQn         = -12,      /*!<  4 Memory Management Interrupt     */
  BusFault_IRQn                 = -11,      /*!<  5 Bus Fault Interrupt             */
  UsageFault_IRQn               = -10,      /*!<  6 Usage Fault Interrupt           */
  SVCall_IRQn                   =  -5,      /*!< 11 SV Call Interrupt               */
  DebugMonitor_IRQn             =  -4,      /*!< 12 Debug Monitor Interrupt         */
  PendSV_IRQn                   =  -2,      /*!< 14 Pend SV Interrupt               */
  SysTick_IRQn                  =  -1,      /*!< 15 System Tick Interrupt           */

/* ----------------------  BEST1000 Specific Interrupt Numbers  --------------------- */
  FPU_IRQn                      =   0,      /*!< FPU Interrupt                      */
  SENSOR_WKUP_IRQn              =   1,      /*!< SENSOR Wakeup Interrupt            */
  SDMMC_IRQn                    =   2,      /*!< SDMMC Interrupt                    */
  AUDMA_IRQn                    =   3,      /*!< Audio DMA Interrupt                */
  GPDMA_IRQn                    =   4,      /*!< General Purpose DMA Interrupt      */
  AON_WDT_IRQn                  =   5,      /*!< AON Watchdog Timer Interrupt       */
  USB_PHY_IRQn                  =   6,      /*!< USB PHY Interrupt                  */
  USB_IRQn                      =   7,      /*!< USB Interrupt                      */
  WAKEUP_IRQn                   =   8,      /*!< Wakeup Interrupt                   */
  AON_GPIO_IRQn                 =   9,      /*!< AON GPIO Interrupt                 */
  MCU_WDT_IRQn                  =  10,      /*!< Watchdog Timer Interrupt           */
  RESERVED11_IRQn               =  11,      /*!< Reserved Interrupt                 */
  MCU_TIMER00_IRQn              =  12,      /*!< Timer00 Interrupt                  */
  MCU_TIMER01_IRQn              =  13,      /*!< Timer01 Interrupt                  */
  I2C0_IRQn                     =  14,      /*!< I2C0 Interrupt                     */
  SPI0_IRQn                     =  15,      /*!< SPI0 Interrupt                     */
  SPILCD_IRQn                   =  16,      /*!< SPILCD Interrupt                   */
  UART0_IRQn                    =  17,      /*!< UART0 Interrupt                    */
  UART1_IRQn                    =  18,      /*!< UART1 Interrupt                    */
  CODEC_IRQn                    =  19,      /*!< CODEC Interrupt                    */
  BTPCM_IRQn                    =  20,      /*!< BTPCM Interrupt                    */
  I2S0_IRQn                     =  21,      /*!< I2S0 Interrupt                     */
  SPDIF0_IRQn                   =  22,      /*!< SPDIF0 Interrupt                   */
  ITNSPI_IRQn                   =  23,      /*!< Internal SPI Interrupt             */
  BT_IRQn                       =  24,      /*!< BT to MCU Interrupt                */
  RESERVED25_IRQn               =  25,      /*!< Reserved Interrupt                 */
  UART2_IRQn                    =  26,      /*!< UART2 Interrupt                    */
  MCU_TIMER10_IRQn              =  27,      /*!< Timer10 Interrupt                  */
  MCU_TIMER11_IRQn              =  28,      /*!< Timer11 Interrupt                  */
  I2C1_IRQn                     =  29,      /*!< I2C1 Interrupt                     */
  DUMP_IRQn                     =  30,      /*!< DUMP Interrupt                     */
  SPIPHY_IRQn                   =  31,      /*!< SPIPHY Interrupt                   */
  ISDONE_IRQn                   =  32,      /*!< Intersys MCU2BT Data Done Interrupt */
  ISDONE1_IRQn                  =  33,      /*!< Intersys MCU2BT Data1 Done Interrupt */
  ISDATA_IRQn                   =  34,      /*!< Intersys BT2MCU Data Indication Interrupt */
  ISDATA1_IRQn                  =  35,      /*!< Intersys BT2MCU Data1 Indication Interrupt */
  SENSOR0_IRQn                  =  36,      /*!< SENSOR0 Interrupt                  */
  SENSOR1_IRQn                  =  37,      /*!< SENSOR1 Interrupt                  */
  SENSOR2_IRQn                  =  38,      /*!< SENSOR2 Interrupt                  */
  SENSOR3_IRQn                  =  39,      /*!< SENSOR3 Interrupt                  */
  USB_CAL_IRQn                  =  40,      /*!< USB Calibration Interrupt          */
  USB_PIN_IRQn                  =  41,      /*!< USB Pin Interrupt                  */
  PMU_IRQn                      =  42,      /*!< PMU Interrupt                      */
  RESERVED43_IRQn               =  43,      /*!< Reserved Interrupt                 */
  AON_IRQn                      =  44,      /*!< AON Interrupt                      */
  AON_TIMER00_IRQn              =  45,      /*!< AON Timer00 Interrupt              */
  AON_TIMER01_IRQn              =  46,      /*!< AON Timer01 Interrupt              */
  RESERVED47_IRQn               =  47,      /*!< Reserved Interrupt                 */

  USER_IRQn_QTY,
  INVALID_IRQn                  = USER_IRQn_QTY,
} IRQn_Type;

#define GPIO_IRQn               AON_GPIO_IRQn
#define GPADC_IRQn              INVALID_IRQn
#define PWRKEY_IRQn             INVALID_IRQn
#ifdef CORE_SLEEP_POWER_DOWN
#define TIMER00_IRQn            AON_TIMER00_IRQn
#define TIMER01_IRQn            AON_TIMER01_IRQn
#else
#define TIMER00_IRQn            MCU_TIMER00_IRQn
#define TIMER01_IRQn            MCU_TIMER01_IRQn
#endif
#define WDT_IRQn                AON_WDT_IRQn

#endif

/* ================================================================================ */
/* ================      Processor and Core Peripheral Section     ================ */
/* ================================================================================ */

/* --------  Configuration of the Cortex-M4 Processor and Core Peripherals  ------- */
#define __CM4_REV                 0x0001    /*!< Core revision r0p1                              */
#define __MPU_PRESENT             1         /*!< MPU present or not                              */
#define __VTOR_PRESENT            1U        /* VTOR present */
#define __NVIC_PRIO_BITS          3         /*!< Number of Bits used for Priority Levels         */
#define __Vendor_SysTickConfig    0         /*!< Set to 1 if different SysTick Config is used    */
#define __FPU_PRESENT             1         /*!< FPU present                                     */
#define __NUM_CODE_PATCH          56
#define __NUM_LIT_PATCH           8

#include "core_cm4.h"                       /* Processor and core peripherals                    */

#ifndef __ASSEMBLER__

#include "system_ARMCM.h"                  /* System Header                                     */

#endif

/* ================================================================================ */
/* ================       Device Specific Peripheral Section       ================ */
/* ================================================================================ */

/* -------------------  Start of section using anonymous unions  ------------------ */
#if   defined (__CC_ARM)
  #pragma push
  #pragma anon_unions
#elif defined (__ICCARM__)
  #pragma language=extended
#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #pragma clang diagnostic push
  #pragma clang diagnostic ignored "-Wc11-extensions"
  #pragma clang diagnostic ignored "-Wreserved-id-macro"
#elif defined (__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined (__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined (__TASKING__)
  #pragma warning 586
#elif defined (__CSMC__)
  /* anonymous unions are enabled by default */
#else
  #warning Not supported compiler type
#endif

/* --------------------  End of section using anonymous unions  ------------------- */
#if   defined (__CC_ARM)
  #pragma pop
#elif defined (__ICCARM__)
  /* leave anonymous unions enabled */
#elif (defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050))
  #pragma clang diagnostic pop
#elif defined (__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined (__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined (__TASKING__)
  #pragma warning restore
#elif defined (__CSMC__)
  /* anonymous unions are enabled by default */
#else
  #warning Not supported compiler type
#endif


#ifdef __cplusplus
}
#endif

#endif
