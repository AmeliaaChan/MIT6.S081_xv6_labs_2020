#include "kernel/types.h"
#include "user/user.h"


int is_prime(int n){
    for(int i = 2; i <= n / 2; i++){
        if(n % i == 0){
            return 0;
        }
    }
    return 1;
}

void new_proc(int p[2]){
        int n, prime;
        close(p[1]);
        read(p[0], &prime, 4);
        printf("prime %d\n",prime);
        if(read(p[0], &n, 4)){
            int np[2];
            pipe(np);
            if(fork() == 0){
                new_proc(np);
            }
            else{
                close(np[0]);
                if(is_prime(n)){
                    write(np[1], &n, 4);
                }
                while(read(p[0], &n, 4)){
                    if(is_prime(n)){
                        write(np[1], &n, 4);
                    }
                }
                close(p[0]);
                close(np[1]);
                wait(0);
            }
        }
        exit(0);
}

int main(int argc, char *argv[])
{
    int p[2];
    pipe(p);
    if(fork() == 0){
        new_proc(p);
    }
    else{
        //第一个进程将2-35写入管道p
        close(p[0]);
        for(int i = 2; i < 36; i++){
            write(p[1], &i, 4);
        }
        close(p[1]);
        wait(0);
    }
    exit(0);
}