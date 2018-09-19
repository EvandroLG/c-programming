#include <stdio.h>
#include <string.h>
#include <assert.h>

/*
* Exercise 4-1. Write the function strrindex (s, t), which returns the position
* of the right most occurrence of t in s, or - 1 if there is none
*/

int strindex(char string[], char pattern[]) {
    int i;
    int j;
    int k;

    for (i = strlen(string) - strlen(pattern); i >= 0; i--) {
        for (j = 0, k = i; pattern[j] != '\0' && pattern[j] == string[k]; j++, k++);

        if (j > 0 && pattern[j] == '\0') {
            return i;
        }
    }

    return -1;
}

int main() {
    int output = strindex("Lua is a very good programming language, while Pearl is a terrible language", "is");
    assert(output == 53);

    return 0;
}

