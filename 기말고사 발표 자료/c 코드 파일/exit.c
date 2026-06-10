#include <stdio.h>
#include <stdlib.h>

// exit: exit(status) 호출을 통한 자원 정리 및 상태 코드 반환 종료
int main() {
    printf("Performing tasks before immediate exit...\n");
    printf("Exiting system with status code 0.\n");
    exit(0);
}