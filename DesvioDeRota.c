#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define INFINITY 100000
#define MAX_NODES 101010

int visited[MAX_NODES];
int distances[MAX_NODES];

typedef struct Node {
    int vertex, weight;
    struct Node* next;
} Node;

typedef struct Graph {
    Node* adjacencyList;
} Graph;

Graph* createGraph(int size);
Node* createNode(int vertex, int weight);
void runDijkstra(Graph* graph, int startVertex, int totalVertices);
void addEdge(Graph* graph, int fromVertex, int toVertex, int weight);

int main() {
    int n, m, c, k, a, b, w;

    while (scanf("%d %d %d %d", &n, &m, &c, &k), (c && n && m && k)) {
        Graph* graph = createGraph(n + 1);

        for (int i = 0; i < m; ++i) {
            scanf("%d %d %d", &a, &b, &w);

            if ((a >= c && b >= c) || ((a < c) && (b < c) && (abs(a - b) == 1))) {
                addEdge(graph, a, b, w);
                addEdge(graph, b, a, w);
            }

            if (a >= c && b < c) {
                addEdge(graph, b, a, w);
            }

            if (b >= c && a < c) {
                addEdge(graph, a, b, w);
            }
        }

        runDijkstra(graph, k, n);
        printf("%d\n", distances[c - 1]);
    }

    return 0;
}

void runDijkstra(Graph* graph, int startVertex, int totalVertices) {
    Node* currentNode;
    int i, j, v;

    for (i = 0; i < totalVertices; ++i)
        distances[i] = INFINITY;

    memset(visited, false, sizeof(visited));
    distances[startVertex] = 0;

    for (i = 0; i < totalVertices; ++i) {
        v = -1;
        for (j = 0; j < totalVertices; ++j)
            if (!visited[j] && (v == -1 || distances[j] < distances[v]))
                v = j;

        if (distances[v] == INFINITY)
            break;

        visited[v] = true;

        for (currentNode = graph->adjacencyList[v].next; currentNode != NULL; currentNode = currentNode->next) {
            int neighbor = currentNode->vertex;
            int weight = currentNode->weight;

            if (distances[v] + weight < distances[neighbor])
                distances[neighbor] = distances[v] + weight;
        }
    }
}

Graph* createGraph(int size) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->adjacencyList = (Node*) malloc(sizeof(Node) * (size + 1));

    for (int i = 0; i < size; ++i)
        graph->adjacencyList[i].next = NULL;

    return graph;
}

Node* createNode(int vertex, int weight) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->weight = weight;
    newNode->next = NULL;

    return newNode;
}

void addEdge(Graph* graph, int fromVertex, int toVertex, int weight) {
    Node* newNode = createNode(fromVertex, weight);
    newNode->next = graph->adjacencyList[toVertex].next;
    graph->adjacencyList[toVertex].next = newNode;
}
