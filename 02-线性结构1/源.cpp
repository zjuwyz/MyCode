#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;

struct Node
{
	ElementType Data;
	PtrToNode Next;
};

typedef PtrToNode List;

List Read()
{
	int n;
	List L = (List)malloc(sizeof(PtrToNode));
	List Head = L;
	L->Next = (PtrToNode)malloc(sizeof(PtrToNode));
	L = L->Next;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int now;
		scanf("%d", &now);
		L->Data = now;
		L->Next = (PtrToNode)malloc(sizeof(PtrToNode));
		if (i == n - 1)
		{
			free(L->Next);
			L->Next = NULL;
		}
		else
		{
			L = L->Next;
		}
	}
	return Head;
}; /* 细节在此不表 */
void Print(List L)
{
	while (L->Next != NULL)
	{
		L = L->Next;
		printf("%d ", &L->Data);
	}
	printf("\n");
}/* 细节在此不表；空链表将输出NULL */

List Merge(List L1, List L2);

int main()
{
	List L1, L2, L;
	L1 = Read();
	L2 = Read();
	L = Merge(L1, L2);
	Print(L);
	Print(L1);
	Print(L2);
	return 0;
}

/* 你的代码将被嵌在这里 */
List Merge(List L1, List L2)
{
	List L, Lt1, Lt2;
	Lt1 = L1->Next;
	Lt2 = L2->Next;
	L1->Next = NULL;
	L2->Next = NULL;
	L1 = Lt1;
	L2 = Lt2;
	L = (List)malloc(sizeof(List));
	List Head = L;
	while (L1 != NULL && L2 != NULL)
	{
		if (L1->Data < L2->Data)
		{
			L->Next = L1;
			L1 = L1->Next;
		}
		else
		{
			L->Next = L2;
			L2 = L2->Next;
		}
		L = L->Next;
	}
	if (L1 == NULL)
	{
		L->Next = L2;
	}
	else
	{
		L->Next = L1;
	}
	return Head;
}
