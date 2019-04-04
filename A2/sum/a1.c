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

Experiments to measure the performance of each of these synchronization constructs. 

*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>


long long int inputSize;
int numThreads;


void fillArray(int ** a, int n){
	int i = 0;
	for(i = 0; i<n ; i++)
		(*a)[i] = (rand() % (100 - 1 + 1)) + 1;
	return;
}



int main(){

	int * array;
	int n;
	printf("Enter input size:\n");
	scanf("%d", &n);
	array = (int*) malloc(n * sizeof(int));
	fillArray(&array, n);
	int i = 0;
	for(i = 0; i<n ; i++)
		printf("%d\n", array[i]);

	free(array);
	return 0;
}