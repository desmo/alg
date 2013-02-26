#include<stdio.h>
#include<string.h>
#define TElemType char
j


typedef struct BiTNode{
	TElemType data;
	struct BiTNode *lchild,*rchild;
	
}BiTNode, *BiTree;

char *str = "-+a  *b  -c  d  /e  f  ";

//用先序的方式创建树
void createBiTree(BiTree* tree){
	static int n = 0;
	char ch = str[n++];
	if(ch == ' ') *tree = NULL;
	else{
		if(!(*tree = (BiTNode *)malloc(sizeof(BiTNode))))
			printf("error\n");
		(*tree)->data = ch;
		createBiTree(&((*tree)->lchild));
		createBiTree(&((*tree)->rchild));
		
	}
}

void createBiTree(BiTree* tree){
	static int n = 0;
	
	char ch = str[n++];
	if(ch == ' '){
		
		*tree = NULL;
		return;
	}
	if(!(*tree = (BiTNode *)malloc(sizeof(BiTNode))))
			printf("error\n");

	BiTree *treep = tree; 
	while(n < strlen(str)){
		char ch = str[n++];
		if(ch == ' ')
			(*treep)->lchild = NULL;
		else{
			
			(*treep)->lchild->data = ch;
			treep =
		}
			
		char ch = str[n++];
		if(ch == ' ')

		(*tree)->lchild = 
}
//先序遍历
void preOrderBitree(BiTree tree){
	printf("%c\n",tree->data);
	if(tree->lchild)
		preOrderBitree(tree->lchild);
	
	if(tree->rchild)
		preOrderBitree(tree->rchild);

}

int main(){
	BiTree tree;
	createBiTree(&tree);
	
	preOrderBitree(tree);
}
