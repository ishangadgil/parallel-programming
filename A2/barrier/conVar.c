/*
Name: Ishan Gadgil
Roll Number: 111601007

Implementing a barrier using condition variables


*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>


int numThreads;
int counter = 0;
pthread_mutex_t mutex;
pthread_cond_t cond_var;


void * threadWork (void * thread){

	int thread_num = *((int *)thread);

	/*Barrier */
	pthread_mutex_lock(&mutex); 
	counter++;
	if (counter == numThreads) {
		counter = 0;
		pthread_cond_broadcast(&cond_var);
	} else {
		while (pthread_cond_wait(&cond_var, &mutex) != 0);
	}
	pthread_mutex_unlock(&mutex);

	//if (thread_num == 0) 
	//	printf("All threads reached this point\n");

	return NULL;

}

void conVarImplementation(void){
	
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

	pthread_mutex_init(&mutex, NULL); 
	pthread_cond_init(&cond_var, NULL); 

	numThreads = 5;
	FILE * fp;
	fp = fopen("conVar.txt", "w");
	while( numThreads < 105){
		int k = 0;
		double time = 0;
		while(k < 10){
			clock_t begin = clock();
			conVarImplementation();
			clock_t end = clock();
			time = time + (double)(end-begin)/CLOCKS_PER_SEC; 
			k = k + 1;
		}
		fprintf(fp, "%d,%f\n",numThreads, time/10);
		numThreads = numThreads + 5;
	}
	fclose(fp);
	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&cond_var);
	return 0;
}
