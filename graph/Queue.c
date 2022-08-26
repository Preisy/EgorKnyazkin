#include "Queue.h"
#include <stdio.h>
#include "stdlib.h"

Queue getQueue() {
    Queue res;
    res.head = NULL;
    return res;
}

QNode* getQNode(Dot* dot) {
    QNode* res = calloc(1, sizeof (QNode));
    res->dot = dot;
    return res;
}

int addQueue(Queue* this, Dot* dot) {
    if (this == NULL) return 1;
    QNode* node = getQNode(dot);

    if (this->head == NULL) {
        this->head = node;
        return 0;
    }

    node->next = this->head;
    this->head = node;
    return 0;
}

Dot* popQueue(Queue* this) {
    if (this == NULL || this->head == NULL) return NULL;

    QNode* it = this->head;
    QNode* prev = NULL;
    for (; it->next != NULL; it = it->next) {
        prev = it;
    }

    if (prev == NULL) {
        QNode* tmp = this->head;
        this->head = NULL;
        Dot* res = tmp->dot;
        free(tmp);
        return res;
    } else {
        QNode* tmp = it;
        prev->next = NULL;
        Dot* res = it->dot;
        free(tmp);
        return res;
    }
}


int isEmpty(Queue* this) {
    return this->head == NULL;
}