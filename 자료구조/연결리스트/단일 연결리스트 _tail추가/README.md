# 단일 연결리스트(노드를 제일 뒤에 삽입)

## 원문 코드 : code.c 참고

![image](https://github.com/sc11046/C-programming/assets/121782720/4541e000-afcc-4e33-ab8d-e65a92d1d0e6)

순회 노드를 이용해서 마지막에 노드를 삽입할 수 있다.

```c
typedef struct NODE {
	int data;
	struct NODE* next;
} NODE;
NODE* Head = NULL;
```

노드 구조체 생성 및 Head 초기화

```c
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
```

가장 핵심이 되는 부분이다. 

`	curNode = Head;`에서 순회 노드를 Head로 설정해 현재 주소를 저장한다.

`while (curNode->next != NULL)`순회 노드가 NULL이 아니라면 다음주소로 계속 넘어가게 설정한다.

`	curNode->next = newNode;` NULL이 되면 while을 탈출하게 되고 그 때가 되서야 새로운 노드의 주소를 다음 주소로 저장해 노드를 추가 할 수 있다.

```c
void display(void)
{
	NODE* curNode = Head;
	while (curNode->next != NULL)
	{
		printf("Data : %d\n", curNode->data);
		curNode = curNode->next;
	}
	printf("Data : %d\n", curNode->data);
}
```

또한 순회 노드를 사용해 현재 연결 리스트의 데이터를 출력하도록 구현했다.

```c
int main()
{
	//list 테스트를 위한 코드
	for (int i = 0; i < 5; i++)
	{
		InsertNewNode();
	}
	display();
	InsertNewNode();
	display();
	return 0;
}
```

출력 

사진 처럼 순서대로 출력이 되고 새로운 노드가 추가가 되면 마지막에 추가되는 모습을 볼 수 있다.

![image](https://github.com/sc11046/C-programming/assets/121782720/b414bfe0-fcd3-4996-ada1-bf7e41a63abb)