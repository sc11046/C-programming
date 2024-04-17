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
	printf("삭제할 노드 몇번? :");
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
	printf("삭제할 노드 몇번? :");
	scanf_s("%d", &sc);

	if (Head == NULL)
	{
		printf("리스트가 비어 있습니다.\n");
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
		printf("이전 주소 :%p,현재 주소 :%p, 현재 값 : %d, 넘어갈 주소 : %p\n",prevNode, curNode,curNode->data, curNode->next);
	}

	if (curNode == NULL)
	{
		printf("해당하는 노드가 없습니다.\n");
		return;
	}

	if (prevNode == NULL) // 삭제하려는 노드가 첫 번째 노드일 경우
	{
		Head = curNode->next;
	}
	else
	{
		prevNode->next = curNode->next;
		printf("이전 주소 :%p,현재 주소 :%p, 현재 값 : %p, 넘어갈 주소 : %p\n", prevNode, curNode, prevNode->next, curNode->next);

	}

	free(curNode);
	printf("노드 %d를 삭제했습니다.\n", sc);
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
	delnode();
	display();
	return 0;
}