/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Final_Simulink_Model_assignment_2.h
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

#ifndef RTW_HEADER_Final_Simulink_Model_assignment_2_h_
#define RTW_HEADER_Final_Simulink_Model_assignment_2_h_
#ifndef Final_Simulink_Model_assignment_2_COMMON_INCLUDES_
#define Final_Simulink_Model_assignment_2_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "MW_I2C.h"
#include "MW_digitalIO.h"
#include "MW_PWM.h"
#include "MW_SCI.h"
#include "MW_AnalogIn.h"
#endif                  /* Final_Simulink_Model_assignment_2_COMMON_INCLUDES_ */

#include "Final_Simulink_Model_assignment_2_types.h"
#include <stddef.h>
#include "send_params.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

#define Final_Simulink_Model_assignment_2_M (Final_Simulink_Model_assignm_M)

/* Block signals (default storage) */
typedef struct {
  real_T reverseSamples[400];
  real_T reverseS[400];
  real_T x[400];
  uint8_T TxDataLocChar[49];
  uint8_T RxData[35];
  uint8_T RxDataLocChar[35];
  uint32_T TxPinLoc;
  uint32_T SCIModuleLoc;
  MW_SCI_StopBits_Type StopBitsValue;
  MW_SCI_Parity_Type ParityValue;
  MW_I2C_Mode_Type ModeType;
  uint32_T i2cname;
  real_T AnalogInput1;                 /* '<S8>/Analog Input1' */
  real_T AnalogInput;                  /* '<S8>/Analog Input' */
  real_T T;
  real_T S;
  real_T M;
  real_T Mprev;
  real_T Sqrt;                         /* '<S1>/Sqrt' */
  real_T rtb_FXOS87006AxesSensor_idx_0;
  real_T rtb_FXOS87006AxesSensor_idx_1;
  real_T rtb_FXOS87006AxesSensor_idx_2;
  real_T d;
  int16_T b_RegisterValue[3];
  uint8_T output_raw[6];
  real32_T VENT_Amplitude;
  real32_T ATR_Amplitude;
  real32_T VENTSENSITIVITY_Amplitude;
  real32_T ATRSENSITIVITY_Amplitude;
  real32_T Activity_threshold;
  real32_T PACING_REF_PWM;             /* '<Root>/Chart1' */
  real32_T VENT_CMP_REF_PWM;           /* '<Root>/Chart1' */
  real32_T ATR_CMP_REF_PWM;            /* '<Root>/Chart1' */
  real32_T VENT_Amplitude_a;           /* '<Root>/COM_IN1' */
  real32_T ATR_Amplitude_m;            /* '<Root>/COM_IN1' */
  real32_T VENTSENSITIVITY_Amplitude_l;/* '<Root>/COM_IN1' */
  real32_T ATRSENSITIVITY_Amplitude_p; /* '<Root>/COM_IN1' */
  real32_T Activity_threshold_d;       /* '<Root>/COM_IN1' */
  int32_T i;
  int32_T i_m;
  int32_T i_c;
  uint32_T qY;
  uint32_T qY_tmp;
  uint32_T qY_k;
  uint16_T ARP;
  uint16_T VRP;
  uint16_T ARP_l;                      /* '<Root>/COM_IN1' */
  uint16_T VRP_o;                      /* '<Root>/COM_IN1' */
  uint8_T BytePack[4];                 /* '<S8>/Byte Pack' */
  uint8_T BytePack1[4];                /* '<S8>/Byte Pack1' */
  uint8_T BytePack2[4];                /* '<S8>/Byte Pack2' */
  uint8_T BytePack3[4];                /* '<S8>/Byte Pack3' */
  uint8_T BytePack4[2];                /* '<S8>/Byte Pack4' */
  uint8_T BytePack5[2];                /* '<S8>/Byte Pack5' */
  uint8_T BytePack6[4];                /* '<S8>/Byte Pack6' */
  uint8_T y[2];
  uint8_T b_x[2];
  uint8_T b_SwappedDataBytes[2];
  uint8_T Reaction_time;
  uint8_T Recovery_time;
  uint8_T BytePack9[8];                /* '<S8>/Byte Pack9' */
  uint8_T BytePack10[8];               /* '<S8>/Byte Pack10' */
  uint8_T BytePack7;                   /* '<S8>/Byte Pack7' */
  uint8_T BytePack8;                   /* '<S8>/Byte Pack8' */
  uint8_T rate;                        /* '<Root>/Find the pacing rate1' */
  uint8_T Desired_rate;         /* '<Root>/Find the desired rate for pacing1' */
  uint8_T mode;                        /* '<Root>/COM_IN1' */
  uint8_T LRL;                         /* '<Root>/COM_IN1' */
  uint8_T URL;                         /* '<Root>/COM_IN1' */
  uint8_T VENT_PULSE_WIDTH;            /* '<Root>/COM_IN1' */
  uint8_T ATR_PULSE_WIDTH;             /* '<Root>/COM_IN1' */
  uint8_T MSR;                         /* '<Root>/COM_IN1' */
  uint8_T Response_Factor;             /* '<Root>/COM_IN1' */
  uint8_T Reaction_time_d;             /* '<Root>/COM_IN1' */
  uint8_T Recovery_time_d;             /* '<Root>/COM_IN1' */
  uint8_T status;
  uint8_T b_RegisterValue_c;
  uint8_T status_b;
  boolean_T ATR_PACE_CTRL;             /* '<Root>/Chart1' */
  boolean_T VENT_PACE_CTRL;            /* '<Root>/Chart1' */
  boolean_T Z_VENT_CTRL;               /* '<Root>/Chart1' */
  boolean_T ATR_GND_CTRL;              /* '<Root>/Chart1' */
  boolean_T VENT_GND_CTRL;             /* '<Root>/Chart1' */
  boolean_T Z_ATR_CTRL;                /* '<Root>/Chart1' */
  boolean_T FRONTEND_CTRL;             /* '<Root>/Chart1' */
  boolean_T b;
  boolean_T b1;
  boolean_T PACE_GND_CTRL;
  boolean_T PACE_CHARGE_CTRL;
} B_Final_Simulink_Model_assign_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  dsp_simulink_MovingStandardDe_T obj; /* '<S1>/Moving Standard Deviation' */
  freedomk64f_fxos8700_Final_Si_T obj_b;/* '<S1>/FXOS8700 6-Axes Sensor' */
  freedomk64f_SCIRead_Final_Sim_T obj_j;/* '<Root>/Serial Receive1' */
  freedomk64f_DigitalRead_Final_T obj_b0;/* '<S7>/VENT_CMP_DETECT' */
  freedomk64f_DigitalRead_Final_T obj_bh;/* '<S7>/ATR_CMP_DETECT' */
  freedomk64f_AnalogInput_Final_T obj_d;/* '<S8>/Analog Input1' */
  freedomk64f_AnalogInput_Final_T obj_e;/* '<S8>/Analog Input' */
  freedomk64f_DigitalWrite_Fina_T obj_i;/* '<S6>/Digital Write8' */
  freedomk64f_DigitalWrite_Fina_T obj_bo;/* '<S6>/Digital Write7' */
  freedomk64f_DigitalWrite_Fina_T obj_f;/* '<S6>/Digital Write6' */
  freedomk64f_DigitalWrite_Fina_T obj_p;/* '<S6>/Digital Write5' */
  freedomk64f_DigitalWrite_Fina_T obj_ej;/* '<S6>/Digital Write3' */
  freedomk64f_DigitalWrite_Fina_T obj_pm;/* '<S6>/Digital Write2' */
  freedomk64f_DigitalWrite_Fina_T obj_g;/* '<S6>/Digital Write10' */
  freedomk64f_DigitalWrite_Fina_T obj_h;/* '<S6>/Digital Write1' */
  freedomk64f_DigitalWrite_Fina_T obj_a;/* '<S6>/Digital Write' */
  freedomk64f_PWMOutput_Final_S_T obj_k;/* '<S6>/PWM Output2' */
  freedomk64f_PWMOutput_Final_S_T obj_kt;/* '<S6>/PWM Output1' */
  freedomk64f_PWMOutput_Final_S_T obj_c;/* '<S6>/PWM Output' */
  freedomk64f_SCIWrite_Final_Si_T obj_es;/* '<S8>/Serial Transmit' */
  uint32_T temporalCounter_i1;         /* '<Root>/Chart1' */
  uint8_T is_c9_Final_Simulink_Model_assi;/* '<Root>/Find the pacing rate1' */
  uint8_T addition;                    /* '<Root>/Find the pacing rate1' */
  uint8_T substruction;                /* '<Root>/Find the pacing rate1' */
  uint8_T is_active_c9_Final_Simulink_Mod;/* '<Root>/Find the pacing rate1' */
  uint8_T temporalCounter_i1_l;        /* '<Root>/Find the pacing rate1' */
  uint8_T is_c8_Final_Simulink_Model_assi;
                                /* '<Root>/Find the desired rate for pacing1' */
  uint8_T temp_rate;            /* '<Root>/Find the desired rate for pacing1' */
  uint8_T is_active_c8_Final_Simulink_Mod;
                                /* '<Root>/Find the desired rate for pacing1' */
  uint8_T temporalCounter_i1_b; /* '<Root>/Find the desired rate for pacing1' */
  uint8_T is_c7_Final_Simulink_Model_assi;/* '<Root>/Chart1' */
  uint8_T is_active_c7_Final_Simulink_Mod;/* '<Root>/Chart1' */
  uint8_T is_c6_Final_Simulink_Model_assi;/* '<Root>/COM_IN1' */
} DW_Final_Simulink_Model_assig_T;

/* Parameters (default storage) */
struct P_Final_Simulink_Model_assign_T_ {
  real_T FXOS87006AxesSensor_SampleTime;/* Expression: 0.01
                                         * Referenced by: '<S1>/FXOS8700 6-Axes Sensor'
                                         */
  real_T SerialReceive1_SampleTime;    /* Expression: -1
                                        * Referenced by: '<Root>/Serial Receive1'
                                        */
  real_T ATR_CMP_DETECT_SampleTime;    /* Expression: SampleTime
                                        * Referenced by: '<S7>/ATR_CMP_DETECT'
                                        */
  real_T VENT_CMP_DETECT_SampleTime;   /* Expression: SampleTime
                                        * Referenced by: '<S7>/VENT_CMP_DETECT'
                                        */
  real_T AnalogInput_SampleTime;       /* Expression: SampleTime
                                        * Referenced by: '<S8>/Analog Input'
                                        */
  real_T AnalogInput1_SampleTime;      /* Expression: SampleTime
                                        * Referenced by: '<S8>/Analog Input1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Final_Simulink_Model__T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block parameters (default storage) */
extern P_Final_Simulink_Model_assign_T Final_Simulink_Model_assignme_P;

/* Block signals (default storage) */
extern B_Final_Simulink_Model_assign_T Final_Simulink_Model_assignme_B;

/* Block states (default storage) */
extern DW_Final_Simulink_Model_assig_T Final_Simulink_Model_assignm_DW;

/* External function called from main */
extern void Final_Simulink_Model_assignment_2_SetEventsForThisBaseStep(boolean_T
  *eventFlags);

/* Model entry point functions */
extern void Final_Simulink_Model_assignment_2_initialize(void);
extern void Final_Simulink_Model_assignment_2_step0(void);
extern void Final_Simulink_Model_assignment_2_step1(void);
extern void Final_Simulink_Model_assignment_2_step(int_T tid);
extern void Final_Simulink_Model_assignment_2_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Final_Simulink_Model_T *const Final_Simulink_Model_assignm_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Scope' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Final_Simulink_Model_assignment_2'
 * '<S1>'   : 'Final_Simulink_Model_assignment_2/Accelerometer1'
 * '<S2>'   : 'Final_Simulink_Model_assignment_2/COM_IN1'
 * '<S3>'   : 'Final_Simulink_Model_assignment_2/Chart1'
 * '<S4>'   : 'Final_Simulink_Model_assignment_2/Find the desired rate for pacing1'
 * '<S5>'   : 'Final_Simulink_Model_assignment_2/Find the pacing rate1'
 * '<S6>'   : 'Final_Simulink_Model_assignment_2/OUTPUT1'
 * '<S7>'   : 'Final_Simulink_Model_assignment_2/Subsystem1'
 * '<S8>'   : 'Final_Simulink_Model_assignment_2/send_params()1'
 */
#endif                     /* RTW_HEADER_Final_Simulink_Model_assignment_2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
