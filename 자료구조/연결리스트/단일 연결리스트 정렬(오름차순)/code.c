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
	printf("노드 데이터 입력 : ");
	scanf_s("%d", &NewNode->data);
	NewNode->next = NULL;
	if (Head == NULL)//1. Head가 null일때
	{
		Head = NewNode;
		return;
	}	
	if (NewNode->data < Head->data)//2. 새로운 노드가 가장 작을 때
	{
		NewNode->next = Head;
		Head = NewNode;
		return;
	}
	NODE* CurNode = Head;//3. 일반적인 경우
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
	CurNode->next = NewNode;//4. 새로운 노드가 가장 클 때

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
	//list 테스트를 위한 코드
	for (int i = 0; i < 5; i++)
	{
		InsertNodeSort();
	}
	display();
	return 0;
}