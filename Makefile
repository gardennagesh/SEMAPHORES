all: scheduler  oddproc  evenproc

scheduler: semid.h scheduler.c
	cc -o scheduler scheduler.c 


oddproc: oddproc.c semid.h
	cc -o oddproc oddproc.c


evenproc: evenproc.c semid.h
	cc -o evenproc evenproc.c

clean: 
	rm -rf scheduler  oddproc  evenproc
