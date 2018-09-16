#include <stdio.h>

/*
 * Exercise 3-1. Our binary search makes two tests inside the loop,
 * when one would suffice (at the price of more tests outside). 
 * Write a version with only one test inside the loop and measure the difference in run-time.
*/

int binary_search(int value, int array[], int size) {
    int low = 0;
    int high = size - 1;

    int middle = (low + high) / 2;

    while (low <= high && value != array[middle]) {
        if (value < array[middle]) {
            high = middle - 1; 
        } else {
            low = middle + 1; 
        }

        middle = (low + high) / 2;
    }

    if (value == array[middle]) {
        return middle;
    }

    return -1;
}

int main() {
    int array[6] = { 5, 10, 20, 30, 100, 200 };
    int output = binary_search(100, array, 6);
    printf("%i\n", output);

    return 0;
}
