#ifndef LAB_5_PQUEUE_H
#define LAB_5_PQUEUE_H

#include "Graph.h"

typedef struct QNode {
    Dot* dot;
    struct QNode* next;
} QNode;

typedef struct Queue {
    QNode* head;
} Queue;

Queue getQueue();

int addQueue(Queue* this, Dot* dot);

Dot* popQueue(Queue* this);

int isEmpty(Queue* this);

#endif //LAB_5_PQUEUE_H
