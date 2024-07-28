#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1000

typedef unsigned short us;

typedef struct NodeQueue {
    int data;
    struct NodeQueue *next;
} NodeQueue;

typedef struct Queue {
    NodeQueue *front;
    NodeQueue *rear;
} Queue;

typedef struct NodeStack {
    int data;
    struct NodeStack *next;
} NodeStack;

typedef struct Stack {
    NodeStack *top;
} Stack;

typedef struct PriorityQueueItem {
    int data;
    int priority;
} PriorityQueueItem;

typedef struct PriorityQueue {
    int size;
    PriorityQueueItem items[MAXSIZE];
} PriorityQueue;

void initQueue(Queue *q);
void enqueue(Queue *q, int value);
int dequeue(Queue *q);
int getFront(Queue *q);
int isQueueEmpty(Queue *q);

void initStack(Stack *s);
void pushStack(Stack *s, int value);
void popStack(Stack *s);
int topStack(Stack *s);
int isStackEmpty(Stack *s);

PriorityQueue* createPriorityQueue();
void insertPriorityQueue(PriorityQueue *pq, int data, int priority);
void removePriorityQueue(PriorityQueue *pq);
int getTopPriorityQueue(PriorityQueue *pq);
void heapifyUp(PriorityQueue *pq, int index);
void heapifyDown(PriorityQueue *pq, int index);

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int x, command, i;
        int isQueue = 1, isStack = 1, isPriorityQueue = 1;
        PriorityQueue *pq = createPriorityQueue();
        Queue q;
        Stack s;

        initQueue(&q);
        initStack(&s);

        for (i = 0; i < n; ++i) {
            scanf("%d %d", &command, &x);

            if (command == 1) {
                insertPriorityQueue(pq, x, x);
                pushStack(&s, x);
                enqueue(&q, x);
            } else {
                if (isStackEmpty(&s) || topStack(&s) != x)
                    isStack = 0;
                else
                    popStack(&s);

                if (isQueueEmpty(&q) || getFront(&q) != x)
                    isQueue = 0;
                else
                    dequeue(&q);

                if (getTopPriorityQueue(pq) != x)
                    isPriorityQueue = 0;
                else
                    removePriorityQueue(pq);
            }
        }

        if (!isStack && !isQueue && !isPriorityQueue)
            printf("impossible\n");
        else if (isStack && isPriorityQueue || isStack && isQueue || isPriorityQueue && isQueue)
            printf("not sure\n");
        else if (isPriorityQueue)
            printf("priority queue\n");
        else if (isQueue)
            printf("queue\n");
        else if (isStack)
            printf("stack\n");
    }

    return 0;
}

void initQueue(Queue *q) {
    q->front = q->rear = NULL;
}

void enqueue(Queue *q, int value) {
    NodeQueue *newNode = (NodeQueue *)malloc(sizeof(NodeQueue));
    if (!newNode) exit(1);
    newNode->data = value;
    newNode->next = NULL;

    if (q->rear) {
        q->rear->next = newNode;
    } else {
        q->front = newNode;
    }
    q->rear = newNode;
}

int dequeue(Queue *q) {
    if (isQueueEmpty(q)) exit(1);
    
    NodeQueue *temp = q->front;
    int value = temp->data;
    q->front = q->front->next;
    if (!q->front) q->rear = NULL;
    free(temp);

    return value;
}

int getFront(Queue *q) {
    if (isQueueEmpty(q)) exit(1);
    return q->front->data;
}

int isQueueEmpty(Queue *q) {
    return q->front == NULL;
}

void initStack(Stack *s) {
    s->top = NULL;
}

void pushStack(Stack *s, int value) {
    NodeStack *newNode = (NodeStack *)malloc(sizeof(NodeStack));
    if (!newNode) exit(1);
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
}

void popStack(Stack *s) {
    if (isStackEmpty(s)) exit(1);

    NodeStack *temp = s->top;
    s->top = s->top->next;
    free(temp);
}

int topStack(Stack *s) {
    if (isStackEmpty(s)) exit(1);
    return s->top->data;
}

int isStackEmpty(Stack *s) {
    return s->top == NULL;
}

PriorityQueue* createPriorityQueue() {
    PriorityQueue *pq = (PriorityQueue *)malloc(sizeof(PriorityQueue));
    if (pq) pq->size = 0;
    return pq;
}

void insertPriorityQueue(PriorityQueue *pq, int data, int priority) {
    if (pq->size == MAXSIZE) exit(1);

    pq->items[pq->size].data = data;
    pq->items[pq->size].priority = priority;
    heapifyUp(pq, pq->size);
    ++pq->size;
}

void removePriorityQueue(PriorityQueue *pq) {
    if (pq->size == 0) exit(1);

    --pq->size;
    pq->items[0] = pq->items[pq->size];
    heapifyDown(pq, 0);
}

int getTopPriorityQueue(PriorityQueue *pq) {
    if (pq->size == 0) exit(1);
    return pq->items[0].data;
}

void heapifyUp(PriorityQueue *pq, int index) {
    int parent = (index - 1) / 2;
    PriorityQueueItem temp;

    while (index > 0 && pq->items[parent].priority <= pq->items[index].priority) {
        temp = pq->items[index];
        pq->items[index] = pq->items[parent];
        pq->items[parent] = temp;
        index = parent;
        parent = (index - 1) / 2;
    }
}

void heapifyDown(PriorityQueue *pq, int index) {
    int child = 2 * index + 1;
    PriorityQueueItem temp;

    while (child < pq->size) {
        if (child + 1 < pq->size && pq->items[child].priority < pq->items[child + 1].priority) {
            child++;
        }
        if (pq->items[index].priority >= pq->items[child].priority) break;

        temp = pq->items[index];
        pq->items[index] = pq->items[child];
        pq->items[child] = temp;

        index = child;
        child = 2 * index + 1;
    }
}
