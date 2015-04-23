#define my
//#define net

#ifdef net
 #include <stdio.h>
 #include <stdlib.h>

#define ElemType char

//节点声明，数据域、左孩子指针、右孩子指针

typedef struct BiTNode{

    char data;

    struct BiTNode *lchild,*rchild;

}BiTNode,*BiTree;

//先序建立二叉树

BiTree CreateBiTree(){

    char ch;

    BiTree T;

    scanf("%c",&ch);

    if(ch=='#')T=NULL;

    else{

        T = (BiTree)malloc(sizeof(BiTNode));

        T->data = ch;

        T->lchild = CreateBiTree();

        T->rchild = CreateBiTree();

    }

    return T;//返回根节点

}

//先序遍历二叉树

void PreOrderTraverse(BiTree T){

    if(T){

       printf("%c",T->data);

       PreOrderTraverse(T->lchild);

       PreOrderTraverse(T->rchild);

    }

}



//中序遍历

void InOrderTraverse(BiTree T){

    if(T){

       PreOrderTraverse(T->lchild);

       printf("%c",T->data);

       PreOrderTraverse(T->rchild);

    }

}

//后序遍历

void PostOrderTraverse(BiTree T){

    if(T){

       PreOrderTraverse(T->lchild);

       PreOrderTraverse(T->rchild);

       printf("%c",T->data);

    }

}

int main(){

    BiTree T;

    T = CreateBiTree();//建立

    PreOrderTraverse(T);//输出

    getch();
    return 0;
}
#endif // net


#ifdef my

#define string_
#include "stdio.h"
#include "stdlib.h"

typedef struct BiTree
{
	char data;
	struct BiTree *Lchild;
	struct BiTree *Rchild;
}*pBiTree,BiTree;

#ifdef char_group
void CreateBiTree(pBiTree &T,char ch[],int &i)
{
	T=NULL;
	i++;
	if(ch[i]!=' ')
	{
		T=(pBiTree)malloc(sizeof(BiTree));
		T->data = ch[i];
		CreateBiTree(T->Lchild,ch,i);
		CreateBiTree(T->Rchild,ch,i);
	}

	return;
}
#endif // char_group

#ifdef string_
void CreateBiTree(pBiTree &T,char *&ch)
{
	T = NULL;
	if(*ch!=' ')
	{
		T = (pBiTree)malloc(sizeof(BiTree));
		T->data=*ch;
		ch++;
		CreateBiTree(T->Lchild,ch);
		CreateBiTree(T->Rchild,ch);
	}
	else
	{
		ch++;
		return;
	}
}
#endif // string_

void OrderTree(pBiTree &T)
{
	if(T)
	{
		printf("%c",T->data);
		OrderTree(T->Lchild);
		OrderTree(T->Rchild);
	}
	else
	{
		return;
	}
}

int main(void)
{
	#ifdef char_group
	char ch[] = {'-','+','a',' ',' ','*','b',' ',' ','-','c',' ',' ','d',' ',' ','/','e',' ',' ','f',' ',' '};
	#endif // char_group
	char *ch="-+a  *b  -c  d  /e  f  ";
	#ifdef string_
	#endif // string_

	pBiTree T;
	int i=-1;

	#ifdef char_group
	CreateBiTree(T,chs,i);
	#endif // char_group
	#ifdef string_
	CreateBiTree(T,ch);
	#endif // string_
	OrderTree(T);
	return 0;
}

#endif
