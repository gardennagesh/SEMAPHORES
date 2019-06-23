// Propgrammer: Nagesh Nanjundachari.
// Demo examples to use semaphore to synchronize two processes.

// How to compile:  Use Makefile of this repo. It creates 3 executables.
// There are three processes: 1. schedproc,  2. evenproc,  3. oddproc

// The process, "schedproc"  controls semapohore operations to release  execution of other processes.
// schedproc controls TIME based  RANDOM reurn value by random(). And plus sleep of 5 secs.

// If randon return value is even, then "evenproc" process is released to run.
// If randon return value is odd , then "oddproc"  process is released to run.

// CONCEPTS:
// If sem_op is +ve , sem_val is added to present value of semphore. This makes release.
// If sem_op is 0, the caller waits until semval become 0. This demo is in "oddproc.c".
// If sem_op is -ve, the caller waits until semaphore becomes GtEq>= to ||sem_op|| . This demo is in "evenproc.c".


//Macros Common Across All processes.
#define SEMID_NUM  16891
#define NO_OF_SEMS  2
#define NO_OF_OPRS  1
#define NO_FLAGS    0


//Macros for Evenproc.
#define FIRST_SEM   0
#define SEMOP1_NEG_VAL  -8
#define LESS_THAN_ABS_OF_SEMOP1 7


//Macros for Oddproc.
#define SEKEND_SEM  1
#define SEMOP2_VAL  0
#define GREATER_THAN_ZERO 1

#define SLEEP_TIME 5
