#include <stdio.h>
#include <stdlib.h>

typedef char elementtype;
typedef struct _Tnode
{
	elementtype inf;
	// Du lieu cua nut
	struct _Tnode *left;
	struct _Tnode *right;
} Treenode;

Treenode *createnewnode(elementtype X){
	Treenode *newnode=(Treenode*)malloc(sizeof(Treenode));
	if(newnode==NULL){printf("Error in memoty allocation\n");exit(0);}
	newnode->inf=X;
	newnode->left=NULL;
	newnode->right=NULL;
	
	return newnode;
}
//duyet theo thu tu truoc
void PREORDER( Treenode *r )
{
	if(r==NULL) return;
	printf("%c ",r->inf);
	PREORDER(r->left);
	PREORDER(r->right);
}
//duyet theo thu tu sau
void POSTORDER( Treenode *r )
{
	if(r==NULL) return;
	POSTORDER(r->left);
	POSTORDER(r->right);
	printf("%c ",r->inf);
}
//duyet theo thu tu giua 
void INORDER( Treenode *r )
{
	if(r==NULL) return;
	INORDER(r->left);
	printf("%c ",r->inf);
	INORDER(r->right);
}
//ham giai phong bo nho
void freeTree(Treenode * r)
{
    if(r == NULL) return;
    freeTree(r->left);
    freeTree(r->right);
    free(r); 
}
//dem so nut tren cay 
int count(Treenode* r){
    if(r == NULL) return 0;
    return 1 + count(r->left) + count(r->right);
}
//dem so nut trong cua cay
int countinternalnode(Treenode *r){
	if(r == NULL) return 0;
	//kiem tra co phai la nut la hay khong
    if (r->left == NULL && r->right == NULL)
        return 0;
        //nut trong
    return 1 + countinternalnode(r->left) + countinternalnode(r->right);
}
// dem so nut co k con
int CountNodeWKChild(Treenode *r,int k)
{
    if(k<0||k>2) return -1;
    int i=0,count=0;
    if(r==NULL) return 0;
    if(r->left!=NULL) i+=1;
    if(r->right!=NULL) i+=1;
    if(i==k) count+=1;
    count+=CountNodeWKChild(r->left,k);
    count+=CountNodeWKChild(r->right,k);
    
    return count;
}

int main(){
	Treenode *root=NULL;
	Treenode *nutB, *nutC, *nutD, *nutE, *nutF, *nutG, *nutH, *nutI, *nutJ, *nutK;
	
	root=createnewnode('A');
	nutB=createnewnode('B');
	nutC=createnewnode('C');
	nutD=createnewnode('D');
	nutE=createnewnode('E');
	nutF=createnewnode('F');
	nutG=createnewnode('G');
	nutH=createnewnode('H');
	nutI=createnewnode('I');
	nutJ=createnewnode('J');
	nutK=createnewnode('K');
	
	root->left=nutB;
	
	nutB->left=nutE;
	nutB->right=nutC;
	
	nutC->left=nutG;
	nutC->right=nutD;
	
	nutE->right=nutF;
	
	nutG->left=nutH;
	
	nutH->right=nutI;
	nutI->right=nutJ;
	nutJ->right=nutK;
	
	
	printf("-----------Duyet truoc-------\n");
	PREORDER(root);
	
	
	printf("\n-----------Duyet sau-------\n");
	POSTORDER(root);
	
	
	printf("\n-----------Duyet giua-------\n");
	INORDER(root);
	
	
	printf("\n-----------Dem so nut: %d\n",count(root));
	
	printf("\n-----------Dem so nut trong la: %d\n",countinternalnode(root));
	
	
	printf("\n-----------Dem so nut 0 con la: %d\n",CountNodeWKChild(root,0));
	printf("\n-----------Dem so nut 1 con la: %d\n",CountNodeWKChild(root,1));
	printf("\n-----------Dem so nut 2 con la: %d\n",CountNodeWKChild(root,2));
	printf("\n-----------Dem so nut 3 con la: %d\n",CountNodeWKChild(root,3));
	
	freeTree(root);
	
	
	return 1;
}