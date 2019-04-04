/*
Name: Ishan Gadgil
Roll Number: 111601007

Implementing a barrier using semaphores


*/

#ifdef __APPLE__

#ifndef PTHREAD_BARRIER_H_
#define PTHREAD_BARRIER_H_

#include <pthread.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <semaphore.h>

typedef int pthread_barrierattr_t;
typedef struct
{
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    int count;
    int tripCount;
} pthread_barrier_t;


int pthread_barrier_init(pthread_barrier_t *barrier, const pthread_barrierattr_t *attr, unsigned int count)
{
    if(count == 0)
    {
        errno = EINVAL;
        return -1;
    }
    if(pthread_mutex_init(&barrier->mutex, 0) < 0)
    {
        return -1;
    }
    if(pthread_cond_init(&barrier->cond, 0) < 0)
    {
        pthread_mutex_destroy(&barrier->mutex);
        return -1;
    }
    barrier->tripCount = count;
    barrier->count = 0;

    return 0;
}

int pthread_barrier_destroy(pthread_barrier_t *barrier)
{
    pthread_cond_destroy(&barrier->cond);
    pthread_mutex_destroy(&barrier->mutex);
    return 0;
}

int pthread_barrier_wait(pthread_barrier_t *barrier)
{
    pthread_mutex_lock(&barrier->mutex);
    ++(barrier->count);
    if(barrier->count >= barrier->tripCount)
    {
        barrier->count = 0;
        pthread_cond_broadcast(&barrier->cond);
        pthread_mutex_unlock(&barrier->mutex);
        return 1;
    }
    else
    {
        pthread_cond_wait(&barrier->cond, &(barrier->mutex));
        pthread_mutex_unlock(&barrier->mutex);
        return 0;
    }
}

#endif // PTHREAD_BARRIER_H_
#endif // __APPLE__


int numThreads;
int counter = 0;

pthread_barrier_t barrier;

void * threadWork (void * thread){

	int thread_num = *((int *)thread);

	/* Barrier */
	int ret; 
	ret = pthread_barrier_wait(&barrier);

//	if (ret != 0) 
//		printf("All threads reached this point, %d\n", thread_num);

	return NULL;

}

void pthreadBarrierImplementation(void){
	
	pthread_t threads[numThreads];
	int args[numThreads];
	for(int t = 0; t < numThreads; t++){
		args[t] = t;
		pthread_create(&threads[t], NULL, threadWork, (void *)&args[t]);
	}

	for(int t = 0; t < numThreads; t++)
		pthread_join(threads[t], NULL);

}


int main(){

	numThreads = 5;
	FILE * fp;
	fp = fopen("pBarrier.txt", "w");
	while( numThreads < 105){
		pthread_barrier_init(&barrier, NULL, numThreads);
		int k = 0;
		double time = 0;
		while(k < 10){
			clock_t begin = clock();
			pthreadBarrierImplementation();
			clock_t end = clock();
			time = time + (double)(end-begin)/CLOCKS_PER_SEC; 
			k = k + 1;
		}
		fprintf(fp, "%d,%f\n",numThreads, time/10);
		numThreads = numThreads + 5;
	}
	fclose(fp);
	pthread_barrier_destroy(&barrier);
	return 0;
}
