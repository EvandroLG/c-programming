#include <stdio.h>
#include <stdlib.h>

int main()
{
    int limit = 1000;
    char buffer[limit];
    FILE *pFile = fopen("random.txt", "r");

    if (!pFile) {
        printf("Error: Couldn't write to file");
        return 1;
    }

    while (fgets(buffer, limit, pFile) != NULL) {
        printf("%s", buffer);
    }


    fclose(pFile);

    return 0;
}
