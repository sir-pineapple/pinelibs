#include <pinelibs/linkedlist.h>
#include <stdlib.h>
#include <pinelibs/bool.h>

struct LinkedList {int value; struct LinkedList* next;};

LinkedList newLinkedList() {
	return NULL;
}

Bool llIsEmpty(LinkedList l) {
	return l == NULL;
}

int llSize(LinkedList l) {
	int size = 0;
	struct LinkedList* n = l;
	while (n != NULL) {
		size++;
		n = n->next;
	}
	return size;
}

void llInsertStart(LinkedList* l, int value) {
	struct LinkedList* newnode = (struct LinkedList*) malloc(sizeof(struct LinkedList));
	if (newnode == NULL) {
		exit(EXIT_FAILURE);
	}
	newnode->value = value;
	newnode->next = *l;
	*l = newnode;
}

void llInsertEnd(LinkedList* l, int value) {
	struct LinkedList* newnode = (struct LinkedList*) malloc(sizeof(struct LinkedList));
	newnode->value = value;
	newnode->next = NULL;
	if (*l == NULL) {
		*l = newnode;
		return;
	}
	Node* n = *l;
	while (n->next != NULL) {
		n = n->next;
	}
	n->next = newnode;
}

void llInsertAt(LinkedList* l, int index, int value) {
	if (index == 0) {
		return llInsertStart(l, value);
	}
	Node* prev = *l;
	for (int i=0; i<index-1; i++) {
		if (prev == NULL) {
			break;
		}
		prev = prev->next;
	}
	if (prev->next == NULL) {
		return llInsertEnd(l, value);
	}
	struct LinkedList* newnode = (struct LinkedList*) malloc(sizeof(struct LinkedList));
	if (newnode == NULL) {
		exit(EXIT_FAILURE);
	}
	newnode->value = value;
	newnode->next = prev->next;
	prev->next = newnode;
}

int llRemoveStart(LinkedList* l) {
	if (*l == NULL) {
		return POP_FAILURE;
	}
	struct LinkedList* n = *l;
	int value = n->value;
	*l = n->next;
	free(n);
	return value;
}

int llRemoveEnd(LinkedList* l) {
	if (*l == NULL) {
		return POP_FAILURE;
	}
	struct LinkedList* n = *l;
	if (n->next == NULL) {
		int value = n->value;
		free(n);
		*l = NULL;
		return value;
	}
	while ((n->next)->next != NULL) {
		n = n->next;
	}
	int value = (n->next)->value;
	free(n->next);
	n->next = NULL;
	return value;
}

int llRemoveAt(LinkedList* l, int index) {
	if (*l == NULL) {
		return POP_FAILURE;
	}
	if (index == 0) {
		return llRemoveStart(l);
	}
	struct LinkedList* prev = *l;
	for (int i=0; i<index-1; i++) {
		if (prev->next == NULL) {
			break;
		}
		prev = prev->next;
	}
	if (prev->next == NULL) {
		return llRemoveEnd(l);
	}
	struct LinkedList* n = prev->next;
	int value = n->value;
	prev->next = n->next;
	free(n);
	return value;
}

int llValAt(LinkedList l, int index) {
	LinkedList n = l;
	for (int i=0; i<index; i++) {
		if (n->next == NULL) {
			break;
		}
		n = n->next;
	}
	return n->value;
}
