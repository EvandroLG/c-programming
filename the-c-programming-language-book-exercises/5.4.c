#include <stdio.h>
#include <string.h>
#include <assert.h>

/*
 * Exercise 5-4. Write the function strend (s ,t ), which returns 1 if the string t
 * occurs at the end of the string s, and zero otherwise
*/

int strend(char s[], char t[]) {
    int s_length = strlen(s);
    int t_length = strlen(t);

    if (t_length > s_length) {
        return 0;
    }

    int diff_lenth = s_length - t_length;

    if (s[diff_lenth] == t[0]) {
        for (int i = s_length, j = 0; s[i] != '\0'; i++, j++) {
            if (s[i] != t[j]) {
                return 0;
            }
        }

        return 1;
    }

    return 0;
}

int main() {
    char string[] = "Lua";

    assert(strend(string, "a") == 1);
    assert(strend(string, "Ruby") == 0);
    assert(strend(string, "ua") == 1);

    return 0;
}
