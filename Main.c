//#include "SqStack.c"
#include "ListStack.c"
void main(){

   //	ListStack stack;
	ListStack *stackp;
	
	//	SqStack stack;
	//	initStack(&stackp);
	stackp = (ListStack*)malloc(sizeof(LNode));
    stackp->next= NULL;
	push(stackp,3);
	
	//push(&stack,4);
	//push(&stack,5);
	//push(&stack,6);
	//push(&stack,7);
	//push(&stack,8);
	//int *a;//直接传指针进去会报段错误，可能会访问内存空间
	int b;
	int i =1;
	while(i == 1){
		i =	pop(stackp,&b);

		printf("the int is %d and return value is %d\n",b,i);
	}		
}
