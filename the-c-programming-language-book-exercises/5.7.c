#include <stdio.h>
#include <string.h>

/*
* 5.7. Rewrite read lines to store lines in an array supplied by main,
* rather than calling alloc to maintain storage. How much faster is the program?
*/

#define MAXLINES 5000

char *lineptr[MAXLINES];

int get_line(char string[], int limit) {
    int c, i;

    for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        string[i] = c;
    }

    if (c == '\n') {
        string[i] = c;
        i = i + 1;
    }

    string[i] = '\0';

    return i;
}

char *alloc(int);

int readlines(char *lineptr[], int maxlines) {
    int len;
    int nlines = 0;
    const int MAXLEN = 1000;
    char *p, line[MAXLEN];

    while ((len = get_line(line, MAXLEN)) > 0) {
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

void swap(char *value[], int i, int j) {
    char *temp = value[i];
    value[i] = value[j];
    value[j] = temp;
}

void qsort(char *value[], int left, int right) {
    int last;

    if (left >= right) {
        return;
    }

    swap(value, left, (left + right) / 2);
    last = left;

    for (int i = left + 1; i <= right; i++) {
        if (strcmp(value[i], value[left]) < 0) {
            swap(value, ++last, i);
        }
    }

    swap(value, left, last);
    qsort(value, left, last - 1);
    qsort(value, last + 1, right);
}

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
