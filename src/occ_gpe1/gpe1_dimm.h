/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/occ_405/gpe/gpe1_dimm.h $                                 */
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

#ifndef _GPE1_DIMM_H
#define _GPE1_DIMM_H

#include "gpe_export.h"

#define PIB_BASE                                  0x000A0000
// Engine B 0x00A0000
// Engine C 0x00A1000
// Engine D 0x00A2000
// Engine E 0x00A3000
#define I2C_FIFO1_REG_READ          0x000A0004
#define I2C_COMMAND_REG             0x000A0005
#define I2C_MODE_REG                0x000A0006
#define I2C_INTERRUPT_MASK_REG      0x000A0008
#define I2C_STATUS_REG              0x000A000B // read
#define I2C_IMM_RESET_I2C           0x000A000B // write
#define I2C_BUSY_REGISTER           0x000A000E
#define I2C_FIFO4_REG_READ          0x000A0012

#define SCOM_ENGINE_OFFSET(engine) (engine << 12)

// I2C Status Register masks
#define STATUS_ERROR_MASK               0xFC80000000000000
#define STATUS_ERROR_OR_COMPLETE_MASK   0xFF80000000000000
#define STATUS_COMPLETE_MASK            0x0100000000000000
#define PEEK_ERROR_MASK                 0x00000000FC000000
#define PEEK_MORE_DATA                  0x0000000002000000


void dimm_set_ffdc(GpeErrorStruct *o_error, uint32_t i_addr, uint32_t i_rc, uint64_t i_ffdc);

void gpe_dimm_sm(ipc_msg_t* cmd, void* arg);


#endif //_GPE1_DIMM_H
