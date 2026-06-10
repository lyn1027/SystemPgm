#include <stdio.h>
#include <unistd.h>

// rmdir: 빈 디렉토리 삭제 처리
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_name>\n", argv[0]);
        return 1;
    }
    if (rmdir(argv[1]) == 0) {
        printf("Directory '%s' removed successfully.\n", argv[1]);
    } else {
        perror("rmdir error");
        return 1;
    }
    return 0;
}