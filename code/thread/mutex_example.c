#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

#define NUM_THREADS 3
#define NUM_MAX_INCREMENT 6

int counter  = 0;
pthread_mutex_t mutex;


void* increment_counter(void* tid) {
    for (int i=0; i < NUM_MAX_INCREMENT; i++) {
        pthread_mutex_lock(&mutex);
        
        counter++;
        // printf();// should not use it
        char buffer[100];
        snprintf(buffer, sizeof(buffer), "Incrementing the counter by thread: %d -> val: %d\n", *((int*) tid), counter);
        write(STDOUT_FILENO, buffer, strlen(buffer));

        pthread_mutex_unlock(&mutex);
    }    

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++)
    {
        int* arg = malloc(sizeof(int));
        *arg = i;
        // why cannot we pass the i as an arguement?
        if (pthread_create(&threads[i], NULL, increment_counter, (void *) arg)) {
            perror("Failed to create the threads");
            exit(EXIT_FAILURE);
        }
    }
    
    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL); // second arguement can keep track of the return value of the thread
    }                                                                   
    

    pthread_mutex_destroy(&mutex);


    printf("Final counter value is: %d \n", counter);
    return 0;
}