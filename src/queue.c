#include <pinelibs/queue.h>
#include <stdlib.h>
#include <pinelibs/bool.h>

Queue newQueue() {
	Queue q;
	q.front = NULL;
	return q;
}

Bool queueIsEmpty(Queue q) {
	return q.front == NULL;
}

void queueInsert(Queue* q, int value) {
	Node* newnode = (Node*) malloc(sizeof(Node));
	if (newnode == NULL) {
		exit(EXIT_FAILURE);
	}
	newnode->value = value;
	newnode->next = NULL;
	if (q->front == NULL) {
		q->front = newnode;
		q->rear = newnode;
		return;
	}
	(q->rear)->next = newnode;
}

int queueRemove(Queue* q) {
	if (q->front == NULL) {
		return POP_FAILURE;
	}
	Node* n = q->front;
	int value = n->value;
	q->front = n->next;
	free(n);
	if (q->front == NULL) {
		q->rear = NULL;
	}
	return value;
}

int front(Queue q) {
	return (q.front)->value;
}

int rear(Queue q) {
	return (q.rear)->value;
}
