#include <stdio.h>
#include <string.h>
#include <malloc.h>
typedef struct NODE {
	int data;
	struct NODE* next;
} NODE;
NODE* Head = NULL;
void InsertNodeSort()
{
	NODE* NewNode = (NODE*)malloc(sizeof(NODE));
	printf("��� ������ �Է� : ");
	scanf_s("%d", &NewNode->data);
	NewNode->next = NULL;
	if (Head == NULL)//1. Head�� null�϶�
	{
		Head = NewNode;
		return;
	}	
	if (NewNode->data < Head->data)//2. ���ο� ��尡 ���� ���� ��
	{
		NewNode->next = Head;
		Head = NewNode;
		return;
	}
	NODE* CurNode = Head;//3. �Ϲ����� ���
	NODE* PreNode = Head;
	while (CurNode->next != NULL)
	{
		CurNode = CurNode->next;
		if (CurNode->data > NewNode->data)
		{
			NewNode->next = CurNode;
			PreNode->next = NewNode;
			return;
		}
		PreNode = PreNode->next;
	}
	CurNode->next = NewNode;//4. ���ο� ��尡 ���� Ŭ ��

}
void display(void)
{
	NODE* curNode = Head;
	while (curNode->next != NULL)
	{
		printf("Data : %d\n", curNode->data);
		curNode = curNode->next;
	}
	printf("Data : %d\n", curNode->data);
	printf("\n");
}
int main()
{
	//list �׽�Ʈ�� ���� �ڵ�
	for (int i = 0; i < 5; i++)
	{
		InsertNodeSort();
	}
	display();
	return 0;
}