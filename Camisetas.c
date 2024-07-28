#include <stdio.h>
#include <string.h>

typedef struct {
    char name[60];
    char color[20];
    char size;
} Shirt;

void sortByName(Shirt *, unsigned short);
void sortBySize(Shirt *, unsigned short);
void sortByColor(Shirt *, unsigned short);

int main() {
    unsigned short numShirts;
    unsigned short i;

    scanf("%hu", &numShirts);

    while (numShirts > 0) {
        Shirt shirts[numShirts];

        for (i = 0; i < numShirts; i++) {
            scanf(" %[^\n]", shirts[i].name);
            scanf("%s %c", shirts[i].color, &shirts[i].size);
        }

        sortByName(shirts, numShirts);
        sortBySize(shirts, numShirts);
        sortByColor(shirts, numShirts);

        for (i = 0; i < numShirts; i++) {
            printf("%s %c %s\n", shirts[i].color, shirts[i].size, shirts[i].name);
        }

        scanf("%hu", &numShirts);
        if (numShirts > 0) {
            printf("\n");
        }
    }

    return 0;
}

void sortByName(Shirt *shirts, unsigned short size) {
    unsigned short i, j;
    Shirt pivot;

    for (i = 1; i < size; i++) {
        j = i - 1;
        pivot = shirts[i];

        while (j >= 0 && strcmp(shirts[j].name, pivot.name) > 0) {
            shirts[j + 1] = shirts[j];
            j--;
        }
        shirts[j + 1] = pivot;
    }
}

void sortByColor(Shirt *shirts, unsigned short size) {
    unsigned short i, j;
    Shirt pivot;

    for (i = 1; i < size; i++) {
        j = i - 1;
        pivot = shirts[i];

        while (j >= 0 && strcmp(shirts[j].color, pivot.color) > 0) {
            shirts[j + 1] = shirts[j];
            j--;
        }
        shirts[j + 1] = pivot;
    }
}

void sortBySize(Shirt *shirts, unsigned short size) {
    unsigned short i, j;
    Shirt pivot;

    for (i = 1; i < size; i++) {
        j = i - 1;
        pivot = shirts[i];

        while (j >= 0 && shirts[j].size < pivot.size) {
            shirts[j + 1] = shirts[j];
            j--;
        }
        shirts[j + 1] = pivot;
    }
}
