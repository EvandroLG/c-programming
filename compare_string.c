#include <stdio.h>
#include <string.h>

int main() {
    char *name = "Lua\n";
    char string[40];

    printf("Which is my favorite programming language?\n");
    fgets(string, sizeof(string), stdin);

    if (strcmp(string, name) == 0) {
        printf("Correct!\n");
    } else {
        printf("Incorrect! My name is %s\n", name);
    }

    return 0;
}
