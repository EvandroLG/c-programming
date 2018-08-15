#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    const char *value = "Evandro Leopoldino Goncalves";
    char *str = (char *) malloc(strlen(value) + 1 * sizeof(char));
    strcpy(str, value);
    printf("String %s, Address %p\n", str, str);
    free(str);

    return 0;
}
