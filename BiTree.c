#include<stdio.h>
typedef struct BiTNode{
	struct BiTNode * lchild;
	struct BiTNode * rchild;
	char data;
}BiTNode,*BiTree;

void PreOrder1(BiTree T)
{
	BiTree t[10];
	int top=0;
	BiTree pt=T;
	do{
		while (pt)
		{
			printf("%c",pt->data);
			if(pt->rchild) t[top++]=pt->rchild;			
			pt=pt->lchild;
		};
		pt=t[--top];
	}while(top>=0);
}
void InOrder1(BiTree T)
{
	BiTree t[10];
	int top=0;
	BiTree pt=T;
	while(pt)
	{
		while(pt->lchild)
		{
			t[top++]=pt;	
			pt=pt->lchild;
		}
		printf("%c",pt->data);
		while(!pt->rchild && top>=0)
		{				
			pt=t[--top];
			if(top>=0) printf("%c",pt->data);
		}			
		pt=pt->rchild;			
	};
}
void PostOrder1(BiTree T)
{

}
void PreOrder(BiTree T)
{
	if(T)
	{
		printf("%c",T->data);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}
void InOrder(BiTree T)
{
	if(T)
	{
		InOrder(T->lchild);
		printf("%c",T->data);		
		InOrder(T->rchild);
	}
}
void PostOrder(BiTree T)
{
	if(T)
	{
		PostOrder(T->lchild);					
		PostOrder(T->rchild);
		printf("%c",T->data);
	}
}
void main(void)
{
//	BiTNode s[9]={
//		                                       {&s[1],&s[2],'-'},
//	               {&s[3],&s[4],'*'},                                          {&s[5],&s[6],'/'},
//	{NULL,NULL,'a'},        {&s[7],&s[8],'-'},                            {NULL,NULL,'d'},      {NULL,NULL,'e'},
//		             {NULL,NULL,'b'},{NULL,NULL,'c'},               
//	};
	BiTNode s[9]={
		                                       {&s[1],&s[2],'A'},
	                               {&s[3],NULL,'B'},         {NULL,&s[4],'E'},
	                      {NULL,&s[5],'C'},                               {&s[6],NULL,'F'},  
		                         {NULL,NULL,'D'},                   {NULL,NULL,'G'},		                              
	};

	BiTree tree=&s[0];
	
	printf("travers the tree begin!\n");
	
	printf("\nPreOrder!\n");
	PreOrder(tree);
	printf("\nPreOrder1!\n");
	PreOrder1(tree);
	printf("\n");
	
	printf("\nInOrder!\n");
	InOrder(tree);
	printf("\nInOrder1!\n");
	InOrder1(tree);
	printf("\n");
	
	printf("\nPostOrder!\n");
	PostOrder(tree);
	printf("\nPostOrder1!\n");
	PostOrder1(tree);
	printf("\n");
}
