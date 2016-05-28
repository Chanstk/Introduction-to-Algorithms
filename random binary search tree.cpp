#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<time.h>
using namespace std;
typedef int ElemType;
typedef struct node{
	 struct node *lchild,*rchild,*parent;
	 ElemType data;
}*Tree;
void Insert(Tree *root,ElemType data)
{
	if((*root)==NULL){
		Tree p=(node*)malloc(sizeof(node));
		p->lchild=NULL;
		p->rchild=NULL; 
		p->data=data;
		(*root)=p;
		p->parent=NULL;
		return ;
	}
	else
		if((*root)->lchild==NULL&&(*root)->data>data){
			Tree p=(node*)malloc(sizeof(node));
			p->lchild=NULL;
		    p->rchild=NULL;
		    p->data=data;
			(*root)->lchild=p;
			p->parent=(*root);
			return ;
		}
             else 
		if((*root)->rchild==NULL&&(*root)->data<data){
			Tree p=(node*)malloc(sizeof(node));
			p->lchild=NULL;
		    p->rchild=NULL;
		    p->data=data;
			(*root)->rchild=p;
			p->parent=(*root);
			return ;
		}
	else
		if((*root)->data>data)
			Insert(&(*root)->lchild,data);
             else
		Insert(&(*root)->rchild,data);

}
void Inorder(Tree root)
{
    if(root){
        Inorder(root->lchild);
        cout<<root->data<<" ";
        Inorder(root->rchild);
    }
}
int main()
{
    Tree root=NULL;
    int n = 10;
    vector<int> arr(n);
    srand(time(NULL));
    for(int i = 0 ; i < n;i++)
        arr[i] = rand()%100;
    cout<<"The former arr is: ";
    for(int i = 0 ; i < n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    cout<<"Sorted: ";
    vector<int>::iterator it = arr.begin();
    for(int i = 0 ; i < n ; i++){
        int randNum = rand()%arr.size();
        Insert(&root,arr[randNum]);
        it = arr.begin()+randNum;
        arr.erase(it);
    }
    Inorder(root);
    return 0;
    
}

    	
