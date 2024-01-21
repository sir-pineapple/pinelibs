#include <pinelibs/linkedlist.h>
#include <stdlib.h>
#include <pinelibs/bool.h>

LinkedList newLinkedList() {
	return NULL;
}

Bool llIsEmpty(LinkedList l) {
	return l == NULL;
}

int llSize(LinkedList l) {
	int size = 0;
	Node* n = l;
	while (n != NULL) {
		size++;
		n = n->next;
	}
	return size;
}

void llInsertStart(LinkedList* l, int value) {
	Node* newnode = (Node*) malloc(sizeof(Node));
	if (newnode == NULL) {
		exit(EXIT_FAILURE);
	}
	newnode->value = value;
	newnode->next = *l;
	*l = newnode;
}

void llInsertEnd(LinkedList* l, int value) {
	Node* newnode = (Node*) malloc(sizeof(Node));
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
	Node* newnode = (Node*) malloc(sizeof(Node));
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
	Node* n = *l;
	int value = n->value;
	*l = n->next;
	free(n);
	return value;
}

int llRemoveEnd(LinkedList* l) {
	if (*l == NULL) {
		return POP_FAILURE;
	}
	Node* n = *l;
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
	Node* prev = *l;
	for (int i=0; i<index-1; i++) {
		if (prev->next == NULL) {
			break;
		}
		prev = prev->next;
	}
	if (prev->next == NULL) {
		return llRemoveEnd(l);
	}
	Node* n = prev->next;
	int value = n->value;
	prev->next = n->next;
	free(n);
	return value;
}
