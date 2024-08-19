#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define MAX_EDGES 40050
#define MAX_NODES 40000

typedef struct {
    int from, to, weight;
} Edge;

Edge edges[MAX_EDGES];
int parent[MAX_NODES];

int compareEdges(const void *, const void *);
int kruskalAlgorithm(int);
int findComponent(int);

int main() {
    int numNodes, numEdges, i;

    while (scanf("%d %d", &numNodes, &numEdges), numNodes && numEdges) {
        memset(edges, 0, sizeof(edges));
        memset(parent, 0, sizeof(parent));

        for (i = 0; i < numEdges; ++i) {
            scanf("%d %d %d", &edges[i].to, &edges[i].from, &edges[i].weight);
        }

        qsort(edges, numEdges, sizeof(Edge), compareEdges);

        for (i = 1; i <= numNodes; ++i) {
            parent[i] = i;
        }

        printf("%d\n", kruskalAlgorithm(numEdges));
    }

    return 0;
}

int compareEdges(const void *a, const void *b) {
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}

int findComponent(int node) {
    if (node == parent[node])
        return node;
    return findComponent(parent[node]);
}

int kruskalAlgorithm(int numEdges) {
    int i, totalWeight = 0, componentFrom, componentTo;

    for (i = 0; i < numEdges; ++i) {
        componentFrom = findComponent(edges[i].to);
        componentTo = findComponent(edges[i].from);

        if (componentFrom != componentTo) {
            parent[componentFrom] = parent[componentTo];
            totalWeight += edges[i].weight;
        }
    }

    return totalWeight;
}
