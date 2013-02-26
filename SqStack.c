#define STACKINCREMENT 10
#define STACK_INIT_SIZE 100
#define SElemType int
typedef struct SqStack{
	SElemType *base;
	SElemType *top;
	int stacksize;
} SqStack;

void initStack(SqStack* stack);
void push(SqStack* stack,SElemType e);
void pop(SqStack* stack,SElemType* e);

void initStack(SqStack* stack){
	stack->base = (SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	stack->top = stack->base;
	stack->stacksize = STACK_INIT_SIZE;
}


void push(SqStack* stack,SElemType e){
	if((stack->top - stack->base) >=  stack->stacksize){
		
	  	stack->stacksize += STACKINCREMENT;
	  	stack->base = (SElemType*)realloc(stack->base,stack->stacksize*sizeof(SElemType));
	  	stack->top = stack->base + stack->stacksize - STACKINCREMENT;
	}
	*stack->top = e;
	stack->top++;

}


void pop(SqStack* stack,SElemType* e){
	if(stack->base == stack->top){
		return;
	}
	*e =*(--(stack->top));
}
