all: busyWait conVar sema pthreadBarrier

busyWait: busyWait.c
	$(CC) busyWait.c -o busyWait.out -Wall -Wextra -pedantic -lpthread -std=c99 -std=c99
conVar: conVar.c
	$(CC) conVar.c -o conVar.out -Wall -Wextra -pedantic -lpthread -std=c99
sema: semaphore.c
	$(CC) semaphore.c -o sema.out -Wall -Wextra -pedantic -lpthread -std=c99
pthreadBarrier: pthreadBarrier.c
	$(CC) pthreadBarrier.c -o pthreadBarrier.out -Wall -Wextra -pedantic -lpthread -std=c99