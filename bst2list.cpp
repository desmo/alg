#include <iostream>
using namespace std;
struct BSTreeNode{
	int value;
	BSTreeNode *leftNode;
	BSTreeNode *rightNode;
};

void addBSTreeNode(BSTreeNode *&pCurrent,int value){
	if(pCurrent == NULL){
		pCurrent = new BSTreeNode();
		pCurrent->leftNode = NULL;
		pCurrent->rightNode = NULL;
		pCurrent->value = value;
		return;
	}
	if(pCurrent->value < value)
		addBSTreeNode(pCurrent->rightNode,value);
	else
		addBSTreeNode(pCurrent->leftNode,value);
}

void BST2List(BSTreeNode *pCurrent,BSTreeNode *&last){
	if(NULL == pCurrent)
		return;
	BST2List(pCurrent->leftNode,last);

	if(last)
		last->rightNode = pCurrent;

	pCurrent->leftNode = last;
	last = pCurrent;


	BST2List(pCurrent->rightNode,last);

}

void inorderTraversal(BSTreeNode *pCurrent){
	if(pCurrent == NULL)
		return;
	if(pCurrent->leftNode){
		inorderTraversal(pCurrent->leftNode);
	}
	
	cout<<pCurrent->value<<endl;


	if(pCurrent->rightNode)
	inorderTraversal(pCurrent->rightNode);


}

void traversalList(BSTreeNode *tail){


	while(tail !=NULL){
		cout<<tail->value<<endl;
		tail = tail->leftNode;
	}
	
}



	


int main(){
	BSTreeNode *pRoot = NULL;
	BSTreeNode *last = NULL;

	addBSTreeNode(pRoot,4);
	addBSTreeNode(pRoot,6);
	addBSTreeNode(pRoot,1);
	addBSTreeNode(pRoot,8);
	addBSTreeNode(pRoot,5);
	addBSTreeNode(pRoot,7);
	inorderTraversal(pRoot);
	BST2List(pRoot,last);
	traversalList(last);
}
