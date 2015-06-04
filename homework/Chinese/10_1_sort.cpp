#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "windows.h"

#define STOP system("pause");

typedef struct
{
	int *data;
	unsigned int quantity;
}*pDATA,DATA;

void ShowNum(pDATA &D);


void InsertSort(pDATA &D)
{
	pDATA _D=(pDATA)malloc(sizeof(DATA));
	_D->data=(int*)malloc(D->quantity*sizeof(int));
	for(int i=0;i<D->quantity;i++)
	{
		int k=0;
		if(0==i)
		{
			k=0;
		}
		else if(1==i)
		{
			if(_D->data[0]<=D->data[1])
			{
				k=1;
			}
			else
			{
				_D->data[1]=_D->data[0];
				k=0;
			}
		}
		else
		{
			int j=1;
			for(;j<i;j++)
			{
				if(D->data[i]<_D->data[0])
				{
					j=0;
					break;
				}
				else if(D->data[i]>_D->data[j-1]&&D->data[i]<=_D->data[j])
				{
					break;
				}
			}
			if(j<i)
			{
				k=j;
				unsigned int h=i;
				while(h!=j)
				{
					_D->data[h]=_D->data[h-1];
					h--;
				}
			}
			else
			{
				k=i;
			}
		}
		_D->data[k]=D->data[i];
	}
	D->data=_D->data;


}

void NumInit(pDATA &D)
{
	int d[]={83,40,63,13,84,35,96,57,39,79,61,15};
	if(!D)
	{
		D=(pDATA)malloc(sizeof(DATA));
		D->data = (int*)malloc(12*sizeof(int));
		D->quantity=12;
		for(int i=0;i<D->quantity;i++)
		{
			*(D->data+i)=d[i];
		}
	}
	else
	{
		for(int i=0;i<D->quantity;i++)
		{
			D->data[i]=d[i];
		}
	}
}

void QuickSort(pDATA &D,unsigned int low,unsigned int high)
{
	if(low<high)
	{
		unsigned int i=low,j=high;
		int pivotekey=D->data[i];
		while(1)
		{
			while(pivotekey<D->data[j]&&j>i)
			{
				j--;
			}
			if(i==j) break;
			D->data[i]=D->data[j];
			i++;
			while(pivotekey>=D->data[i]&&i<j)
			{
				i++;
			}
			if(i==j) break;
			D->data[j]=D->data[i];
			j--;
		}
		D->data[i]=pivotekey;

		QuickSort(D,low,i);
		QuickSort(D,i+1,high);
	}
}

void ShowNum(pDATA &D)
{
	for(int i=0;i<D->quantity;i++)
	{
		printf("%d ",*(D->data+i));
	}
	printf("\n");
}

int main(void)
{
	pDATA D=NULL;
	NumInit(D);
	ShowNum(D);
	printf("\n\n------------------------\n²åÈëÅÅÐò\n");
	InsertSort(D);
	ShowNum(D);

	printf("\n\n------------------------\n¿ìËÙÅÅÐò\n");
	NumInit(D);
	QuickSort(D,0,D->quantity-1);
	ShowNum(D);

	return 0;
}
