#include <stdio.h>

void file_copy(FILE *firstFile, FILE *secondFile) {
    int c;

    // read and write every characters from the file 
    // into the second file
    while ((c = getc(firstFile)) != EOF) {
        putc(c, secondFile);
    }
}

int main(int argc, char *argv[]) {
    FILE *file;

    // if we don't receive args
    if (argc == 1) {
        file_copy(stdin, stdout); 
    } else {
        while (--argc > 0) {
            file = fopen(*++argv, "r");

            if (file == NULL) {
                printf("cat: can't open %s\n", *argv);

                return 1;
            } else {
                file_copy(file, stdout);
                fclose(file);
            }
        }
    }

    return 0;
}
