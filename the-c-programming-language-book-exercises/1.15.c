#include <stdio.h>

/*
* Exercise 1-15. Rewrite the temperature conversion program of Section 1.2 to use a function for conversion
*/

void convertTemperature(int fahr, int *celsius) {
    *celsius = 5 * (fahr - 32) / 9;
}

int main() {
    int celsius;
    int const UPPER = 300;

    for (int fahr = 0; fahr <= UPPER; fahr += 20) {
       convertTemperature(fahr, &celsius); 
       printf("%i %i\n", fahr, celsius);
    }

    return 0;
}
