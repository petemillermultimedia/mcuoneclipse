/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : MMA1.h
**     CDE edition : Standard
**     Project     : tinyK22_SGP30
**     Processor   : MK22FN512VLH12
**     Component   : MMA8451Q
**     Version     : Component 01.046, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2018-10-02, 07:40, # CodeGen: 22
**     Abstract    :
**         Implements a Driver for the MMA8451 accelerometer from NXP/Freescale.
**     Settings    :
**          Component Name                                 : MMA1
**          Slave Address                                  : 1D
**          I2C Bus                                        : GI2C1
**          Constant Offsets                               : Enabled
**            X offset                                     : 0
**            Y offset                                     : 0
**            Z offset                                     : 0
**          Shell                                          : Enabled
**            Shell                                        : CLS1
**            Utility                                      : UTIL1
**     Contents    :
**         Enable         - uint8_t MMA1_Enable(void);
**         Disable        - uint8_t MMA1_Disable(void);
**         isEnabled      - uint8_t MMA1_isEnabled(bool *isEnabled);
**         SwReset        - uint8_t MMA1_SwReset(void);
**         ReadReg8       - uint8_t MMA1_ReadReg8(uint8_t addr, uint8_t *val);
**         WriteReg8      - uint8_t MMA1_WriteReg8(uint8_t addr, uint8_t val);
**         GetX           - int16_t MMA1_GetX(void);
**         GetY           - int16_t MMA1_GetY(void);
**         GetZ           - int16_t MMA1_GetZ(void);
**         GetRaw8XYZ     - uint8_t MMA1_GetRaw8XYZ(uint8_t *xyz);
**         CalibrateX1g   - void MMA1_CalibrateX1g(void);
**         CalibrateY1g   - void MMA1_CalibrateY1g(void);
**         CalibrateZ1g   - void MMA1_CalibrateZ1g(void);
**         GetXmg         - int16_t MMA1_GetXmg(void);
**         GetYmg         - int16_t MMA1_GetYmg(void);
**         GetZmg         - int16_t MMA1_GetZmg(void);
**         MeasureGetRawX - uint16_t MMA1_MeasureGetRawX(void);
**         MeasureGetRawY - uint16_t MMA1_MeasureGetRawY(void);
**         MeasureGetRawZ - uint16_t MMA1_MeasureGetRawZ(void);
**         GetXOffset     - int16_t MMA1_GetXOffset(void);
**         GetYOffset     - int16_t MMA1_GetYOffset(void);
**         GetZOffset     - int16_t MMA1_GetZOffset(void);
**         GetX1gValue    - int16_t MMA1_GetX1gValue(void);
**         GetY1gValue    - int16_t MMA1_GetY1gValue(void);
**         GetZ1gValue    - int16_t MMA1_GetZ1gValue(void);
**         SetFastMode    - uint8_t MMA1_SetFastMode(bool on);
**         WhoAmI         - uint8_t MMA1_WhoAmI(uint8_t *value);
**         GetScaleRangeG - uint8_t MMA1_GetScaleRangeG(uint8_t *gScale);
**         SetScaleRangeG - uint8_t MMA1_SetScaleRangeG(uint8_t gScale);
**         ParseCommand   - uint8_t MMA1_ParseCommand(const unsigned char *cmd, bool *handled, const...
**         Deinit         - uint8_t MMA1_Deinit(void);
**         Init           - uint8_t MMA1_Init(void);
**
** * Copyright (c) 2013-2018, Erich Styger
**  * Web:         https://mcuoneclipse.com
**  * SourceForge: https://sourceforge.net/projects/mcuoneclipse
**  * Git:         https://github.com/ErichStyger/McuOnEclipse_PEx
**  * All rights reserved.
**  *
**  * Redistribution and use in source and binary forms, with or without modification,
**  * are permitted provided that the following conditions are met:
**  *
**  * - Redistributions of source code must retain the above copyright notice, this list
**  *   of conditions and the following disclaimer.
**  *
**  * - Redistributions in binary form must reproduce the above copyright notice, this
**  *   list of conditions and the following disclaimer in the documentation and/or
**  *   other materials provided with the distribution.
**  *
**  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**  * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
** ###################################################################*/
/*!
** @file MMA1.h
** @version 01.00
** @brief
**         Implements a Driver for the MMA8451 accelerometer from NXP/Freescale.
*/         
/*!
**  @addtogroup MMA1_module MMA1 module documentation
**  @{
*/         

#ifndef __MMA1_H
#define __MMA1_H

/* MODULE MMA1. */
#include "MCUC1.h" /* SDK and API used */
#include "MMA1config.h" /* configuration */

/* Include inherited components */
#include "GI2C1.h"
#include "WAIT1.h"
#include "MCUC1.h"
#include "CLS1.h"
#include "UTIL1.h"

#define MMA1_PARSE_COMMAND_ENABLED  1  /* set to 1 if method ParseCommand() is present, 0 otherwise */

/* 3-axis accelerometer control register addresses */
#define MMA1_CTRL_REG_1 0x2A
/* 3-axis accelerometer control register bit masks */
#define MMA1_ACTIVE_BIT_MASK 0x01
#define MMA1_F_READ_BIT_MASK 0x02

#define MMA1_CTRL_REG_2 0x2B
#define MMA1_CTRL_REG_2_MASK_RST (1<<4) /* software reset */

/* External 3-axis accelerometer data register addresses */
#define MMA1_OUT_X_MSB 0x01
#define MMA1_OUT_X_LSB 0x02
#define MMA1_OUT_Y_MSB 0x03
#define MMA1_OUT_Y_LSB 0x04
#define MMA1_OUT_Z_MSB 0x05
#define MMA1_OUT_Z_LSB 0x06

#define MMA1_WHO_AM_I  0x0D    /* Who am I register, should return 0xC4 for preproduction devices and 0xC7 for production devices */
#define MMA1_WHO_AM_I_VAL 0x1A /* production device value */

#define MMA1_XYZ_DATA_CFG 0x0E  /* XYZ Data Configuration Register */

#define MMA1_I2C_ADDR   (0x1D) /* I2C slave device address as set in the properties */


uint8_t MMA1_GetRaw8XYZ(uint8_t *xyz);
/*
** ===================================================================
**     Method      :  GetRaw8XYZ (component MMA8451Q)
**
**     Description :
**         Returns in an array the x, y and z accelerometer as 8bit
**         values.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * xyz             - Pointer to an array of three unsigned 8bit
**                           values which are used to return the
**                           accelerometer values.
**     Returns     :
**         ---             - Error code, ERR_OK for no error.
** ===================================================================
*/

uint8_t MMA1_Deinit(void);
/*
** ===================================================================
**     Method      :  Deinit (component MMA8451Q)
**
**     Description :
**         Counterpart to Init() method.
**     Parameters  : None
**     Returns     :
**         ---             - Error code, ERR_OK if everything is ok.
** ===================================================================
*/

uint8_t MMA1_Init(void);
/*
** ===================================================================
**     Method      :  Init (component MMA8451Q)
**
**     Description :
**         Initializes the device driver
**     Parameters  : None
**     Returns     :
**         ---             - Error code, ERR_OK if everything is ok.
** ===================================================================
*/

void MMA1_CalibrateX1g(void);
/*
** ===================================================================
**     Method      :  CalibrateX1g (component MMA8451Q)
**
**     Description :
**         Performs a calibration of the sensor. It is assumed that the
**         Y and Z sensors have 0 g, and the X sensor has 1 g.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void MMA1_CalibrateY1g(void);
/*
** ===================================================================
**     Method      :  CalibrateY1g (component MMA8451Q)
**
**     Description :
**         Performs a calibration of the sensor. It is assumed that the
**         X and Z sensors have 0 g, and the Y sensor has 1 g.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void MMA1_CalibrateZ1g(void);
/*
** ===================================================================
**     Method      :  CalibrateZ1g (component MMA8451Q)
**
**     Description :
**         Performs a calibration of the sensor. It is assumed that the
**         X and Y sensors have 0 g, and the Z sensor has 1 g.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

int16_t MMA1_GetXmg(void);
/*
** ===================================================================
**     Method      :  GetXmg (component MMA8451Q)
**
**     Description :
**         Returns the X value in mg
**     Parameters  : None
**     Returns     :
**         ---             - The g value in 1/1000g units
** ===================================================================
*/

int16_t MMA1_GetYmg(void);
/*
** ===================================================================
**     Method      :  GetYmg (component MMA8451Q)
**
**     Description :
**         Returns the Y value in mg
**     Parameters  : None
**     Returns     :
**         ---             - The g value in 1/1000g units
** ===================================================================
*/

int16_t MMA1_GetZmg(void);
/*
** ===================================================================
**     Method      :  GetZmg (component MMA8451Q)
**
**     Description :
**         Returns the Z value in mg
**     Parameters  : None
**     Returns     :
**         ---             - The g value in 1/1000g units
** ===================================================================
*/

uint16_t MMA1_MeasureGetRawX(void);
/*
** ===================================================================
**     Method      :  MeasureGetRawX (component MMA8451Q)
**
**     Description :
**         Performs a measurement on X channel and returns the raw
**         value.
**     Parameters  : None
**     Returns     :
**         ---             - X sensor value
** ===================================================================
*/

uint16_t MMA1_MeasureGetRawY(void);
/*
** ===================================================================
**     Method      :  MeasureGetRawY (component MMA8451Q)
**
**     Description :
**         Performs a measurement on Y channel and returns the raw
**         value.
**     Parameters  : None
**     Returns     :
**         ---             - Y sensor value
** ===================================================================
*/

uint16_t MMA1_MeasureGetRawZ(void);
/*
** ===================================================================
**     Method      :  MeasureGetRawZ (component MMA8451Q)
**
**     Description :
**         Performs a measurement on Z channel and returns the raw
**         value.
**     Parameters  : None
**     Returns     :
**         ---             - Z sensor value
** ===================================================================
*/

int16_t MMA1_GetXOffset(void);
/*
** ===================================================================
**     Method      :  GetXOffset (component MMA8451Q)
**
**     Description :
**         Returns the offset applied to the X value.
**     Parameters  : None
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

int16_t MMA1_GetYOffset(void);
/*
** ===================================================================
**     Method      :  GetYOffset (component MMA8451Q)
**
**     Description :
**         Returns the offset applied to the Y value.
**     Parameters  : None
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

int16_t MMA1_GetZOffset(void);
/*
** ===================================================================
**     Method      :  GetZOffset (component MMA8451Q)
**
**     Description :
**         Returns the offset applied to the Z value.
**     Parameters  : None
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

int16_t MMA1_GetX1gValue(void);
/*
** ===================================================================
**     Method      :  GetX1gValue (component MMA8451Q)
**
**     Description :
**         Returns the value for 1g for channel  X.
**     Parameters  : None
**     Returns     :
**         ---             - 1g value for X
** ===================================================================
*/

int16_t MMA1_GetY1gValue(void);
/*
** ===================================================================
**     Method      :  GetY1gValue (component MMA8451Q)
**
**     Description :
**         Returns the value for 1g for channel  Y.
**     Parameters  : None
**     Returns     :
**         ---             - 1g value for Y
** ===================================================================
*/

int16_t MMA1_GetZ1gValue(void);
/*
** ===================================================================
**     Method      :  GetZ1gValue (component MMA8451Q)
**
**     Description :
**         Returns the value for 1g for channel  Z.
**     Parameters  : None
**     Returns     :
**         ---             - 1g value for Z
** ===================================================================
*/

int16_t MMA1_GetX(void);
/*
** ===================================================================
**     Method      :  GetX (component MMA8451Q)
**
**     Description :
**         Retrieves the value for the X axis. The value is adjusted
**         with the zero calibration value (0 for 0 g, negative for
**         negative acceleration and positive for positive acceleration).
**     Parameters  : None
**     Returns     :
**         ---             - Measured X value
** ===================================================================
*/

int16_t MMA1_GetY(void);
/*
** ===================================================================
**     Method      :  GetY (component MMA8451Q)
**
**     Description :
**         Retrieves the value for the Y axis. The value is adjusted
**         with the zero calibration value (0 for 0 g, negative for
**         negative acceleration and positive for positive acceleration).
**     Parameters  : None
**     Returns     :
**         ---             - Measured Y value
** ===================================================================
*/

int16_t MMA1_GetZ(void);
/*
** ===================================================================
**     Method      :  GetZ (component MMA8451Q)
**
**     Description :
**         Retrieves the value for the Z axis. The value is adjusted
**         with the zero calibration value (0 for 0 g, negative for
**         negative acceleration and positive for positive acceleration).
**     Parameters  : None
**     Returns     :
**         ---             - Measured Z value
** ===================================================================
*/

uint8_t MMA1_ParseCommand(const unsigned char *cmd, bool *handled, const CLS1_StdIOType *io);
/*
** ===================================================================
**     Method      :  ParseCommand (component MMA8451Q)
**
**     Description :
**         Shell Command Line parser. This method is enabled/disabled
**         depending on if you have the Shell enabled/disabled in the
**         properties.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * cmd             - Pointer to command string
**       * handled         - Pointer to variable which tells if
**                           the command has been handled or not
**       * io              - Pointer to I/O structure
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t MMA1_SetFastMode(bool on);
/*
** ===================================================================
**     Method      :  SetFastMode (component MMA8451Q)
**
**     Description :
**         Turns the F_READ (Fast Read Mode) on or off
**     Parameters  :
**         NAME            - DESCRIPTION
**         on              - if to turn the F_READ mode on or off
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t MMA1_Enable(void);
/*
** ===================================================================
**     Method      :  Enable (component MMA8451Q)
**
**     Description :
**         Enables the device with setting the ACTIVE bit in the CTRL
**         register 1
**     Parameters  : None
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t MMA1_Disable(void);
/*
** ===================================================================
**     Method      :  Disable (component MMA8451Q)
**
**     Description :
**         Disables the device with clearing the ACTIVE bit in the CTRL
**         register 1
**     Parameters  : None
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t MMA1_isEnabled(bool *isEnabled);
/*
** ===================================================================
**     Method      :  isEnabled (component MMA8451Q)
**
**     Description :
**         Returns the status of the the ACTIVE bit in the CTRL
**         register 1
**     Parameters  :
**         NAME            - DESCRIPTION
**       * isEnabled       - Pointer to where to store the
**                           result, TRUE if ACTIVE bit is set, FALSE
**                           otherwise
**     Returns     :
**         ---             - error code
** ===================================================================
*/

uint8_t MMA1_WhoAmI(uint8_t *value);
/*
** ===================================================================
**     Method      :  WhoAmI (component MMA8451Q)
**
**     Description :
**         Returns the value of the WHO_AM_I (0x0D) register
**     Parameters  :
**         NAME            - DESCRIPTION
**       * value           - Pointer to value to store
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t MMA1_ReadReg8(uint8_t addr, uint8_t *val);
/*
** ===================================================================
**     Method      :  ReadReg8 (component MMA8451Q)
**
**     Description :
**         Reads an 8bit device register
**     Parameters  :
**         NAME            - DESCRIPTION
**         addr            - device memory map address
**       * val             - Pointer to value
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t MMA1_WriteReg8(uint8_t addr, uint8_t val);
/*
** ===================================================================
**     Method      :  WriteReg8 (component MMA8451Q)
**
**     Description :
**         Write an 8bit device register
**     Parameters  :
**         NAME            - DESCRIPTION
**         addr            - device memory map address
**         val             - value to write
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t MMA1_SwReset(void);
/*
** ===================================================================
**     Method      :  SwReset (component MMA8451Q)
**
**     Description :
**         Perform a software reset using the rst bit in the CTRL
**         register 2
**     Parameters  : None
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t MMA1_GetScaleRangeG(uint8_t *gScale);
/*
** ===================================================================
**     Method      :  GetScaleRangeG (component MMA8451Q)
**
**     Description :
**         Returns the selected Full Scale Range from the XYZ_Data_CFG
**         Register
**     Parameters  :
**         NAME            - DESCRIPTION
**       * gScale          - Pointer to where to store the
**                           desired full scale g value (returns 2, 4 or
**                           8)
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t MMA1_SetScaleRangeG(uint8_t gScale);
/*
** ===================================================================
**     Method      :  SetScaleRangeG (component MMA8451Q)
**
**     Description :
**         Sets the desired full scale range G value (2, 4 or 6) using
**         the XYZ_DATA_CFG register. Note that the device has to be
**         disabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**         gScale          - desired g value, has to be 2, 4 or 8
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

/* END MMA1. */

#endif
/* ifndef __MMA1_H */
/*!
** @}
*/
