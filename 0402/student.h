/* student.h - 학생 레코드 구조체 정의 */
struct student {
    int id;           // 학번 정수형
    char name[20];    // 이름 문자열
    short score;      // 점수 정수형
};

#define START_ID 1001
