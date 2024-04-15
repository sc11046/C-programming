#include <stdio.h>

typedef struct NODE
{
	int ndata;//������ ������

	struct NODE* next;//������ ������ ���� ������
	
} NODE;

int main()
{
	NODE list[5] = {0};
	//���ʱ�ȭ
	list[0].ndata = 100;
	list[1].ndata = 200;
	list[2].ndata = 300;
	list[3].ndata = 400;
	list[4].ndata = 500;
	//���� ����Ʈ ����ȭ
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