#include <stdio.h>

typedef int datatype;

typedef struct tnode {
	datatype data;
	struct tnode* lchild;
	struct tnode* rchild;
	struct tnode* parent;
} tnode;

tnode*
min_ancestor (tnode* one, tnode* two) {
	if (NULL == one || NULL == two)
		return NULL;
	if (one == two)
		return one;
	unsigned depth1 = 0, depth2 = 0;
	tnode *p = one, *q = two;
	for (; p != NULL; p = p->parent)
		depth1++;
	for (; q != NULL; q = q->parent)
		depth2++;
	unsigned delta;
	//p is deeper
	if (depth1 > depth2) {
		delta = depth1 - depth2;
		p = one;
		q = two;
	} else {
		delta = depth2 - depth1;
		p = two;
		q = one;
	}
	while (delta--) {
		p = p->parent;
	}
	//now p, q is at the same depth
	for (; p != q && p != NULL && p != NULL; p = p->parent, q = q->parent)
		;
	return p;
}
int
main() {
	const unsigned n = 6;
	tnode nodes[n];
	int i;
	/*
	 *          0
	 *         / \
	 *        1   2
	 *       / \
	 *      3   4
	 *         /
	 *        5
	 */
	for (i = 0; i < n; i++) {
		nodes[i].data = i;
		nodes->lchild = NULL;
		nodes->rchild = NULL;
		nodes->parent = NULL;
	}
	tnode* root = &nodes[0];
	root->lchild = &nodes[1];
	nodes[1].parent = root;
	root->rchild = &nodes[2];
	nodes[2].parent = root;
	root->lchild->lchild = &nodes[3];
	nodes[3].parent = &nodes[1];
	root->lchild->rchild = &nodes[4];
	nodes[4].parent = &nodes[1];
	root->lchild->rchild->lchild = &nodes[5];
	nodes[5].parent = &nodes[4];
	tnode *ret = min_ancestor(nodes + 3, nodes + 2);
	printf(" 3 & 2 : %d", ret->data);
	ret = min_ancestor(nodes + 3, nodes + 5);
	printf(" 3 & 5 : %d", ret->data);
	return 0;
}
