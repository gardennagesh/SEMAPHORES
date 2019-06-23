// Propgrammer: Nagesh Nanjundachari.
// Compile this as "cc -o oddproc oddproc.c" OR use Makefile.
// This "oddproc" process waits on SEKEND_SEM operations.
// Please see README or "semid.h" to know SEM OPERATIONS.

#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include"semid.h"


union semun {
               int              val;    
               struct semid_ds *buf;    
               unsigned short  *array;  
               struct seminfo  *__buf; 
           };



struct sembuf sem_op = {SEKEND_SEM, SEMOP2_VAL, NO_FLAGS};

union semun sem_val; 

main () {

int semid=-1; 

	semid = semget (SEMID_NUM, NO_OF_SEMS, IPC_CREAT|0666);
	if (semid < 0) {
		perror("semget");
	}

        // Initially Block Myself. Let schedproc release me.
	printf ("+++++ I am Oddproc. I block myself +++++\n");

	sem_val.val = GREATER_THAN_ZERO;
	semctl (semid, SEKEND_SEM, SETVAL, sem_val);
	while (1) {
		semop (semid, &sem_op, NO_OF_OPRS);
		printf ("+++++ I am Oddproc. Schedproc released me +++++\n");
	}
}
