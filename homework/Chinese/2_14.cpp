#include "stdio.h"
#include "list.h"
using namespace data_structure;
using data_structure::List;

int main(void)
{
	List::pLink L=NULL,M=NULL,N=NULL;
	List Li;
	Li.List_Init(M);
	Li.List_Init(N);
	Li.List_Init(L);

	for(int i=0;i<6;i++)
	{
		List::pLink llink,mlink,nlink;

		llink=(List::pLink)malloc(sizeof(List::Link));
		mlink=(List::pLink)malloc(sizeof(List::Link));
		nlink=(List::pLink)malloc(sizeof(List::Link));

		llink->data.num=i;
		mlink->data.num=i+6;
		nlink->data.num=i+11;

		strcpy(llink->data.name,"L");
		strcpy(mlink->data.name,"M");
		strcpy(nlink->data.name,"N");

		Li.Insert_Link(L,llink);
		Li.Insert_Link(M,mlink);
		Li.Insert_Link(N,nlink);
	}

	Li.Print_List(L);
	//Li.Print_List(M);
	//Li.Print_List(N);

	Li.Delete_Link(L,2,100);

	Li.Print_List(L);

	Li.Destory_List(L);
	Li.Destory_List(M);
	Li.Destory_List(N);

	return 0;
}



