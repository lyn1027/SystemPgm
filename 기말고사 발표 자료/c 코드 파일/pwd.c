#include <stdio.h>
#include <unistd.h>

// pwd: 현재 작업 디렉토리의 경로 출력
int main() {
    char buf[1024];
    if (getcwd(buf, sizeof(buf)) != NULL) {
        printf("%s\n", buf);
    } else {
        perror("pwd error");
        return 1;
    }
    return 0;
}