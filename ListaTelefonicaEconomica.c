#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_STRINGS 100050
#define MAX_LENGTH 250

typedef struct {
    char s1[MAX_LENGTH];
} String;

String sstrings[MAX_STRINGS];

int compare(const void *, const void *);

int main() {
    unsigned t, i, j;

    while (scanf("%u", &t) != EOF) {
        i = 0;
        unsigned aux = t;
        while (t--) {
            scanf("%s", sstrings[i++].s1);
        }

        unsigned ans = 0;
        qsort(sstrings, i, sizeof(String), compare);

        for (i = 1; i < aux; ++i) {
            for (j = 0; sstrings[i].s1[j]; ++j) {
                if (sstrings[i].s1[j] == sstrings[i - 1].s1[j]) {
                    ++ans;
                } else {
                    break;
                }
            }
        }

        printf("%u\n", ans);
    }

    return 0;
}

int compare(const void *a, const void *b) {
    return strcmp(((String *)a)->s1, ((String *)b)->s1);
}
