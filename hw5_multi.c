#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <stdbool.h>

int CNT = 0;
pthread_mutex_t mutex;

/*
int cntPrime(int num) {
	int cnt = 0;
	int i;

	for (i = 1; i * i < num; i++) {
		if (num % i == 0) cnt++;
	}
	if (i * i == num) cnt++;

	if (cnt == 1) return true;
	else return false;
}*/

void* partial_prime(void* param) {

	pthread_mutex_lock(&mutex);
	int range = *(int*)param;
	printf("thread for range (%d ~ %d) \n", range, range + 99999);
	int cnt = 0;
	int i;

	for (i = 1; i * i < range; i++) {
		if (range % i == 0) cnt++;
	}
	if (i * i == range) cnt++;
	CNT += cnt;
	printf("The number of prime numbers between %d~%d is %d\n", range, range + 99999, cnt);

	pthread_mutex_unlock(&mutex);
	pthread_exit(0);
}


int main(int argc, char* argv[]) {
	int range = atoi(argv[1]);

	struct timespec start, finish;
	double elapsed;

	// start
	clock_gettime(CLOCK_MONOTONIC, &start);

	// MUTEX lock
	mutex = PTHREAD_MUTEX_INITIALIZER;

	int num_thread = 0;
	pthread_t tids[1024];
	int limit[1024];

	int idx = 0;
	while (idx < range) {
		limit[num_thread] = idx;
		num_thread++;
		// add logic to create threads
		pthread_create(&tids[idx], NULL, partial_prime(idx), NULL);

		idx += 100000;
		if (idx + 1 > range) idx = range;
	}
	// add logic to wait all the threads until they finish the prime number computation

	// add logic to measure the time clock difference
	clock_gettime(CLOCK_MONOTONIC, &finish);
	elapsed = (finish.tv_sec - start.tv_sec); // seconds
	elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0; // nanoseconds

	printf("elapsed time: %f sec \n", elapsed);
	printf("The number of prime numbers between 1~%d is %d\n", range, CNT);

	return 0;
}
