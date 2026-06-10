#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>

// kill: kill(pid, SIGKILL) 시그널 전송을 통한 타겟 프로세스 강제 강제 제어
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <target_pid>\n", argv[0]);
        return 1;
    }
    pid_t pid = atoi(argv[1]);
    // SIGKILL(9) 전송으로 강제 종료 수행
    if (kill(pid, SIGKILL) == 0) {
        printf("Sent SIGKILL to process %d successfully.\n", pid);
    } else {
        perror("kill error");
        return 1;
    }
    return 0;
}