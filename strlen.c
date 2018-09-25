#include <stdio.h>

int _strlen(char *string) {
    char *p = string;

    while (*p != '\0') {
        p++;
    }

    return p - string;
}

int main()
{
    char array[] = "abc";
    int result = &array[2] - array;
    printf("%i\n", _strlen("Lua is a great language!"));

    return 0;
}
