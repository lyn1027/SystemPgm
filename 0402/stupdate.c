#include <stdio.h>
#include <stdlib.h>
#include "student.h"

int main(int argc, char* argv[]) {
    struct student rec;
    FILE *fp;
    int id;
    if (argc != 2) exit(1);
    fp = fopen(argv[1], "rb+"); // 읽기/쓰기 동시 모드

    printf("수정할 학번 입력: ");
    while (scanf("%d", &id) == 1) {
        fseek(fp, (id - START_ID) * sizeof(rec), SEEK_SET);
        if (fread(&rec, sizeof(rec), 1, fp) > 0 && rec.id != 0) {
            printf("현재 점수: %d, 새로운 점수: ", rec.score);
            scanf("%hd", &rec.score); // 점수 수정

            // fread 후에는 포인터가 다음 칸으로 가버리므로 다시 뒤로 한 칸 옮겨줘야 함
            fseek(fp, -sizeof(rec), SEEK_CUR);
            fwrite(&rec, sizeof(rec), 1, fp);
        }
        printf("추가 수정 학번(종료: 0): ");
    }
    fclose(fp);
    return 0;
}
