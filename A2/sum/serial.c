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
This program is to measure the performance of a serial implementaion

*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>


long long int inputSize, sum;
int numThreads;


void fillArray(int ** a, int n){
	int i = 0;
	for(i = 0; i<n ; i++)
		(*a)[i] = (rand() % (100 - 1 + 1)) + 1;
	return;
}

void serialSummation(int ** a, int n){
	long long int i;
	sum = 0;
	for(i = 0; i< n; i++)
		sum = sum + (*a)[i];
	return;
}

int main(){

	inputSize = 1000;
	FILE * fp;
	fp = fopen("serial.txt", "w");
	while( inputSize < 100000){
		int k = 0;
		double time = 0;
		while(k < 10){
			int * array;
			array = (int*) malloc(inputSize * sizeof(int));
			fillArray(&array, inputSize);
			clock_t begin = clock();
			serialSummation(&array, inputSize);
			//printf("Sum: %lld\n",sum);
			clock_t end = clock();
			time = time + (double)(end-begin)/CLOCKS_PER_SEC; 
			free(array);
			k = k + 1;
		}
		fprintf(fp, "%lld,%f\n",inputSize, time/10);
		inputSize = inputSize + 1000;
	}
	fclose(fp);
	return 0;
}