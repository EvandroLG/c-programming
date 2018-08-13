#include <stdio.h>
#include <ctype.h>

void makeLowerCase(char* str) {
    int i = 0; 

    while (str[i]) {
        str[i] = tolower(str[i]);
        i++;
    }
}

void makeUpperCase(char* str) {
    int i = 0;

    while (str[i]) {
        str[i] = toupper(str[i]);
        i++;
    }
}

int main() {
    char str[] = "Evandro is learn to program in C, finally";

    makeLowerCase(str);
    printf("%s\n", str);

    makeUpperCase(str);
    printf("%s\n", str);

    return 0;
}
