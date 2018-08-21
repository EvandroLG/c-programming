#include <stdio.h>

int main() {
    char ch = 'a';

    while(ch <= 'z') {
        printf("value %d | char %c\n", ch, ch);
        ch = ch + 1;
    }

    return 0;
}
