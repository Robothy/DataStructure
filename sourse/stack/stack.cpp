
//#define _0419
//#define _0421
//#define _0422_SquenceStack
#define _0422_LinkStack

#ifdef _0422_LinkStack

#include "stdio.h"
#include "stdlib.h"
#include "iostream"

using namespace std;

typedef struct
{
	int num;
	char name[20];
}Data,*pData;

typedef struct LinkStack
{
	Data data;
	struct LinkStack *next;
}LinkStack,*pLinkStack;

bool Show_Link(pLinkStack &LS)
{
	pLinkStack p = LS;
	while(p)
	{
		printf("%d\t%s\n",p->data.num,p->data.name);
		p=p->next;
	}
	return true;
}

bool Show_Node(pLinkStack &e)
{
	if(!e)	return false;
	cout << e->data.name << "\t" << e->data.num << endl;
	return true;
}

bool Stack_Push(pLinkStack &LS,pLinkStack &e)
{
	if(!LS) LS = e;
	else
	{
		e->next = LS;
		LS = e;
	}
	return true;
}

bool Stack_Pop(pLinkStack &LS,pLinkStack &e)
{
	e = LS;
	LS = LS->next;
	e->next = NULL;
	return true;
}

pLinkStack Stack_GetTop(pLinkStack &LS)
{
	pLinkStack p = (pLinkStack)malloc(sizeof(LinkStack));
	p->next = NULL;
	p->data = LS->data;
	return p;
}

int main(void)
{
	Data d[10] = {{0,"zero"},{1,"one"},{2,"two"},{3,"three"},{4,"four"},{5,"five"},{6,"six"},{7,"seven"},{8,"eight"},{9,"nine"}};
	pLinkStack LS = NULL;
	for(int i=0;i<10;i++)
	{
		pLinkStack e = (pLinkStack)malloc(sizeof(LinkStack));
		e->next = NULL;
		e->data = d[i];
		Stack_Push(LS,e);
	}

	pLinkStack e;
	e = Stack_GetTop(LS);
	Show_Node(e);
	free(e);

	Stack_Pop(LS,e);
	free(e);

	e = Stack_GetTop(LS);
	Show_Node(e);
	return 0;
}

#endif // _0422_LinkStack

#ifdef _0422_SquenceStack
#include "stdio.h"
#include "stdlib.h"
#include "iostream"

#define STACK_INIT_SIZE 10
#define INCREAMENT_SIZE 3

using namespace std;

typedef struct
{
	int num;
	char name[20];
}Data,*pData;

typedef struct
{
	pData top;
	pData base;
	unsigned int stacksize;
}Stack,*pStack;

bool Stack_Init(Stack &S)
{
	S.base = (pData)malloc(sizeof(Data)*STACK_INIT_SIZE);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return true;
}

bool Stack_Push(Stack &S,Data &e)
{
	if(S.top - S.base == S.stacksize) ///It means that S is full!
	{
		S.base = (pData)malloc(sizeof(Data)*(S.stacksize + INCREAMENT_SIZE));
		S.top = S.base + S.stacksize;
		S.stacksize += INCREAMENT_SIZE;
	}
	*S.top = e;
	S.top ++;
	return true;
}

bool Stack_Pop(Stack &S,Data &e)
{
	if(1)
	{
		S.top --;
		e = *S.top;
		return true;
	}
	else
	{
		return false;
	}
}

int main(void)
{
	Stack S;
	Data d[10] = {{0,"zero"},{1,"one"},{2,"two"},{3,"three"},{4,"four"},{5,"five"},{6,"six"},{7,"seven"},{8,"eight"},{9,"nine"}};
	Stack_Init(S);
	for(int i = 0  ; i < 10 ; i++)
	{
		Stack_Push(S,d[i]);
		cout << d[i].num << "\t" << d[i].name << endl;
	}

	cout << "--------------------------\n";

	for(int i = 0 ; i < 10 ; i++)
	{
		Stack_Pop(S,d[i]);
		cout << d[i].num << "\t" << d[i].name << endl;
	}

	return 0;
}

#endif // _0422


#ifdef _0421


#include"stdio.h"
#include"stdlib.h"
#include"iostream"

#define STACK_INIT_SIZE 10
#define STACK_INCREMENT 3

typedef struct Data
		{
			int num;
			char name[30];
		}Data,*pData;


typedef struct{
  pData base;
  pData top;
  int stacksize;
}SqStack;

bool InitStack(SqStack &S)
{
 S.base = (pData)malloc(STACK_INIT_SIZE*sizeof(Data));
 S.top = S.base;
 S.stacksize = STACK_INIT_SIZE;
 return true;
}

bool Push(SqStack &S,Data &e)
{
 if(S.top - S.base >= S.stacksize)
 {
   S.base = (pData)realloc(S.base,(S.stacksize+STACK_INCREMENT)*sizeof(Data));
   S.top = S.base + S.stacksize;
   S.stacksize = STACK_INCREMENT;
 }
 *S.top++ = e;
 return true;
}

bool Pop(SqStack &S,Data &e)
{
  if(S.top == S.base) return false;
  e = *--S.top;
  return true;
}

int main(void)
{
  Data E[]={{0,"zero"},{1,"one"},{2,"two"},{3,"three"},{4,"four"}};
  SqStack S;
  InitStack(S);
  for(int i=0;i<5;i++)
  {
    Push(S,E[i]);
  }
  for(int i=0;i<5;i++)
  {
    Pop(S,E[i]);
    printf("%d\t%s\n",E[i].num,E[i].name);
  }
  return 0;
}

#endif

#ifdef _0419
#include"stdio.h"
#include"stdlib.h"
#include"iostream"

#define STACK_INIT_SIZE 10
#define STACK_INCREMENT 3

using namespace std;


typedef struct
{
	int num;
	char name[20];
}Data,*pData;


typedef struct SqStack
{
	pData top;
	pData base;
	unsigned int stacksize;
}Stack,*pStack;

bool StackInit(Stack &S)
{
	S.base = (pData)malloc(sizeof(Data)*STACK_INIT_SIZE);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return true;
}

bool Push(Stack &S,Data &e)
{
	if(S.top-S.base>=S.stacksize)
	{
		S.base = (pData)malloc(sizeof(Data)*(S.stacksize+STACK_INCREMENT));
		S.top = S.base + S.stacksize;
		S.stacksize += STACK_INCREMENT;
	}
	*S.top++ = e;
	return true;
}

bool Pop(Stack &S,Data &e)
{
	e = *--S.top;
	S.stacksize--;
	return true;
}

bool StackEmpty(pStack &S)
{

}

int main(void)
{
	Data E[10]={{0,"zero"},{1,"one"},{2,"two"},{3,"three"},{4,"four"}};
	SqStack S;
	StackInit(S);
	for(int i=0;i<5;i++)
	{
		Push(S,E[i]);
		Push(S,E[i]);
	}
	for(int i=0;i<10;i++)
	{
		Pop(S,E[i]);
		cout<<E[i].name<<"\t"<<E[i].num<<endl;
	}
	system("pause");
	return 0;
}

#endif // _0419




