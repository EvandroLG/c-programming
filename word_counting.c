#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
    int character, new_word, char_counter, state;

    state = OUT;
    new_word = char_counter = 0;

    while ((character = getchar()) != EOF) {
        ++char_counter;

        if (character == '\n') {
            ++char_counter;
        }
        
        if (character == ' ' || character == '\n' || character == '\t') {
            state = OUT;
        } else if (state == OUT) {
            state = IN;
            ++new_word;
        }
    }

    printf("%d %d\n", new_word, char_counter);

    return 0;
}
