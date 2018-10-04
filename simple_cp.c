#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define PERMISSION 0666

void error(char *fmt, ...) {
    exit(1);
}

int main(int argc, char *argv[]) {
    int file, to, n;
    char buffer[BUFSIZ];

    if (argc != 3) {
        error("Usage: cp from to");
    }

    if ((file = open(argv[1], O_RDONLY, 0)) == -1) {
        error("cp: can't open %s", argv[1]);
    }

    if ((to = creat(argv[2], PERMISSION)) == -1) {
        error("cp: can't create %s, mode %03o", argv[2], PERMISSION);
    }

    while ((n = read(file, buffer, BUFSIZ)) > 0) {
        if (write(to, buffer, n) != n) {
            error("cp: write error on file %s", argv[2]);
        }
    }

    return 0;
}
