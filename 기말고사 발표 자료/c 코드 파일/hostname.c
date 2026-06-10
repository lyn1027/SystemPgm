#include <stdio.h>
#include <unistd.h>

// hostname: 시스템의 호스트 이름 출력
int main() {
    char name[1024];
    if (gethostname(name, sizeof(name)) == 0) {
        printf("%s\n", name);
    } else {
        perror("hostname error");
        return 1;
    }
    return 0;
}