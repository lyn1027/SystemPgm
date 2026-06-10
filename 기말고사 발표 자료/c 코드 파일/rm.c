#include <stdio.h>
#include <unistd.h>

// rm: unlink() 함수를 사용한 파일 영구 삭제
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file_name>\n", argv[0]);
        return 1;
    }
    if (unlink(argv[1]) == 0) {
        printf("File '%s' deleted successfully.\n", argv[1]);
    } else {
        perror("rm error");
        return 1;
    }
    return 0;
}