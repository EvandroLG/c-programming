#include <stdio.h>

/*
 * for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
        s[i] = c;
 * Exercise 2-2. Write a loop equivalent to the for loop above without using && or ||.
*/

int main() {
    const int LIMIT = 100;
    char string[LIMIT];
    int c;
    int i = 0;

    while ((c = getchar()) != EOF) {
        if (i >= LIMIT) {
            break;
        }

        if (c == '\n') {
            break;
        }

        string[i] = c;

        i = i + 1;
    }

    printf("%s\n", string);

    return 0;
}
