#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct {
    int start, end, weight;
} Edge;

Edge graph[250];
int parent[70];

int compareEdges(const void *, const void *);
int findParent(int);
int kruskalAlgorithm(int);

int main() {
    int nodes, edges, i;
    scanf("%d %d", &nodes, &edges);

    for (i = 0; i < edges; ++i) {
        scanf("%d %d %d", &graph[i].start, &graph[i].end, &graph[i].weight);
    }

    qsort(graph, edges, sizeof(Edge), compareEdges);

    for (i = 1; i <= nodes; ++i) {
        parent[i] = i;
    }

    printf("%d\n", kruskalAlgorithm(edges));

    return 0;
}

int compareEdges(const void *a, const void *b) {
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}

int findParent(int node) {
    if (node == parent[node])
        return node;
    return findParent(parent[node]);
}

int kruskalAlgorithm(int edgeCount) {
    int i, totalWeight = 0, rootStart, rootEnd;

    for (i = 0; i < edgeCount; ++i) {
        rootStart = findParent(graph[i].start);
        rootEnd = findParent(graph[i].end);

        if (rootStart != rootEnd) {
            parent[rootStart] = rootEnd;
            totalWeight += graph[i].weight;
        }
    }

    return totalWeight;
}
