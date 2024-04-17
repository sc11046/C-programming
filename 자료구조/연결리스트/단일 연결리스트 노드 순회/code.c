#include <stdio.h>
#include <string.h>
#include <malloc.h>
typedef struct NODE {
	int data;
	struct NODE* next;

} NODE;

NODE* Head = NULL;
//���� ����Ʈ ��ü ������ ���


void InsertNewNode(void)
{
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	printf("Node ������ �Է� : \n");
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
	//list �׽�Ʈ�� ���� �ڵ�
	for (int i = 0; i < 5; i++)
	{
		InsertNewNode();
	}
	display();
	return 0;

}