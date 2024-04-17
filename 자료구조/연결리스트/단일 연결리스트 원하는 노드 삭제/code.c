#include <stdio.h>
#include <string.h>
#include <malloc.h>
typedef struct NODE {
	int data;
	struct NODE* next;
} NODE;

NODE* Head = NULL;
/*void delnode(void)
{
	NODE* delnode = Head;
	int sc;
	printf("������ ��� ���? :");
	scanf_s("%d", &sc);
	if (delnode == NULL)
	{
		return;
	}
	else {
		for(int i=0;i<sc-1;i++)
		{
			Head = Head->next;
		}
		delnode = Head;
		free(delnode);
	}
}
//12345 1>2>3>3>5
*/
void delnode(void)
{
	int sc;
	printf("������ ��� ���? :");
	scanf_s("%d", &sc);

	if (Head == NULL)
	{
		printf("����Ʈ�� ��� �ֽ��ϴ�.\n");
		return;
	}

	NODE* prevNode = NULL;
	NODE* curNode = Head;
	int count = 1;

	while (curNode != NULL && count != sc)
	{
		prevNode = curNode;	
		curNode = curNode->next;
		count++;
		printf("���� �ּ� :%p,���� �ּ� :%p, ���� �� : %d, �Ѿ �ּ� : %p\n",prevNode, curNode,curNode->data, curNode->next);
	}

	if (curNode == NULL)
	{
		printf("�ش��ϴ� ��尡 �����ϴ�.\n");
		return;
	}

	if (prevNode == NULL) // �����Ϸ��� ��尡 ù ��° ����� ���
	{
		Head = curNode->next;
	}
	else
	{
		prevNode->next = curNode->next;
		printf("���� �ּ� :%p,���� �ּ� :%p, ���� �� : %p, �Ѿ �ּ� : %p\n", prevNode, curNode, prevNode->next, curNode->next);

	}

	free(curNode);
	printf("��� %d�� �����߽��ϴ�.\n", sc);
}

void InsertNewNode(void)
{
	NODE* curNode;
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	printf("Node ������ �Է� :");
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
	//list �׽�Ʈ�� ���� �ڵ�
	for (int i = 0; i < 5; i++)
	{
		InsertNewNode();
	}
	display();
	delnode();
	display();
	return 0;
}