#include <stdio.h>
#include <string.h>
#include <malloc.h>
typedef struct NODE {
	int data;
	struct NODE* next;
} NODE;
void display(void);
NODE* Head = NULL;
void alldelnode(void)
{
	NODE* delnode = Head;
	while (delnode != NULL)
	{
		Head = Head->next;
		free(delnode);
		delnode = Head;
		printf("현재 리스트 : \n");
		display();
	}
	
}
void InsertNewNode(void)
{
	NODE* curNode;
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	printf("Node 데이터 입력 :");
	scanf_s("%d", &newNode->data);
	newNode->next = NULL;
	if (Head == NULL)
	{
		Head = newNode;
		return;
	}
	curNode = Head;
	while (curNode->next != NULL)
	{
		curNode = curNode->next;

	}
	curNode->next = newNode;
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
		InsertNewNode();
	}
	display();
	alldelnode();
	return 0;
}
