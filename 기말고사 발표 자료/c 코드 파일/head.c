#include <stdio.h>

// head: 파일의 상단 10줄을 fgets() 루프로 제어하여 출력
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file_name>\n", argv[0]);
        return 1;
    }
    FILE *fp = fopen(argv[1], "r");
    if (!fp) { perror("head open error"); return 1; }

    char line[1024];
    int count = 0;
    while (fgets(line, sizeof(line), fp) != NULL && count < 10) {
        printf("%s", line);
        count++;
    }
    fclose(fp);
    return 0;
}