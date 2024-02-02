#include <pinelibs/stack.h>
#include <stdlib.h>
#include <pinelibs/bool.h>

struct Stack {int value; struct Stack* next;};

Stack newStack() {
	return NULL;
}

Bool stackIsEmpty(Stack s) {
	return s == NULL;
}

void stackPush(Stack* s, int value) {
	struct Stack* newnode = (struct Stack*) malloc(sizeof(struct Stack));
	if (newnode == NULL) {
		exit(EXIT_FAILURE);
	}
	newnode->value = value;
	newnode->next = *s;
	*s = newnode;
}

int stackPop(Stack* s) {
	if (*s == NULL) {
		return POP_FAILURE;
	}
	struct Stack* n = *s;
	int value = n->value;
	*s = n->next;
	free(n);
	return value;
}

int stackTop(Stack s) {
	if (s != NULL) {
		return s->value;
	}
}
