/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: send_params.c
 *
 * Code generated for Simulink model 'Final_Simulink_Model_assignment_2'.
 *
 * Model version                  : 2.134
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Sun Nov 27 20:58:58 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Final_Simulink_Model_assignment_2_types.h"
#include "send_params_private.h"
#include "Final_Simulink_Model_assignment_2.h"
#include "send_params.h"
#include <string.h>
#include "rtwtypes.h"
#include <stddef.h>

/* Forward declaration for local functions */
static void Final_Simulink_SystemCore_setup(freedomk64f_SCIWrite_Final_Si_T *obj);
static void Final_Simulink_SystemCore_setup(freedomk64f_SCIWrite_Final_Si_T *obj)
{
  MW_SCI_Parity_Type ParityValue;
  MW_SCI_StopBits_Type StopBitsValue;
  uint32_T RxPinLoc;
  uint32_T SCIModuleLoc;
  obj->isInitialized = 1;
  RxPinLoc = MW_UNDEFINED_VALUE;
  SCIModuleLoc = 0;
  obj->MW_SCIHANDLE = MW_SCI_Open(&SCIModuleLoc, false, RxPinLoc, 10U);
  MW_SCI_SetBaudrate(obj->MW_SCIHANDLE, 115200U);
  StopBitsValue = MW_SCI_STOPBITS_1;
  ParityValue = MW_SCI_PARITY_NONE;
  MW_SCI_SetFrameFormat(obj->MW_SCIHANDLE, 8, ParityValue, StopBitsValue);
  obj->isSetupComplete = true;
}

/* System initialize for Simulink Function: '<Root>/send_params()1' */
void send_params_Init(void)
{
  MW_AnalogIn_TriggerSource_Type trigger_val;
  freedomk64f_AnalogInput_Final_T *obj;

  /* Start for MATLABSystem: '<S8>/Analog Input' */
  Final_Simulink_Model_assignm_DW.obj_e.matlabCodegenIsDeleted = false;
  Final_Simulink_Model_assignm_DW.obj_e.SampleTime =
    Final_Simulink_Model_assignme_P.AnalogInput_SampleTime;
  obj = &Final_Simulink_Model_assignm_DW.obj_e;
  Final_Simulink_Model_assignm_DW.obj_e.isInitialized = 1;
  obj->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(16U);
  trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
  MW_AnalogIn_SetTriggerSource
    (Final_Simulink_Model_assignm_DW.obj_e.MW_ANALOGIN_HANDLE, trigger_val, 0U);
  Final_Simulink_Model_assignm_DW.obj_e.isSetupComplete = true;

  /* Start for MATLABSystem: '<S8>/Analog Input1' */
  Final_Simulink_Model_assignm_DW.obj_d.matlabCodegenIsDeleted = false;
  Final_Simulink_Model_assignm_DW.obj_d.SampleTime =
    Final_Simulink_Model_assignme_P.AnalogInput1_SampleTime;
  obj = &Final_Simulink_Model_assignm_DW.obj_d;
  Final_Simulink_Model_assignm_DW.obj_d.isInitialized = 1;
  obj->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(17U);
  trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
  MW_AnalogIn_SetTriggerSource
    (Final_Simulink_Model_assignm_DW.obj_d.MW_ANALOGIN_HANDLE, trigger_val, 0U);
  Final_Simulink_Model_assignm_DW.obj_d.isSetupComplete = true;

  /* Start for MATLABSystem: '<S8>/Serial Transmit' */
  Final_Simulink_Model_assignm_DW.obj_es.isInitialized = 0;
  Final_Simulink_Model_assignm_DW.obj_es.matlabCodegenIsDeleted = false;
  Final_Simulink_SystemCore_setup(&Final_Simulink_Model_assignm_DW.obj_es);
}

/* Output and update for Simulink Function: '<Root>/send_params()1' */
void send_params(void)
{
  int32_T i;
  uint8_T rtb_TmpSignalConversionAtSerial[49];
  uint8_T status;

  /* SignalConversion generated from: '<S8>/VENT_Amplitude' */
  Final_Simulink_Model_assignme_B.VENT_Amplitude =
    Final_Simulink_Model_assignme_B.VENT_Amplitude_a;

  /* SignalConversion generated from: '<S8>/ATR_Amplitude' */
  Final_Simulink_Model_assignme_B.ATR_Amplitude =
    Final_Simulink_Model_assignme_B.ATR_Amplitude_m;

  /* SignalConversion generated from: '<S8>/VENTSENSITIVITY_Amplitude' */
  Final_Simulink_Model_assignme_B.VENTSENSITIVITY_Amplitude =
    Final_Simulink_Model_assignme_B.VENTSENSITIVITY_Amplitude_l;

  /* SignalConversion generated from: '<S8>/ATRSENSITIVITY_Amplitude' */
  Final_Simulink_Model_assignme_B.ATRSENSITIVITY_Amplitude =
    Final_Simulink_Model_assignme_B.ATRSENSITIVITY_Amplitude_p;

  /* SignalConversion generated from: '<S8>/ARP' */
  Final_Simulink_Model_assignme_B.ARP = Final_Simulink_Model_assignme_B.ARP_l;

  /* SignalConversion generated from: '<S8>/VRP' */
  Final_Simulink_Model_assignme_B.VRP = Final_Simulink_Model_assignme_B.VRP_o;

  /* SignalConversion generated from: '<S8>/Activity_threshold' */
  Final_Simulink_Model_assignme_B.Activity_threshold =
    Final_Simulink_Model_assignme_B.Activity_threshold_d;

  /* SignalConversion generated from: '<S8>/Reaction_time' */
  Final_Simulink_Model_assignme_B.Reaction_time =
    Final_Simulink_Model_assignme_B.Reaction_time_d;

  /* SignalConversion generated from: '<S8>/Recovery_time' */
  Final_Simulink_Model_assignme_B.Recovery_time =
    Final_Simulink_Model_assignme_B.Recovery_time_d;

  /* MATLABSystem: '<S8>/Analog Input' */
  if (Final_Simulink_Model_assignm_DW.obj_e.SampleTime !=
      Final_Simulink_Model_assignme_P.AnalogInput_SampleTime) {
    Final_Simulink_Model_assignm_DW.obj_e.SampleTime =
      Final_Simulink_Model_assignme_P.AnalogInput_SampleTime;
  }

  MW_AnalogIn_Start(Final_Simulink_Model_assignm_DW.obj_e.MW_ANALOGIN_HANDLE);

  /* MATLABSystem: '<S8>/Analog Input' */
  MW_AnalogInSingle_ReadResult
    (Final_Simulink_Model_assignm_DW.obj_e.MW_ANALOGIN_HANDLE,
     &Final_Simulink_Model_assignme_B.AnalogInput, 7);

  /* S-Function (any2byte): '<S8>/Byte Pack9' */

  /* Pack: <S8>/Byte Pack9 */
  (void) memcpy(&Final_Simulink_Model_assignme_B.BytePack9[0],
                &Final_Simulink_Model_assignme_B.AnalogInput,
                8);

  /* MATLABSystem: '<S8>/Analog Input1' */
  if (Final_Simulink_Model_assignm_DW.obj_d.SampleTime !=
      Final_Simulink_Model_assignme_P.AnalogInput1_SampleTime) {
    Final_Simulink_Model_assignm_DW.obj_d.SampleTime =
      Final_Simulink_Model_assignme_P.AnalogInput1_SampleTime;
  }

  MW_AnalogIn_Start(Final_Simulink_Model_assignm_DW.obj_d.MW_ANALOGIN_HANDLE);

  /* MATLABSystem: '<S8>/Analog Input1' */
  MW_AnalogInSingle_ReadResult
    (Final_Simulink_Model_assignm_DW.obj_d.MW_ANALOGIN_HANDLE,
     &Final_Simulink_Model_assignme_B.AnalogInput1, 7);

  /* S-Function (any2byte): '<S8>/Byte Pack10' */

  /* Pack: <S8>/Byte Pack10 */
  (void) memcpy(&Final_Simulink_Model_assignme_B.BytePack10[0],
                &Final_Simulink_Model_assignme_B.AnalogInput1,
                8);

  /* S-Function (any2byte): '<S8>/Byte Pack' */

  /* Pack: <S8>/Byte Pack */
  (void) memcpy(&Final_Simulink_Model_assignme_B.BytePack[0],
                &Final_Simulink_Model_assignme_B.VENT_Amplitude,
                4);

  /* S-Function (any2byte): '<S8>/Byte Pack1' */

  /* Pack: <S8>/Byte Pack1 */
  (void) memcpy(&Final_Simulink_Model_assignme_B.BytePack1[0],
                &Final_Simulink_Model_assignme_B.ATR_Amplitude,
                4);

  /* S-Function (any2byte): '<S8>/Byte Pack2' */

  /* Pack: <S8>/Byte Pack2 */
  (void) memcpy(&Final_Simulink_Model_assignme_B.BytePack2[0],
                &Final_Simulink_Model_assignme_B.VENTSENSITIVITY_Amplitude,
                4);

  /* S-Function (any2byte): '<S8>/Byte Pack3' */

  /* Pack: <S8>/Byte Pack3 */
  (void) memcpy(&Final_Simulink_Model_assignme_B.BytePack3[0],
                &Final_Simulink_Model_assignme_B.ATRSENSITIVITY_Amplitude,
                4);

  /* S-Function (any2byte): '<S8>/Byte Pack4' */

  /* Pack: <S8>/Byte Pack4 */
  (void) memcpy(&Final_Simulink_Model_assignme_B.BytePack4[0],
                &Final_Simulink_Model_assignme_B.ARP,
                2);

  /* S-Function (any2byte): '<S8>/Byte Pack5' */

  /* Pack: <S8>/Byte Pack5 */
  (void) memcpy(&Final_Simulink_Model_assignme_B.BytePack5[0],
                &Final_Simulink_Model_assignme_B.VRP,
                2);

  /* S-Function (any2byte): '<S8>/Byte Pack6' */

  /* Pack: <S8>/Byte Pack6 */
  (void) memcpy(&Final_Simulink_Model_assignme_B.BytePack6[0],
                &Final_Simulink_Model_assignme_B.Activity_threshold,
                4);

  /* S-Function (any2byte): '<S8>/Byte Pack7' */

  /* Pack: <S8>/Byte Pack7 */
  (void) memcpy(&Final_Simulink_Model_assignme_B.BytePack7,
                &Final_Simulink_Model_assignme_B.Reaction_time,
                1);

  /* S-Function (any2byte): '<S8>/Byte Pack8' */

  /* Pack: <S8>/Byte Pack8 */
  (void) memcpy(&Final_Simulink_Model_assignme_B.BytePack8,
                &Final_Simulink_Model_assignme_B.Recovery_time,
                1);

  /* SignalConversion generated from: '<S8>/Serial Transmit' incorporates:
   *  SignalConversion generated from: '<S8>/ATR_PULSE_WIDTH'
   *  SignalConversion generated from: '<S8>/LRL'
   *  SignalConversion generated from: '<S8>/MSR'
   *  SignalConversion generated from: '<S8>/Response_Factor'
   *  SignalConversion generated from: '<S8>/URL'
   *  SignalConversion generated from: '<S8>/VENT_PULSE_WIDTH'
   *  SignalConversion generated from: '<S8>/mode'
   */
  for (i = 0; i < 8; i++) {
    rtb_TmpSignalConversionAtSerial[i] =
      Final_Simulink_Model_assignme_B.BytePack9[i];
    rtb_TmpSignalConversionAtSerial[i + 8] =
      Final_Simulink_Model_assignme_B.BytePack10[i];
  }

  rtb_TmpSignalConversionAtSerial[16] = Final_Simulink_Model_assignme_B.mode;
  rtb_TmpSignalConversionAtSerial[17] = Final_Simulink_Model_assignme_B.LRL;
  rtb_TmpSignalConversionAtSerial[18] = Final_Simulink_Model_assignme_B.URL;
  rtb_TmpSignalConversionAtSerial[27] =
    Final_Simulink_Model_assignme_B.VENT_PULSE_WIDTH;
  rtb_TmpSignalConversionAtSerial[28] =
    Final_Simulink_Model_assignme_B.ATR_PULSE_WIDTH;
  rtb_TmpSignalConversionAtSerial[19] =
    Final_Simulink_Model_assignme_B.BytePack[0];
  rtb_TmpSignalConversionAtSerial[23] =
    Final_Simulink_Model_assignme_B.BytePack1[0];
  rtb_TmpSignalConversionAtSerial[29] =
    Final_Simulink_Model_assignme_B.BytePack2[0];
  rtb_TmpSignalConversionAtSerial[33] =
    Final_Simulink_Model_assignme_B.BytePack3[0];
  rtb_TmpSignalConversionAtSerial[20] =
    Final_Simulink_Model_assignme_B.BytePack[1];
  rtb_TmpSignalConversionAtSerial[24] =
    Final_Simulink_Model_assignme_B.BytePack1[1];
  rtb_TmpSignalConversionAtSerial[30] =
    Final_Simulink_Model_assignme_B.BytePack2[1];
  rtb_TmpSignalConversionAtSerial[34] =
    Final_Simulink_Model_assignme_B.BytePack3[1];
  rtb_TmpSignalConversionAtSerial[21] =
    Final_Simulink_Model_assignme_B.BytePack[2];
  rtb_TmpSignalConversionAtSerial[25] =
    Final_Simulink_Model_assignme_B.BytePack1[2];
  rtb_TmpSignalConversionAtSerial[31] =
    Final_Simulink_Model_assignme_B.BytePack2[2];
  rtb_TmpSignalConversionAtSerial[35] =
    Final_Simulink_Model_assignme_B.BytePack3[2];
  rtb_TmpSignalConversionAtSerial[22] =
    Final_Simulink_Model_assignme_B.BytePack[3];
  rtb_TmpSignalConversionAtSerial[26] =
    Final_Simulink_Model_assignme_B.BytePack1[3];
  rtb_TmpSignalConversionAtSerial[32] =
    Final_Simulink_Model_assignme_B.BytePack2[3];
  rtb_TmpSignalConversionAtSerial[36] =
    Final_Simulink_Model_assignme_B.BytePack3[3];
  rtb_TmpSignalConversionAtSerial[37] =
    Final_Simulink_Model_assignme_B.BytePack4[0];
  rtb_TmpSignalConversionAtSerial[39] =
    Final_Simulink_Model_assignme_B.BytePack5[0];
  rtb_TmpSignalConversionAtSerial[38] =
    Final_Simulink_Model_assignme_B.BytePack4[1];
  rtb_TmpSignalConversionAtSerial[40] =
    Final_Simulink_Model_assignme_B.BytePack5[1];
  rtb_TmpSignalConversionAtSerial[41] = Final_Simulink_Model_assignme_B.MSR;
  rtb_TmpSignalConversionAtSerial[42] =
    Final_Simulink_Model_assignme_B.BytePack6[0];
  rtb_TmpSignalConversionAtSerial[43] =
    Final_Simulink_Model_assignme_B.BytePack6[1];
  rtb_TmpSignalConversionAtSerial[44] =
    Final_Simulink_Model_assignme_B.BytePack6[2];
  rtb_TmpSignalConversionAtSerial[45] =
    Final_Simulink_Model_assignme_B.BytePack6[3];
  rtb_TmpSignalConversionAtSerial[46] =
    Final_Simulink_Model_assignme_B.Response_Factor;
  rtb_TmpSignalConversionAtSerial[47] =
    Final_Simulink_Model_assignme_B.BytePack7;
  rtb_TmpSignalConversionAtSerial[48] =
    Final_Simulink_Model_assignme_B.BytePack8;

  /* End of SignalConversion generated from: '<S8>/Serial Transmit' */

  /* MATLABSystem: '<S8>/Serial Transmit' */
  status = 1U;
  while (status != 0) {
    memcpy((void *)&Final_Simulink_Model_assignme_B.TxDataLocChar[0], (void *)
           &rtb_TmpSignalConversionAtSerial[0], (size_t)49 * sizeof(uint8_T));
    status = MW_SCI_Transmit(Final_Simulink_Model_assignm_DW.obj_es.MW_SCIHANDLE,
      &Final_Simulink_Model_assignme_B.TxDataLocChar[0], 49U);
  }

  /* End of MATLABSystem: '<S8>/Serial Transmit' */
}

/* Termination for Simulink Function: '<Root>/send_params()1' */
void send_params_Term(void)
{
  /* Terminate for MATLABSystem: '<S8>/Analog Input' */
  if (!Final_Simulink_Model_assignm_DW.obj_e.matlabCodegenIsDeleted) {
    Final_Simulink_Model_assignm_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((Final_Simulink_Model_assignm_DW.obj_e.isInitialized == 1) &&
        Final_Simulink_Model_assignm_DW.obj_e.isSetupComplete) {
      MW_AnalogIn_Stop(Final_Simulink_Model_assignm_DW.obj_e.MW_ANALOGIN_HANDLE);
      MW_AnalogIn_Close(Final_Simulink_Model_assignm_DW.obj_e.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S8>/Analog Input' */

  /* Terminate for MATLABSystem: '<S8>/Analog Input1' */
  if (!Final_Simulink_Model_assignm_DW.obj_d.matlabCodegenIsDeleted) {
    Final_Simulink_Model_assignm_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((Final_Simulink_Model_assignm_DW.obj_d.isInitialized == 1) &&
        Final_Simulink_Model_assignm_DW.obj_d.isSetupComplete) {
      MW_AnalogIn_Stop(Final_Simulink_Model_assignm_DW.obj_d.MW_ANALOGIN_HANDLE);
      MW_AnalogIn_Close(Final_Simulink_Model_assignm_DW.obj_d.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S8>/Analog Input1' */

  /* Terminate for MATLABSystem: '<S8>/Serial Transmit' */
  if (!Final_Simulink_Model_assignm_DW.obj_es.matlabCodegenIsDeleted) {
    Final_Simulink_Model_assignm_DW.obj_es.matlabCodegenIsDeleted = true;
    if ((Final_Simulink_Model_assignm_DW.obj_es.isInitialized == 1) &&
        Final_Simulink_Model_assignm_DW.obj_es.isSetupComplete) {
      MW_SCI_Close(Final_Simulink_Model_assignm_DW.obj_es.MW_SCIHANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S8>/Serial Transmit' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
