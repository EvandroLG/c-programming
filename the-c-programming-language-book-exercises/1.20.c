#include <stdio.h>

/*
 * Exercise 1-20. Write a program detab that replaces tabs
 * in the input with the proper number of blanks to space to the next tab stop.
 * Assume a fixed set of tab stops, say every n columns.
 * Should n be a variable or a symbolic parameter?
*/

int main() {
    int const TAB_INCREMENT = 3;
    int c;
    int i = 4;

    while ((c=getchar()) != EOF) {
        if (c == '\t') {
            while (i >= 0) {
                putchar(' '); 
                i = i - 1;
            }

            i = 3;
        } else {
            putchar(c);
        }
    }

    return 0;
}
