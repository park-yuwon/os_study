#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define true 1
#define false 0

int cnt = 0;
pthread_mutex_t mutex;

int cntPrime(int num) {
	int cnt = 0;
	int i;
	if (num < 2) return false;
	for (i = 1; i * i < num; i++) {
		if (num % i == 0) cnt++;
	}
	if (i * i == num) cnt++;
	if (cnt == 1) return true;
	else return false;
}

void* partial_prime(void* param) {
	int range = *(int*)param;
	printf("thread for range (%d ~ %d)\n", range, range + 99999);

	// add logic to count the number of prime numbers within the range (increase cnt with mutex lock)

	pthread_exit(0);
}

int main(int argc, char* argv[]) {
	int range = atoi(argv[1]);

	struct timespec start, finish;
	double elapsed;

	// add logic to get time clock (i.e., start)

	// add logic to initialize mutex lock

	int num_thread = 0;
	pthread_t tids[1024];
	int limit[1024];

	int idx = 0;
	while (idx < range) {
		limit[num_thread] = idx;
		// add logic to create threads
		num_thread++;
		idx += 100000;
		if (idx + 1 > range) idx = range;
	}
	// add logic to wait all the threads until they finish the prime number computation

	// add logic to measure the time clock difference

	printf("elapsed time: %f sec \n", elapsed);
	printf("The number of prime numbers between 1~%d is %d\n", range, cnt);

	return 0;
}
