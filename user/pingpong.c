#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
    int p1[2],p2[2];
    pipe(p1);
    pipe(p2);
    char buf1[5] = "ping";
    char buf2[5] = "pong";
    char buf[5];
    int pid_c, pid_p;
    if(fork() == 0){
        pid_c = getpid();

        close(p1[1]);
        read(p1[0],buf,5);
        printf("%d: received %s\n",pid_c, buf);
        close(p1[0]);

        close(p2[0]);
        write(p2[1],buf2,5);
        close(p2[1]);

        exit(0);
    }
    else{
        pid_p = getpid();

        close(p1[0]);
        write(p1[1],buf1,5);
        close(p1[1]);

        close(p2[1]);
        read(p2[0],buf,5);
        printf("%d: received %s\n",pid_p, buf);
        close(p2[0]);
    }
    exit(0);
}