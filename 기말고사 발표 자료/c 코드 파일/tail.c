#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

// tail: lseek() 오프셋 역추적을 간소화하여 끝부분 일부 출력 처리
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file_name>\n", argv[0]);
        return 1;
    }
    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) { perror("tail open error"); return 1; }

    // 파일의 끝에서 500바이트 앞으로 이동하여 출력 시도
    off_t offset = lseek(fd, -500, SEEK_END);
    if (offset < 0) {
        lseek(fd, 0, SEEK_SET); // 파일이 500바이트보다 작으면 처음부터
    }

    char buf[1024];
    ssize_t n_read;
    while ((n_read = read(fd, buf, sizeof(buf))) > 0) {
        write(STDOUT_FILENO, buf, n_read);
    }
    close(fd);
    return 0;
}