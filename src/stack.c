#include <pinelibs/stack.h>
#include <stdlib.h>
#include <pinelibs/bool.h>

Bool stackIsEmpty(Stack s) {
	return s == newStack;
}

void stackPush(Stack* s, int value) {
	Node* newnode = (Node*) malloc(sizeof(Node));
	if (newnode == NULL) {
		exit(EXIT_FAILURE);
	}
	newnode->value = value;
	newnode->next = *s;
	*s = newnode;
}

int stackPop(Stack* s) {
	if (*s == newStack) {
		return POP_FAILURE;
	}
	Node* n = *s;
	int value = n->value;
	*s = n->next;
	free(n);
	return value;
}

int stackTop(Stack s) {
	return s->value;
}
