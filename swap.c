#include <stdio.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int x = 10;
    int y = 20;

    swap(&x, &y);

    printf("x = %i\n", x);
    printf("y = %i\n", y);

    return 0;
}
