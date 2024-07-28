#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_TEXT_LENGTH 1001
#define MAX_DATA_LENGTH 1001

typedef struct {
    char character;
    unsigned short frequency;
} Data;

void quickSort(Data *array, int left, int right);
void insertionSort(Data *array, unsigned short size);

int main() {
    char text[MAX_TEXT_LENGTH];
    Data data[MAX_DATA_LENGTH];
    bool seen[MAX_TEXT_LENGTH];
    unsigned short dataSize, i, j;
    short freq;
    unsigned int result;

    while (fgets(text, sizeof(text), stdin)) {
        memset(seen, false, sizeof(seen));
        dataSize = 0;

        for (i = 0; text[i]; i++) {
            if (!seen[i]) {
                freq = 0;
                for (j = 0; text[j]; j++) {
                    if (text[i] == text[j]) {
                        seen[j] = true;
                        freq++;
                    }
                }
                data[dataSize].character = text[i];
                data[dataSize].frequency = freq;
                dataSize++;
            }
        }

        quickSort(data, 0, dataSize - 1);
        insertionSort(data, dataSize);

        if (result) {
            printf("\n");
        }
        result = 1;

        for (i = 0; i < dataSize; i++) {
            printf("%c %hu\n", data[i].character, data[i].frequency);
        }
    }

    return 0;
}

void quickSort(Data *array, int left, int right) {
    if (left < right) {
        int i = left, j = right;
        Data pivot = array[(left + right) / 2];
        Data temp;

        while (i <= j) {
            while (array[i].character < pivot.character) i++;
            while (array[j].character > pivot.character) j--;

            if (i <= j) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                i++;
                j--;
            }
        }

        quickSort(array, left, j);
        quickSort(array, i, right);
    }
}

void insertionSort(Data *array, unsigned short size) {
    unsigned short i, j;
    Data key;

    for (i = 1; i < size; i++) {
        key = array[i];
        j = i - 1;

        while (j >= 0 && array[j].frequency > key.frequency) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}
