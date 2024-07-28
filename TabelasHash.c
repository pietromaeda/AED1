#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct LinkedList {
    Node *head;
    Node *tail;
} LinkedList;

void insertToHashTable(LinkedList *, const int, unsigned);
void printHashTable(LinkedList *, unsigned);

int main() {
    unsigned numCases, tableSize;
    int numElements, value;

    scanf("%u", &numCases);

    while (numCases--) {
        scanf("%u %d", &tableSize, &numElements);

        LinkedList hashTable[tableSize];
        for (unsigned i = 0; i < tableSize; ++i) {
            hashTable[i].head = NULL;
            hashTable[i].tail = NULL;
        }

        for (int i = 0; i < numElements; ++i) {
            scanf("%d", &value);
            insertToHashTable(hashTable, value, tableSize);
        }

        printHashTable(hashTable, tableSize);

        if (numCases) {
            printf("\n");
        }
    }

    return 0;
}

void insertToHashTable(LinkedList *hashTable, const int key, unsigned tableSize) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    int index = key % tableSize;
    newNode->data = key;
    newNode->next = NULL;

    if (hashTable[index].tail) {
        hashTable[index].tail->next = newNode;
    } else {
        hashTable[index].head = newNode;
    }

    hashTable[index].tail = newNode;
}

void printHashTable(LinkedList *hashTable, unsigned tableSize) {
    for (unsigned i = 0; i < tableSize; ++i) {
        printf("%u -> ", i);
        Node *current = hashTable[i].head;
        while (current) {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("\\\n");
    }
}
