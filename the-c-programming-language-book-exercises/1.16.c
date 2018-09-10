#include <stdio.h>

/*
 * Exercise 1-16. Revise the main routine of the longest-line program so it will correctly print the length of arbitrarily long input lines,
 * and as much as possible of the text.
*/

#define MAX_LINE 1000

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

void copy(char from[], char to[]) {
    int i = 0;

    while ((to[i] = from[i]) != '\0') {
        i = i + 1;
    }
}

int main() {
    int len;
    int max = 0;
    char line[MAX_LINE];
    char longest[MAX_LINE];

    while ((len = get_line(line, MAX_LINE)) > 0) {
        if (len > max) {
            max = len;
            copy(line, longest);
        } 
    }

    if (max > 0) {
        printf("\n%i\n", max);
        printf("%s", longest);
    }

    return 0;
}
