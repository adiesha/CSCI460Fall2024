

#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>

int N=15, M=10;
int pid, tid1, tid2;
pthread_t thread;

int produce1(){
  while (1) {
	if (N>30) {
		  printf("N --- Overflow!\n");
		  sleep (1);
		/*  
		*/
		  return 0; 
		  };
    	N=N+1;
	printf("Child Process %d, Thread %d,%d: Current N=%d, M=%d.\n", pid, tid1, pthread_self(), N, M);
        }
}

int produce2(){
  while (1) {
	if (M>30) {
		  printf("M --- Overflow!\n");
		 /*  
		  sleep (1);
		*/
		  return 0; 
		  };
    	M=M+2;
	printf("Child Process %d, Thread %d,%d: Current N=%d, M=%d.\n", pid, tid2, pthread_self(), N, M);
        }
}

int consumer() {
  while (1) {
	if (N<=0) {
		  printf("N --- Underflow!\n");
		  return 0; 
		  };
    	N=N-1;
	printf("Consumer: Current N=%d.\n", N);
	/*  
        */
        sleep(1); 
        }
}

int main() {
	pid = fork();
	if (pid < 0 )
		printf("Fork failure.\n");
	else if (pid > 0)
	{
		printf("Parent PID=%d.\n",pid);
		consumer();
	} else
	{
		printf("Child PID=%d.\n",pid);
		tid1 = pthread_create(&thread,NULL,(void *)produce1, (void *)0);
		if (tid1 < 0 ) printf("1st thread_create failure.\n");
		else {
		      tid2 = pthread_create(&thread,NULL,(void *)produce2, (void *)0);
		      if (tid2 < 0 ) printf("2nd thread_create failure.\n");
		}
	}
}
