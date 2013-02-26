#define ElemType int
#include <stdio.h>

typedef struct LNode{
	ElemType value;
 	struct 	LNode *next;
}LNode,ListStack;


void initStack(ListStack *stack){
	stack = (ListStack*)malloc(sizeof(LNode));
	stack->next= NULL;
	printf("the node adress is %p\n",stack->next);
}

void push(ListStack *stack,ElemType value){
	LNode* lnode = (LNode *)malloc(sizeof(LNode)); 
	lnode->value = value;
	LNode* node = stack->next;
	printf("the node adress is %p\n",stack->next);
	printf("the node adress is %p\n",node);
	stack->next = lnode;
	lnode->next = node;

}
	
int  pop(ListStack *stack,ElemType *value){
	if(stack->next == NULL)
		return -1;
	*value = stack->next->value;
	stack->next = stack->next->next;

	return 1;	
}
