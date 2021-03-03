// ----------------------------------------------------------------------------
//! @file       common.h
//! @brief      Commonly used definitions.
//! @mnemonic   None
//! @copyright  (c) 2019 X Corporation, All Rights Reserved
// ----------------------------------------------------------------------------

// Define to prevent recursive inclusion
#ifndef __COMMON_H
#define __COMMON_H

#ifdef __cplusplus
// Declaration for linkage with C++ program.
extern "C"
{
#endif

//  ----------------------------------------------------------------------------
//  Includes
//  ----------------------------------------------------------------------------
// Compiler specific definitions
#include "compiler_defs.h"

//  STANDARD LIBRARIES
#include <stdint.h>

// STMicro Libraries
#ifdef STM32F072xB
    #include "stm32f0xx_hal.h"
#endif // end of - STM32F072xB

#ifdef STM32F205xx
    #include "stm32f2xx_hal.h"
#endif // end of - STM32F205xx

// STMicro Libraries
#ifdef STM32F334x8
    #include "stm32f3xx_hal.h"
#endif // end of - STM32F334x8

#ifdef STM32F405xx
    #include "stm32f4xx_hal.h"
#endif // end of - STM32F405xx

#ifdef STM32F767xx
    #include "stm32f7xx_hal.h"
#endif // end of - STM32F767xx

// Microchip Libraries
#ifdef dsPIC33FJ128GP310A
    #include <p33fxxxx.h>
#endif // end of - dsPIC33FJ128GP310A

//  X LIBRARIES
#if defined SYSTEM_SLC_CARD || defined SYSTEM_MAIN_CARD || SYSTEM_RDU_CARD
    #include "conditionals.h"
#endif
#include "system_fit.h"

// ----------------------------------------------------------------------------
// Defines
// ----------------------------------------------------------------------------

#define TERMINATION_32                          ((uint32_t)0xA5A5A5A5)
#define TERMINATION_16                          ((uint16_t)0xA5A5)
#define TERMINATION_8                           ((uint8_t)0xA5)
#define UNNEEDED_PARAMETER                      ((uint8_t)0u)

#define BIT_SET                                 1
#define BIT_CLEAR                               0

#define UINT8_BIT_MAX                           ((uint8_t)8)

#define UINT16_BIT_MAX                          ((uint8_t)16)

#define UINT32_BIT_MAX                          ((uint8_t)32)
#define ORING_FLAG_START                        0x00000001
#define CLEAR                                   0
#define QUANTITY_ONE                            1

#define SIZE_1K                                 ((uint32_t)1024)
#define SIZE_1M                                 ((uint32_t)(SIZE_1K * SIZE_1K))

#ifndef DEF_ON
    #define     DEF_ON                          ((uint8_t)1)
#endif
#define SIZE_OF_STRUCT_EL(s, e)                 (sizeof(((s*)0)->e))
#define SIZE_OF_STRUCT_EL_ARRAY(s, a)           (sizeof(((s*)0)->a[0]))
#define SIZE_OF_STRUCT_EL_ARRAY_EL(s, a, e)     (sizeof(((s*)0)->a[0].e))
#define SIZE_OF_UNION_EL(u, t, e)               (sizeof(((u*)0)->t.e))
#define SIZE_OF_UNION_TYPE(u, t)                (sizeof(((u*)0)->t))
#define SIZE_OF_ARRAY_EL(a)                     ((sizeof(a)) / (sizeof((a)[0])))
#define MAX(a,b)                                (((a) > (b)) ? (a) : (b))
#define MIN(a,b)                                (((a) < (b)) ? (a) : (b))

// Empty define to indicate a private function in the private header file
#define PRIVATE
#define RETURNABLE

// State values for state machine implementation.
#define STATE_0                                 ((uint8_t)0)
#define STATE_1                                 ((uint8_t)1)
#define STATE_2                                 ((uint8_t)2)
#define STATE_3                                 ((uint8_t)3)
#define STATE_4                                 ((uint8_t)4)
#define STATE_5                                 ((uint8_t)5)
#define STATE_6                                 ((uint8_t)6)
#define STATE_7                                 ((uint8_t)7)
#define STATE_8                                 ((uint8_t)8)
#define STATE_9                                 ((uint8_t)9)
#define STATE_10                                ((uint8_t)10)
#define STATE_11                                ((uint8_t)11)
#define STATE_12                                ((uint8_t)12)
#define STATE_13                                ((uint8_t)13)
#define STATE_14                                ((uint8_t)14)
#define STATE_15                                ((uint8_t)15)

// - LED / Switch Card Usage.
// UPPER Position. LED/Switches are per the schematic (physical layout).
// LOWER Position. Physical LED/Switches  1-10 (ADD + 10) to map to Virtual 11-20.
//                 Physical LED/Switches 11-20 (SUB - 10) to map to Virtual  1-10.
#define POSITION_UPPER              ((uint8_t)0)   // 0 - Upper   /  Connector on bottom.
#define POSITION_LOWER              ((uint8_t)1)   // 1 - Lower   /  Connector at top.
#define POSITION_TBD                ((uint8_t)2)   // 2 - To Be Determined

// Used with LED Operational states/values
#define IGNORE_LED_RATE_MASK                   ((uint8_t)0x0F)  // Keep Color Only
#define IGNORE_LED_COLOR_MASK                  ((uint8_t)0xF0)  // Keep Rate Only

// Type of checksum values used with configuration string and dataset CRC calculations.
typedef uint16_t tCRC;

typedef enum
{
    BLOCK_THIS_THREAD_ONLY = 1,
    BLOCK_ALL_THREADS
} teBLOCKING_MODE;

typedef enum
{
    START_AND_RETURN_IMMEDIATELY = 1,
    WAIT_FOR_COMPLETION
} teOPERATION_WAIT_MODE;


typedef enum
{
    eLOOP_DRVR_GROUP,
    eLOOP_DRVR_DEVICE_ECLIPS = 1,  // Eclipse Protocol device
    eLOOP_DRVR_DEVICE_AP     = 2,  // Advanced Protocol device
    eLOOP_DRVR_PSEUDO        = 3,  // Pseudo event
    eLOOP_DRVR_DEVICE_SLC    = 4,  // SLC generated event
    eLOOP_DRVR_DEVICE_TYPE_MAX = eLOOP_DRVR_DEVICE_SLC
}teLOOP_DRVR_DEVICE_TYPE;

typedef enum
{
    eEVENT_REPORTING_FORMAT_STANDARD,
    eEVENT_REPORTING_FORMAT_SLC,
    eEVENT_REPORTING_FORMAT_PSEUDO,
    eEVENT_REPORTING_FORMAT_VESDA
}teEVENT_REPORTING_FORMATS;

//
// FIT status return codes.
typedef enum
{
    teFIT_STATUS_GOOD,
    teFIT_STATUS_QUEUE_TIMEOUT,
    teFIT_STATUS_PEND_TIMEOUT = teFIT_STATUS_QUEUE_TIMEOUT,
    teFIT_STATUS_QUEUE_EMPTY = teFIT_STATUS_QUEUE_TIMEOUT,
    teFIT_STATUS_QUEUE_FULL,
    teFIT_STATUS_GENERAL_ERROR,
    teFIT_STATUS_BAD_HANDLE,
    teFIT_STATUS_BAD_MEMORY_POOL,
    teFIT_STATUS_BAD_TASK_CONFIG,
    teFIT_STATUS_BAD_TMR_CONFIG
}teFIT_STAT;

//
// FIT queue return codes.
typedef enum
{
    teFIT_DQ_WITHNOWAIT,
    teFIT_DQ_WITHWAIT,
    teFIT_DQ_WITHTIMEOUT
}teFIT_DQ_MECHANISM;

//
// General Pass/Fail values. Can be used for result of an execution.
typedef enum
{
    RESULT_FAIL = 0xAA,
    RESULT_PASS = 0x55,
}teRESULT;

// Command types.
typedef enum
{
    CMD_NONE,
    CMD_RESET = 1,
    CMD_ALARM_SILENCE,
    CMD_PANEL_SILENCE,
    CMD_DRILL,
    CMD_EVACUATE,
    CMD_PAGE_TO_EVAC,
    CMD_PAGE_TO_ALERT,
    CMD_PAGE_TO_MNS,
    CMD_MNS_SILENCE,
    CMD_MNS_RESET,
    CMD_MICROPHONE_KEYED,
}teCMD_TYPE;

typedef enum
{
    DISABLE_STATE_NATURAL,
    DISABLE_STATE_ACTIVE,
    DISABLE_STATE_QUIESCENT,
    DISABLE_STATE_MAX,
    DISABLE_STATE_SIZE = 0x0100
}teDISABLE_STATE_MODES;

// - LED / Switch Card Usage.
typedef enum
{
    teLED1,     //  0
    teLED2,     //  1
    teLED3,     //  2
    teLED4,     //  3
    teLED5,     //  4
    teLED6,     //  5
    teLED7,     //  6
    teLED8,     //  7
    teLED9,     //  8
    teLED10,    //  9
    teLED11,    // 10
    teLED12,    // 11
    teLED13,    // 12
    teLED14,    // 13
    teLED15,    // 14
    teLED16,    // 15
    teLED17,    // 16
    teLED18,    // 17
    teLED19,    // 18
    teLED20,    // 19
    teLEDMAX    // 20
}teLED;

// - LED States ON/OFF/Blink. Uses Upper Nibble of CAN message.
//   Corresponds to teEVENTS_OUTPUT_xxxxxxxx attribute types.
typedef enum
{
    teLED_STATE_OFF      = 0x00,     // 0 - OFF     formerly - teLED_STATE_QUIESCENT,
    teLED_STATE_STEADY   = 0x10,     // 1 - ON
    teLED_STATE_3_SEC    = 0x20,     // 2 - 3 Sec ON/OFF.     20 BPS
    teLED_STATE_1_SEC    = 0x30,     // 3 - 1 Sec ON/OFF.     60 BPS
    teLED_STATE_HALF_SEC = 0x40,     // 4 - 1/2 Sec ON/OFF.  120 BPS
    teLED_STATE_TEMPORAL = 0x50,     // 5 - Unused. TBD.     Ignore.
    teLED_STATE_SLOW     = 0x60,     // 6 - Unused. TBD.     Ignore.
    teLED_STATE_FAST     = 0x70,     // 7 - 1/4 Sec ON/OFF.  240 BPS
    teLED_STATE_IGNORE   = 0x80,     // 8 - Used by Card to  Ignore if this bit is set.
}  teLED_STATE;

// -  LED Color Options.  Uses Lower Nibble of CAN message.
typedef enum
{
    teLED_COLOR_NONE   = 0x00,       // 0
    teLED_COLOR_RED    = 0x01,       // 1
    teLED_COLOR_GREEN  = 0x02,       // 2
    teLED_COLOR_YELLOW = 0x03,       // 3
    teLED_COLOR_BLUE   = 0x04,       // 4
} teLED_COLOR_TYPES;


// ------------------------------------------------------------------------------
//  Type Definitions
// ------------------------------------------------------------------------------

// Time-stamp
typedef struct
{
   int16_t               Weekday;
   int16_t               DayLightSavingsIsInEffect;
   int16_t               Seconds;
   int16_t               Minutes;
   int16_t               Hours;
   int16_t               Day;
   int16_t               Month;
   int16_t               Year;
}tsEventProcTimeFormat;

// Loop device format.
typedef PACKED_ATTRIBUTE_IAR union
{
    struct
    {
        uint16_t Device:10;
        uint16_t AP_Module:1;
        uint16_t LoopID:3;
        uint16_t DeviceFormat:2;
    }sLOOP_DEVICE;

    struct
    {
        uint16_t Pipe:7;
        uint16_t Zone:7;
        uint16_t DeviceFormat:2;
    }sVESDA;

    struct
    {
        uint16_t Device:14;
        uint16_t DeviceFormat:2;
    }sPSEDUO;

    uint16_t Device;
}PACKED_ATTRIBUTE_MICROCHIP tuLoopDevice;

//
// Object TAG formats.
typedef PACKED_ATTRIBUTE_IAR union
{
    struct
    {
        uint8_t  Panel;
        uint8_t  Card;
        uint16_t Device;
    }sCMO;
    struct
    {
        uint8_t  Panel:8;
        uint8_t  Card:8;
        uint16_t Device:10;
        uint16_t AP_Module:1;
        uint16_t LoopID:3;
        uint16_t DeviceFormat:2;
    }sLOOP;
    struct
    {
        uint8_t  Panel:8;
        uint8_t  Card:8;
        uint16_t Pipe:7;
        uint16_t Zone:7;
        uint16_t DeviceFormat:2;
    }sVESDA;
    struct
    {
        uint8_t Primary;
        uint8_t Secondary;
        uint16_t SubType;
    }sCONF_NAME;
    struct
    {
        uint16_t MSW;
        uint16_t LSW;
    }sWORDS;
    struct
    {
        uint8_t Array[4];
    }sBYTES;
    uint32_t name;
}PACKED_ATTRIBUTE_MICROCHIP tuObjectTagName;

//
// Event vector format.
typedef PACKED_ATTRIBUTE_IAR union
{
    #define VECT_DIS_AUTO                       0x02
    #define VECT_DIS_MANU                       0x04
    #define VECT_MSGS_HIDDN                     0x08
    #define VECT_UNDER_TST                      0x10
    #define VECT_LOC_DISTRB                     0x20
    #define VECT_REDNDNT                        0x40

    struct
    {
        uint8_t Active:1;
        uint8_t DisableAuto:1;
        uint8_t DisableManual:1;
        uint8_t MessageHidden:1;
        uint8_t UnderTest:1;
        uint8_t LocalDistributionOnly:1;
        uint8_t Redundant:1;
        uint8_t Available:1;
    }usBITS;

    uint8_t     vect;
}PACKED_ATTRIBUTE_MICROCHIP tuVector;

//
// Event response deferment element format.
typedef PACKED_ATTRIBUTE_IAR union
{
    PACKED_ATTRIBUTE_IAR struct
    {
        uint16_t DependantIndex;
        uint32_t TotalTicks;
        uint16_t flag;
        uint16_t logic;
    }PACKED_ATTRIBUTE_MICROCHIP tsBlocked;

    PACKED_ATTRIBUTE_IAR struct
    {
        uint16_t ReloadValue;
        uint16_t ReloadTimes;
        uint16_t available_0;
        uint16_t available_1;
        uint16_t available_2;
    }PACKED_ATTRIBUTE_MICROCHIP sRecursive;
}PACKED_ATTRIBUTE_MICROCHIP tuBlocking;

typedef PACKED_ATTRIBUTE_IAR struct strctDefvdCont
{
    struct strctDefvdCont  *nextPtr;
    uint32_t                moment;
    uint8_t                 category;
    uint8_t                 profile;
    uint32_t                index;
    tuVector                vector;
    teEVENTS                eType;
    tuObjectTagName         Name;
    tuBlocking              blocking;
    void                   *GPPtr;
}PACKED_ATTRIBUTE_MICROCHIP tsDeferrableContent;

//
// External event format.
typedef PACKED_ATTRIBUTE_IAR struct
{
    uint16_t        cmd;
    tuVector        vector;
    uint8_t         eType;
    tuObjectTagName Name;
}PACKED_ATTRIBUTE_MICROCHIP tsExternalEvent;

// Structure for common activation commands - Reset, Silence, Acknowledge, Drill etc.
typedef PACKED_ATTRIBUTE_IAR struct tsCommand_struct
{
    teCMD_TYPE  cmdType;
}PACKED_ATTRIBUTE_MICROCHIP tsCommand;

typedef PACKED_ATTRIBUTE_IAR struct
{
    uint16_t Device;
    uint32_t StatusFlags;
}PACKED_ATTRIBUTE_MICROCHIP tsStatusObject;

typedef PACKED_ATTRIBUTE_IAR struct
{
    teEVENTS        Type;
    tuVector        Vector;
    tuObjectTagName Obj;
}PACKED_ATTRIBUTE_MICROCHIP tsEvent;

typedef PACKED_ATTRIBUTE_IAR struct
{
    tuVector        Vector;
    tuObjectTagName Obj;
}PACKED_ATTRIBUTE_MICROCHIP tsSwitch;

typedef PACKED_ATTRIBUTE_IAR struct
{
    uint16_t Device;
    uint16_t type   :3;
    uint16_t color  :5;
    uint16_t attrib :8;
}PACKED_ATTRIBUTE_MICROCHIP tsOutput;

typedef PACKED_ATTRIBUTE_IAR struct
{
    uint16_t Device;
    uint16_t OutputType     :3;
    uint16_t Color_Message  :5;
    uint16_t Attrib_AmpMode :8;
}PACKED_ATTRIBUTE_MICROCHIP tsOutputCommand;

typedef PACKED_ATTRIBUTE_IAR union
{
    PACKED_ATTRIBUTE_IAR struct
    {
        uint16_t Device;
        uint16_t PacketID;
        uint8_t Dest;
        uint8_t returnPanel;
        uint8_t returnCard;
        uint8_t returnQueue;
    }PACKED_ATTRIBUTE_MICROCHIP tsReconReq;

    PACKED_ATTRIBUTE_IAR struct
    {
        uint16_t Quan;
        tsOutput Output[1];
    }PACKED_ATTRIBUTE_MICROCHIP tsOutputCmds;

    PACKED_ATTRIBUTE_IAR struct
    {
        uint16_t Quan;
        tsOutputCommand Output[1];
    }PACKED_ATTRIBUTE_MICROCHIP tsNewOutputCmds;

    PACKED_ATTRIBUTE_IAR struct
    {
        uint16_t startingDevice;
        uint16_t PacketID;
        uint16_t Quan;
        tsStatusObject Obj[1];
    }PACKED_ATTRIBUTE_MICROCHIP tsActReport;

    PACKED_ATTRIBUTE_IAR struct
    {
        uint8_t returnPanel;
        uint8_t returnCard;
        uint8_t returnQueue;
    }PACKED_ATTRIBUTE_MICROCHIP tsVersionReportReq;

    PACKED_ATTRIBUTE_IAR struct
    {
        uint8_t cardType;
        uint8_t brandDiscrimination;
        uint32_t dataVersion;
        uint32_t hardwareVersion;
        uint32_t firmwareVersion;
        uint16_t testQuantity;
        uint16_t testData[1];
    }PACKED_ATTRIBUTE_MICROCHIP tsVersionReport;

    PACKED_ATTRIBUTE_IAR struct
    {
        uint16_t Quan;
        tsEvent  Event[1];
    }PACKED_ATTRIBUTE_MICROCHIP tsEventCmds;

    PACKED_ATTRIBUTE_IAR struct
    {
        uint16_t Quan;
        tsSwitch Switch[1];
    }PACKED_ATTRIBUTE_MICROCHIP tsSwitchCmds;

    PACKED_ATTRIBUTE_IAR struct
    {
        bool requestState;
    }PACKED_ATTRIBUTE_MICROCHIP tsControlRequest;

    PACKED_ATTRIBUTE_IAR struct
    {
        tuObjectTagName requester;
        bool state;
    }PACKED_ATTRIBUTE_MICROCHIP tsControlResponse;

    PACKED_ATTRIBUTE_IAR struct
    {
        uint16_t Action;
        teDISABLE_STATE_MODES DSM;         // Force Disable State Mode, 0=Natural, 1=Active, 2=Quiescent.
        tuObjectTagName Name;
    }PACKED_ATTRIBUTE_MICROCHIP tsDisableRequest;

    uint8_t payload[1];
}PACKED_ATTRIBUTE_MICROCHIP tuLocalCommDefinitions;

// Point of control structure
// Used by panel network, peripheral communications, and display.
#define POC_ADDRESS_IGNORE          ((uint8_t)0xFF)
#define POC_ALL_ADDRESSES_IGNORE    ((uint32_t)0xFFFFFFFF)
typedef PACKED_ATTRIBUTE_IAR union
{
    PACKED_ATTRIBUTE_IAR struct
    {
        uint8_t         inControlPanel;
        uint8_t         inControlCard;
        uint8_t         requestingPanel;
        uint8_t         requestingCard;
    }PACKED_ATTRIBUTE_MICROCHIP  byte;
    uint32_t word;
}PACKED_ATTRIBUTE_MICROCHIP tuControlAddress;

typedef PACKED_ATTRIBUTE_IAR struct
{
    tuControlAddress    address;
    teDEVICE_TYPE       inControlCardType;
    teDEVICE_TYPE       requestingCardType;
}PACKED_ATTRIBUTE_MICROCHIP tsControlData;

// Definitions for projects not utilizing nds_dataset_interface.h
// @todo -  The following definitions exist in nds_dataset_interface.h for the projects that have that file.
//          Make these definitions common for all projects so that we don't have to maintain multiple copies of the same thing.
#if defined SYSTEM_FLEX_CARD || defined SYSTEM_DPM_CARD || defined SYSTEM_LOC_CARD || defined SYSTEM_AMPLIFIER_CARD || defined SYSTEM_MIM_CARD || defined SYSTEM_RDU_CARD

typedef enum
{
    teSTATUS_FLG_NONE,
    teSTATUS_FLG0                             = ((uint32_t)0x00000001),
    teSTATUS_FLG1                             = ((uint32_t)0x00000002),
    teSTATUS_FLG2                             = ((uint32_t)0x00000004),
    teSTATUS_FLG3                             = ((uint32_t)0x00000008),
    teSTATUS_FLG4                             = ((uint32_t)0x00000010),
    teSTATUS_FLG5                             = ((uint32_t)0x00000020),
    teSTATUS_FLG6                             = ((uint32_t)0x00000040),
    teSTATUS_FLG7                             = ((uint32_t)0x00000080),
    teSTATUS_FLG8                             = ((uint32_t)0x00000100),
    teSTATUS_FLG9                             = ((uint32_t)0x00000200),
    teSTATUS_FLG10                            = ((uint32_t)0x00000400),
    teSTATUS_FLG11                            = ((uint32_t)0x00000800),
    teSTATUS_FLG12                            = ((uint32_t)0x00001000),
    teSTATUS_FLG13                            = ((uint32_t)0x00002000),
    teSTATUS_FLG14                            = ((uint32_t)0x00004000),
    teSTATUS_FLG15                            = ((uint32_t)0x00008000),
    teSTATUS_FLG16                            = ((uint32_t)0x00010000),
    teSTATUS_FLG17                            = ((uint32_t)0x00020000),
    teSTATUS_FLG18                            = ((uint32_t)0x00040000),
    teSTATUS_FLG19                            = ((uint32_t)0x00080000),
    teSTATUS_FLG20                            = ((uint32_t)0x00100000),
    teSTATUS_FLG21                            = ((uint32_t)0x00200000),
    teSTATUS_FLG22                            = ((uint32_t)0x00400000),
    teSTATUS_FLG23                            = ((uint32_t)0x00800000),
    teSTATUS_FLG24                            = ((uint32_t)0x01000000),
    teSTATUS_FLG25                            = ((uint32_t)0x02000000),
    teSTATUS_FLG26                            = ((uint32_t)0x04000000),
    teSTATUS_FLG27                            = ((uint32_t)0x08000000),
    teSTATUS_FLG28                            = ((uint32_t)0x10000000),
    teSTATUS_FLG29                            = ((uint32_t)0x20000000),
    teSTATUS_FLG30                            = ((uint32_t)0x40000000),
    teSTATUS_FLG31                            = ((uint32_t)0x80000000),
    teMAX_STATUS_FLG
}teSTATUS_BITS;

typedef enum
{  // Fire, Trouble,...
    teSYS_STATUS_NONE                         = ((uint8_t)0x00),
    teSYS_STATUS_OUTPUT,
    teSYS_STATUS_FIRE,
    teSYS_STATUS_RELEASING,
    teSYS_STATUS_TROUBLES,
    teSYS_STATUS_SUPERVISORY,
    teSYS_STATUS_MONITORS,
    teSYS_STATUS_DISABLES_A,
    teSYS_STATUS_DISABLES_M,
    teSYS_STATUS_VERIFICATIONS,
    teSYS_STATUS_PRERELEASES,
    teSYS_STATUS_SPRINKLER_SUPERVISORY,
    teSYS_STATUS_MAX
}teSYSTEM_STATUS_GROUPS;

typedef PACKED_ATTRIBUTE_IAR struct
{
    teSTATUS_BITS               flag;
    teSYSTEM_STATUS_GROUPS      sysStat;
    bool                        latched;
}PACKED_ATTRIBUTE_MICROCHIP tsProfileElements;

typedef PACKED_ATTRIBUTE_IAR struct
{
#define STATUS_WIDTH            ((uint16_t)31)
    tsProfileElements           LookUp[teEVENTS_MAX_EVENTS];
    teEVENTS                    Events[(STATUS_WIDTH + 1)];
}PACKED_ATTRIBUTE_MICROCHIP tsProfileDirectory;

typedef PACKED_ATTRIBUTE_IAR struct
{
    uint8_t                     QofProfiles;
    uint8_t                     StatusWidth;
    uint16_t                    QofEvents;
    tsProfileDirectory          ProfilesHook[QUANTITY_OF_PROFILES];
}PACKED_ATTRIBUTE_MICROCHIP tsProfileTable;

#endif // end of - Definitions for projects not utilizing an RTOS.

#ifdef __cplusplus
} // end of - extern "C"
#endif

#endif // __COMMON_H
// -------------
// End of file
// -------------
