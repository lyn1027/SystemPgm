#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

// fork: fork() 호출을 통한 부모/자식 프로세스 분리 실행
int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
        // 자식 프로세스 이미지
        printf("[Child] PID: %d, Parent PID: %d\n", getpid(), getppid());
    } else {
        // 부모 프로세스 이미지
        printf("[Parent] Created Child PID: %d, My PID: %d\n", pid, getpid());
    }
    return 0;
}