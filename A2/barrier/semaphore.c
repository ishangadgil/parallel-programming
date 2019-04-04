/*
Name: Ishan Gadgil
Roll Number: 111601007

Implementing a barrier using semaphores


*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <semaphore.h>


int numThreads;
int counter = 0;

sem_t count_sem;
sem_t barrier_sem; 


void * threadWork (void * thread){

	int thread_num = *((int *)thread);

	/* Barrier */
	sem_wait(&count_sem);
	if (counter == numThreads - 1) {
		counter = 0;
		sem_post(&count_sem);
		for (int j = 0; j < (numThreads - 1); j++)
			sem_post(&barrier_sem);
	} else { 
		counter++;
		sem_post(&count_sem);
		sem_wait(&barrier_sem);
	}

//	if (thread_num == 0) 
//		printf("All threads reached this point\n");

	return NULL;

}

void semaphoreImplementation(void){
	
	pthread_t threads[numThreads];
	int args[numThreads];
	for(int t = 0; t < numThreads; t++){
		args[t] = t;
		pthread_create(&threads[t], NULL, threadWork, &args[t]);
	}

	for(int t = 0; t < numThreads; t++)
		pthread_join(threads[t], NULL);

}


int main(){

	sem_init(&count_sem, 0, 1);
	sem_init(&barrier_sem, 0, 0);
	numThreads = 5;
	FILE * fp;
	fp = fopen("sema.txt", "w");
	while( numThreads < 105){
		int k = 0;
		double time = 0;
		while(k < 10){
			clock_t begin = clock();
			semaphoreImplementation();
			clock_t end = clock();
			time = time + (double)(end-begin)/CLOCKS_PER_SEC; 
			k = k + 1;
		}
		fprintf(fp, "%d,%f\n",numThreads, time/10);
		numThreads = numThreads + 5;
	}
	fclose(fp);
	sem_destroy(&count_sem);
	sem_destroy(&barrier_sem);
	return 0;
}
