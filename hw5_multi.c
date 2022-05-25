#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define true 1
#define false 0

int glob;

int cntPrime(int num) {
	int cnt = 0;
	int i;

	for (i = 1; i * i < num; i++) {
		if (num % i == 0) cnt++;
	}
	if (i * i == num) cnt++;


	pthread_exit(&glob); // Added
	
	if (cnt == 1) return true;
	else return false;
}

int main(int argc, char* argv[]) {
	int cnt = 0;
	int total_cnt = 0;
	int range = atoi(argv[1]);
	int thread_num = 20;
	int quantum = range / thread_num;
	pthread_t thread_id[20];

	struct timespec start, finish;
	double elapsed;

	clock_gettime(CLOCK_MONOTONIC, &start);
	/* Multi Threading Part Should be here ...*/

	for (int base = 0; base < range; base += quantum) {
		if (base < 2) continue;
		cnt = 0;
		for (int i = 0; i < quantum; i++) {
			pthread_create(&thread_id[base + i], NULL, cntPrime(base + i), NULL);
			if (cntPrime(i) == true) cnt++;
		}
		printf("The number of prime numbers between %d~%d is %d\n", base, base + quantum, cnt);
		total_cnt += cnt;
	}
		
	clock_gettime(CLOCK_MONOTONIC, &finish);

	elapsed = (finish.tv_sec - start.tv_sec); // seconds
	elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0; // nanoseconds

	printf("elapsed time: %f sec \n", elapsed);
	printf("The number of prime numbers between 1~%d is %d\n", range, total_cnt);

	return 0;
}
