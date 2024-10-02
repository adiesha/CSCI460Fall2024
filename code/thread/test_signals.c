#include <stdio.h>
#include <unistd.h>



int main() {

    printf("This program is demonstrating the how a process handles signals\n");
    printf("The PID of this process is %d\n", getpid());
    while (1)
    {
        // doing nothing
    }

    return 0;
    


}