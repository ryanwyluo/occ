/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/occ_405/pss/avsbus.h $                                    */
/*                                                                        */
/* OpenPOWER OnChipController Project                                     */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2015                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

#ifndef _AVSBUS_H
#define _AVSBUS_H

#include <errl.h>

extern bool G_avsbus_vdd_monitoring;
extern bool G_avsbus_vdn_monitoring;

#define AVSBUS_STATUS_OVER_CURRENT_MASK     0x4000
#define AVSBUS_STATUS_UNDER_VOLTAGE_MASK    0x2000
#define AVSBUS_STATUS_OVER_TEMPERATURE_MASK 0x1000
#define AVSBUS_STATUS_OVER_POWER_MASK       0x0800

typedef enum
{
    AVSBUS_VDD = 0x00,
    AVSBUS_VDN = 0x01,
} avsbus_type_e;

typedef enum
{
    // This enum contains the AVS Bus CmdDataType that can be read
    AVSBUS_VOLTAGE          = 0x00,
    AVSBUS_CURRENT          = 0x02,
    AVSBUS_STATUS           = 0x0E
} avsbus_cmdtype_e;

// Setup the AVS Bus for reading
void avsbus_init();

// Initiate AVS Bus read for specified cmdtype (Voltage / Current)
// (results can then be read on the next tick)
void initiate_avsbus_reads(avsbus_cmdtype_e i_cmdType);

// Process AVS Bus read results (or errors) for specified bus/cmdtype.
// Returns the data requested (voltage units are mV, current units are in 10mA)
// Predictive error will be logged after MAX_READ_ATTEMPTS failures on the specific
// bus/cmdtype and an OCC reset will be requested
uint16_t avsbus_read(const avsbus_type_e i_type,
                     const avsbus_cmdtype_e i_cmdtype);

// Initiate read of AVS Bus Status
// (results can then be read on the next tick)
void initiate_avsbus_read_status();

// Read the status from AVS Bus and return 1 if over-temperature was found for either bus
// or 0 if no OT was found.  0xFF will be returned if there was an error reading status
// on either bus.  Mfg error will be logged for the first OT or first OC condition.
// Error history counters will be incremented for any over-temp/over-current condition.
uint8_t process_avsbus_status();

#endif //_AVSBUS_H
