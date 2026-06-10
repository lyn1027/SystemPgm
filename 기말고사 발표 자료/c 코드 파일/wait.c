#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// wait: wait(&status) 기반 자식 프로세스 종료 동기화 대기
int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("[Child] Working...\n");
        sleep(2);
        printf("[Child] Exiting.\n");
    } else if (pid > 0) {
        int status;
        printf("[Parent] Waiting for child to finish...\n");
        wait(&status); // 자식 프로세스 종료 대기 동기화
        printf("[Parent] Child finished execution.\n");
    } else {
        perror("fork error");
        return 1;
    }
    return 0;
}