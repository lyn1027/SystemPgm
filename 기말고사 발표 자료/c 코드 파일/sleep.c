#include <stdio.h>
#include <unistd.h>

// sleep: sleep() 커널 호출로 프로세스 타이머 지정 시간 일시 중단
int main() {
    printf("Sleeping for 3 seconds...\n");
    sleep(3);
    printf("Woke up successfully!\n");
    return 0;
}