/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Final_Simulink_Model_assignment_2_types.h
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

#ifndef RTW_HEADER_Final_Simulink_Model_assignment_2_types_h_
#define RTW_HEADER_Final_Simulink_Model_assignment_2_types_h_
#include "rtwtypes.h"
#include "MW_SVD.h"

/* Custom Type definition for MATLABSystem: '<S8>/Serial Transmit' */
#include "MW_SVD.h"
#ifndef struct_tag_0QIIqIWUIOhUbf1p9QN9pB
#define struct_tag_0QIIqIWUIOhUbf1p9QN9pB

struct tag_0QIIqIWUIOhUbf1p9QN9pB
{
  int32_T __dummy;
};

#endif                                 /* struct_tag_0QIIqIWUIOhUbf1p9QN9pB */

#ifndef typedef_b_freedomk64f_Hardware_Final__T
#define typedef_b_freedomk64f_Hardware_Final__T

typedef struct tag_0QIIqIWUIOhUbf1p9QN9pB b_freedomk64f_Hardware_Final__T;

#endif                             /* typedef_b_freedomk64f_Hardware_Final__T */

#ifndef struct_tag_s1eQZAg8cMgwN6kxxyzYvC
#define struct_tag_s1eQZAg8cMgwN6kxxyzYvC

struct tag_s1eQZAg8cMgwN6kxxyzYvC
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_freedomk64f_Hardware_Final__T Hw;
  MW_Handle_Type MW_ANALOGIN_HANDLE;
  real_T SampleTime;
};

#endif                                 /* struct_tag_s1eQZAg8cMgwN6kxxyzYvC */

#ifndef typedef_freedomk64f_AnalogInput_Final_T
#define typedef_freedomk64f_AnalogInput_Final_T

typedef struct tag_s1eQZAg8cMgwN6kxxyzYvC freedomk64f_AnalogInput_Final_T;

#endif                             /* typedef_freedomk64f_AnalogInput_Final_T */

#ifndef struct_tag_GV9UedAE1zOVNNbkXknChB
#define struct_tag_GV9UedAE1zOVNNbkXknChB

struct tag_GV9UedAE1zOVNNbkXknChB
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_freedomk64f_Hardware_Final__T Hw;
  MW_Handle_Type MW_SCIHANDLE;
};

#endif                                 /* struct_tag_GV9UedAE1zOVNNbkXknChB */

#ifndef typedef_freedomk64f_SCIWrite_Final_Si_T
#define typedef_freedomk64f_SCIWrite_Final_Si_T

typedef struct tag_GV9UedAE1zOVNNbkXknChB freedomk64f_SCIWrite_Final_Si_T;

#endif                             /* typedef_freedomk64f_SCIWrite_Final_Si_T */

/* Custom Type definition for MATLABSystem: '<S1>/FXOS8700 6-Axes Sensor' */
#include "MW_I2C.h"
#ifndef struct_tag_z9SsGP6dTisbbvuAkyqvkC
#define struct_tag_z9SsGP6dTisbbvuAkyqvkC

struct tag_z9SsGP6dTisbbvuAkyqvkC
{
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T pReverseSamples[400];
  real_T pReverseT[400];
  real_T pReverseS[400];
  real_T pT;
  real_T pS;
  real_T pM;
  real_T pCounter;
  real_T pModValueRev;
};

#endif                                 /* struct_tag_z9SsGP6dTisbbvuAkyqvkC */

#ifndef typedef_g_dsp_internal_SlidingWindowV_T
#define typedef_g_dsp_internal_SlidingWindowV_T

typedef struct tag_z9SsGP6dTisbbvuAkyqvkC g_dsp_internal_SlidingWindowV_T;

#endif                             /* typedef_g_dsp_internal_SlidingWindowV_T */

#ifndef struct_tag_BlgwLpgj2bjudmbmVKWwDE
#define struct_tag_BlgwLpgj2bjudmbmVKWwDE

struct tag_BlgwLpgj2bjudmbmVKWwDE
{
  uint32_T f1[8];
};

#endif                                 /* struct_tag_BlgwLpgj2bjudmbmVKWwDE */

#ifndef typedef_cell_wrap_Final_Simulink_Mode_T
#define typedef_cell_wrap_Final_Simulink_Mode_T

typedef struct tag_BlgwLpgj2bjudmbmVKWwDE cell_wrap_Final_Simulink_Mode_T;

#endif                             /* typedef_cell_wrap_Final_Simulink_Mode_T */

#ifndef struct_tag_Bzx3kWCFPqTJENygYb5fYF
#define struct_tag_Bzx3kWCFPqTJENygYb5fYF

struct tag_Bzx3kWCFPqTJENygYb5fYF
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap_Final_Simulink_Mode_T inputVarSize;
  g_dsp_internal_SlidingWindowV_T *pStatistic;
  int32_T NumChannels;
  int32_T FrameLength;
  g_dsp_internal_SlidingWindowV_T _pobj0;
};

#endif                                 /* struct_tag_Bzx3kWCFPqTJENygYb5fYF */

#ifndef typedef_dsp_simulink_MovingStandardDe_T
#define typedef_dsp_simulink_MovingStandardDe_T

typedef struct tag_Bzx3kWCFPqTJENygYb5fYF dsp_simulink_MovingStandardDe_T;

#endif                             /* typedef_dsp_simulink_MovingStandardDe_T */

#ifndef struct_tag_O0UAiliRyLLAe38ibfdAhE
#define struct_tag_O0UAiliRyLLAe38ibfdAhE

struct tag_O0UAiliRyLLAe38ibfdAhE
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  b_freedomk64f_Hardware_Final__T Hw;
  uint32_T BusSpeed;
  MW_Handle_Type MW_I2C_HANDLE;
};

#endif                                 /* struct_tag_O0UAiliRyLLAe38ibfdAhE */

#ifndef typedef_b_freedomk64f_I2CMasterWrite__T
#define typedef_b_freedomk64f_I2CMasterWrite__T

typedef struct tag_O0UAiliRyLLAe38ibfdAhE b_freedomk64f_I2CMasterWrite__T;

#endif                             /* typedef_b_freedomk64f_I2CMasterWrite__T */

#ifndef struct_tag_v5Zyp5raUQrCF4f9Ln2EwE
#define struct_tag_v5Zyp5raUQrCF4f9Ln2EwE

struct tag_v5Zyp5raUQrCF4f9Ln2EwE
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T SampleTime;
  b_freedomk64f_I2CMasterWrite__T i2cobj;
};

#endif                                 /* struct_tag_v5Zyp5raUQrCF4f9Ln2EwE */

#ifndef typedef_freedomk64f_fxos8700_Final_Si_T
#define typedef_freedomk64f_fxos8700_Final_Si_T

typedef struct tag_v5Zyp5raUQrCF4f9Ln2EwE freedomk64f_fxos8700_Final_Si_T;

#endif                             /* typedef_freedomk64f_fxos8700_Final_Si_T */

#ifndef struct_tag_EkIWEs70Gs0LyfeXELZ2TC
#define struct_tag_EkIWEs70Gs0LyfeXELZ2TC

struct tag_EkIWEs70Gs0LyfeXELZ2TC
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_freedomk64f_Hardware_Final__T Hw;
  MW_Handle_Type MW_DIGITALIO_HANDLE;
};

#endif                                 /* struct_tag_EkIWEs70Gs0LyfeXELZ2TC */

#ifndef typedef_freedomk64f_DigitalWrite_Fina_T
#define typedef_freedomk64f_DigitalWrite_Fina_T

typedef struct tag_EkIWEs70Gs0LyfeXELZ2TC freedomk64f_DigitalWrite_Fina_T;

#endif                             /* typedef_freedomk64f_DigitalWrite_Fina_T */

#ifndef struct_tag_RYgVoAXTz61tXGMaBAGv7F
#define struct_tag_RYgVoAXTz61tXGMaBAGv7F

struct tag_RYgVoAXTz61tXGMaBAGv7F
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_freedomk64f_Hardware_Final__T Hw;
  MW_Handle_Type MW_PWM_HANDLE;
};

#endif                                 /* struct_tag_RYgVoAXTz61tXGMaBAGv7F */

#ifndef typedef_freedomk64f_PWMOutput_Final_S_T
#define typedef_freedomk64f_PWMOutput_Final_S_T

typedef struct tag_RYgVoAXTz61tXGMaBAGv7F freedomk64f_PWMOutput_Final_S_T;

#endif                             /* typedef_freedomk64f_PWMOutput_Final_S_T */

#ifndef struct_tag_214cR1nKZWaoqoq0FTtOUH
#define struct_tag_214cR1nKZWaoqoq0FTtOUH

struct tag_214cR1nKZWaoqoq0FTtOUH
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_freedomk64f_Hardware_Final__T Hw;
  MW_Handle_Type MW_SCIHANDLE;
  real_T SampleTime;
};

#endif                                 /* struct_tag_214cR1nKZWaoqoq0FTtOUH */

#ifndef typedef_freedomk64f_SCIRead_Final_Sim_T
#define typedef_freedomk64f_SCIRead_Final_Sim_T

typedef struct tag_214cR1nKZWaoqoq0FTtOUH freedomk64f_SCIRead_Final_Sim_T;

#endif                             /* typedef_freedomk64f_SCIRead_Final_Sim_T */

#ifndef struct_tag_q6HQSF2nXq6EjCNj0vbuLD
#define struct_tag_q6HQSF2nXq6EjCNj0vbuLD

struct tag_q6HQSF2nXq6EjCNj0vbuLD
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_freedomk64f_Hardware_Final__T Hw;
  MW_Handle_Type MW_DIGITALIO_HANDLE;
  real_T SampleTime;
};

#endif                                 /* struct_tag_q6HQSF2nXq6EjCNj0vbuLD */

#ifndef typedef_freedomk64f_DigitalRead_Final_T
#define typedef_freedomk64f_DigitalRead_Final_T

typedef struct tag_q6HQSF2nXq6EjCNj0vbuLD freedomk64f_DigitalRead_Final_T;

#endif                             /* typedef_freedomk64f_DigitalRead_Final_T */

/* Parameters (default storage) */
typedef struct P_Final_Simulink_Model_assign_T_ P_Final_Simulink_Model_assign_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_Final_Simulink_Model__T RT_MODEL_Final_Simulink_Model_T;

#endif               /* RTW_HEADER_Final_Simulink_Model_assignment_2_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
