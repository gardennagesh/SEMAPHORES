// Propgrammer: Nagesh Nanjundachari.
// Compile this as "cc -o schedproc schedproc.c" OR use Makefile.
// Demo For Process scheduling using Semaphore control.
// Please see README or "semid.h" to know SEM OPERATIONS.

#include<stdio.h>
#include<stdlib.h>
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

union semun sem_val; 

main () {

int semid=-1;

	semid = semget (SEMID_NUM, NO_OF_SEMS, IPC_CREAT|0666);
	if (semid < 0) {
		perror("semget");
	}

	while (1) {

		if (random()%2) {
                        // Here I set 8 because, evenproc was blocked by -8. 
			sem_val.val = 8;
			semctl (semid, FIRST_SEM, SETVAL, sem_val);
			printf ("+++++ EVN. evenproc_released +++++\n");
		}
		else {
                        // Here I set 0 because, oddproc was blocked by 0. 
			sem_val.val = 0;
			semctl (semid, SEKEND_SEM, SETVAL, sem_val);
			printf ("------- ODD. oddproc_released ------\n");
			sem_val.val = GREATER_THAN_ZERO;
			semctl (semid, SEKEND_SEM, SETVAL, sem_val);
		}
		sleep (SLEEP_TIME);
	}
}
