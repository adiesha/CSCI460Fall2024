#include <stdio.h>
#include <pthread.h>
#include <unistd.h>


void *compute() {
    sleep(2);
    printf("computing something\n");
    return NULL;
}

int main () {


    pthread_t thread1;
    
    int return_create = pthread_create(&thread1, NULL, compute, NULL);
    
    printf("Thread creation returned: %d\n" , return_create);
    if (return_create == 0)
        printf("Thread creation was successfull\n");
    
    // pthread_join(thread1, NULL);
    sleep(3);
    return 0;
}