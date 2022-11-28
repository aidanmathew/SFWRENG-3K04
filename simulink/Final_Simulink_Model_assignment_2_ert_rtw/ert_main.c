/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
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
#include "Final_Simulink_Model_assignment_2_private.h"
#include "rtwtypes.h"
#include "limits.h"
#include "board.h"
#include "mw_cmsis_rtos.h"
#define UNUSED(x)                      x = x
#define NAMELEN                        16

/* Function prototype declaration*/
void exitFcn(int sig);
void *terminateTask(void *arg);
void *baseRateTask(void *arg);
void *subrateTask(void *arg);
volatile boolean_T stopRequested = false;
volatile boolean_T runModel = true;
mw_signal_event_t stopSem;
mw_signal_event_t baserateTaskSem;
mw_signal_event_t subrateTaskSem[1];
int taskId[1];
mw_thread_t schedulerThread;
mw_thread_t baseRateThread;
void *threadJoinStatus;
int terminatingmodel = 0;
mw_thread_t subRateThread[1];
int subratePriority[1];
void *subrateTask(void *arg)
{
  int tid = *((int *) arg);
  int subRateId;
  subRateId = tid + 1;
  while (runModel) {
    mw_osSignalEventWaitEver(&subrateTaskSem[tid]);
    if (terminatingmodel)
      break;
    Final_Simulink_Model_assignment_2_step(subRateId);

    /* Get model outputs here */
  }

  mw_osThreadExit((void *)0);
  return NULL;
}

void *baseRateTask(void *arg)
{
  runModel = (rtmGetErrorStatus(Final_Simulink_Model_assignm_M) == (NULL));
  while (runModel) {
    mw_osSignalEventWaitEver(&baserateTaskSem);
    if (rtmStepTask(Final_Simulink_Model_assignm_M, 1)
        ) {
      mw_osSignalEventRelease(&subrateTaskSem[0]);
    }

    Final_Simulink_Model_assignment_2_step(0);

    /* Get model outputs here */
    stopRequested = !((rtmGetErrorStatus(Final_Simulink_Model_assignm_M) ==
                       (NULL)));
  }

  terminateTask(arg);
  mw_osThreadExit((void *)0);
  return NULL;
}

void exitFcn(int sig)
{
  UNUSED(sig);
  rtmSetErrorStatus(Final_Simulink_Model_assignm_M, "stopping the model");
  runModel = 0;
}

void *terminateTask(void *arg)
{
  UNUSED(arg);
  terminatingmodel = 1;

  {
    int i;

    /* Signal all periodic tasks to complete */
    for (i=0; i<1; i++) {
      CHECK_STATUS(mw_osSignalEventRelease(&subrateTaskSem[i]), 0,
                   "mw_osSignalEventRelease");
      CHECK_STATUS(mw_osSignalEventDelete(&subrateTaskSem[i]), 0,
                   "mw_osSignalEventDelete");
    }

    /* Wait for all periodic tasks to complete */
    for (i=0; i<1; i++) {
      CHECK_STATUS(mw_osThreadJoin(subRateThread[i], &threadJoinStatus), 0,
                   "mw_osThreadJoin");
    }

    runModel = 0;
  }

  /* Terminate model */
  Final_Simulink_Model_assignment_2_terminate();
  mw_osSignalEventRelease(&stopSem);
  return NULL;
}

int main(int argc, char **argv)
{
  subratePriority[0] = 41;
  SystemCoreClockUpdate();
  hardware_init();
  rtmSetErrorStatus(Final_Simulink_Model_assignm_M, 0);

  /* Initialize model */
  Final_Simulink_Model_assignment_2_initialize();

  /* Call RTOS Initialization function */
  mw_RTOSInit(0.001, 1);

  /* Wait for stop semaphore */
  mw_osSignalEventWaitEver(&stopSem);

#if (MW_NUMBER_TIMER_DRIVEN_TASKS > 0)

  {
    int i;
    for (i=0; i < MW_NUMBER_TIMER_DRIVEN_TASKS; i++) {
      CHECK_STATUS(mw_osSignalEventDelete(&timerTaskSem[i]), 0,
                   "mw_osSignalEventDelete");
    }
  }

#endif

  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */