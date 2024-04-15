#include <stdio.h>

typedef struct NODE
{
	int ndata;//관리될 데이터

	struct NODE* next;//데이터 관리를 위한 포인터
	
} NODE;

int main()
{
	NODE list[5] = {0};
	//값초기화
	list[0].ndata = 100;
	list[1].ndata = 200;
	list[2].ndata = 300;
	list[3].ndata = 400;
	list[4].ndata = 500;
	//연결 리스트 구조화
	list[0].next = &list[3];
	list[1].next = &list[4];
	list[2].next = NULL;
	list[3].next = &list[1];
	list[4].next = &list[2];

	for (int i = 0;i < 5;i++)
	{
		printf("list[%d] : %d\n", i, list[i].ndata);
	}
	
	NODE* pTmp = &list[0];
	while (pTmp != NULL)
	{
		printf("%p,%d\n", pTmp, pTmp->ndata);
		pTmp = pTmp->next;
	}
	return 0;
}