#include <stdio.h>
#include <unistd.h>

// ln_s: symlink()를 이용한 심볼릭 링크 생성
int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <target_file> <link_name>\n", argv[0]);
        return 1;
    }

    // 시스템 호출 symlink() 사용
    if (symlink(argv[1], argv[2]) == 0) {
        printf("Symbolic link created successfully: %s -> %s\n", argv[2], argv[1]);
    } else {
        perror("ln_s error");
        return 1;
    }
    return 0;
}