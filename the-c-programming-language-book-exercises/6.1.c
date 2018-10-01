#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*
 * Exercise 6-1. Our version of getwords does not properly
 * handle underscores, string constants, comments, or preprocessor control lines.
 * Write a better version.
*/

#define MAX_WORD 100

struct key {
    char *word;
    int count;
};

struct key keytab[] = {
    "auto", 0,
    "break", 0,
    "case", 0,
    "char", 0,
    "const", 0,
    "const", 0,
    "continue", 0,
    "default", 0,
    "unsigned", 0,
    "void", 0,
    "volatile", 0,
    "while", 0,
    "for", 0,
    "enum", 0,
    "if", 0,
    "else", 0,
    "switch", 0,
    "int", 0,
    "float", 0,
};

#define TOTAL_KEYWORDS (sizeof keytab / sizeof keytab[0])
#define BUFFER_SIZE 100

char buffer[BUFFER_SIZE];
int buffer_free = 0;

int getch() {
    return (buffer_free > 0) ? buffer[--buffer_free] : getchar();
}

void ungetch(int c) {
    if (buffer_free >= BUFFER_SIZE) {
        printf("ungetch: too many characters\n");
    } else {
        buffer[buffer_free++] = c;
    }
}

int get_word(char *word, int limit) {
    int c, t;

    char *w = word;

    while (isspace(c = getch()));

    if (c != EOF) {
        *w++ = c;
    }

    if (!isalpha(c)) {
        if (c == '#') {
            for (c = getch(); c != '\n'; c = getch());
        } else if (c == '/') {
            if ((c = getch()) == '/') {
                for (c = getch(); c != '\n'; c = getch());
            } else if (c == '*') {
                for (c = getch(), t = getch(); c != '*' && t != '/'; c = getch(), t = getch()) {
                    ungetch(t);
                } 
            }
        }

        if (c != '\n') {
            ungetch(c);
        }


        *w = '\0';
        return c;
    }

    for (; --limit > 0; w++) {
        if (!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }
    }

    *w = '\0';
    return word[0];
}

int binary_search(char *word, struct key tab[], int size) {
    int low = 0;
    int high = size - 1;
    int middle;
    int condition;

    while (low <= high) {
        middle = (low + high) / 2;
        condition = strcmp(word, tab[middle].word);

        if (condition < 0) {
            high = middle - 1;
        } else if (condition > 0) {
            low = middle + 1; 
        } else {
            return middle;
        }
    }

    return -1;
}

int main() {
    int n;
    char word[MAX_WORD];

    while (get_word(word, MAX_WORD) != EOF) {
        if (isalpha(word[0])) {
            if ((n = binary_search(word, keytab, TOTAL_KEYWORDS)) >= 0) {
                keytab[n].count++;
            }
        }
    }

    for (n = 0; n < TOTAL_KEYWORDS; n++) {
        if (keytab[n].count > 0) {
            printf("%4d %s\n", keytab[n].count, keytab[n].word);
        }
    }

    return 0;
}
