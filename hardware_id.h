// -----------------------------------------------------------------------------
//! @file       hardware_ID.h
//! @brief      Public definitions for reading the hardware ID value.
//! @mnemonic   hwid
// -----------------------------------------------------------------------------
#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

// -----------------------------------------------------------------------------
// Includes
// -----------------------------------------------------------------------------
#include "common.h"

// -----------------------------------------------------------------------------
// Public Definitions and Types
// -----------------------------------------------------------------------------

// Hardware ID resistor:
//
//  3.3V
//   |
//   \
//   /  hardware ID resistor (1%)
//   \
//   |
//   |---- microcontroller ADC input (12-bit)
//   |
//   \
//   /  10kohm resistor (1%)
//   \
//   |
//  GND
//
// Use measured ADC value as index into hwid_MapADCToIDValue[]
// to return the revision value.
// Revision values are between 0 and 27,
// and a returned value of 255 indicates an invalid ADC value.

// Use this chart to choose a hardware ID resistor value
// that represents the desired revision.
//
// low ADC      high ADC    target ADC      ID resistor     revision        alternate
// (counts)     (counts)    (counts)        (ohms)          value           value
// ---------------------------------------------------------------------------------------------------------
// 3792         4095                                        invalid         invalid
// 3606         3791        3663            1.18k           0               0   // only for prototype builds
// 3486         3605        3549            1.54k           1               N/C
// 3359         3485        3424            1.96k           2               A
// 3230         3358        3295            2.43k           3               B
// 3101         3229        3165            2.94k           4               C
// 2979         3100        3038            3.48k           5               D
// 2859         2978        2921            4.02k           6               E
// 2731         2858        2797            4.64k           7               F
// 2609         2730        2666            5.36k           8               G
// 2482         2608        2553            6.04k           9               H
// 2352         2481        2412            6.98k           10              J
// 2231         2351        2292            7.87k           11              K
// 2109         2230        2170            8.87k           12              L
// 1985         2108        2048            10k             13              M
// 1863         1984        1923            11.3k           14              N
// 1744         1862        1804            12.7k           15              P
// 1624         1743        1685            14.3k           16              R
// 1495         1623        1563            16.2k           17              S
// 1364         1494        1427            18.7k           18              T
// 1236         1363        1300            21.5k           19              U
// 1115         1235        1173            24.9k           20              V
// 994          1114        1058            28.7k           21              W
// 872          993         930             34k             22              X
// 749          871         815             40.2k           23              Y
// 626          748         683             49.9k           24              Z
// 505          625         569             61.9k           25              AA
// 377          504         442             82.5k           26              AB
// 156          376         312             121k            27              AC
// 0            155                                         invalid         invalid
// ---------------------------------------------------------------------------------------------------------


// ----------------------------------------------------------------------------
// Public Function Prototypes
// ----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
//! @brief  Clear, read and store value of hardware ID ADC input
//!         and calculate value of hardware ID.
//! @param  void
//! @return void
// -----------------------------------------------------------------------------
void hwid_Init(void);

// -----------------------------------------------------------------------------
//! @brief  Read and store value of hardware ID ADC input.
//! @param  void
//! @return void
// -----------------------------------------------------------------------------
void hwid_ReadADCValue(void);

// -----------------------------------------------------------------------------
//! @brief  Calculate hardware ID value and store locally.
//! @param  uint16_t ADC value to convert.
//! @return uint8_t calculated hardware ID value.
// -----------------------------------------------------------------------------
uint8_t hwid_CalculateHardwareIDValue(uint16_t hwid_ADC_value);

// -----------------------------------------------------------------------------
//! @brief  Return locally-stored ADC value of hardware ID.
//! @param  void
//! @return uint32_t hardware ID ADC value.
// -----------------------------------------------------------------------------
uint16_t hwid_GetHardwareIDADCValue(void);

// -----------------------------------------------------------------------------
//! @brief  Return locally-stored value of hardware ID.
//! @param  void
//! @return uint8_t hardware ID value.
// -----------------------------------------------------------------------------
uint8_t hwid_GetHardwareIDValue(void);

#ifdef __cplusplus
}
#endif

// end file
