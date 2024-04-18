#include <stdio.h>
#include <string.h>
#include <malloc.h>
typedef struct DNODE {
	int data;
	struct DNODE* next;
	struct DNODE* prev;
} DNODE;

DNODE* Head = NULL;
DNODE* Tail = NULL;
void insertDnodeFront(int value)
{
	DNODE* NewNode;
	NewNode = (DNODE*)malloc(sizeof(DNODE));
	NewNode->data = value;
	NewNode->next = NewNode->prev = NULL;
	if (Head == NULL)
	{
		Head = NewNode;
		Tail = NewNode;
		printf("이전주소 : %p, 현재 값 : %d, 다음 주소 : %p\n", Head->prev, NewNode->data, NewNode->next);
		return;
	}
	NewNode->next = Head;
	Head->prev = NewNode;
	printf("이전주소 : %p, 현재 값 : %d, 다음 주소 : %p\n", Head->prev, NewNode->data, NewNode->next);
	Head = NewNode;
}
void display(void)
{
	DNODE* curNode = Head;
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
	
	insertDnodeFront(1);
	insertDnodeFront(2);
	insertDnodeFront(6);
	insertDnodeFront(4);
	insertDnodeFront(3);

	//display();

	return 0;
}