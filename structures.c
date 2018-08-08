#include <stdio.h>

struct personFavorites {
    char *food;
    char *language;
};

typedef struct person {
    const char *name;
    int age;
    struct personFavorites favoriteThings;
} person;

void getPersonInfo(struct person thePerson) {
    printf("Name: %s\n", thePerson.name);
    printf("Age: %d\n", thePerson.age);

    struct personFavorites favorites = thePerson.favoriteThings;

    printf("Favorite food: %s\n", favorites.food);
    printf("Favorite programming language: %s\n", favorites.language);
}

void getMemoryLocations(struct person thePerson) {
    printf("Name: %p\n", thePerson.name);
    printf("Age: %p\n", &thePerson.age);
}

void setNewAge(person *thePerson, int newAge) {
    (*thePerson).age = newAge;
}

int main() {
    person evandro = {
      "Evandro",
      30,
      {"Stroganoff", "Lua"}
    };

    getPersonInfo(evandro);
    printf("\n");
    getMemoryLocations(evandro);
    printf("\n");

    setNewAge(&evandro, 31);
    printf("\n");
    getPersonInfo(evandro);
    printf("\n");
    getMemoryLocations(evandro);
    printf("\n");

    return 0;
};
