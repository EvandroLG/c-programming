#include <stdio.h>

/*
 * Exercise 1-19. Write a function reverse(s) that reverses the character strings.
 * Use it to write a program that reverses its input a line at a time
*/

void reverse(char string[], int size) {
    int count = 0;

    for (int i = size; i >= 0; i--) {
        string[count] = string[i];
        count = count + 1;
    }

    printf("%s\n", string);
}

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
    const int MAX_LINES = 1000;
    int len;
    char line[MAX_LINES];

    while ((len = get_line(line, MAX_LINES)) > 0) {
        reverse(line, len);
    }

    return 0;
}
