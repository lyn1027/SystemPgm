# 컴파일러 및 옵션 설정
CC = gcc
CFLAGS = -Wall -g

# 최종 실행 파일 생성 규칙
app: main.o utils.o
  $(CC) $(CFLAGS) -o app main.o utils.o

# 각 소스 파일을 목적 파일로 컴파일
main.o: main.c
	$(CC) $(CFLAGS) -c main.c

utils.o: utils.c
	$(CC) $(CFLAGS) -c utils.c

# 빌드 결과물 삭제 (정리용)
clean:
	rm -f *.o app
