#include <stdio.h>
#include <stdlib.h>
#include "student.h"

int main(int argc, char* argv[]) {
    struct student rec;
    FILE *fp;
    int id;
    if (argc != 2) exit(1);
    fp = fopen(argv[1], "rb");

    do {
        printf("조회할 학번 입력 (종료: 0): ");
        if (scanf("%d", &id) == 1 && id == 0) break;

        // 원하는 학번 위치로 순간이동
        fseek(fp, (id - START_ID) * sizeof(rec), SEEK_SET);

        if ((fread(&rec, sizeof(rec), 1, fp) > 0) && (rec.id != 0))
            printf("학번: %d 이름: %s 점수: %d\n", rec.id, rec.name, rec.score);
        else printf("해당 기록이 없습니다.\n");
    } while (1);

    fclose(fp);
    return 0;
}
