#include <stdio.h>
#include <stdlib.h>

int main() {
  int rand1 = 12;
  int rand2 = 15;

  printf("rand1 = %p : rand2 = %p\n\n", &rand1, &rand2);
  printf("size of int %lu\n\n", sizeof(rand2));

  int * pRand1 = &rand1;

  printf("Pointer %p\n\n", pRand1);

  printf("Value %d\n\n", *pRand1);

  return 0;
}
