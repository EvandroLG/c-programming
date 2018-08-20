#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *pRfile = fopen("file.bin", "rb");

    if (pRfile == NULL) {
        char languages[5][60] = {
            "JavaScript\n",
            "Python\n",
            "Ruby\n",
            "Lua\n",
            "C\n"
        };

        char string[60];
        strcpy(string, languages[0]);

        for (int i = 1; i < 5; i++) {
            strcat(string, languages[i]);
        }

        FILE *pWfile = fopen("file.bin", "wb");
        fwrite(string, 1, sizeof(string), pWfile);

        fclose(pWfile);
    }

    unsigned char buffer[60];
    fread(&buffer, sizeof(buffer), 1, pRfile);
    printf("%s", buffer);

    fclose(pRfile);
    return 0;
}
