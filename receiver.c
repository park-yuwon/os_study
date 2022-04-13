/* Error */

// include files
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h> // added
#include <fcntl.h>

#define MAX_BUF 1024 // maximum buffer size

int main(void)
{
	// file descriptor for son/dau fifo
	int fd_son; 
	int fd_dau;
/* Error: DO NOT fork() HERE */
	// 1. Fork twice (son, daughter)
	pid_t pid_son = fork();
	printf("process son created\n");


	// 2. For each child process (use if pid == 0)
	if (pid_son == 0) {
		// 1. Set a buffer (Ex. Char buf[10000])
		char buf[MAX_BUF];

		// 2. Open message_queue: Same with server but use O_RDONLY instead of O_WRONLY
		// 3. Use the same name with server (Ex. /tmp/hw3_fifo_son or /tmp/hw3_fifo_dau)
		char *fifo_son = "/tmp/hw3_fifo_son"; // assign fifo name
		fd_son = open(fifo_son, O_RDONLY);


		// 4. For Loop 
		// 5. Until get ‘0’ (means buf[0] == ‘0’)
		for (int i=0; buf[0] != '0'; i++)
		{
			// 1. Read buffer (refer page 10)
			//read(fd, buffer(string of char*), sizeof(buffer));
			read(fd_son, buf, sizeof(buf));

			// 2. Display the received message
			printf("Son receivers: %s", buf);
		}
		// 6. Close message_queue (Ex. Close(queue_name))
		close(fd_son);	//unlink?
		exit(1);

	}
	else  {
		pid_t pid_dau = fork();
		if (pid_dau == 0) {
			printf("process daughter created\n");

			// 1. Set a buffer (Ex. Char buf[10000])
			char buf[MAX_BUF];

			// 2. Open message_queue: Same with server but use O_RDONLY instead of O_WRONLY
			// 3. Use the same name with server (Ex. /tmp/hw3_fifo_son or /tmp/hw3_fifo_dau)
			char *fifo_dau = "/tmp/hw3_fifo_dau"; // assign fifo name
			fd_dau = open(fifo_dau, O_RDONLY);

			

			// 4. For Loop 
			// 5. Until get ‘0’ (means buf[0] == ‘0’)
			for (int i=0; buf[0] != '0'; i++)
			{
				// 1. Read buffer (refer page 10)
				//read(fd, buffer(string of char*), sizeof(buffer));
				read(fd_dau, buf, sizeof(buf));
				
				// 2. Display the received message
				printf("Dauhter receivers: %s", buf);
			}

			close(fd_dau);
		}

	}
	// 7. Parent should wait its children (Ex. Wait(NULL))
	wait(NULL);
	printf("Child Complete");
	
	return 0;
}
