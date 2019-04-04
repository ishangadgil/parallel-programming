/*
Name: Ishan Gadgil
Roll Number: 111601007

Implementing a barrier using busy-waiting and a mutex


*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>


int numThreads;
int counter = 0;
pthread_mutex_t barrier_mutex;


void * threadWork (void * thread){

	int thread_num = *((int *)thread);

	/*Barrier */
	pthread_mutex_lock(&barrier_mutex); 
	counter++;
	pthread_mutex_unlock(&barrier_mutex); 
	while (counter < numThreads);

//	if (thread_num == 0) 
//		printf("All threads reached this point\n");

	return NULL;

}

void busyWaitImplementation(void){
	
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

	pthread_mutex_init(&barrier_mutex, NULL); 
	numThreads = 5;
	FILE * fp;
	fp = fopen("busyWait.txt", "w");
	while( numThreads < 105){
		int k = 0;
		double time = 0;
		while(k < 10){
			clock_t begin = clock();
			busyWaitImplementation();
			clock_t end = clock();
			time = time + (double)(end-begin)/CLOCKS_PER_SEC; 
			k = k + 1;
		}
		fprintf(fp, "%d,%f\n",numThreads, time/10);
		numThreads = numThreads + 5;
	}
	fclose(fp);
	pthread_mutex_destroy(&barrier_mutex);
	return 0;
}
