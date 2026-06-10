#include <stdio.h>

// mv: rename() 호출로 파일 이동 및 이름 변경
int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
        return 1;
    }
    if (rename(argv[1], argv[2]) == 0) {
        printf("Moved '%s' to '%s'.\n", argv[1], argv[2]);
    } else {
        perror("mv error");
        return 1;
    }
    return 0;
}