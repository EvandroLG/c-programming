#include <stdio.h>
#include <string.h>

union Person {
    int age;
    float height;
    char name[20];
};

int main() {
    union Person person;
    person.height = 1.81;
    person.age = 31;
    strcpy(person.name, "Evandro");

    printf("Memory size occupied by data: %ld\n", sizeof(person));
    printf("%s\n", person.name);

    return 0;
}
