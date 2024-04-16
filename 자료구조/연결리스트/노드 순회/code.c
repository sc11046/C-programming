#include <stdio.h>
#include <string.h>
#include <malloc.h>
typedef struct NODE {
	int data;
	struct NODE* next;

} NODE;

NODE* Head = NULL;
//연결 리스트 전체 데이터 출력


void InsertNewNode(void)
{
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	printf("Node 데이터 입력 : \n");
	scanf_s("%d", &newNode->data);
	newNode->next = NULL;
	if (Head== NULL)
		Head = newNode;
	else {
		newNode->next = Head;
		Head = newNode;
	}
}

void display(void)
{
	NODE* curNode = Head;
	while(curNode->next!=NULL)
	{
		printf("Data : %d\n", curNode->data);
		curNode = curNode->next;
	}
	printf("Data : %d\n", curNode->data);
}
int main()
{
	//list 테스트를 위한 코드
	for (int i = 0; i < 5; i++)
	{
		InsertNewNode();
	}
	display();
	return 0;

}