#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>




int main() {

    while (1)
    {
        printf("Wasting time %d\n", getpid());
        sleep(2);
    }
    
    return 0;
}


// signal(SIGINT, handle_sig_int);
// signal(SIGTERM, handle_sig_terminate);
// signal(SIGKILL, handle_sig_kill);
// signal(SIGSTOP, handle_sig_STOP);

// void handle_sig_int(int num) {
//     // printf("I won't be interrupted\n"); // should not do this
//     write(STDOUT_FILENO, "I won't be interrupted\n", strlen("I won't be interrupted\n"));
// }



// void handle_sig_terminate(int num) {
//     write(STDOUT_FILENO, "I won't be terminated\n", strlen("I won't be terminated\n"));
// }

// void handle_sig_kill(int num) {
//     write(STDOUT_FILENO, "I won't be killed\n", strlen("I won't be killed\n"));
// }

// void handle_sig_STOP(int num) {
//     write(STDOUT_FILENO, "I won't be stopped\n", strlen("I won't be stopped\n"));
// }