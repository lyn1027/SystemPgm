#include <stdio.h>
#include <unistd.h>

// ln: link()를 이용한 하드 링크 생성
int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <target_file> <link_name>\n", argv[0]);
        return 1;
    }

    // 시스템 호출 link() 사용
    if (link(argv[1], argv[2]) == 0) {
        printf("Hard link created successfully: %s -> %s\n", argv[2], argv[1]);
    } else {
        perror("ln error");
        return 1;
    }
    return 0;
}