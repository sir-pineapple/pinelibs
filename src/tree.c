#include <pinelibs/tree.h>
#include <stdlib.h>

Tree newTree(int value) {
	Tree t = (Tree) malloc(sizeof(struct Tree));
	if (t == NULL) {
		exit(1);
	}
	t->value = value;
	t->left = NULL;
	t->right = NULL;
	return t;
}

int treeHeight(Tree t) {
	if (t == NULL) {
		return 0;
	}
	int l = treeHeight(t->left);
	int r = treeHeight(t->right);
	return 1 + ((l > r) ? l : r);
}

void treeLLRot(Tree* t) {
	if (*t != NULL && (*t)->left != NULL && (*t)->left->left != NULL) {
		Tree n = (*t)->left->right;
		(*t)->left->right = *t;
		*t = (*t)->left;
		(*t)->right->left = n;
	}
}

void treeLRRot(Tree* t) {
	if (*t != NULL && (*t)->left != NULL && (*t)->left->right != NULL) {
		Tree l = (*t)->left->right->left;
		Tree r = (*t)->left->right->right;
		(*t)->left->right->left = (*t)->left;
		(*t)->left->right->right = *t;
		*t = (*t)->left->right;
		(*t)->left->right = l;
		(*t)->right->left = r;
	}
}

void treeRLRot(Tree* t) {
	if (*t != NULL && (*t)->right != NULL && (*t)->right->left != NULL) {
		Tree l = (*t)->right->left->left;
		Tree r = (*t)->right->left->right;
		(*t)->right->left->right = (*t)->right;
		(*t)->right->left->left = *t;
		*t = (*t)->right->left;
		(*t)->left->right = l;
		(*t)->right->left = r;
	}
}

void treeRRRot(Tree* t) {
	if (*t != NULL && (*t)->right != NULL && (*t)->right->right != NULL) {
		Tree n = (*t)->right->left;
		(*t)->right->left = *t;
		*t = (*t)->right;
		(*t)->left->right = n;
	}
}

void treeBalance(Tree* t) {
	if (*t == NULL) {
		return;
	}
	int balance = treeHeight((*t)->left) - treeHeight((*t)->right);
	if (balance > 1) {
		if (treeHeight((*t)->left) > treeHeight((*t)->right)) {
			treeLLRot(t);
		}
		else {
			treeLRRot(t);
		}
	}
	else if (balance < -1) {
		if (treeHeight((*t)->left) > treeHeight((*t)->right)) {
			treeRLRot(t);
		}
		else {
			treeRRRot(t);
		}
	}
	treeBalance(&(*t)->left);
	treeBalance(&(*t)->right);

	return;
}

void treeInsert(Tree* t, int value) {
	if (*t == NULL) {
		*t = newTree(value);
		return;
	}
	if ((*t)->value > value) {
		treeInsert(&(*t)->left, value);
	}
	else {
		treeInsert(&(*t)->right, value);
	}
}

int treeRemove(Tree* t) {
	if (*t == NULL) {
		return POP_FAILURE;
	}
	int value = (*t)->value;
	if ((*t)->right == NULL) {
		Tree rem = *t;
		*t = (*t)->left;
		free(rem);
		return value;
	}
	Tree n = (*t)->right;
	while (n->left != NULL) {
		n = n->left;
	}
	Tree rem = *t;
	*t = (*t)->right;
	free(rem);
	return value;
}
