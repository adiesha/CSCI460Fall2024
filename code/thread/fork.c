#include <stdio.h>
#include <unistd.h>

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

void partent() {
    printf("%sMy pid is %d and this is the parent process %s\n", KRED, getpid(), KNRM);
    sleep(2);
    return;
}

void child() {
    printf("%sThis is the child process\n%s", KGRN,KNRM);
    sleep(1);    
}

int main() {

    int pid = fork();
    if (pid < 0) {
        printf("Error occurred during forking\n");

    } else if (pid == 0) { // This is the parent process

        printf("%sSince pid value returned is 0, this must be the parent process\n" \
        "And the pid of this process is %d\n", KRED, getpid());
        printf("For the parent returned pid and actual pid values are different");
        printf("returned: %d PID: %d", pid, getpid());
        printf("Let's invoke the parent function in this process.\n%s", KNRM);
        partent();

    } else {

        printf("%sSince the pid: %d is greater than 0, this must be the child process\n", KGRN, pid);
        printf("Let's invoke the child method%s\n", KNRM);
        child();

    }
    return 0;
}