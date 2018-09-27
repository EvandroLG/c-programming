#include <stdio.h>
#include <string.h>

#define MAXLINES 5000

char *lineptr[MAXLINES];

int _getline(char *, int size);
char *alloc(int);

int readlines(char *lineptr[], int maxlines) {
    int len;
    int nlines = 0;
    const int MAXLEN = 1000;
    char *p, line[MAXLEN];

    while ((len = _getline(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || (p = alloc(len)) == NULL) {
            return -1;
        }

        line[len-1] = '\0';
        strcpy(p, line);
        lineptr[nlines++] = p;
    }

    return nlines;
}

void writelines(char *lineptr[], int nlines) {
    for (int i = 0; i < nlines; i++) {
        printf("%s\n", lineptr[i]);
    }
}

void qsort(char *lineptr[], int left, int right);

int main() {
    int nlines;

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    }

    printf("error: input too big to sort\n");
    return 1;
}
