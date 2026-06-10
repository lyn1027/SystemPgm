#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

// cat: 저수준 open(), read(), write() 파일 출력
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file_name>\n", argv[0]);
        return 1;
    }
    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) { perror("cat open error"); return 1; }

    char buf[1024];
    ssize_t n_read;
    while ((n_read = read(fd, buf, sizeof(buf))) > 0) {
        write(STDOUT_FILENO, buf, n_read);
    }
    close(fd);
    return 0;
}