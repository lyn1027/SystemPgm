#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

// chmod: 파일 권한 변경 (strtol() 모드 8진수 파싱)
int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <octal_mode> <file_name>\n", argv[0]);
        return 1;
    }
    // 8진수 문자열을 숫자로 변환 (예: "0755")
    mode_t mode = strtol(argv[1], NULL, 8);
    if (chmod(argv[2], mode) == 0) {
        printf("Permissions of '%s' changed to %s.\n", argv[2], argv[1]);
    } else {
        perror("chmod error");
        return 1;
    }
    return 0;
}