// ----------------------------------------------------------------------------
//! @file       adc.c
//! @brief      This file contains functions to configure and operate ADC.
//! @mnemonic   adc
//! @copyright  Copyright (c) 2017 X Corporation, All Rights Reserved
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------------
#include "adc.h"
#include "main.h"
#include "gpio.h"

// ----------------------------------------------------------------------------
// Private Global Variables
// ----------------------------------------------------------------------------

// Structures to configure ADC
static ADC_HandleTypeDef    adc1Handle;
static ADC_HandleTypeDef    adc2Handle;

// ----------------------------------------------------------------------------
// Functions
// ----------------------------------------------------------------------------

void adc_Init(void)
{
    // List all ADC init functions here.
    adc_gf_Init();
    adc_hwid_Init();
} // end adc_Init()

void adc_StopADC(void)
{
    // List all ADC stop functions here.
    adc_gf_StopADC();
    adc_hwid_StopADC();
} // end adc_StopADC()

void adc_gf_Init(void)
{
    ADC_ChannelConfTypeDef channelConfig;

    // Configure the global features of ADC1 -
    // Clock, Resolution, Data Alignment and number of conversions etc.
    adc1Handle.Instance                         = ADC1;
    adc1Handle.Init.ClockPrescaler              = ADC_CLOCK_SYNC_PCLK_DIV4;
    adc1Handle.Init.Resolution                  = ADC_RESOLUTION_12B;
    adc1Handle.Init.ScanConvMode                = DISABLE;
    adc1Handle.Init.ContinuousConvMode          = DISABLE;
    adc1Handle.Init.DiscontinuousConvMode       = DISABLE;
    adc1Handle.Init.ExternalTrigConvEdge        = ADC_EXTERNALTRIGCONVEDGE_NONE;
    adc1Handle.Init.ExternalTrigConv            = ADC_SOFTWARE_START;
    adc1Handle.Init.DataAlign                   = ADC_DATAALIGN_RIGHT;
    adc1Handle.Init.NbrOfConversion             = 1;
    adc1Handle.Init.DMAContinuousRequests       = DISABLE;
    adc1Handle.Init.EOCSelection                = ADC_EOC_SINGLE_CONV;

    if(HAL_OK != HAL_ADC_Init(&adc1Handle))
    {
        Error_Handler();
    }

    // Configure the rank and sample time for ADC1 channel 8
    channelConfig.Channel           = ADC_CHANNEL_8;
    channelConfig.Rank              = ADC_REGULAR_RANK_1;
    channelConfig.SamplingTime      = ADC_SAMPLETIME_480CYCLES;

    if(HAL_OK != HAL_ADC_ConfigChannel(&adc1Handle, &channelConfig))
    {
        Error_Handler();
    }

} // end adc_gf_Init()

void adc_gf_StartADCforOneValue(void)
{
    HAL_ADC_Start(&adc1Handle);
} // end adc_gf_StartADCforOneValue()

void adc_gf_StopADC(void)
{
    HAL_ADC_Stop(&adc1Handle);
} // end adc_gf_StopADC()

uint32_t adc_gf_GetADCValue(void)
{
    return HAL_ADC_GetValue(&adc1Handle);
} // end adc_gf_GetADCValue()

void adc_hwid_Init(void)
{
    ADC_ChannelConfTypeDef channelConfig;

    // ADC1 Clock Enable
    __HAL_RCC_ADC2_CLK_ENABLE();

    // Configure GPIO signals as ADC inputs
    gpio_Hardware_ID_Signal_Init();

    // Configure the global features of ADC2 -
    // Clock, Resolution, Data Alignment and number of conversions etc.
    adc2Handle.Instance                   = ADC2;
    adc2Handle.Init.ClockPrescaler        = ADC_CLOCK_SYNC_PCLK_DIV8;
    adc2Handle.Init.Resolution            = ADC_RESOLUTION_12B;
    adc2Handle.Init.ScanConvMode          = DISABLE;
    adc2Handle.Init.ContinuousConvMode    = DISABLE;
    adc2Handle.Init.DiscontinuousConvMode = DISABLE;
    adc2Handle.Init.NbrOfDiscConversion   = 0;
    adc2Handle.Init.ExternalTrigConvEdge  = ADC_EXTERNALTRIGCONVEDGE_NONE;
    adc2Handle.Init.ExternalTrigConv      = ADC_SOFTWARE_START;
    adc2Handle.Init.DataAlign             = ADC_DATAALIGN_RIGHT;
    adc2Handle.Init.NbrOfConversion       = ((uint32_t)1);
    adc2Handle.Init.DMAContinuousRequests = DISABLE;
    adc2Handle.Init.EOCSelection          = DISABLE;

    if(HAL_OK != HAL_ADC_Init(&adc2Handle))
    {
        Error_Handler();
    }

    // Configure the rank and sample time for ADC2 channel/s.
    channelConfig.Channel      = ADC_CHANNEL_13;
    channelConfig.Rank         = ADC_REGULAR_RANK_1;
    channelConfig.SamplingTime = ADC_SAMPLETIME_480CYCLES;

    if(HAL_OK != HAL_ADC_ConfigChannel(&adc2Handle, &channelConfig))
    {
        Error_Handler();
    }
} // end adc_hwid_Init()

void adc_hwid_StartADCforOneValue(void)
{
    if(HAL_OK != HAL_ADC_Start(&adc2Handle))
    {
        Error_Handler();
    }
} // end adc_hwid_StartADCforOneValue()

void adc_hwid_StopADC(void)
{
    HAL_ADC_Stop(&adc2Handle);
} // end adc_hwid_StopADC()

uint32_t adc_hwid_GetADCValue(void)
{
    uint32_t adcVal = 0;

    // Note - this happens only once during power-up so it does not need to be re-entrant.
    HAL_ADC_PollForConversion(&adc2Handle, ADC2_CONVERSION_DELAY_TIME);

    // Is ADC conversion complete?
    if(HAL_ADC_STATE_EOC_REG == (HAL_ADC_GetState(&adc2Handle) & HAL_ADC_STATE_EOC_REG))
    {
        adcVal = HAL_ADC_GetValue(&adc2Handle);
    }

    return adcVal;
} // end adc_hwid_GetADCValue()

// end of file