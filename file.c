#include <stdio.h>
#include <stdlib.h>

int main() {
    const char languages[4][11] = {
        "JavaScript",
        "Lua",
        "Python",
        "Ruby"
    };

    FILE *pFile = fopen("random.txt", "w");

    if (!pFile) {
        printf("Error: We couldn't write the file");
        return 1;
    }

    for (int i=0; i < 4; i++) {
        fprintf(pFile, "%s\n", languages[i]);
    }

    fclose(pFile);

    return 0;
}
