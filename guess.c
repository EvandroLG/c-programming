#include <stdio.h>

int main() {
  printf("\n");

  int secretNumber = 10;
  int numberGuessed = 0;

  while(1) {
    printf("Guess my secret number:");
    scanf(" %d", &numberGuessed);

    if (numberGuessed == secretNumber) {
      printf("You got it!");
      break;
    }
  }

}
