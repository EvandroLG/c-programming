#include <stdio.h>

/*
 * Exercise 1-17. Write a program to print all input lines that are longer than 80 characters.
*/

#define MAX_LINES 1000
#define MINIMUM_CHARS 80

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

int main() {
    int len;
    char line[MAX_LINES];

    while ((len = get_line(line, MAX_LINES)) > 0) {
        if (len > MINIMUM_CHARS) {
            printf("%s", line);
        }
    }

    return 0;
}
