// ----------------------------------------------------------------------------
//! @file       adc.h
//! @brief      This file contains function headers to configure and operate ADC.
//! @mnemonic   adc
//! @copyright  Copyright (c) 2017 X Corporation, All Rights Reserved
// ----------------------------------------------------------------------------

// Define to prevent recursive inclusion
#pragma once

#ifdef __cplusplus
// Declaration for linkage with C++ program.
extern "C"
{
#endif

// ----------------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------------
#include "fike_reuse.h"

// ----------------------------------------------------------------------------
// Public Definitions and Types
// ----------------------------------------------------------------------------

#define ADC1_NUMBER_OF_LEVELS                   ((uint32_t)4096)
#define ADC2_NUMBER_OF_LEVELS                   ((uint32_t)4096)

// Time period to allow enough time for ADC1 to stabilize and complete a conversion.
#define ADC2_CONVERSION_DELAY_TIME              TICKS_100_MILI_SECOND

// ----------------------------------------------------------------------------
// Public Function Prototypes
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
//! @brief  Initialize ADC channels.
//! @param  void
//! @return void
// ----------------------------------------------------------------------------
void adc_Init(void);

// ----------------------------------------------------------------------------
//! @brief  Stop all ADC channels.
//! @param  void
//! @return void
// ----------------------------------------------------------------------------
void adc_StopADC(void);

// ----------------------------------------------------------------------------
//! @brief  Initialize Ground Fault ADC channel.
//! @param  void
//! @return void
// ----------------------------------------------------------------------------
void adc_gf_Init(void);

// ----------------------------------------------------------------------------
//! @brief  Begin Ground Fault measurement.
//! @param  void
//! @return void
// ----------------------------------------------------------------------------
void adc_gf_StartADCforOneValue(void);

// ----------------------------------------------------------------------------
//! @brief  Stop Ground Fault measurements.
//! @param  void
//! @return void
// ----------------------------------------------------------------------------
void adc_gf_StopADC(void);

// ----------------------------------------------------------------------------
//! @brief  Return the most recently-measured Ground Fault value.
//! @param  void
//! @return uint32_t value of ADC1 channel 8
// ----------------------------------------------------------------------------
uint32_t adc_gf_GetADCValue(void);

// ----------------------------------------------------------------------------
//! @brief  Initialize hardware ID ADC channel (ADC2).
//! @param  void
//! @return void
// ----------------------------------------------------------------------------
void adc_hwid_Init(void);

// ----------------------------------------------------------------------------
//! @brief  Begin hardware ID ADC measurement utilizing ADC2.
//! @param  void
//! @return void
// ----------------------------------------------------------------------------
void adc_hwid_StartADCforOneValue(void);

// ----------------------------------------------------------------------------
//! @brief  Stop hardware ID ADC measurement (ADC2).
//! @param  void
//! @return void
// ----------------------------------------------------------------------------
void adc_hwid_StopADC(void);

// ----------------------------------------------------------------------------
//! @brief  Return the most recently-measured hardware ID ADC value (ADC2).
//! @param  void
//! @return uint32_t value of ADC2 channel tied to the hardware ID circuit.
// ----------------------------------------------------------------------------
uint32_t adc_hwid_GetADCValue(void);


#ifdef __cplusplus
} // end of - extern "C"
#endif

// end of file