/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Final_Simulink_Model_assignment_2.c
 *
 * Code generated for Simulink model 'Final_Simulink_Model_assignment_2'.
 *
 * Model version                  : 2.133
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Sun Nov 27 18:36:21 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Final_Simulink_Model_assignment_2.h"
#include "Final_Simulink_Model_assignment_2_types.h"
#include "rtwtypes.h"
#include <string.h>
#include <math.h>
#include "rt_roundd_snf.h"
#include <stddef.h>
#include "send_params.h"
#include "send_params_private.h"

/* Named constants for Chart: '<Root>/COM_IN1' */
#define Final_Simulink_Mo_IN_ECHO_PARAM ((uint8_T)1U)
#define Final_Simulink_Mo_IN_Initialize ((uint8_T)2U)
#define Final_Simulink_Mod_IN_SET_PARAM ((uint8_T)3U)
#define Final_Simulink_Model_IN_STANDBY ((uint8_T)4U)

/* Named constants for Chart: '<Root>/Chart1' */
#define Final_Simuli_IN_AAIR_REFRACTORY ((uint8_T)3U)
#define Final_Simuli_IN_VVIR_REFRACTORY ((uint8_T)20U)
#define Final_Simulin_IN_AAI_REFRACTORY ((uint8_T)4U)
#define Final_Simulin_IN_VVI_REFRACTORY ((uint8_T)21U)
#define Final_Simulink_M_IN_Pacing_AAI1 ((uint8_T)8U)
#define Final_Simulink_M_IN_Pacing_AAIR ((uint8_T)9U)
#define Final_Simulink_M_IN_Pacing_AOOR ((uint8_T)11U)
#define Final_Simulink_M_IN_Pacing_VOOR ((uint8_T)13U)
#define Final_Simulink_M_IN_Pacing_VVIR ((uint8_T)15U)
#define Final_Simulink_Mo_IN_Pacing_AOO ((uint8_T)10U)
#define Final_Simulink_Mo_IN_Pacing_VOO ((uint8_T)12U)
#define Final_Simulink_Mo_IN_Pacing_VVI ((uint8_T)14U)
#define Final_Simulink_Model_as_IN_AAIR ((uint8_T)2U)
#define Final_Simulink_Model_as_IN_AOOR ((uint8_T)6U)
#define Final_Simulink_Model_as_IN_MAIN ((uint8_T)7U)
#define Final_Simulink_Model_as_IN_VOOR ((uint8_T)17U)
#define Final_Simulink_Model_as_IN_VVIR ((uint8_T)19U)
#define Final_Simulink_Model_ass_IN_AAI ((uint8_T)1U)
#define Final_Simulink_Model_ass_IN_AOO ((uint8_T)5U)
#define Final_Simulink_Model_ass_IN_VOO ((uint8_T)16U)
#define Final_Simulink_Model_ass_IN_VVI ((uint8_T)18U)

/* Named constants for Chart: '<Root>/Find the desired rate for pacing1' */
#define Final_Simuli_IN_Linear_increase ((uint8_T)5U)
#define Final_Simulink_Model_a_IN_Check ((uint8_T)1U)
#define Final__IN_Desired_rate_output_1 ((uint8_T)2U)
#define Final__IN_Desired_rate_output_2 ((uint8_T)3U)
#define Final__IN_Desired_rate_output_3 ((uint8_T)4U)

/* Named constants for Chart: '<Root>/Find the pacing rate1' */
#define Final_Simulink_IN_Initial_state ((uint8_T)3U)
#define Final_Simulink_Mo_IN_Decreasing ((uint8_T)1U)
#define Final_Simulink_Mo_IN_Increasing ((uint8_T)2U)
#define Final_Simulink_Model_a_IN_Steps ((uint8_T)4U)

/* Block signals (default storage) */
B_Final_Simulink_Model_assign_T Final_Simulink_Model_assignme_B;

/* Block states (default storage) */
DW_Final_Simulink_Model_assig_T Final_Simulink_Model_assignm_DW;

/* Real-time model */
static RT_MODEL_Final_Simulink_Model_T Final_Simulink_Model_assignm_M_;
RT_MODEL_Final_Simulink_Model_T *const Final_Simulink_Model_assignm_M =
  &Final_Simulink_Model_assignm_M_;

/* Forward declaration for local functions */
static void Final_Simulink_M_VVI_REFRACTORY(boolean_T *PACE_GND_CTRL, boolean_T *
  PACE_CHARGE_CTRL);
static void Final_Simulink_Model_assign_AAI(boolean_T *PACE_GND_CTRL, boolean_T *
  PACE_CHARGE_CTRL, const boolean_T *ATR_CMP_DETECT);
static void Final_Simulink_Model_assig_AAIR(boolean_T *PACE_GND_CTRL, boolean_T *
  PACE_CHARGE_CTRL, const boolean_T *ATR_CMP_DETECT);
static void Final_Simulink__AAIR_REFRACTORY(boolean_T *PACE_GND_CTRL, boolean_T *
  PACE_CHARGE_CTRL);
static void Final_Simulink_M_AAI_REFRACTORY(boolean_T *PACE_GND_CTRL, boolean_T *
  PACE_CHARGE_CTRL);
static void Final_Simulink_Model_assig_MAIN(boolean_T *PACE_GND_CTRL, boolean_T *
  PACE_CHARGE_CTRL);
static void Final_Simulink_Model_assign_VVI(boolean_T *PACE_GND_CTRL, boolean_T *
  PACE_CHARGE_CTRL, const boolean_T *VENT_CMP_DETECT);
static void Final_Simulink_Model_assig_VVIR(boolean_T *PACE_GND_CTRL, boolean_T *
  PACE_CHARGE_CTRL, const boolean_T *VENT_CMP_DETECT);
static void Final_Simulink__VVIR_REFRACTORY(boolean_T *PACE_GND_CTRL, boolean_T *
  PACE_CHARGE_CTRL);
static void Final_Simu_SystemCore_setup_mmp(freedomk64f_SCIRead_Final_Sim_T *obj);
static void Final_Simuli_SystemCore_setup_m(freedomk64f_fxos8700_Final_Si_T *obj);
static void Final_Simul_SystemCore_setup_mm(dsp_simulink_MovingStandardDe_T *obj);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void Final_Simulink_Model_assignment_2_SetEventsForThisBaseStep(boolean_T
  *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(Final_Simulink_Model_assignm_M, 1));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Final_Simulink_Model_assignm_M->Timing.TaskCounters.TID[1])++;
  if ((Final_Simulink_Model_assignm_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.01s, 0.0s] */
    Final_Simulink_Model_assignm_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Function for Chart: '<Root>/Chart1' */
static void Final_Simulink_M_VVI_REFRACTORY(boolean_T *PACE_GND_CTRL, boolean_T *
  PACE_CHARGE_CTRL)
{
  Final_Simulink_Model_assignme_B.FRONTEND_CTRL = false;
  Final_Simulink_Model_assignme_B.VENT_GND_CTRL = true;
  *PACE_CHARGE_CTRL = false;
  *PACE_GND_CTRL = true;
  if ((uint32_T)((int32_T)Final_Simulink_Model_assignm_DW.temporalCounter_i1 *
                 10) >= Final_Simulink_Model_assignme_B.VRP_o) {
    Final_Simulink_Model_assignm_DW.is_c7_Final_Simulink_Model_assi =
      Final_Simulink_Model_ass_IN_VVI;
    Final_Simulink_Model_assignm_DW.temporalCounter_i1 = 0U;
    Final_Simulink_Model_assignme_B.FRONTEND_CTRL = true;
    Final_Simulink_Model_assignme_B.VENT_PACE_CTRL = false;
    *PACE_CHARGE_CTRL = true;
    *PACE_GND_CTRL = true;
    Final_Simulink_Model_assignme_B.PACING_REF_PWM = 20.0F *
      Final_Simulink_Model_assignme_B.VENT_Amplitude_a;
    Final_Simulink_Model_assignme_B.VENT_CMP_REF_PWM = 20.0F *
      Final_Simulink_Model_assignme_B.VENTSENSITIVITY_Amplitude_l;
  }
}

/* Function for Chart: '<Root>/Chart1' */
static void Final_Simulink_Model_assign_AAI(boolean_T *PACE_GND_CTRL, boolean_T *
  PACE_CHARGE_CTRL, const boolean_T *ATR_CMP_DETECT)
{
  real_T tmp_1;
  int32_T tmp;
  uint32_T qY;
  uint8_T tmp_0;
  boolean_T out;
  Final_Simulink_Model_assignme_B.FRONTEND_CTRL = true;
  Final_Simulink_Model_assignme_B.ATR_PACE_CTRL = false;
  *PACE_CHARGE_CTRL = true;
  Final_Simulink_Model_assignme_B.ATR_GND_CTRL = true;
  *PACE_GND_CTRL = true;
  if (!*ATR_CMP_DETECT) {
    tmp_1 = rt_roundd_snf(60000.0 / (real_T)Final_Simulink_Model_assignme_B.LRL);
    if (tmp_1 < 256.0) {
      tmp_0 = (uint8_T)tmp_1;
    } else {
      tmp_0 = MAX_uint8_T;
    }

    qY = (uint32_T)tmp_0 - /*MW:OvSatOk*/
      Final_Simulink_Model_assignme_B.ATR_PULSE_WIDTH;
    if (qY > tmp_0) {
      qY = 0U;
    }

    tmp = (int32_T)qY - Final_Simulink_Model_assignme_B.ARP_l;
    if (tmp < 0) {
      tmp = 0;
    }

    out = ((uint32_T)((int32_T)
                      Final_Simulink_Model_assignm_DW.temporalCounter_i1 * 10) >=
           (uint32_T)tmp);
  } else {
    out = false;
  }

  if (out) {
    Final_Simulink_Model_assignm_DW.is_c7_Final_Simulink_Model_assi =
      Final_Simulink_M_IN_Pacing_AAI1;
    *PACE_CHARGE_CTRL = false;
    *PACE_GND_CTRL = true;
    Final_Simulink_Model_assignme_B.ATR_PACE_CTRL = true;
    Final_Simulink_Model_assignme_B.ATR_GND_CTRL = false;
    Final_Simulink_Model_assignme_B.PACING_REF_PWM = 20.0F *
      Final_Simulink_Model_assignme_B.ATR_Amplitude_m;
  } else if (*ATR_CMP_DETECT) {
    Final_Simulink_Model_assignm_DW.is_c7_Final_Simulink_Model_assi =
      Final_Simulin_IN_AAI_REFRACTORY;
    Final_Simulink_Model_assignm_DW.temporalCounter_i1 = 0U;
    Final_Simulink_Model_assignme_B.FRONTEND_CTRL = false;
    Final_Simulink_Model_assignme_B.PACING_REF_PWM = 20.0F *
      Final_Simulink_Model_assignme_B.ATR_Amplitude_m;
    *PACE_CHARGE_CTRL = false;
    *PACE_GND_CTRL = true;
  }
}

/* Function for Chart: '<Root>/Chart1' */
static void Final_Simulink_Model_assig_AAIR(boolean_T *PACE_GND_CTRL, boolean_T *
  PACE_CHARGE_CTRL, const boolean_T *ATR_CMP_DETECT)
{
  real_T tmp_1;
  int32_T tmp;
  uint32_T qY;
  uint8_T tmp_0;
  boolean_T out;
  Final_Simulink_Model_assignme_B.FRONTEND_CTRL = true;
  Final_Simulink_Model_assignme_B.ATR_PACE_CTRL = false;
  *PACE_CHARGE_CTRL = true;
  Final_Simulink_Model_assignme_B.ATR_GND_CTRL = true;
  *PACE_GND_CTRL = true;
  if (!*ATR_CMP_DETECT) {
    tmp_1 = rt_roundd_snf(60000.0 / (real_T)Final_Simulink_Model_assignme_B.rate);
    if (tmp_1 < 256.0) {
      tmp_0 = (uint8_T)tmp_1;
    } else {
      tmp_0 = MAX_uint8_T;
    }

    qY = (uint32_T)tmp_0 - /*MW:OvSatOk*/
      Final_Simulink_Model_assignme_B.ATR_PULSE_WIDTH;
    if (qY > tmp_0) {
      qY = 0U;
    }

    tmp = (int32_T)qY - Final_Simulink_Model_assignme_B.ARP_l;
    if (tmp < 0) {
      tmp = 0;
    }

    out = ((uint32_T)((int32_T)
                      Final_Simulink_Model_assignm_DW.temporalCounter_i1 * 10) >=
           (uint32_T)tmp);
  } else {
    out = false;
  }

  if (out) {
    Final_Simulink_Model_assignm_DW.is_c7_Final_Simulink_Model_assi =
      Final_Simulink_M_IN_Pacing_AAIR;
    *PACE_CHARGE_CTRL = false;
    *PACE_GND_CTRL = true;
    Final_Simulink_Model_assignme_B.ATR_PACE_CTRL = true;
    Final_Simulink_Model_assignme_B.ATR_GND_CTRL = false;
    Final_Simulink_Model_assignme_B.PACING_REF_PWM = 20.0F *
      Final_Simulink_Model_assignme_B.ATR_Amplitude_m;
  } else if (*ATR_CMP_DETECT) {
    Final_Simulink_Model_assignm_DW.is_c7_Final_Simulink_Model_assi =
      Final_Simuli_IN_AAIR_REFRACTORY;
    Final_Simulink_Model_assignm_DW.temporalCounter_i1 = 0U;
    Final_Simulink_Model_assignme_B.FRONTEND_CTRL = false;
    Final_Simulink_Model_assignme_B.PACING_REF_PWM = 20.0F *
      Final_Simulink_Model_assignme_B.ATR_Amplitude_m;
    *PACE_CHARGE_CTRL = false;
    *PACE_GND_CTRL = true;
  }
}

/* Function for Chart: '<Root>/Chart1' */
static void Final_Simulink__AAIR_REFRACTORY(boolean_T *PACE_GND_CTRL, boolean_T *
  PACE_CHARGE_CTRL)
{
  Final_Simulink_Model_assignme_B.FRONTEND_CTRL = false;
  Final_Simulink_Model_assignme_B.ATR_PACE_CTRL = false;
  Final_Simulink_Model_assignme_B.ATR_GND_CTRL = true;
  *PACE_CHARGE_CTRL = false;
  *PACE_GND_CTRL = true;
  if ((uint32_T)((int32_T)Final_Simulink_Model_assignm_DW.temporalCounter_i1 *
                 10) >= Final_Simulink_Model_assignme_B.ARP_l) {
    Final_Simulink_Model_assignm_DW.is_c7_Final_Simulink_Model_assi =
      Final_Simulink_Model_as_IN_AAIR;
    Final_Simulink_Model_assignm_DW.temporalCounter_i1 = 0U;
    Final_Simulink_Model_assignme_B.FRONTEND_CTRL = true;
    *PACE_CHARGE_CTRL = true;
    *PACE_GND_CTRL = true;
    Final_Simulink_Model_assignme_B.PACING_REF_PWM = 20.0F *
      Final_Simulink_Model_assignme_B.ATR_Amplitude_m;
    Final_Simulink_Model_assignme_B.ATR_CMP_REF_PWM = 20.0F *
      Final_Simulink_Model_assignme_B.ATRSENSITIVITY_Amplitude_p;
  }
}

/* Function for Chart: '<Root>/Chart1' */
static void Final_Simulink_M_AAI_REFRACTORY(boolean_T *PACE_GND_CTRL, boolean_T *
  PACE_CHARGE_CTRL)
{
  Final_Simulink_Model_assignme_B.FRONTEND_CTRL = false;
  Final_Simulink_Model_assignme_B.ATR_PACE_CTRL = false;
  Final_Simulink_Model_assignme_B.ATR_GND_CTRL = true;
  *PACE_CHARGE_CTRL = false;
  *PACE_GND_CTRL = true;
  if ((uint32_T)((int32_T)Final_Simulink_Model_assignm_DW.temporalCounter_i1 *
                 10) >= Final_Simulink_Model_assignme_B.ARP_l) {
    Final_Simulink_Model_assignm_DW.is_c7_Final_Simulink_Model_assi =
      Final_Simulink_Model_ass_IN_AAI;
    Final_Simulink_Model_assignm_DW.temporalCounter_i1 = 0U;
    Final_Simulink_Model_assignme_B.FRONTEND_CTRL = true;
    *PACE_CHARGE_CTRL = true;
    *PACE_GND_CTRL = true;
    Final_Simulink_Model_assignme_B.PACING_REF_PWM = 20.0F *
      Final_Simulink_Model_assignme_B.ATR_Amplitude_m;
    Final_Simulink_Model_assignme_B.ATR_CMP_REF_PWM = 20.0F *
      Final_Simulink_Model_assignme_B.ATRSENSITIVITY_Amplitude_p;
  }
}

/* Function for Chart: '<Root>/Chart1' */
static void Final_Simulink_Model_assig_MAIN(boolean_T *PACE_GND_CTRL, boolean_T *
  PACE_CHARGE_CTRL)
{
  Final_Simulink_Model_assignme_B.VENT_GND_CTRL = false;
  Final_Simulink_Model_assignme_B.Z_ATR_CTRL = false;
  Final_Simulink_Model_assignme_B.Z_VENT_CTRL = false;
  Final_Simulink_Model_assignme_B.FRONTEND_CTRL = false;
  *PACE_CHARGE_CTRL = false;
  Final_Simulink_Model_assignme_B.VENT_PACE_CTRL = false;
  Final_Simulink_Model_assignme_B.ATR_PACE_CTRL = false;
  *PACE_GND_CTRL = false;
  Final_Simulink_Model_assignme_B.ATR_GND_CTRL = false;
  switch (Final_Simulink_Model_assignme_B.mode) {
   case 2:
    Final_Simulink_Model_assignm_DW.is_c7_Final_Simulink_Model_assi =
      Final_Simulink_Model_ass_IN_VOO;
    Final_Simulink_Model_assignm_DW.temporalCounter_i1 = 0U;
    *PACE_CHARGE_CTRL = true;
    Final_Simulink_Model_assignme_B.VENT_GND_CTRL = true;
    *PACE_GND_CTRL = true;
    Final_Simulink_Model_assignme_B.PACING_REF_PWM = 20.0F *
      Final_Simulink_Model_assignme_B.VENT_Amplitude_a;
    break;

   case 4:
    Final_Simulink_Model_assignm_DW.is_c7_Final_Simulink_Model_assi =
      Final_Simulink_Model_ass_IN_VVI;
    Final_Simulink_Model_assignm_DW.temporalCounter_i1 = 0U;
    Final_Simulink_Model_assignme_B.FRONTEND_CTRL = true;
    *PACE_CHARGE_CTRL = true;
    Final_Simulink_Model_assignme_B.VENT_GND_CTRL = true;
    *PACE_GND_CTRL = true;
    Final_Simulink_Model_assignme_B.PACING_REF_PWM = 20.0F *
      Final_Simulink_Model_assignme_B.VENT_Amplitude_a;
    Final_Simulink_Model_assignme_B.VENT_CMP_REF_PWM = 20.0F *
      Final_Simulink_Model_assignme_B.VENTSENSITIVITY_Amplitude_l;
    break;

   case 3:
    Final_Simulink_Model_assignm_DW.is_c7_Final_Simulink_Model_assi =
      Final_Simulink_Model_ass_IN_AAI;
    Final_Simulink_Model_assignm_DW.temporalCounter_i1 = 0U;
    Final_Simulink_Model_assignme_B.FRONTEND_CTRL = true;
    *PACE_CHARGE_CTRL = true;
    Final_Simulink_Model_assignme_B.ATR_GND_CTRL = true;
    *PACE_GND_CTRL = true;
    Final_Simulink_Model_assignme_B.PACING_REF_PWM = 20.0F *
      Final_Simulink_Model_assignme_B.ATR_Amplitude_m;
    Final_Simulink_Model_assignme_B.ATR_CMP_REF_PWM = 20.0F *
      Final_Simulink_Model_assignme_B.ATRSENSITIVITY_Amplitude_p;
    break;

   case 1:
    Final_Simulink_Model_assignm_DW.is_c7_Final_Simulink_Model_assi =
      Final_Simulink_Model_ass_IN_AOO;
    Final_Simulink_Model_assignm_DW.temporalCounter_i1 = 0U;
    *PACE_CHARGE_CTRL = true;
    Final_Simulink_Model_assignme_B.ATR_GND_CTRL = true;
    *PACE_GND_CTRL = true;
    Final_Simulink_Model_assignme_B.PACING_REF_PWM = 20.0F *
      Final_Simulink_Model_assignme_B.ATR_Amplitude_m;
    break;

   case 5:
    Final_Simulink_Model_assignm_DW.is_c7_Final_Simulink_Model_assi =
      Final_Simulink_Model_as_IN_AOOR;
    Final_Simulink_Model_assignm_DW.temporalCounter_i1 = 0U;
    *PACE_CHARGE_CTRL = true;
    Final_Simulink_Model_assignme_B.ATR_GND_CTRL = true;
    *PACE_GND_CTRL = true;
    Final_Simulink_Model_assignme_B.PACING_REF_PWM = 20.0F *
      Final_Simulink_Model_assignme_B.ATR_Amplitude_m;
    break;

   case 6:
    Final_Simulink_Model_assignm_DW.is_c7_Final_Simulink_Model_assi =
      Final_Simulink_Model_as_IN_VOOR;
    Final_Simulink_Model_assignm_DW.temporalCounter_i1 = 0U;
    *PACE_CHARGE_CTRL = true;
    Final_Simulink_Model_assignme_B.VENT_GND_CTRL = true;
    *PACE_GND_CTRL = true;
    Final_Simulink_Model_assignme_B.PACING_REF_PWM = 20.0F *
      Final_Simulink_Model_assignme_B.VENT_Amplitude_a;
    break;

   case 7:
    Final_Simulink_Model_assignm_DW.is_c7_Final_Simulink_Model_assi =
      Final_Simulink_Model_as_IN_AAIR;
    Final_Simulink_Model_assignm_DW.temporalCounter_i1 = 0U;
    Final_Simulink_Model_assignme_B.FRONTEND_CTRL = true;
    *PACE_CHARGE_CTRL = true;
    Final_Simulink_Model_assignme_B.ATR_GND_CTRL = true;
    *PACE_GND_CTRL = true;
    Final_Simulink_Model_assignme_B.PACING_REF_PWM = 20.0F *
      Final_Simulink_Model_assignme_B.ATR_Amplitude_m;
    Final_Simulink_Model_assignme_B.ATR_CMP_REF_PWM = 20.0F *
      Final_Simulink_Model_assignme_B.ATRSENSITIVITY_Amplitude_p;
    break;

   case 8:
    Final_Simulink_Model_assignm_DW.is_c7_Final_Simulink_Model_assi =
      Final_Simulink_Model_as_IN_VVIR;
    Final_Simulink_Model_assignm_DW.temporalCounter_i1 = 0U;
    Final_Simulink_Model_assignme_B.FRONTEND_CTRL = true;
    *PACE_CHARGE_CTRL = true;
    Final_Simulink_Model_assignme_B.VENT_GND_CTRL = true;
    *PACE_GND_CTRL = true;
    Final_Simulink_Model_assignme_B.PACING_REF_PWM = 20.0F *
      Final_Simulink_Model_assignme_B.VENT_Amplitude_a;
    Final_Simulink_Model_assignme_B.VENT_CMP_REF_PWM = 20.0F *
      Final_Simulink_Model_assignme_B.VENTSENSITIVITY_Amplitude_l;
    break;
  }
}

/* Function for Chart: '<Root>/Chart1' */
static void Final_Simulink_Model_assign_VVI(boolean_T *PACE_GND_CTRL, boolean_T *
  PACE_CHARGE_CTRL, const boolean_T *VENT_CMP_DETECT)
{
  real_T tmp_1;
  int32_T tmp;
  uint32_T qY;
  uint8_T tmp_0;
  boolean_T out;
  Final_Simulink_Model_assignme_B.FRONTEND_CTRL = true;
  Final_Simulink_Model_assignme_B.VENT_PACE_CTRL = false;
  *PACE_CHARGE_CTRL = true;
  Final_Simulink_Model_assignme_B.VENT_GND_CTRL = true;
  *PACE_GND_CTRL = true;
  if (!*VENT_CMP_DETECT) {
    tmp_1 = rt_roundd_snf(60000.0 / (real_T)Final_Simulink_Model_assignme_B.LRL);
    if (tmp_1 < 256.0) {
      tmp_0 = (uint8_T)tmp_1;
    } else {
      tmp_0 = MAX_uint8_T;
    }

    qY = (uint32_T)tmp_0 - /*MW:OvSatOk*/
      Final_Simulink_Model_assignme_B.VENT_PULSE_WIDTH;
    if (qY > tmp_0) {
      qY = 0U;
    }

    tmp = (int32_T)qY - Final_Simulink_Model_assignme_B.VRP_o;
    if (tmp < 0) {
      tmp = 0;
    }

    out = ((uint32_T)((int32_T)
                      Final_Simulink_Model_assignm_DW.temporalCounter_i1 * 10) >=
           (uint32_T)tmp);
  } else {
    out = false;
  }

  if (out) {
    Final_Simulink_Model_assignm_DW.is_c7_Final_Simulink_Model_assi =
      Final_Simulink_Mo_IN_Pacing_VVI;
    *PACE_CHARGE_CTRL = false;
    *PACE_GND_CTRL = true;
    Final_Simulink_Model_assignme_B.VENT_GND_CTRL = false;
    Final_Simulink_Model_assignme_B.VENT_PACE_CTRL = true;
    Final_Simulink_Model_assignme_B.PACING_REF_PWM = 20.0F *
      Final_Simulink_Model_assignme_B.VENT_Amplitude_a;
  } else if (*VENT_CMP_DETECT) {
    Final_Simulink_Model_assignm_DW.is_c7_Final_Simulink_Model_assi =
      Final_Simulin_IN_VVI_REFRACTORY;
    Final_Simulink_Model_assignm_DW.temporalCounter_i1 = 0U;
    Final_Simulink_Model_assignme_B.FRONTEND_CTRL = false;
    Final_Simulink_Model_assignme_B.PACING_REF_PWM = 20.0F *
      Final_Simulink_Model_assignme_B.VENT_Amplitude_a;
    *PACE_CHARGE_CTRL = false;
    *PACE_GND_CTRL = true;
  }
}

/* Function for Chart: '<Root>/Chart1' */
static void Final_Simulink_Model_assig_VVIR(boolean_T *PACE_GND_CTRL, boolean_T *
  PACE_CHARGE_CTRL, const boolean_T *VENT_CMP_DETECT)
{
  uint8_T tmp;
  boolean_T out;
  Final_Simulink_Model_assignme_B.FRONTEND_CTRL = true;
  Final_Simulink_Model_assignme_B.VENT_PACE_CTRL = false;
  *PACE_CHARGE_CTRL = true;
  Final_Simulink_Model_assignme_B.VENT_GND_CTRL = true;
  *PACE_GND_CTRL = true;
  if (!*VENT_CMP_DETECT) {
    Final_Simulink_Model_assignme_B.d = rt_roundd_snf(60000.0 / (real_T)
      Final_Simulink_Model_assignme_B.rate);
    if (Final_Simulink_Model_assignme_B.d < 256.0) {
      tmp = (uint8_T)Final_Simulink_Model_assignme_B.d;
    } else {
      tmp = MAX_uint8_T;
    }

    Final_Simulink_Model_assignme_B.qY_k = (uint32_T)tmp - /*MW:OvSatOk*/
      Final_Simulink_Model_assignme_B.VENT_PULSE_WIDTH;
    if (Final_Simulink_Model_assignme_B.qY_k > tmp) {
      Final_Simulink_Model_assignme_B.qY_k = 0U;
    }

    Final_Simulink_Model_assignme_B.i_m = (int32_T)
      Final_Simulink_Model_assignme_B.qY_k -
      Final_Simulink_Model_assignme_B.VRP_o;
    if (Final_Simulink_Model_assignme_B.i_m < 0) {
      Final_Simulink_Model_assignme_B.i_m = 0;
    }

    out = ((uint32_T)((int32_T)
                      Final_Simulink_Model_assignm_DW.temporalCounter_i1 * 10) >=
           (uint32_T)Final_Simulink_Model_assignme_B.i_m);
  } else {
    out = false;
  }

  if (out) {
    Final_Simulink_Model_assignm_DW.is_c7_Final_Simulink_Model_assi =
      Final_Simulink_M_IN_Pacing_VVIR;
    *PACE_CHARGE_CTRL = false;
    *PACE_GND_CTRL = true;
    Final_Simulink_Model_assignme_B.VENT_GND_CTRL = false;
    Final_Simulink_Model_assignme_B.VENT_PACE_CTRL = true;
    Final_Simulink_Model_assignme_B.PACING_REF_PWM = 20.0F *
      Final_Simulink_Model_assignme_B.VENT_Amplitude_a;
  } else if (*VENT_CMP_DETECT) {
    Final_Simulink_Model_assignm_DW.is_c7_Final_Simulink_Model_assi =
      Final_Simuli_IN_VVIR_REFRACTORY;
    Final_Simulink_Model_assignm_DW.temporalCounter_i1 = 0U;
    Final_Simulink_Model_assignme_B.FRONTEND_CTRL = false;
    Final_Simulink_Model_assignme_B.PACING_REF_PWM = 20.0F *
      Final_Simulink_Model_assignme_B.VENT_Amplitude_a;
    *PACE_CHARGE_CTRL = false;
    *PACE_GND_CTRL = true;
  }
}

/* Function for Chart: '<Root>/Chart1' */
static void Final_Simulink__VVIR_REFRACTORY(boolean_T *PACE_GND_CTRL, boolean_T *
  PACE_CHARGE_CTRL)
{
  Final_Simulink_Model_assignme_B.FRONTEND_CTRL = false;
  Final_Simulink_Model_assignme_B.VENT_GND_CTRL = true;
  *PACE_CHARGE_CTRL = false;
  *PACE_GND_CTRL = true;
  if ((uint32_T)((int32_T)Final_Simulink_Model_assignm_DW.temporalCounter_i1 *
                 10) >= Final_Simulink_Model_assignme_B.VRP_o) {
    Final_Simulink_Model_assignm_DW.is_c7_Final_Simulink_Model_assi =
      Final_Simulink_Model_as_IN_VVIR;
    Final_Simulink_Model_assignm_DW.temporalCounter_i1 = 0U;
    Final_Simulink_Model_assignme_B.FRONTEND_CTRL = true;
    Final_Simulink_Model_assignme_B.VENT_PACE_CTRL = false;
    *PACE_CHARGE_CTRL = true;
    *PACE_GND_CTRL = true;
    Final_Simulink_Model_assignme_B.PACING_REF_PWM = 20.0F *
      Final_Simulink_Model_assignme_B.VENT_Amplitude_a;
    Final_Simulink_Model_assignme_B.VENT_CMP_REF_PWM = 20.0F *
      Final_Simulink_Model_assignme_B.VENTSENSITIVITY_Amplitude_l;
  }
}

static void Final_Simu_SystemCore_setup_mmp(freedomk64f_SCIRead_Final_Sim_T *obj)
{
  obj->isInitialized = 1;
  Final_Simulink_Model_assignme_B.TxPinLoc = MW_UNDEFINED_VALUE;
  Final_Simulink_Model_assignme_B.SCIModuleLoc = 0;
  obj->MW_SCIHANDLE = MW_SCI_Open(&Final_Simulink_Model_assignme_B.SCIModuleLoc,
    false, 10U, Final_Simulink_Model_assignme_B.TxPinLoc);
  MW_SCI_SetBaudrate(obj->MW_SCIHANDLE, 115200U);
  Final_Simulink_Model_assignme_B.StopBitsValue = MW_SCI_STOPBITS_1;
  Final_Simulink_Model_assignme_B.ParityValue = MW_SCI_PARITY_NONE;
  MW_SCI_SetFrameFormat(obj->MW_SCIHANDLE, 8,
                        Final_Simulink_Model_assignme_B.ParityValue,
                        Final_Simulink_Model_assignme_B.StopBitsValue);
  obj->isSetupComplete = true;
}

static void Final_Simuli_SystemCore_setup_m(freedomk64f_fxos8700_Final_Si_T *obj)
{
  obj->isInitialized = 1;
  Final_Simulink_Model_assignme_B.ModeType = MW_I2C_MASTER;
  Final_Simulink_Model_assignme_B.i2cname = 0;
  obj->i2cobj.MW_I2C_HANDLE = MW_I2C_Open
    (Final_Simulink_Model_assignme_B.i2cname,
     Final_Simulink_Model_assignme_B.ModeType);
  obj->i2cobj.BusSpeed = 100000U;
  MW_I2C_SetBusSpeed(obj->i2cobj.MW_I2C_HANDLE, obj->i2cobj.BusSpeed);
  Final_Simulink_Model_assignme_B.b_SwappedDataBytes[0] = 43U;
  Final_Simulink_Model_assignme_B.b_SwappedDataBytes[1] = 64U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U,
                     &Final_Simulink_Model_assignme_B.b_SwappedDataBytes[0], 2U,
                     false, false);
  OSA_TimeDelay(500U);
  Final_Simulink_Model_assignme_B.status_b = 42U;
  Final_Simulink_Model_assignme_B.status_b = MW_I2C_MasterWrite
    (obj->i2cobj.MW_I2C_HANDLE, 29U, &Final_Simulink_Model_assignme_B.status_b,
     1U, true, false);
  if (Final_Simulink_Model_assignme_B.status_b == 0) {
    MW_I2C_MasterRead(obj->i2cobj.MW_I2C_HANDLE, 29U,
                      &Final_Simulink_Model_assignme_B.status_b, 1U, false, true);
    memcpy((void *)&Final_Simulink_Model_assignme_B.b_RegisterValue_c, (void *)
           &Final_Simulink_Model_assignme_B.status_b, (size_t)1 * sizeof(uint8_T));
  } else {
    Final_Simulink_Model_assignme_B.b_RegisterValue_c = 0U;
  }

  Final_Simulink_Model_assignme_B.b_SwappedDataBytes[0] = 42U;
  Final_Simulink_Model_assignme_B.b_SwappedDataBytes[1] = (uint8_T)
    (Final_Simulink_Model_assignme_B.b_RegisterValue_c & 254);
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U,
                     &Final_Simulink_Model_assignme_B.b_SwappedDataBytes[0], 2U,
                     false, false);
  Final_Simulink_Model_assignme_B.b_SwappedDataBytes[0] = 14U;
  Final_Simulink_Model_assignme_B.b_SwappedDataBytes[1] = 1U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U,
                     &Final_Simulink_Model_assignme_B.b_SwappedDataBytes[0], 2U,
                     false, false);
  Final_Simulink_Model_assignme_B.b_SwappedDataBytes[0] = 91U;
  Final_Simulink_Model_assignme_B.b_SwappedDataBytes[1] = 0U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U,
                     &Final_Simulink_Model_assignme_B.b_SwappedDataBytes[0], 2U,
                     false, false);
  Final_Simulink_Model_assignme_B.b_SwappedDataBytes[0] = 42U;
  Final_Simulink_Model_assignme_B.b_SwappedDataBytes[1] = 1U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U,
                     &Final_Simulink_Model_assignme_B.b_SwappedDataBytes[0], 2U,
                     false, false);
  obj->isSetupComplete = true;
}

static void Final_Simul_SystemCore_setup_mm(dsp_simulink_MovingStandardDe_T *obj)
{
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  obj->NumChannels = 1;
  obj->FrameLength = 1;
  obj->_pobj0.isInitialized = 0;
  obj->_pobj0.isInitialized = 0;
  obj->pStatistic = &obj->_pobj0;
  obj->isSetupComplete = true;
  obj->TunablePropsChanged = false;
}

/* Model step function for TID0 */
void Final_Simulink_Model_assignment_2_step0(void) /* Sample time: [0.001s, 0.0s] */
{
  {                                    /* Sample time: [0.001s, 0.0s] */
    rate_monotonic_scheduler();
  }
}

/* Model step function for TID1 */
void Final_Simulink_Model_assignment_2_step1(void) /* Sample time: [0.01s, 0.0s] */
{
  g_dsp_internal_SlidingWindowV_T *obj;

  /* MATLABSystem: '<Root>/Serial Receive1' */
  if (Final_Simulink_Model_assignm_DW.obj_j.SampleTime !=
      Final_Simulink_Model_assignme_P.SerialReceive1_SampleTime) {
    Final_Simulink_Model_assignm_DW.obj_j.SampleTime =
      Final_Simulink_Model_assignme_P.SerialReceive1_SampleTime;
  }

  Final_Simulink_Model_assignme_B.status = MW_SCI_Receive
    (Final_Simulink_Model_assignm_DW.obj_j.MW_SCIHANDLE,
     &Final_Simulink_Model_assignme_B.RxDataLocChar[0], 35U);
  memcpy((void *)&Final_Simulink_Model_assignme_B.RxData[0], (void *)
         &Final_Simulink_Model_assignme_B.RxDataLocChar[0], (size_t)35 * sizeof
         (uint8_T));

  /* Chart: '<Root>/COM_IN1' incorporates:
   *  MATLABSystem: '<Root>/Serial Receive1'
   */
  switch (Final_Simulink_Model_assignm_DW.is_c6_Final_Simulink_Model_assi) {
   case Final_Simulink_Mo_IN_ECHO_PARAM:
    Final_Simulink_Model_assignm_DW.is_c6_Final_Simulink_Model_assi =
      Final_Simulink_Model_IN_STANDBY;
    break;

   case Final_Simulink_Mo_IN_Initialize:
    Final_Simulink_Model_assignm_DW.is_c6_Final_Simulink_Model_assi =
      Final_Simulink_Model_IN_STANDBY;
    break;

   case Final_Simulink_Mod_IN_SET_PARAM:
    Final_Simulink_Model_assignm_DW.is_c6_Final_Simulink_Model_assi =
      Final_Simulink_Model_IN_STANDBY;
    break;

   default:
    /* case IN_STANDBY: */
    if (Final_Simulink_Model_assignme_B.status == 0) {
      if (Final_Simulink_Model_assignme_B.RxData[0] == 22) {
        switch (Final_Simulink_Model_assignme_B.RxData[1]) {
         case 85:
          Final_Simulink_Model_assignm_DW.is_c6_Final_Simulink_Model_assi =
            Final_Simulink_Mod_IN_SET_PARAM;
          Final_Simulink_Model_assignme_B.mode =
            Final_Simulink_Model_assignme_B.RxData[2];
          Final_Simulink_Model_assignme_B.LRL =
            Final_Simulink_Model_assignme_B.RxData[3];
          Final_Simulink_Model_assignme_B.URL =
            Final_Simulink_Model_assignme_B.RxData[4];
          memcpy((void *)&Final_Simulink_Model_assignme_B.VENT_Amplitude_a,
                 (void *)&Final_Simulink_Model_assignme_B.RxData[5], (size_t)1 *
                 sizeof(real32_T));
          memcpy((void *)&Final_Simulink_Model_assignme_B.ATR_Amplitude_m, (void
                  *)&Final_Simulink_Model_assignme_B.RxData[9], (size_t)1 *
                 sizeof(real32_T));
          Final_Simulink_Model_assignme_B.VENT_PULSE_WIDTH =
            Final_Simulink_Model_assignme_B.RxData[13];
          Final_Simulink_Model_assignme_B.ATR_PULSE_WIDTH =
            Final_Simulink_Model_assignme_B.RxData[14];
          memcpy((void *)
                 &Final_Simulink_Model_assignme_B.VENTSENSITIVITY_Amplitude_l,
                 (void *)&Final_Simulink_Model_assignme_B.RxData[15], (size_t)1 *
                 sizeof(real32_T));
          memcpy((void *)
                 &Final_Simulink_Model_assignme_B.ATRSENSITIVITY_Amplitude_p,
                 (void *)&Final_Simulink_Model_assignme_B.RxData[19], (size_t)1 *
                 sizeof(real32_T));
          memcpy((void *)&Final_Simulink_Model_assignme_B.ARP_l, (void *)
                 &Final_Simulink_Model_assignme_B.RxData[23], (size_t)1 * sizeof
                 (uint16_T));
          memcpy((void *)&Final_Simulink_Model_assignme_B.VRP_o, (void *)
                 &Final_Simulink_Model_assignme_B.RxData[25], (size_t)1 * sizeof
                 (uint16_T));
          Final_Simulink_Model_assignme_B.MSR =
            Final_Simulink_Model_assignme_B.RxData[27];
          memcpy((void *)&Final_Simulink_Model_assignme_B.Activity_threshold_d,
                 (void *)&Final_Simulink_Model_assignme_B.RxData[28], (size_t)1 *
                 sizeof(real32_T));
          Final_Simulink_Model_assignme_B.Response_Factor =
            Final_Simulink_Model_assignme_B.RxData[32];
          Final_Simulink_Model_assignme_B.Reaction_time_d =
            Final_Simulink_Model_assignme_B.RxData[33];
          Final_Simulink_Model_assignme_B.Recovery_time_d =
            Final_Simulink_Model_assignme_B.RxData[34];
          break;

         case 34:
          Final_Simulink_Model_assignm_DW.is_c6_Final_Simulink_Model_assi =
            Final_Simulink_Mo_IN_ECHO_PARAM;
          send_params();
          break;

         default:
          Final_Simulink_Model_assignm_DW.is_c6_Final_Simulink_Model_assi =
            Final_Simulink_Model_IN_STANDBY;
          break;
        }
      } else {
        Final_Simulink_Model_assignm_DW.is_c6_Final_Simulink_Model_assi =
          Final_Simulink_Model_IN_STANDBY;
      }
    }
    break;
  }

  /* End of Chart: '<Root>/COM_IN1' */

  /* MATLABSystem: '<S1>/FXOS8700 6-Axes Sensor' */
  if (Final_Simulink_Model_assignm_DW.obj_b.SampleTime !=
      Final_Simulink_Model_assignme_P.FXOS87006AxesSensor_SampleTime) {
    Final_Simulink_Model_assignm_DW.obj_b.SampleTime =
      Final_Simulink_Model_assignme_P.FXOS87006AxesSensor_SampleTime;
  }

  Final_Simulink_Model_assignme_B.status = 1U;
  Final_Simulink_Model_assignme_B.status = MW_I2C_MasterWrite
    (Final_Simulink_Model_assignm_DW.obj_b.i2cobj.MW_I2C_HANDLE, 29U,
     &Final_Simulink_Model_assignme_B.status, 1U, true, false);
  if (Final_Simulink_Model_assignme_B.status == 0) {
    MW_I2C_MasterRead(Final_Simulink_Model_assignm_DW.obj_b.i2cobj.MW_I2C_HANDLE,
                      29U, &Final_Simulink_Model_assignme_B.output_raw[0], 6U,
                      false, true);
    memcpy((void *)&Final_Simulink_Model_assignme_B.b_RegisterValue[0], (void *)
           &Final_Simulink_Model_assignme_B.output_raw[0], (size_t)3 * sizeof
           (int16_T));
    memcpy((void *)&Final_Simulink_Model_assignme_B.y[0], (void *)
           &Final_Simulink_Model_assignme_B.b_RegisterValue[0], (size_t)2 *
           sizeof(uint8_T));
    Final_Simulink_Model_assignme_B.b_x[0] = Final_Simulink_Model_assignme_B.y[1];
    Final_Simulink_Model_assignme_B.b_x[1] = Final_Simulink_Model_assignme_B.y[0];
    memcpy((void *)&Final_Simulink_Model_assignme_B.b_RegisterValue[0], (void *)
           &Final_Simulink_Model_assignme_B.b_x[0], (size_t)1 * sizeof(int16_T));
    memcpy((void *)&Final_Simulink_Model_assignme_B.y[0], (void *)
           &Final_Simulink_Model_assignme_B.b_RegisterValue[1], (size_t)2 *
           sizeof(uint8_T));
    Final_Simulink_Model_assignme_B.b_x[0] = Final_Simulink_Model_assignme_B.y[1];
    Final_Simulink_Model_assignme_B.b_x[1] = Final_Simulink_Model_assignme_B.y[0];
    memcpy((void *)&Final_Simulink_Model_assignme_B.b_RegisterValue[1], (void *)
           &Final_Simulink_Model_assignme_B.b_x[0], (size_t)1 * sizeof(int16_T));
    memcpy((void *)&Final_Simulink_Model_assignme_B.y[0], (void *)
           &Final_Simulink_Model_assignme_B.b_RegisterValue[2], (size_t)2 *
           sizeof(uint8_T));
    Final_Simulink_Model_assignme_B.b_x[0] = Final_Simulink_Model_assignme_B.y[1];
    Final_Simulink_Model_assignme_B.b_x[1] = Final_Simulink_Model_assignme_B.y[0];
    memcpy((void *)&Final_Simulink_Model_assignme_B.b_RegisterValue[2], (void *)
           &Final_Simulink_Model_assignme_B.b_x[0], (size_t)1 * sizeof(int16_T));
  } else {
    Final_Simulink_Model_assignme_B.b_RegisterValue[0] = 0;
    Final_Simulink_Model_assignme_B.b_RegisterValue[1] = 0;
    Final_Simulink_Model_assignme_B.b_RegisterValue[2] = 0;
  }

  Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_0 = (real_T)
    (int16_T)(Final_Simulink_Model_assignme_B.b_RegisterValue[0] >> 2) * 2.0 *
    0.244 / 1000.0;
  Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_1 = (real_T)
    (int16_T)(Final_Simulink_Model_assignme_B.b_RegisterValue[1] >> 2) * 2.0 *
    0.244 / 1000.0;
  Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_2 = (real_T)
    (int16_T)(Final_Simulink_Model_assignme_B.b_RegisterValue[2] >> 2) * 2.0 *
    0.244 / 1000.0;

  /* End of MATLABSystem: '<S1>/FXOS8700 6-Axes Sensor' */

  /* Sqrt: '<S1>/Sqrt' incorporates:
   *  Math: '<S1>/Math Function'
   *  Math: '<S1>/Math Function1'
   *  Math: '<S1>/Math Function2'
   *  Sum: '<S1>/Add'
   *
   * About '<S1>/Math Function':
   *  Operator: magnitude^2
   *
   * About '<S1>/Math Function1':
   *  Operator: magnitude^2
   *
   * About '<S1>/Math Function2':
   *  Operator: magnitude^2
   */
  Final_Simulink_Model_assignme_B.Sqrt = sqrt
    ((Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_0 *
      Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_0 +
      Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_1 *
      Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_1) +
     Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_2 *
     Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_2);

  /* MATLABSystem: '<S1>/Moving Standard Deviation' */
  if (Final_Simulink_Model_assignm_DW.obj.TunablePropsChanged) {
    Final_Simulink_Model_assignm_DW.obj.TunablePropsChanged = false;
  }

  obj = Final_Simulink_Model_assignm_DW.obj.pStatistic;
  if (obj->isInitialized != 1) {
    obj->isSetupComplete = false;
    obj->isInitialized = 1;
    for (Final_Simulink_Model_assignme_B.i = 0;
         Final_Simulink_Model_assignme_B.i < 400;
         Final_Simulink_Model_assignme_B.i++) {
      obj->pReverseSamples[Final_Simulink_Model_assignme_B.i] = 0.0;
    }

    for (Final_Simulink_Model_assignme_B.i = 0;
         Final_Simulink_Model_assignme_B.i < 400;
         Final_Simulink_Model_assignme_B.i++) {
      obj->pReverseT[Final_Simulink_Model_assignme_B.i] = 0.0;
    }

    for (Final_Simulink_Model_assignme_B.i = 0;
         Final_Simulink_Model_assignme_B.i < 400;
         Final_Simulink_Model_assignme_B.i++) {
      obj->pReverseS[Final_Simulink_Model_assignme_B.i] = 0.0;
    }

    obj->pT = 0.0;
    obj->pS = 0.0;
    obj->pM = 0.0;
    obj->pCounter = 0.0;
    obj->pModValueRev = 0.0;
    obj->isSetupComplete = true;
    for (Final_Simulink_Model_assignme_B.i = 0;
         Final_Simulink_Model_assignme_B.i < 400;
         Final_Simulink_Model_assignme_B.i++) {
      obj->pReverseSamples[Final_Simulink_Model_assignme_B.i] = 0.0;
    }

    for (Final_Simulink_Model_assignme_B.i = 0;
         Final_Simulink_Model_assignme_B.i < 400;
         Final_Simulink_Model_assignme_B.i++) {
      obj->pReverseT[Final_Simulink_Model_assignme_B.i] = 0.0;
    }

    for (Final_Simulink_Model_assignme_B.i = 0;
         Final_Simulink_Model_assignme_B.i < 400;
         Final_Simulink_Model_assignme_B.i++) {
      obj->pReverseS[Final_Simulink_Model_assignme_B.i] = 0.0;
    }

    obj->pT = 0.0;
    obj->pS = 0.0;
    obj->pM = 0.0;
    obj->pCounter = 1.0;
    obj->pModValueRev = 0.0;
  }

  for (Final_Simulink_Model_assignme_B.i = 0; Final_Simulink_Model_assignme_B.i <
       400; Final_Simulink_Model_assignme_B.i++) {
    Final_Simulink_Model_assignme_B.reverseSamples[Final_Simulink_Model_assignme_B.i]
      = obj->pReverseSamples[Final_Simulink_Model_assignme_B.i];
  }

  for (Final_Simulink_Model_assignme_B.i = 0; Final_Simulink_Model_assignme_B.i <
       400; Final_Simulink_Model_assignme_B.i++) {
    Final_Simulink_Model_assignme_B.x[Final_Simulink_Model_assignme_B.i] =
      obj->pReverseT[Final_Simulink_Model_assignme_B.i];
  }

  for (Final_Simulink_Model_assignme_B.i = 0; Final_Simulink_Model_assignme_B.i <
       400; Final_Simulink_Model_assignme_B.i++) {
    Final_Simulink_Model_assignme_B.reverseS[Final_Simulink_Model_assignme_B.i] =
      obj->pReverseS[Final_Simulink_Model_assignme_B.i];
  }

  Final_Simulink_Model_assignme_B.T = obj->pT;
  Final_Simulink_Model_assignme_B.S = obj->pS;
  Final_Simulink_Model_assignme_B.M = obj->pM;
  Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_0 = obj->pCounter;
  Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_1 =
    obj->pModValueRev;
  Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_2 = 0.0;
  Final_Simulink_Model_assignme_B.T += Final_Simulink_Model_assignme_B.Sqrt;
  Final_Simulink_Model_assignme_B.Mprev = Final_Simulink_Model_assignme_B.M;
  Final_Simulink_Model_assignme_B.M += 1.0 /
    Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_0 *
    (Final_Simulink_Model_assignme_B.Sqrt - Final_Simulink_Model_assignme_B.M);
  Final_Simulink_Model_assignme_B.Mprev = Final_Simulink_Model_assignme_B.Sqrt -
    Final_Simulink_Model_assignme_B.Mprev;
  Final_Simulink_Model_assignme_B.S +=
    (Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_0 - 1.0) *
    Final_Simulink_Model_assignme_B.Mprev *
    Final_Simulink_Model_assignme_B.Mprev /
    Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_0;
  if (Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_1 == 0.0) {
    Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_2 = (400.0 -
      Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_0) /
      Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_0 *
      Final_Simulink_Model_assignme_B.T - Final_Simulink_Model_assignme_B.x
      [(int32_T)(400.0 -
                 Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_0)
      - 1];
    Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_2 =
      (Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_0 / (((400.0
          - Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_0) +
         Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_0) * (400.0
         - Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_0)) *
       (Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_2 *
        Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_2) +
       (Final_Simulink_Model_assignme_B.reverseS[(int32_T)(400.0 -
         Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_0) - 1] +
        Final_Simulink_Model_assignme_B.S)) / 399.0;
  }

  Final_Simulink_Model_assignme_B.reverseSamples[(int32_T)(400.0 -
    Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_0) - 1] =
    Final_Simulink_Model_assignme_B.Sqrt;
  if (Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_0 < 399.0) {
    Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_0++;
  } else {
    Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_0 = 1.0;
    memcpy(&Final_Simulink_Model_assignme_B.x[0],
           &Final_Simulink_Model_assignme_B.reverseSamples[0], 400U * sizeof
           (real_T));
    Final_Simulink_Model_assignme_B.Sqrt = 0.0;
    Final_Simulink_Model_assignme_B.T = 0.0;
    for (Final_Simulink_Model_assignme_B.i = 0;
         Final_Simulink_Model_assignme_B.i < 399;
         Final_Simulink_Model_assignme_B.i++) {
      Final_Simulink_Model_assignme_B.S =
        Final_Simulink_Model_assignme_B.reverseSamples[Final_Simulink_Model_assignme_B.i];
      Final_Simulink_Model_assignme_B.x[Final_Simulink_Model_assignme_B.i + 1] +=
        Final_Simulink_Model_assignme_B.x[Final_Simulink_Model_assignme_B.i];
      Final_Simulink_Model_assignme_B.M = Final_Simulink_Model_assignme_B.Sqrt;
      Final_Simulink_Model_assignme_B.Sqrt += 1.0 / ((real_T)
        Final_Simulink_Model_assignme_B.i + 1.0) *
        (Final_Simulink_Model_assignme_B.S -
         Final_Simulink_Model_assignme_B.Sqrt);
      Final_Simulink_Model_assignme_B.S -= Final_Simulink_Model_assignme_B.M;
      Final_Simulink_Model_assignme_B.T += (((real_T)
        Final_Simulink_Model_assignme_B.i + 1.0) - 1.0) *
        Final_Simulink_Model_assignme_B.S * Final_Simulink_Model_assignme_B.S /
        ((real_T)Final_Simulink_Model_assignme_B.i + 1.0);
      Final_Simulink_Model_assignme_B.reverseS[Final_Simulink_Model_assignme_B.i]
        = Final_Simulink_Model_assignme_B.T;
    }

    Final_Simulink_Model_assignme_B.T = 0.0;
    Final_Simulink_Model_assignme_B.S = 0.0;
    Final_Simulink_Model_assignme_B.M = 0.0;
  }

  for (Final_Simulink_Model_assignme_B.i = 0; Final_Simulink_Model_assignme_B.i <
       400; Final_Simulink_Model_assignme_B.i++) {
    obj->pReverseSamples[Final_Simulink_Model_assignme_B.i] =
      Final_Simulink_Model_assignme_B.reverseSamples[Final_Simulink_Model_assignme_B.i];
  }

  for (Final_Simulink_Model_assignme_B.i = 0; Final_Simulink_Model_assignme_B.i <
       400; Final_Simulink_Model_assignme_B.i++) {
    obj->pReverseT[Final_Simulink_Model_assignme_B.i] =
      Final_Simulink_Model_assignme_B.x[Final_Simulink_Model_assignme_B.i];
  }

  for (Final_Simulink_Model_assignme_B.i = 0; Final_Simulink_Model_assignme_B.i <
       400; Final_Simulink_Model_assignme_B.i++) {
    obj->pReverseS[Final_Simulink_Model_assignme_B.i] =
      Final_Simulink_Model_assignme_B.reverseS[Final_Simulink_Model_assignme_B.i];
  }

  obj->pT = Final_Simulink_Model_assignme_B.T;
  obj->pS = Final_Simulink_Model_assignme_B.S;
  obj->pM = Final_Simulink_Model_assignme_B.M;
  obj->pCounter = Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_0;
  if (Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_1 > 0.0) {
    obj->pModValueRev =
      Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_1 - 1.0;
  } else {
    obj->pModValueRev = 0.0;
  }

  Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_0 = sqrt
    (Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_2);

  /* End of MATLABSystem: '<S1>/Moving Standard Deviation' */

  /* Chart: '<Root>/Find the desired rate for pacing1' */
  if (Final_Simulink_Model_assignm_DW.temporalCounter_i1_b < 31U) {
    Final_Simulink_Model_assignm_DW.temporalCounter_i1_b++;
  }

  if (Final_Simulink_Model_assignm_DW.is_active_c8_Final_Simulink_Mod == 0U) {
    Final_Simulink_Model_assignm_DW.is_active_c8_Final_Simulink_Mod = 1U;
    Final_Simulink_Model_assignm_DW.is_c8_Final_Simulink_Model_assi =
      Final_Simulink_Model_a_IN_Check;
  } else {
    switch (Final_Simulink_Model_assignm_DW.is_c8_Final_Simulink_Model_assi) {
     case Final_Simulink_Model_a_IN_Check:
      if (Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_0 >
          Final_Simulink_Model_assignme_B.Activity_threshold_d) {
        Final_Simulink_Model_assignm_DW.is_c8_Final_Simulink_Model_assi =
          Final_Simuli_IN_Linear_increase;
        Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_0 =
          rt_roundd_snf
          ((Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_0 -
            Final_Simulink_Model_assignme_B.Activity_threshold_d) * (real_T)
           Final_Simulink_Model_assignme_B.Response_Factor);
        if (Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_0 <
            256.0) {
          if (Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_0 >=
              0.0) {
            Final_Simulink_Model_assignme_B.status = (uint8_T)
              Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_0;
          } else {
            Final_Simulink_Model_assignme_B.status = 0U;
          }
        } else {
          Final_Simulink_Model_assignme_B.status = MAX_uint8_T;
        }

        Final_Simulink_Model_assignme_B.i = (int32_T)((uint32_T)
          Final_Simulink_Model_assignme_B.LRL +
          Final_Simulink_Model_assignme_B.status);
        if ((uint32_T)Final_Simulink_Model_assignme_B.i > 255U) {
          Final_Simulink_Model_assignme_B.i = 255;
        }

        Final_Simulink_Model_assignm_DW.temp_rate = (uint8_T)
          Final_Simulink_Model_assignme_B.i;
      } else if (Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_0 <=
                 Final_Simulink_Model_assignme_B.Activity_threshold_d) {
        Final_Simulink_Model_assignm_DW.is_c8_Final_Simulink_Model_assi =
          Final__IN_Desired_rate_output_3;
        Final_Simulink_Model_assignm_DW.temporalCounter_i1_b = 0U;
        Final_Simulink_Model_assignme_B.Desired_rate =
          Final_Simulink_Model_assignme_B.LRL;
      }
      break;

     case Final__IN_Desired_rate_output_1:
      if (Final_Simulink_Model_assignm_DW.temporalCounter_i1_b >= 30U) {
        Final_Simulink_Model_assignm_DW.is_c8_Final_Simulink_Model_assi =
          Final_Simulink_Model_a_IN_Check;
      }
      break;

     case Final__IN_Desired_rate_output_2:
      if (Final_Simulink_Model_assignm_DW.temporalCounter_i1_b >= 30U) {
        Final_Simulink_Model_assignm_DW.is_c8_Final_Simulink_Model_assi =
          Final_Simulink_Model_a_IN_Check;
      }
      break;

     case Final__IN_Desired_rate_output_3:
      if (Final_Simulink_Model_assignm_DW.temporalCounter_i1_b >= 30U) {
        Final_Simulink_Model_assignm_DW.is_c8_Final_Simulink_Model_assi =
          Final_Simulink_Model_a_IN_Check;
      }
      break;

     default:
      /* case IN_Linear_increase: */
      if (Final_Simulink_Model_assignm_DW.temp_rate <
          Final_Simulink_Model_assignme_B.MSR) {
        Final_Simulink_Model_assignm_DW.is_c8_Final_Simulink_Model_assi =
          Final__IN_Desired_rate_output_1;
        Final_Simulink_Model_assignm_DW.temporalCounter_i1_b = 0U;
        Final_Simulink_Model_assignme_B.Desired_rate =
          Final_Simulink_Model_assignm_DW.temp_rate;
      } else if (Final_Simulink_Model_assignm_DW.temp_rate >=
                 Final_Simulink_Model_assignme_B.MSR) {
        Final_Simulink_Model_assignm_DW.is_c8_Final_Simulink_Model_assi =
          Final__IN_Desired_rate_output_2;
        Final_Simulink_Model_assignm_DW.temporalCounter_i1_b = 0U;
        Final_Simulink_Model_assignme_B.Desired_rate =
          Final_Simulink_Model_assignme_B.MSR;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Find the desired rate for pacing1' */

  /* Chart: '<Root>/Find the pacing rate1' */
  if (Final_Simulink_Model_assignm_DW.temporalCounter_i1_l < 31U) {
    Final_Simulink_Model_assignm_DW.temporalCounter_i1_l++;
  }

  if (Final_Simulink_Model_assignm_DW.is_active_c9_Final_Simulink_Mod == 0U) {
    Final_Simulink_Model_assignm_DW.is_active_c9_Final_Simulink_Mod = 1U;
    Final_Simulink_Model_assignm_DW.is_c9_Final_Simulink_Model_assi =
      Final_Simulink_IN_Initial_state;
    Final_Simulink_Model_assignme_B.rate = Final_Simulink_Model_assignme_B.LRL;
  } else {
    switch (Final_Simulink_Model_assignm_DW.is_c9_Final_Simulink_Model_assi) {
     case Final_Simulink_Mo_IN_Decreasing:
      if (Final_Simulink_Model_assignm_DW.temporalCounter_i1_l >= 30U) {
        Final_Simulink_Model_assignm_DW.is_c9_Final_Simulink_Model_assi =
          Final_Simulink_Model_a_IN_Steps;
        Final_Simulink_Model_assignm_DW.temporalCounter_i1_l = 0U;
        Final_Simulink_Model_assignme_B.qY_tmp = (uint32_T)
          Final_Simulink_Model_assignme_B.MSR - /*MW:OvSatOk*/
          Final_Simulink_Model_assignme_B.LRL;
        Final_Simulink_Model_assignme_B.qY =
          Final_Simulink_Model_assignme_B.qY_tmp;
        if (Final_Simulink_Model_assignme_B.qY_tmp >
            Final_Simulink_Model_assignme_B.MSR) {
          Final_Simulink_Model_assignme_B.qY = 0U;
        }

        Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_0 =
          rt_roundd_snf((real_T)(int32_T)Final_Simulink_Model_assignme_B.qY /
                        (real_T)Final_Simulink_Model_assignme_B.Reaction_time_d);
        if (Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_0 <
            256.0) {
          Final_Simulink_Model_assignm_DW.addition = (uint8_T)
            Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_0;
        } else {
          Final_Simulink_Model_assignm_DW.addition = MAX_uint8_T;
        }

        if (Final_Simulink_Model_assignme_B.qY_tmp >
            Final_Simulink_Model_assignme_B.MSR) {
          Final_Simulink_Model_assignme_B.qY_tmp = 0U;
        }

        Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_0 =
          rt_roundd_snf((real_T)(int32_T)Final_Simulink_Model_assignme_B.qY_tmp /
                        (real_T)Final_Simulink_Model_assignme_B.Recovery_time_d);
        if (Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_0 <
            256.0) {
          Final_Simulink_Model_assignm_DW.substruction = (uint8_T)
            Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_0;
        } else {
          Final_Simulink_Model_assignm_DW.substruction = MAX_uint8_T;
        }
      }
      break;

     case Final_Simulink_Mo_IN_Increasing:
      if (Final_Simulink_Model_assignm_DW.temporalCounter_i1_l >= 30U) {
        Final_Simulink_Model_assignm_DW.is_c9_Final_Simulink_Model_assi =
          Final_Simulink_Model_a_IN_Steps;
        Final_Simulink_Model_assignm_DW.temporalCounter_i1_l = 0U;
        Final_Simulink_Model_assignme_B.qY_tmp = (uint32_T)
          Final_Simulink_Model_assignme_B.MSR - /*MW:OvSatOk*/
          Final_Simulink_Model_assignme_B.LRL;
        Final_Simulink_Model_assignme_B.qY =
          Final_Simulink_Model_assignme_B.qY_tmp;
        if (Final_Simulink_Model_assignme_B.qY_tmp >
            Final_Simulink_Model_assignme_B.MSR) {
          Final_Simulink_Model_assignme_B.qY = 0U;
        }

        Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_0 =
          rt_roundd_snf((real_T)(int32_T)Final_Simulink_Model_assignme_B.qY /
                        (real_T)Final_Simulink_Model_assignme_B.Reaction_time_d);
        if (Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_0 <
            256.0) {
          Final_Simulink_Model_assignm_DW.addition = (uint8_T)
            Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_0;
        } else {
          Final_Simulink_Model_assignm_DW.addition = MAX_uint8_T;
        }

        if (Final_Simulink_Model_assignme_B.qY_tmp >
            Final_Simulink_Model_assignme_B.MSR) {
          Final_Simulink_Model_assignme_B.qY_tmp = 0U;
        }

        Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_0 =
          rt_roundd_snf((real_T)(int32_T)Final_Simulink_Model_assignme_B.qY_tmp /
                        (real_T)Final_Simulink_Model_assignme_B.Recovery_time_d);
        if (Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_0 <
            256.0) {
          Final_Simulink_Model_assignm_DW.substruction = (uint8_T)
            Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_0;
        } else {
          Final_Simulink_Model_assignm_DW.substruction = MAX_uint8_T;
        }
      }
      break;

     case Final_Simulink_IN_Initial_state:
      Final_Simulink_Model_assignm_DW.is_c9_Final_Simulink_Model_assi =
        Final_Simulink_Model_a_IN_Steps;
      Final_Simulink_Model_assignm_DW.temporalCounter_i1_l = 0U;
      Final_Simulink_Model_assignme_B.qY_tmp = (uint32_T)
        Final_Simulink_Model_assignme_B.MSR - /*MW:OvSatOk*/
        Final_Simulink_Model_assignme_B.LRL;
      Final_Simulink_Model_assignme_B.qY =
        Final_Simulink_Model_assignme_B.qY_tmp;
      if (Final_Simulink_Model_assignme_B.qY_tmp >
          Final_Simulink_Model_assignme_B.MSR) {
        Final_Simulink_Model_assignme_B.qY = 0U;
      }

      Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_0 =
        rt_roundd_snf((real_T)(int32_T)Final_Simulink_Model_assignme_B.qY /
                      (real_T)Final_Simulink_Model_assignme_B.Reaction_time_d);
      if (Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_0 < 256.0)
      {
        Final_Simulink_Model_assignm_DW.addition = (uint8_T)
          Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_0;
      } else {
        Final_Simulink_Model_assignm_DW.addition = MAX_uint8_T;
      }

      if (Final_Simulink_Model_assignme_B.qY_tmp >
          Final_Simulink_Model_assignme_B.MSR) {
        Final_Simulink_Model_assignme_B.qY_tmp = 0U;
      }

      Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_0 =
        rt_roundd_snf((real_T)(int32_T)Final_Simulink_Model_assignme_B.qY_tmp /
                      (real_T)Final_Simulink_Model_assignme_B.Recovery_time_d);
      if (Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_0 < 256.0)
      {
        Final_Simulink_Model_assignm_DW.substruction = (uint8_T)
          Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_0;
      } else {
        Final_Simulink_Model_assignm_DW.substruction = MAX_uint8_T;
      }
      break;

     default:
      /* case IN_Steps: */
      if ((Final_Simulink_Model_assignm_DW.temporalCounter_i1_l >= 30U) &&
          (Final_Simulink_Model_assignme_B.rate >
           Final_Simulink_Model_assignme_B.Desired_rate)) {
        Final_Simulink_Model_assignm_DW.is_c9_Final_Simulink_Model_assi =
          Final_Simulink_Mo_IN_Decreasing;
        Final_Simulink_Model_assignm_DW.temporalCounter_i1_l = 0U;
        if (Final_Simulink_Model_assignme_B.rate <
            Final_Simulink_Model_assignme_B.MSR) {
          Final_Simulink_Model_assignme_B.qY = (uint32_T)
            Final_Simulink_Model_assignme_B.rate - /*MW:OvSatOk*/
            Final_Simulink_Model_assignm_DW.substruction;
          if (Final_Simulink_Model_assignme_B.qY >
              Final_Simulink_Model_assignme_B.rate) {
            Final_Simulink_Model_assignme_B.qY = 0U;
          }

          Final_Simulink_Model_assignme_B.rate = (uint8_T)
            Final_Simulink_Model_assignme_B.qY;
        } else if (Final_Simulink_Model_assignme_B.rate <=
                   Final_Simulink_Model_assignme_B.LRL) {
          Final_Simulink_Model_assignme_B.rate =
            Final_Simulink_Model_assignme_B.LRL;
        }
      } else if (Final_Simulink_Model_assignm_DW.temporalCounter_i1_l >= 30U) {
        Final_Simulink_Model_assignm_DW.is_c9_Final_Simulink_Model_assi =
          Final_Simulink_Mo_IN_Increasing;
        Final_Simulink_Model_assignm_DW.temporalCounter_i1_l = 0U;
        if ((Final_Simulink_Model_assignme_B.rate <
             Final_Simulink_Model_assignme_B.MSR) &&
            (Final_Simulink_Model_assignme_B.rate <
             Final_Simulink_Model_assignme_B.Desired_rate)) {
          Final_Simulink_Model_assignme_B.i = (int32_T)((uint32_T)
            Final_Simulink_Model_assignme_B.rate +
            Final_Simulink_Model_assignm_DW.addition);
          if ((uint32_T)Final_Simulink_Model_assignme_B.i > 255U) {
            Final_Simulink_Model_assignme_B.i = 255;
          }

          Final_Simulink_Model_assignme_B.rate = (uint8_T)
            Final_Simulink_Model_assignme_B.i;
        } else if (Final_Simulink_Model_assignme_B.rate ==
                   Final_Simulink_Model_assignme_B.Desired_rate) {
          Final_Simulink_Model_assignme_B.rate =
            Final_Simulink_Model_assignme_B.Desired_rate;
        } else if (Final_Simulink_Model_assignme_B.rate >=
                   Final_Simulink_Model_assignme_B.MSR) {
          Final_Simulink_Model_assignme_B.rate =
            Final_Simulink_Model_assignme_B.MSR;
        }
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Find the pacing rate1' */

  /* MATLABSystem: '<S7>/VENT_CMP_DETECT' */
  if (Final_Simulink_Model_assignm_DW.obj_b0.SampleTime !=
      Final_Simulink_Model_assignme_P.VENT_CMP_DETECT_SampleTime) {
    Final_Simulink_Model_assignm_DW.obj_b0.SampleTime =
      Final_Simulink_Model_assignme_P.VENT_CMP_DETECT_SampleTime;
  }

  Final_Simulink_Model_assignme_B.b = MW_digitalIO_read
    (Final_Simulink_Model_assignm_DW.obj_b0.MW_DIGITALIO_HANDLE);

  /* MATLABSystem: '<S7>/ATR_CMP_DETECT' */
  if (Final_Simulink_Model_assignm_DW.obj_bh.SampleTime !=
      Final_Simulink_Model_assignme_P.ATR_CMP_DETECT_SampleTime) {
    Final_Simulink_Model_assignm_DW.obj_bh.SampleTime =
      Final_Simulink_Model_assignme_P.ATR_CMP_DETECT_SampleTime;
  }

  Final_Simulink_Model_assignme_B.b1 = MW_digitalIO_read
    (Final_Simulink_Model_assignm_DW.obj_bh.MW_DIGITALIO_HANDLE);

  /* Chart: '<Root>/Chart1' incorporates:
   *  MATLABSystem: '<S7>/ATR_CMP_DETECT'
   *  MATLABSystem: '<S7>/VENT_CMP_DETECT'
   */
  if (Final_Simulink_Model_assignm_DW.temporalCounter_i1 < MAX_uint32_T) {
    Final_Simulink_Model_assignm_DW.temporalCounter_i1++;
  }

  if (Final_Simulink_Model_assignm_DW.is_active_c7_Final_Simulink_Mod == 0U) {
    Final_Simulink_Model_assignm_DW.is_active_c7_Final_Simulink_Mod = 1U;
    Final_Simulink_Model_assignm_DW.is_c7_Final_Simulink_Model_assi =
      Final_Simulink_Model_as_IN_MAIN;
    Final_Simulink_Model_assignme_B.VENT_GND_CTRL = false;
    Final_Simulink_Model_assignme_B.Z_ATR_CTRL = false;
    Final_Simulink_Model_assignme_B.Z_VENT_CTRL = false;
    Final_Simulink_Model_assignme_B.FRONTEND_CTRL = false;
    Final_Simulink_Model_assignme_B.PACE_CHARGE_CTRL = false;
    Final_Simulink_Model_assignme_B.VENT_PACE_CTRL = false;
    Final_Simulink_Model_assignme_B.ATR_PACE_CTRL = false;
    Final_Simulink_Model_assignme_B.PACE_GND_CTRL = false;
    Final_Simulink_Model_assignme_B.ATR_GND_CTRL = false;
  } else {
    switch (Final_Simulink_Model_assignm_DW.is_c7_Final_Simulink_Model_assi) {
     case Final_Simulink_Model_ass_IN_AAI:
      Final_Simulink_Model_assign_AAI
        (&Final_Simulink_Model_assignme_B.PACE_GND_CTRL,
         &Final_Simulink_Model_assignme_B.PACE_CHARGE_CTRL,
         &Final_Simulink_Model_assignme_B.b1);
      break;

     case Final_Simulink_Model_as_IN_AAIR:
      Final_Simulink_Model_assig_AAIR
        (&Final_Simulink_Model_assignme_B.PACE_GND_CTRL,
         &Final_Simulink_Model_assignme_B.PACE_CHARGE_CTRL,
         &Final_Simulink_Model_assignme_B.b1);
      break;

     case Final_Simuli_IN_AAIR_REFRACTORY:
      Final_Simulink__AAIR_REFRACTORY
        (&Final_Simulink_Model_assignme_B.PACE_GND_CTRL,
         &Final_Simulink_Model_assignme_B.PACE_CHARGE_CTRL);
      break;

     case Final_Simulin_IN_AAI_REFRACTORY:
      Final_Simulink_M_AAI_REFRACTORY
        (&Final_Simulink_Model_assignme_B.PACE_GND_CTRL,
         &Final_Simulink_Model_assignme_B.PACE_CHARGE_CTRL);
      break;

     case Final_Simulink_Model_ass_IN_AOO:
      Final_Simulink_Model_assignme_B.ATR_PACE_CTRL = false;
      Final_Simulink_Model_assignme_B.PACE_CHARGE_CTRL = true;
      Final_Simulink_Model_assignme_B.ATR_GND_CTRL = true;
      Final_Simulink_Model_assignme_B.PACE_GND_CTRL = true;
      Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_0 =
        rt_roundd_snf(60000.0 / (real_T)Final_Simulink_Model_assignme_B.LRL);
      if (Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_0 < 256.0)
      {
        Final_Simulink_Model_assignme_B.status = (uint8_T)
          Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_0;
      } else {
        Final_Simulink_Model_assignme_B.status = MAX_uint8_T;
      }

      Final_Simulink_Model_assignme_B.qY = (uint32_T)
        Final_Simulink_Model_assignme_B.status - /*MW:OvSatOk*/
        Final_Simulink_Model_assignme_B.ATR_PULSE_WIDTH;
      if (Final_Simulink_Model_assignme_B.qY >
          Final_Simulink_Model_assignme_B.status) {
        Final_Simulink_Model_assignme_B.qY = 0U;
      }

      if ((uint32_T)((int32_T)Final_Simulink_Model_assignm_DW.temporalCounter_i1
                     * 10) >= Final_Simulink_Model_assignme_B.qY) {
        Final_Simulink_Model_assignm_DW.is_c7_Final_Simulink_Model_assi =
          Final_Simulink_Mo_IN_Pacing_AOO;
        Final_Simulink_Model_assignm_DW.temporalCounter_i1 = 0U;
        Final_Simulink_Model_assignme_B.PACE_CHARGE_CTRL = false;
        Final_Simulink_Model_assignme_B.ATR_PACE_CTRL = true;
        Final_Simulink_Model_assignme_B.ATR_GND_CTRL = false;
      }
      break;

     case Final_Simulink_Model_as_IN_AOOR:
      Final_Simulink_Model_assignme_B.ATR_PACE_CTRL = false;
      Final_Simulink_Model_assignme_B.PACE_CHARGE_CTRL = true;
      Final_Simulink_Model_assignme_B.ATR_GND_CTRL = true;
      Final_Simulink_Model_assignme_B.PACE_GND_CTRL = true;
      Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_0 =
        rt_roundd_snf(60000.0 / (real_T)Final_Simulink_Model_assignme_B.rate);
      if (Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_0 < 256.0)
      {
        Final_Simulink_Model_assignme_B.status = (uint8_T)
          Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_0;
      } else {
        Final_Simulink_Model_assignme_B.status = MAX_uint8_T;
      }

      Final_Simulink_Model_assignme_B.qY = (uint32_T)
        Final_Simulink_Model_assignme_B.status - /*MW:OvSatOk*/
        Final_Simulink_Model_assignme_B.ATR_PULSE_WIDTH;
      if (Final_Simulink_Model_assignme_B.qY >
          Final_Simulink_Model_assignme_B.status) {
        Final_Simulink_Model_assignme_B.qY = 0U;
      }

      if ((uint32_T)((int32_T)Final_Simulink_Model_assignm_DW.temporalCounter_i1
                     * 10) >= Final_Simulink_Model_assignme_B.qY) {
        Final_Simulink_Model_assignm_DW.is_c7_Final_Simulink_Model_assi =
          Final_Simulink_M_IN_Pacing_AOOR;
        Final_Simulink_Model_assignm_DW.temporalCounter_i1 = 0U;
        Final_Simulink_Model_assignme_B.PACE_CHARGE_CTRL = false;
        Final_Simulink_Model_assignme_B.ATR_PACE_CTRL = true;
        Final_Simulink_Model_assignme_B.ATR_GND_CTRL = false;
      }
      break;

     case Final_Simulink_Model_as_IN_MAIN:
      Final_Simulink_Model_assig_MAIN
        (&Final_Simulink_Model_assignme_B.PACE_GND_CTRL,
         &Final_Simulink_Model_assignme_B.PACE_CHARGE_CTRL);
      break;

     case Final_Simulink_M_IN_Pacing_AAI1:
      Final_Simulink_Model_assignme_B.PACE_CHARGE_CTRL = false;
      Final_Simulink_Model_assignme_B.PACE_GND_CTRL = true;
      Final_Simulink_Model_assignme_B.ATR_PACE_CTRL = true;
      Final_Simulink_Model_assignme_B.ATR_GND_CTRL = false;
      if (Final_Simulink_Model_assignme_B.b1) {
        Final_Simulink_Model_assignm_DW.is_c7_Final_Simulink_Model_assi =
          Final_Simulin_IN_AAI_REFRACTORY;
        Final_Simulink_Model_assignm_DW.temporalCounter_i1 = 0U;
        Final_Simulink_Model_assignme_B.FRONTEND_CTRL = false;
        Final_Simulink_Model_assignme_B.ATR_PACE_CTRL = false;
        Final_Simulink_Model_assignme_B.ATR_GND_CTRL = true;
        Final_Simulink_Model_assignme_B.PACING_REF_PWM = 20.0F *
          Final_Simulink_Model_assignme_B.ATR_Amplitude_m;
      }
      break;

     case Final_Simulink_M_IN_Pacing_AAIR:
      Final_Simulink_Model_assignme_B.PACE_CHARGE_CTRL = false;
      Final_Simulink_Model_assignme_B.PACE_GND_CTRL = true;
      Final_Simulink_Model_assignme_B.ATR_PACE_CTRL = true;
      Final_Simulink_Model_assignme_B.ATR_GND_CTRL = false;
      if (Final_Simulink_Model_assignme_B.b1) {
        Final_Simulink_Model_assignm_DW.is_c7_Final_Simulink_Model_assi =
          Final_Simuli_IN_AAIR_REFRACTORY;
        Final_Simulink_Model_assignm_DW.temporalCounter_i1 = 0U;
        Final_Simulink_Model_assignme_B.FRONTEND_CTRL = false;
        Final_Simulink_Model_assignme_B.ATR_PACE_CTRL = false;
        Final_Simulink_Model_assignme_B.ATR_GND_CTRL = true;
        Final_Simulink_Model_assignme_B.PACING_REF_PWM = 20.0F *
          Final_Simulink_Model_assignme_B.ATR_Amplitude_m;
      }
      break;

     case Final_Simulink_Mo_IN_Pacing_AOO:
      Final_Simulink_Model_assignme_B.PACE_CHARGE_CTRL = false;
      Final_Simulink_Model_assignme_B.PACE_GND_CTRL = true;
      Final_Simulink_Model_assignme_B.ATR_PACE_CTRL = true;
      Final_Simulink_Model_assignme_B.ATR_GND_CTRL = false;
      if ((uint32_T)((int32_T)Final_Simulink_Model_assignm_DW.temporalCounter_i1
                     * 10) >= Final_Simulink_Model_assignme_B.ATR_PULSE_WIDTH) {
        Final_Simulink_Model_assignm_DW.is_c7_Final_Simulink_Model_assi =
          Final_Simulink_Model_ass_IN_AOO;
        Final_Simulink_Model_assignm_DW.temporalCounter_i1 = 0U;
        Final_Simulink_Model_assignme_B.ATR_PACE_CTRL = false;
        Final_Simulink_Model_assignme_B.PACE_CHARGE_CTRL = true;
        Final_Simulink_Model_assignme_B.ATR_GND_CTRL = true;
        Final_Simulink_Model_assignme_B.PACING_REF_PWM = 20.0F *
          Final_Simulink_Model_assignme_B.ATR_Amplitude_m;
      }
      break;

     case Final_Simulink_M_IN_Pacing_AOOR:
      Final_Simulink_Model_assignme_B.PACE_CHARGE_CTRL = false;
      Final_Simulink_Model_assignme_B.PACE_GND_CTRL = true;
      Final_Simulink_Model_assignme_B.ATR_PACE_CTRL = true;
      Final_Simulink_Model_assignme_B.ATR_GND_CTRL = false;
      if ((uint32_T)((int32_T)Final_Simulink_Model_assignm_DW.temporalCounter_i1
                     * 10) >= Final_Simulink_Model_assignme_B.ATR_PULSE_WIDTH) {
        Final_Simulink_Model_assignm_DW.is_c7_Final_Simulink_Model_assi =
          Final_Simulink_Model_as_IN_AOOR;
        Final_Simulink_Model_assignm_DW.temporalCounter_i1 = 0U;
        Final_Simulink_Model_assignme_B.ATR_PACE_CTRL = false;
        Final_Simulink_Model_assignme_B.PACE_CHARGE_CTRL = true;
        Final_Simulink_Model_assignme_B.ATR_GND_CTRL = true;
        Final_Simulink_Model_assignme_B.PACING_REF_PWM = 20.0F *
          Final_Simulink_Model_assignme_B.ATR_Amplitude_m;
      }
      break;

     case Final_Simulink_Mo_IN_Pacing_VOO:
      Final_Simulink_Model_assignme_B.PACE_CHARGE_CTRL = false;
      Final_Simulink_Model_assignme_B.PACE_GND_CTRL = true;
      Final_Simulink_Model_assignme_B.VENT_GND_CTRL = false;
      Final_Simulink_Model_assignme_B.VENT_PACE_CTRL = true;
      if ((uint32_T)((int32_T)Final_Simulink_Model_assignm_DW.temporalCounter_i1
                     * 10) >= Final_Simulink_Model_assignme_B.VENT_PULSE_WIDTH)
      {
        Final_Simulink_Model_assignm_DW.is_c7_Final_Simulink_Model_assi =
          Final_Simulink_Model_ass_IN_VOO;
        Final_Simulink_Model_assignm_DW.temporalCounter_i1 = 0U;
        Final_Simulink_Model_assignme_B.VENT_PACE_CTRL = false;
        Final_Simulink_Model_assignme_B.PACE_CHARGE_CTRL = true;
        Final_Simulink_Model_assignme_B.VENT_GND_CTRL = true;
        Final_Simulink_Model_assignme_B.PACING_REF_PWM = 20.0F *
          Final_Simulink_Model_assignme_B.VENT_Amplitude_a;
      }
      break;

     case Final_Simulink_M_IN_Pacing_VOOR:
      Final_Simulink_Model_assignme_B.PACE_CHARGE_CTRL = false;
      Final_Simulink_Model_assignme_B.PACE_GND_CTRL = true;
      Final_Simulink_Model_assignme_B.VENT_GND_CTRL = false;
      Final_Simulink_Model_assignme_B.VENT_PACE_CTRL = true;
      if ((uint32_T)((int32_T)Final_Simulink_Model_assignm_DW.temporalCounter_i1
                     * 10) >= Final_Simulink_Model_assignme_B.VENT_PULSE_WIDTH)
      {
        Final_Simulink_Model_assignm_DW.is_c7_Final_Simulink_Model_assi =
          Final_Simulink_Model_as_IN_VOOR;
        Final_Simulink_Model_assignm_DW.temporalCounter_i1 = 0U;
        Final_Simulink_Model_assignme_B.VENT_PACE_CTRL = false;
        Final_Simulink_Model_assignme_B.PACE_CHARGE_CTRL = true;
        Final_Simulink_Model_assignme_B.VENT_GND_CTRL = true;
        Final_Simulink_Model_assignme_B.PACING_REF_PWM = 20.0F *
          Final_Simulink_Model_assignme_B.VENT_Amplitude_a;
      }
      break;

     case Final_Simulink_Mo_IN_Pacing_VVI:
      Final_Simulink_Model_assignme_B.PACE_CHARGE_CTRL = false;
      Final_Simulink_Model_assignme_B.PACE_GND_CTRL = true;
      Final_Simulink_Model_assignme_B.VENT_GND_CTRL = false;
      Final_Simulink_Model_assignme_B.VENT_PACE_CTRL = true;
      if (Final_Simulink_Model_assignme_B.b) {
        Final_Simulink_Model_assignm_DW.is_c7_Final_Simulink_Model_assi =
          Final_Simulin_IN_VVI_REFRACTORY;
        Final_Simulink_Model_assignm_DW.temporalCounter_i1 = 0U;
        Final_Simulink_Model_assignme_B.FRONTEND_CTRL = false;
        Final_Simulink_Model_assignme_B.VENT_GND_CTRL = true;
        Final_Simulink_Model_assignme_B.PACING_REF_PWM = 20.0F *
          Final_Simulink_Model_assignme_B.VENT_Amplitude_a;
      }
      break;

     case Final_Simulink_M_IN_Pacing_VVIR:
      Final_Simulink_Model_assignme_B.PACE_CHARGE_CTRL = false;
      Final_Simulink_Model_assignme_B.PACE_GND_CTRL = true;
      Final_Simulink_Model_assignme_B.VENT_GND_CTRL = false;
      Final_Simulink_Model_assignme_B.VENT_PACE_CTRL = true;
      if (Final_Simulink_Model_assignme_B.b) {
        Final_Simulink_Model_assignm_DW.is_c7_Final_Simulink_Model_assi =
          Final_Simuli_IN_VVIR_REFRACTORY;
        Final_Simulink_Model_assignm_DW.temporalCounter_i1 = 0U;
        Final_Simulink_Model_assignme_B.FRONTEND_CTRL = false;
        Final_Simulink_Model_assignme_B.VENT_GND_CTRL = true;
        Final_Simulink_Model_assignme_B.PACING_REF_PWM = 20.0F *
          Final_Simulink_Model_assignme_B.VENT_Amplitude_a;
      }
      break;

     case Final_Simulink_Model_ass_IN_VOO:
      Final_Simulink_Model_assignme_B.VENT_PACE_CTRL = false;
      Final_Simulink_Model_assignme_B.PACE_CHARGE_CTRL = true;
      Final_Simulink_Model_assignme_B.VENT_GND_CTRL = true;
      Final_Simulink_Model_assignme_B.PACE_GND_CTRL = true;
      Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_0 =
        rt_roundd_snf(60000.0 / (real_T)Final_Simulink_Model_assignme_B.LRL);
      if (Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_0 < 256.0)
      {
        Final_Simulink_Model_assignme_B.status = (uint8_T)
          Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_0;
      } else {
        Final_Simulink_Model_assignme_B.status = MAX_uint8_T;
      }

      Final_Simulink_Model_assignme_B.qY = (uint32_T)
        Final_Simulink_Model_assignme_B.status - /*MW:OvSatOk*/
        Final_Simulink_Model_assignme_B.VENT_PULSE_WIDTH;
      if (Final_Simulink_Model_assignme_B.qY >
          Final_Simulink_Model_assignme_B.status) {
        Final_Simulink_Model_assignme_B.qY = 0U;
      }

      if ((uint32_T)((int32_T)Final_Simulink_Model_assignm_DW.temporalCounter_i1
                     * 10) >= Final_Simulink_Model_assignme_B.qY) {
        Final_Simulink_Model_assignm_DW.is_c7_Final_Simulink_Model_assi =
          Final_Simulink_Mo_IN_Pacing_VOO;
        Final_Simulink_Model_assignm_DW.temporalCounter_i1 = 0U;
        Final_Simulink_Model_assignme_B.PACE_CHARGE_CTRL = false;
        Final_Simulink_Model_assignme_B.VENT_GND_CTRL = false;
        Final_Simulink_Model_assignme_B.VENT_PACE_CTRL = true;
      }
      break;

     case Final_Simulink_Model_as_IN_VOOR:
      Final_Simulink_Model_assignme_B.VENT_PACE_CTRL = false;
      Final_Simulink_Model_assignme_B.PACE_CHARGE_CTRL = true;
      Final_Simulink_Model_assignme_B.VENT_GND_CTRL = true;
      Final_Simulink_Model_assignme_B.PACE_GND_CTRL = true;
      Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_0 =
        rt_roundd_snf(60000.0 / (real_T)Final_Simulink_Model_assignme_B.rate);
      if (Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_0 < 256.0)
      {
        Final_Simulink_Model_assignme_B.status = (uint8_T)
          Final_Simulink_Model_assignme_B.rtb_FXOS87006AxesSensor_idx_0;
      } else {
        Final_Simulink_Model_assignme_B.status = MAX_uint8_T;
      }

      Final_Simulink_Model_assignme_B.qY = (uint32_T)
        Final_Simulink_Model_assignme_B.status - /*MW:OvSatOk*/
        Final_Simulink_Model_assignme_B.VENT_PULSE_WIDTH;
      if (Final_Simulink_Model_assignme_B.qY >
          Final_Simulink_Model_assignme_B.status) {
        Final_Simulink_Model_assignme_B.qY = 0U;
      }

      if ((uint32_T)((int32_T)Final_Simulink_Model_assignm_DW.temporalCounter_i1
                     * 10) >= Final_Simulink_Model_assignme_B.qY) {
        Final_Simulink_Model_assignm_DW.is_c7_Final_Simulink_Model_assi =
          Final_Simulink_M_IN_Pacing_VOOR;
        Final_Simulink_Model_assignm_DW.temporalCounter_i1 = 0U;
        Final_Simulink_Model_assignme_B.PACE_CHARGE_CTRL = false;
        Final_Simulink_Model_assignme_B.VENT_GND_CTRL = false;
        Final_Simulink_Model_assignme_B.VENT_PACE_CTRL = true;
      }
      break;

     case Final_Simulink_Model_ass_IN_VVI:
      Final_Simulink_Model_assign_VVI
        (&Final_Simulink_Model_assignme_B.PACE_GND_CTRL,
         &Final_Simulink_Model_assignme_B.PACE_CHARGE_CTRL,
         &Final_Simulink_Model_assignme_B.b);
      break;

     case Final_Simulink_Model_as_IN_VVIR:
      Final_Simulink_Model_assig_VVIR
        (&Final_Simulink_Model_assignme_B.PACE_GND_CTRL,
         &Final_Simulink_Model_assignme_B.PACE_CHARGE_CTRL,
         &Final_Simulink_Model_assignme_B.b);
      break;

     case Final_Simuli_IN_VVIR_REFRACTORY:
      Final_Simulink__VVIR_REFRACTORY
        (&Final_Simulink_Model_assignme_B.PACE_GND_CTRL,
         &Final_Simulink_Model_assignme_B.PACE_CHARGE_CTRL);
      break;

     default:
      /* case IN_VVI_REFRACTORY: */
      Final_Simulink_M_VVI_REFRACTORY
        (&Final_Simulink_Model_assignme_B.PACE_GND_CTRL,
         &Final_Simulink_Model_assignme_B.PACE_CHARGE_CTRL);
      break;
    }
  }

  /* End of Chart: '<Root>/Chart1' */

  /* MATLABSystem: '<S6>/Digital Write' */
  MW_digitalIO_write(Final_Simulink_Model_assignm_DW.obj_a.MW_DIGITALIO_HANDLE,
                     Final_Simulink_Model_assignme_B.PACE_CHARGE_CTRL);

  /* MATLABSystem: '<S6>/Digital Write1' */
  MW_digitalIO_write(Final_Simulink_Model_assignm_DW.obj_h.MW_DIGITALIO_HANDLE,
                     Final_Simulink_Model_assignme_B.Z_ATR_CTRL);

  /* MATLABSystem: '<S6>/Digital Write10' */
  MW_digitalIO_write(Final_Simulink_Model_assignm_DW.obj_g.MW_DIGITALIO_HANDLE,
                     Final_Simulink_Model_assignme_B.FRONTEND_CTRL);

  /* MATLABSystem: '<S6>/Digital Write2' */
  MW_digitalIO_write(Final_Simulink_Model_assignm_DW.obj_pm.MW_DIGITALIO_HANDLE,
                     Final_Simulink_Model_assignme_B.ATR_PACE_CTRL);

  /* MATLABSystem: '<S6>/Digital Write3' */
  MW_digitalIO_write(Final_Simulink_Model_assignm_DW.obj_ej.MW_DIGITALIO_HANDLE,
                     Final_Simulink_Model_assignme_B.Z_VENT_CTRL);

  /* MATLABSystem: '<S6>/Digital Write5' */
  MW_digitalIO_write(Final_Simulink_Model_assignm_DW.obj_p.MW_DIGITALIO_HANDLE,
                     Final_Simulink_Model_assignme_B.VENT_PACE_CTRL);

  /* MATLABSystem: '<S6>/Digital Write6' */
  MW_digitalIO_write(Final_Simulink_Model_assignm_DW.obj_f.MW_DIGITALIO_HANDLE,
                     Final_Simulink_Model_assignme_B.PACE_GND_CTRL);

  /* MATLABSystem: '<S6>/Digital Write7' */
  MW_digitalIO_write(Final_Simulink_Model_assignm_DW.obj_bo.MW_DIGITALIO_HANDLE,
                     Final_Simulink_Model_assignme_B.ATR_GND_CTRL);

  /* MATLABSystem: '<S6>/Digital Write8' */
  MW_digitalIO_write(Final_Simulink_Model_assignm_DW.obj_i.MW_DIGITALIO_HANDLE,
                     Final_Simulink_Model_assignme_B.VENT_GND_CTRL);

  /* MATLABSystem: '<S6>/PWM Output' */
  MW_PWM_SetDutyCycle(Final_Simulink_Model_assignm_DW.obj_c.MW_PWM_HANDLE,
                      (real_T)Final_Simulink_Model_assignme_B.PACING_REF_PWM);

  /* MATLABSystem: '<S6>/PWM Output1' */
  MW_PWM_SetDutyCycle(Final_Simulink_Model_assignm_DW.obj_kt.MW_PWM_HANDLE,
                      (real_T)Final_Simulink_Model_assignme_B.VENT_CMP_REF_PWM);

  /* MATLABSystem: '<S6>/PWM Output2' */
  MW_PWM_SetDutyCycle(Final_Simulink_Model_assignm_DW.obj_k.MW_PWM_HANDLE,
                      (real_T)Final_Simulink_Model_assignme_B.ATR_CMP_REF_PWM);
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void Final_Simulink_Model_assignment_2_step(int_T tid)
{
  switch (tid) {
   case 0 :
    Final_Simulink_Model_assignment_2_step0();
    break;

   case 1 :
    Final_Simulink_Model_assignment_2_step1();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Model initialize function */
void Final_Simulink_Model_assignment_2_initialize(void)
{
  {
    freedomk64f_DigitalRead_Final_T *obj_0;
    freedomk64f_DigitalWrite_Fina_T *obj_1;
    freedomk64f_PWMOutput_Final_S_T *obj_2;
    g_dsp_internal_SlidingWindowV_T *obj;

    /* Chart: '<Root>/COM_IN1' */
    Final_Simulink_Model_assignm_DW.is_c6_Final_Simulink_Model_assi =
      Final_Simulink_Mo_IN_Initialize;
    Final_Simulink_Model_assignme_B.mode = 5U;
    Final_Simulink_Model_assignme_B.LRL = 60U;
    Final_Simulink_Model_assignme_B.URL = 120U;
    Final_Simulink_Model_assignme_B.VENT_Amplitude_a = 3.5F;
    Final_Simulink_Model_assignme_B.ATR_Amplitude_m = 3.5F;
    Final_Simulink_Model_assignme_B.VENT_PULSE_WIDTH = 10U;
    Final_Simulink_Model_assignme_B.ATR_PULSE_WIDTH = 10U;
    Final_Simulink_Model_assignme_B.VENTSENSITIVITY_Amplitude_l = 1.5F;
    Final_Simulink_Model_assignme_B.ATRSENSITIVITY_Amplitude_p = 1.5F;
    Final_Simulink_Model_assignme_B.ARP_l = 250U;
    Final_Simulink_Model_assignme_B.VRP_o = 250U;
    Final_Simulink_Model_assignme_B.MSR = 120U;
    Final_Simulink_Model_assignme_B.Activity_threshold_d = 1.1F;
    Final_Simulink_Model_assignme_B.Response_Factor = 8U;
    Final_Simulink_Model_assignme_B.Reaction_time_d = 30U;
    Final_Simulink_Model_assignme_B.Recovery_time_d = 50U;

    /* SystemInitialize for S-Function (sfun_private_function_caller) generated from: '<Root>/send_params()1' incorporates:
     *  SubSystem: '<Root>/send_params()1'
     */
    send_params_Init();

    /* End of SystemInitialize for S-Function (sfun_private_function_caller) generated from: '<Root>/send_params()1' */

    /* Start for MATLABSystem: '<Root>/Serial Receive1' */
    Final_Simulink_Model_assignm_DW.obj_j.isInitialized = 0;
    Final_Simulink_Model_assignm_DW.obj_j.matlabCodegenIsDeleted = false;
    Final_Simulink_Model_assignm_DW.obj_j.SampleTime =
      Final_Simulink_Model_assignme_P.SerialReceive1_SampleTime;
    Final_Simu_SystemCore_setup_mmp(&Final_Simulink_Model_assignm_DW.obj_j);

    /* Start for MATLABSystem: '<S1>/FXOS8700 6-Axes Sensor' */
    Final_Simulink_Model_assignm_DW.obj_b.isInitialized = 0;
    Final_Simulink_Model_assignm_DW.obj_b.i2cobj.isInitialized = 0;
    Final_Simulink_Model_assignm_DW.obj_b.i2cobj.matlabCodegenIsDeleted = false;
    Final_Simulink_Model_assignm_DW.obj_b.matlabCodegenIsDeleted = false;
    Final_Simulink_Model_assignm_DW.obj_b.SampleTime =
      Final_Simulink_Model_assignme_P.FXOS87006AxesSensor_SampleTime;
    Final_Simuli_SystemCore_setup_m(&Final_Simulink_Model_assignm_DW.obj_b);

    /* Start for MATLABSystem: '<S1>/Moving Standard Deviation' */
    Final_Simulink_Model_assignm_DW.obj.isInitialized = 0;
    Final_Simulink_Model_assignm_DW.obj.NumChannels = -1;
    Final_Simulink_Model_assignm_DW.obj.FrameLength = -1;
    Final_Simulink_Model_assignm_DW.obj.matlabCodegenIsDeleted = false;
    Final_Simul_SystemCore_setup_mm(&Final_Simulink_Model_assignm_DW.obj);

    /* InitializeConditions for MATLABSystem: '<S1>/Moving Standard Deviation' */
    obj = Final_Simulink_Model_assignm_DW.obj.pStatistic;
    if (obj->isInitialized == 1) {
      for (Final_Simulink_Model_assignme_B.i_c = 0;
           Final_Simulink_Model_assignme_B.i_c < 400;
           Final_Simulink_Model_assignme_B.i_c++) {
        obj->pReverseSamples[Final_Simulink_Model_assignme_B.i_c] = 0.0;
      }

      for (Final_Simulink_Model_assignme_B.i_c = 0;
           Final_Simulink_Model_assignme_B.i_c < 400;
           Final_Simulink_Model_assignme_B.i_c++) {
        obj->pReverseT[Final_Simulink_Model_assignme_B.i_c] = 0.0;
      }

      for (Final_Simulink_Model_assignme_B.i_c = 0;
           Final_Simulink_Model_assignme_B.i_c < 400;
           Final_Simulink_Model_assignme_B.i_c++) {
        obj->pReverseS[Final_Simulink_Model_assignme_B.i_c] = 0.0;
      }

      obj->pT = 0.0;
      obj->pS = 0.0;
      obj->pM = 0.0;
      obj->pCounter = 1.0;
      obj->pModValueRev = 0.0;
    }

    /* End of InitializeConditions for MATLABSystem: '<S1>/Moving Standard Deviation' */

    /* Start for MATLABSystem: '<S7>/VENT_CMP_DETECT' */
    Final_Simulink_Model_assignm_DW.obj_b0.matlabCodegenIsDeleted = false;
    Final_Simulink_Model_assignm_DW.obj_b0.SampleTime =
      Final_Simulink_Model_assignme_P.VENT_CMP_DETECT_SampleTime;
    obj_0 = &Final_Simulink_Model_assignm_DW.obj_b0;
    Final_Simulink_Model_assignm_DW.obj_b0.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(1U, 0);
    Final_Simulink_Model_assignm_DW.obj_b0.isSetupComplete = true;

    /* Start for MATLABSystem: '<S7>/ATR_CMP_DETECT' */
    Final_Simulink_Model_assignm_DW.obj_bh.matlabCodegenIsDeleted = false;
    Final_Simulink_Model_assignm_DW.obj_bh.SampleTime =
      Final_Simulink_Model_assignme_P.ATR_CMP_DETECT_SampleTime;
    obj_0 = &Final_Simulink_Model_assignm_DW.obj_bh;
    Final_Simulink_Model_assignm_DW.obj_bh.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(0U, 0);
    Final_Simulink_Model_assignm_DW.obj_bh.isSetupComplete = true;

    /* Start for MATLABSystem: '<S6>/Digital Write' */
    Final_Simulink_Model_assignm_DW.obj_a.matlabCodegenIsDeleted = false;
    obj_1 = &Final_Simulink_Model_assignm_DW.obj_a;
    Final_Simulink_Model_assignm_DW.obj_a.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
    Final_Simulink_Model_assignm_DW.obj_a.isSetupComplete = true;

    /* Start for MATLABSystem: '<S6>/Digital Write1' */
    Final_Simulink_Model_assignm_DW.obj_h.matlabCodegenIsDeleted = false;
    obj_1 = &Final_Simulink_Model_assignm_DW.obj_h;
    Final_Simulink_Model_assignm_DW.obj_h.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(4U, 1);
    Final_Simulink_Model_assignm_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<S6>/Digital Write10' */
    Final_Simulink_Model_assignm_DW.obj_g.matlabCodegenIsDeleted = false;
    obj_1 = &Final_Simulink_Model_assignm_DW.obj_g;
    Final_Simulink_Model_assignm_DW.obj_g.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(13U, 1);
    Final_Simulink_Model_assignm_DW.obj_g.isSetupComplete = true;

    /* Start for MATLABSystem: '<S6>/Digital Write2' */
    Final_Simulink_Model_assignm_DW.obj_pm.matlabCodegenIsDeleted = false;
    obj_1 = &Final_Simulink_Model_assignm_DW.obj_pm;
    Final_Simulink_Model_assignm_DW.obj_pm.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(8U, 1);
    Final_Simulink_Model_assignm_DW.obj_pm.isSetupComplete = true;

    /* Start for MATLABSystem: '<S6>/Digital Write3' */
    Final_Simulink_Model_assignm_DW.obj_ej.matlabCodegenIsDeleted = false;
    obj_1 = &Final_Simulink_Model_assignm_DW.obj_ej;
    Final_Simulink_Model_assignm_DW.obj_ej.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(7U, 1);
    Final_Simulink_Model_assignm_DW.obj_ej.isSetupComplete = true;

    /* Start for MATLABSystem: '<S6>/Digital Write5' */
    Final_Simulink_Model_assignm_DW.obj_p.matlabCodegenIsDeleted = false;
    obj_1 = &Final_Simulink_Model_assignm_DW.obj_p;
    Final_Simulink_Model_assignm_DW.obj_p.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(9U, 1);
    Final_Simulink_Model_assignm_DW.obj_p.isSetupComplete = true;

    /* Start for MATLABSystem: '<S6>/Digital Write6' */
    Final_Simulink_Model_assignm_DW.obj_f.matlabCodegenIsDeleted = false;
    obj_1 = &Final_Simulink_Model_assignm_DW.obj_f;
    Final_Simulink_Model_assignm_DW.obj_f.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
    Final_Simulink_Model_assignm_DW.obj_f.isSetupComplete = true;

    /* Start for MATLABSystem: '<S6>/Digital Write7' */
    Final_Simulink_Model_assignm_DW.obj_bo.matlabCodegenIsDeleted = false;
    obj_1 = &Final_Simulink_Model_assignm_DW.obj_bo;
    Final_Simulink_Model_assignm_DW.obj_bo.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(11U, 1);
    Final_Simulink_Model_assignm_DW.obj_bo.isSetupComplete = true;

    /* Start for MATLABSystem: '<S6>/Digital Write8' */
    Final_Simulink_Model_assignm_DW.obj_i.matlabCodegenIsDeleted = false;
    obj_1 = &Final_Simulink_Model_assignm_DW.obj_i;
    Final_Simulink_Model_assignm_DW.obj_i.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(12U, 1);
    Final_Simulink_Model_assignm_DW.obj_i.isSetupComplete = true;

    /* Start for MATLABSystem: '<S6>/PWM Output' */
    Final_Simulink_Model_assignm_DW.obj_c.matlabCodegenIsDeleted = false;
    obj_2 = &Final_Simulink_Model_assignm_DW.obj_c;
    Final_Simulink_Model_assignm_DW.obj_c.isInitialized = 1;
    obj_2->MW_PWM_HANDLE = MW_PWM_Open(5U, 2000.0, 0.0);
    MW_PWM_Start(Final_Simulink_Model_assignm_DW.obj_c.MW_PWM_HANDLE);
    Final_Simulink_Model_assignm_DW.obj_c.isSetupComplete = true;

    /* Start for MATLABSystem: '<S6>/PWM Output1' */
    Final_Simulink_Model_assignm_DW.obj_kt.matlabCodegenIsDeleted = false;
    obj_2 = &Final_Simulink_Model_assignm_DW.obj_kt;
    Final_Simulink_Model_assignm_DW.obj_kt.isInitialized = 1;
    obj_2->MW_PWM_HANDLE = MW_PWM_Open(3U, 2000.0, 0.0);
    MW_PWM_Start(Final_Simulink_Model_assignm_DW.obj_kt.MW_PWM_HANDLE);
    Final_Simulink_Model_assignm_DW.obj_kt.isSetupComplete = true;

    /* Start for MATLABSystem: '<S6>/PWM Output2' */
    Final_Simulink_Model_assignm_DW.obj_k.matlabCodegenIsDeleted = false;
    obj_2 = &Final_Simulink_Model_assignm_DW.obj_k;
    Final_Simulink_Model_assignm_DW.obj_k.isInitialized = 1;
    obj_2->MW_PWM_HANDLE = MW_PWM_Open(6U, 2000.0, 0.0);
    MW_PWM_Start(Final_Simulink_Model_assignm_DW.obj_k.MW_PWM_HANDLE);
    Final_Simulink_Model_assignm_DW.obj_k.isSetupComplete = true;
  }
}

/* Model terminate function */
void Final_Simulink_Model_assignment_2_terminate(void)
{
  b_freedomk64f_I2CMasterWrite__T *obj;
  g_dsp_internal_SlidingWindowV_T *obj_0;

  /* Terminate for MATLABSystem: '<Root>/Serial Receive1' */
  if (!Final_Simulink_Model_assignm_DW.obj_j.matlabCodegenIsDeleted) {
    Final_Simulink_Model_assignm_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((Final_Simulink_Model_assignm_DW.obj_j.isInitialized == 1) &&
        Final_Simulink_Model_assignm_DW.obj_j.isSetupComplete) {
      MW_SCI_Close(Final_Simulink_Model_assignm_DW.obj_j.MW_SCIHANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Serial Receive1' */

  /* Terminate for S-Function (sfun_private_function_caller) generated from: '<Root>/send_params()1' incorporates:
   *  SubSystem: '<Root>/send_params()1'
   */
  send_params_Term();

  /* End of Terminate for S-Function (sfun_private_function_caller) generated from: '<Root>/send_params()1' */

  /* Terminate for MATLABSystem: '<S1>/FXOS8700 6-Axes Sensor' */
  if (!Final_Simulink_Model_assignm_DW.obj_b.matlabCodegenIsDeleted) {
    Final_Simulink_Model_assignm_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((Final_Simulink_Model_assignm_DW.obj_b.isInitialized == 1) &&
        Final_Simulink_Model_assignm_DW.obj_b.isSetupComplete) {
      MW_I2C_Close(Final_Simulink_Model_assignm_DW.obj_b.i2cobj.MW_I2C_HANDLE);
    }
  }

  obj = &Final_Simulink_Model_assignm_DW.obj_b.i2cobj;
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if (obj->isInitialized == 1) {
      obj->isInitialized = 2;
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/FXOS8700 6-Axes Sensor' */

  /* Terminate for MATLABSystem: '<S1>/Moving Standard Deviation' */
  if (!Final_Simulink_Model_assignm_DW.obj.matlabCodegenIsDeleted) {
    Final_Simulink_Model_assignm_DW.obj.matlabCodegenIsDeleted = true;
    if ((Final_Simulink_Model_assignm_DW.obj.isInitialized == 1) &&
        Final_Simulink_Model_assignm_DW.obj.isSetupComplete) {
      obj_0 = Final_Simulink_Model_assignm_DW.obj.pStatistic;
      if (obj_0->isInitialized == 1) {
        obj_0->isInitialized = 2;
      }

      Final_Simulink_Model_assignm_DW.obj.NumChannels = -1;
      Final_Simulink_Model_assignm_DW.obj.FrameLength = -1;
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Moving Standard Deviation' */

  /* Terminate for MATLABSystem: '<S7>/VENT_CMP_DETECT' */
  if (!Final_Simulink_Model_assignm_DW.obj_b0.matlabCodegenIsDeleted) {
    Final_Simulink_Model_assignm_DW.obj_b0.matlabCodegenIsDeleted = true;
    if ((Final_Simulink_Model_assignm_DW.obj_b0.isInitialized == 1) &&
        Final_Simulink_Model_assignm_DW.obj_b0.isSetupComplete) {
      MW_digitalIO_close
        (Final_Simulink_Model_assignm_DW.obj_b0.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S7>/VENT_CMP_DETECT' */

  /* Terminate for MATLABSystem: '<S7>/ATR_CMP_DETECT' */
  if (!Final_Simulink_Model_assignm_DW.obj_bh.matlabCodegenIsDeleted) {
    Final_Simulink_Model_assignm_DW.obj_bh.matlabCodegenIsDeleted = true;
    if ((Final_Simulink_Model_assignm_DW.obj_bh.isInitialized == 1) &&
        Final_Simulink_Model_assignm_DW.obj_bh.isSetupComplete) {
      MW_digitalIO_close
        (Final_Simulink_Model_assignm_DW.obj_bh.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S7>/ATR_CMP_DETECT' */

  /* Terminate for MATLABSystem: '<S6>/Digital Write' */
  if (!Final_Simulink_Model_assignm_DW.obj_a.matlabCodegenIsDeleted) {
    Final_Simulink_Model_assignm_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((Final_Simulink_Model_assignm_DW.obj_a.isInitialized == 1) &&
        Final_Simulink_Model_assignm_DW.obj_a.isSetupComplete) {
      MW_digitalIO_close
        (Final_Simulink_Model_assignm_DW.obj_a.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/Digital Write' */

  /* Terminate for MATLABSystem: '<S6>/Digital Write1' */
  if (!Final_Simulink_Model_assignm_DW.obj_h.matlabCodegenIsDeleted) {
    Final_Simulink_Model_assignm_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((Final_Simulink_Model_assignm_DW.obj_h.isInitialized == 1) &&
        Final_Simulink_Model_assignm_DW.obj_h.isSetupComplete) {
      MW_digitalIO_close
        (Final_Simulink_Model_assignm_DW.obj_h.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/Digital Write1' */

  /* Terminate for MATLABSystem: '<S6>/Digital Write10' */
  if (!Final_Simulink_Model_assignm_DW.obj_g.matlabCodegenIsDeleted) {
    Final_Simulink_Model_assignm_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((Final_Simulink_Model_assignm_DW.obj_g.isInitialized == 1) &&
        Final_Simulink_Model_assignm_DW.obj_g.isSetupComplete) {
      MW_digitalIO_close
        (Final_Simulink_Model_assignm_DW.obj_g.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/Digital Write10' */

  /* Terminate for MATLABSystem: '<S6>/Digital Write2' */
  if (!Final_Simulink_Model_assignm_DW.obj_pm.matlabCodegenIsDeleted) {
    Final_Simulink_Model_assignm_DW.obj_pm.matlabCodegenIsDeleted = true;
    if ((Final_Simulink_Model_assignm_DW.obj_pm.isInitialized == 1) &&
        Final_Simulink_Model_assignm_DW.obj_pm.isSetupComplete) {
      MW_digitalIO_close
        (Final_Simulink_Model_assignm_DW.obj_pm.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/Digital Write2' */

  /* Terminate for MATLABSystem: '<S6>/Digital Write3' */
  if (!Final_Simulink_Model_assignm_DW.obj_ej.matlabCodegenIsDeleted) {
    Final_Simulink_Model_assignm_DW.obj_ej.matlabCodegenIsDeleted = true;
    if ((Final_Simulink_Model_assignm_DW.obj_ej.isInitialized == 1) &&
        Final_Simulink_Model_assignm_DW.obj_ej.isSetupComplete) {
      MW_digitalIO_close
        (Final_Simulink_Model_assignm_DW.obj_ej.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/Digital Write3' */

  /* Terminate for MATLABSystem: '<S6>/Digital Write5' */
  if (!Final_Simulink_Model_assignm_DW.obj_p.matlabCodegenIsDeleted) {
    Final_Simulink_Model_assignm_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((Final_Simulink_Model_assignm_DW.obj_p.isInitialized == 1) &&
        Final_Simulink_Model_assignm_DW.obj_p.isSetupComplete) {
      MW_digitalIO_close
        (Final_Simulink_Model_assignm_DW.obj_p.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/Digital Write5' */

  /* Terminate for MATLABSystem: '<S6>/Digital Write6' */
  if (!Final_Simulink_Model_assignm_DW.obj_f.matlabCodegenIsDeleted) {
    Final_Simulink_Model_assignm_DW.obj_f.matlabCodegenIsDeleted = true;
    if ((Final_Simulink_Model_assignm_DW.obj_f.isInitialized == 1) &&
        Final_Simulink_Model_assignm_DW.obj_f.isSetupComplete) {
      MW_digitalIO_close
        (Final_Simulink_Model_assignm_DW.obj_f.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/Digital Write6' */

  /* Terminate for MATLABSystem: '<S6>/Digital Write7' */
  if (!Final_Simulink_Model_assignm_DW.obj_bo.matlabCodegenIsDeleted) {
    Final_Simulink_Model_assignm_DW.obj_bo.matlabCodegenIsDeleted = true;
    if ((Final_Simulink_Model_assignm_DW.obj_bo.isInitialized == 1) &&
        Final_Simulink_Model_assignm_DW.obj_bo.isSetupComplete) {
      MW_digitalIO_close
        (Final_Simulink_Model_assignm_DW.obj_bo.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/Digital Write7' */

  /* Terminate for MATLABSystem: '<S6>/Digital Write8' */
  if (!Final_Simulink_Model_assignm_DW.obj_i.matlabCodegenIsDeleted) {
    Final_Simulink_Model_assignm_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((Final_Simulink_Model_assignm_DW.obj_i.isInitialized == 1) &&
        Final_Simulink_Model_assignm_DW.obj_i.isSetupComplete) {
      MW_digitalIO_close
        (Final_Simulink_Model_assignm_DW.obj_i.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/Digital Write8' */

  /* Terminate for MATLABSystem: '<S6>/PWM Output' */
  if (!Final_Simulink_Model_assignm_DW.obj_c.matlabCodegenIsDeleted) {
    Final_Simulink_Model_assignm_DW.obj_c.matlabCodegenIsDeleted = true;
    if ((Final_Simulink_Model_assignm_DW.obj_c.isInitialized == 1) &&
        Final_Simulink_Model_assignm_DW.obj_c.isSetupComplete) {
      MW_PWM_Stop(Final_Simulink_Model_assignm_DW.obj_c.MW_PWM_HANDLE);
      MW_PWM_Close(Final_Simulink_Model_assignm_DW.obj_c.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/PWM Output' */

  /* Terminate for MATLABSystem: '<S6>/PWM Output1' */
  if (!Final_Simulink_Model_assignm_DW.obj_kt.matlabCodegenIsDeleted) {
    Final_Simulink_Model_assignm_DW.obj_kt.matlabCodegenIsDeleted = true;
    if ((Final_Simulink_Model_assignm_DW.obj_kt.isInitialized == 1) &&
        Final_Simulink_Model_assignm_DW.obj_kt.isSetupComplete) {
      MW_PWM_Stop(Final_Simulink_Model_assignm_DW.obj_kt.MW_PWM_HANDLE);
      MW_PWM_Close(Final_Simulink_Model_assignm_DW.obj_kt.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/PWM Output1' */

  /* Terminate for MATLABSystem: '<S6>/PWM Output2' */
  if (!Final_Simulink_Model_assignm_DW.obj_k.matlabCodegenIsDeleted) {
    Final_Simulink_Model_assignm_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((Final_Simulink_Model_assignm_DW.obj_k.isInitialized == 1) &&
        Final_Simulink_Model_assignm_DW.obj_k.isSetupComplete) {
      MW_PWM_Stop(Final_Simulink_Model_assignm_DW.obj_k.MW_PWM_HANDLE);
      MW_PWM_Close(Final_Simulink_Model_assignm_DW.obj_k.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/PWM Output2' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
