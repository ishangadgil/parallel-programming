/*
Name: Ishan Gadgil
Roll Number: 111601007

Different types of synchronisation constructs
1)Busy Waiting
2)Mutexes
3)Semaphores
4)Barriers
5)Condition Variables
6)Read-write locks

Experiments to measure the performance of each of these synchronization constructs. Experiment is to get the summation of n numbers.
This program is to measure the performance of a semaphore parallel implementaion

*/

# include <stdio.h>
# include <pthread.h>
# include <semaphore.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>


long long int inputSize, sum;
int numThreads;
sem_t sem_lock;

struct inputThread 
{ 
   int * a; 
   int rank; 
};


void fillArray(int ** a, int n){
	int i = 0;
	for(i = 0; i<n ; i++)
		(*a)[i] = (rand() % (100 - 1 + 1)) + 1;
	return;
}

void *semaphoretSummation(void * thread){
	int thread_num = ((struct inputThread *)thread)->rank;
	int * ar = ((struct inputThread *)thread)->a;
    long long int my_start = (thread_num)*(inputSize/numThreads);
    long long int my_end   = (thread_num + 1)*(inputSize/numThreads);
    //printf("My Start = %lld, My End = %lld and thread num = %d\n",my_start,my_end,thread_num);
   	long long int mySum = 0;
    for(long long int i = my_start; i < my_end; i++)
        mySum = mySum + ar[i];
    //printf("Hello from %d\n", thread_num);
    sem_wait(&sem_lock);
    sum = sum + mySum;
	sem_post(&sem_lock);

    return NULL;
}


int main(){

	numThreads = 5;
	FILE * fp;
	fp = fopen("sem5.txt", "w");
	inputSize = 1000;
	while( inputSize < 100000){
		double time = 0;
		for(int k = 0; k < 10; k ++){
			sem_init(&sem_lock, 0, 0);
			sem_post(&sem_lock);
			int * array;
			array = (int*) malloc(inputSize * sizeof(int));
			fillArray(&array, inputSize);
			clock_t begin = clock();
			pthread_t threads[numThreads];
			struct inputThread arr[inputSize];
	    	for(int t = 0; t < numThreads; t++){
	    		arr[t].a = array;
	    		arr[t].rank = t;
				pthread_create(&threads[t], NULL, semaphoreSummation, (void  *)(&arr[t]));
	    	}
		    for(int t = 0; t < numThreads; t++)
				pthread_join(threads[t], NULL);
			//printf("Hello\n");
			printf("Sum: %lld\n",sum);
			clock_t end = clock();
			time = time + (double)(end-begin)/CLOCKS_PER_SEC;
			free(array);
			sem_destroy(&sem_lock); 
		}
		fprintf(fp, "%lld,%f\n",inputSize, time/10);
		inputSize = inputSize + 1000;
	}
	
	fclose(fp);
	return 0;
}