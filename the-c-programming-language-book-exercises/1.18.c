#include <stdio.h>

/*
* Exercise 1-18. Write a program to remove trailing blanks and tabs from each line of input,
* and to delete entirely blank lines.
*/

int get_line(char string[], int limit) {
    int c, i;

    for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        if (c != ' ' || c != '\t') {
            string[i] = c;
        }
    }

    if (c == '\n') {
        string[i] = c;
        i = i + 1;
    }

    string[i] = '\0';

    return i;
}

int removeSpaces(char string[]) {
    int count = 0;

    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] != ' ' && string[i] != '\t') {
            string[count++] = string[i];
        }
    }

    string[count] = '\0';

    return count;
}

int main() {
    const int MAX_LINES = 1000;
    int len;
    char line[MAX_LINES];

    while ((len = get_line(line, MAX_LINES)) > 0) {
        if (removeSpaces(line) > 0) {
            printf("%s", line);
        }
    }

    return 0;
}
