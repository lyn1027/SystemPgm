#include <stdio.h>
#include <stdlib.h>
#include "student.h"

int main(int argc, char* argv[]) {
    struct student rec;
    FILE *fp;
    if (argc != 2) exit(1);

    fp = fopen(argv[1], "wb"); // 바이너리 쓰기 모드

    printf("학번 이름 점수를 입력하세요\n");
    while (scanf("%d %s %hd", &rec.id, rec.name, &rec.score) == 3) {
        // (입력학번 - 시작학번) * 구조체크기 만큼 건너뛰어서 저장
        fseek(fp, (rec.id - START_ID) * sizeof(rec), SEEK_SET);
        fwrite(&rec, sizeof(rec), 1, fp);
    }
    fclose(fp);
    return 0;
}
