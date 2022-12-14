#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <poll.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct pollfd *pfds;

void handle_pipe(int pipefd) {
        char    buf[1024];
        ssize_t nread;

        while ((nread = read(pipefd, buf, sizeof(buf))) > 0) {
                fwrite(buf, 1, nread, stdout);
                // добавляется запись в буфер на отправку
        }
}

int main(int argc, char **argv) {
        pfds = calloc(argc, sizeof(struct pollfd));
        for (int i = 1; i < argc; i++) {
                unlink(argv[i]);
                mkfifo(argv[i], 0666);
                pfds[i-1].fd = open(argv[i], O_RDONLY | O_NONBLOCK);
                pfds[i-1].events = POLLIN;
        }
        for (;;) {
                poll(pfds, argc - 1, -1);
                for (int i = 0; i < argc - 1; i++) {
                        if ((pfds[i].revents & POLLIN) == POLLIN) {
                                handle_pipe(pfds[i].fd);
                        }
                }
        }
        return 0;
}
