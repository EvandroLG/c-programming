#include <stdio.h>

int strcmp_array_version(char *s, char *t) {
    int i;

    for (i = 0; s[i] == t[i]; i++) {
        if (s[i] == '\0') {
            return 0;
        }     
    }

    return s[i] - t[i];
}

int main() {
    char dynamics[] = "xxx";
    char statics[] = "xxxx";

    printf("%i\n", strcmp_array_version(statics, dynamics));

    return 0;
}
