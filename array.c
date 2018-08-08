#include <stdio.h>
#include <stdlib.h>

int main() {
  char * languages[4] = { "JavaScript", "Lua", "Python", "Ruby" };

  for(int i=0; i < 4; i++) {
    printf("%s : %p\n\n", languages[i], &languages[i]);
  }

  return 0;
}
