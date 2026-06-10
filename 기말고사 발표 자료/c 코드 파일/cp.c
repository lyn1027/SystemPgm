#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

// cp: read() 버퍼를 write()로 복사하는 I/O 루프 구현
int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <source_file> <dest_file>\n", argv[0]);
        return 1;
    }
    int src_fd = open(argv[1], O_RDONLY);
    if (src_fd < 0) { perror("open source"); return 1; }

    int dest_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd < 0) { perror("open destination"); close(src_fd); return 1; }

    char buf[1024];
    ssize_t n_read;
    while ((n_read = read(src_fd, buf, sizeof(buf))) > 0) {
        write(dest_fd, buf, n_read);
    }

    close(src_fd);
    close(dest_fd);
    printf("File copied from '%s' to '%s'.\n", argv[1], argv[2]);
    return 0;
}