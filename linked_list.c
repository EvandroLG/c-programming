#include <stdio.h>

typedef struct history {
    char *url;
    struct history *next;
} history;

void printHistory(history *pHistory) {
    while (pHistory != NULL) {
        printf("%s\n", pHistory->url);
        pHistory = pHistory->next;
    }
}

int main() {
    history google = {"www.google.com", NULL}; 
    history facebook = {"www.facebook.com", &google};
    history youtube = {"www.youtube.com", &facebook};
    history amazon = {"www.amazon.com", &youtube};

    printHistory(&amazon);

    return 0;
}
