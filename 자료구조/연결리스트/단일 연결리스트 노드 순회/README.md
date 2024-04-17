# 노드 순회

## **원문 코드 : code.c 참고**

![image](https://github.com/sc11046/C-programming/assets/121782720/08af2361-9091-44d7-9ccb-5aa8628cf408)

순회 노드를 생성하여 각 노드의 데이터를 다음 주소를 따라가며 데이터를 출력한다.

```c
void InsertNewNode(void)
{
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	printf("Node 데이터 입력 : ");
	scanf_s("%d\n", &newNode->data);
	newNode->next = NULL;
	if (Head== NULL)
		Head = newNode;
	else {
		newNode->next = Head;
		Head = newNode;
	}
}
```

노드들의 데이터를 입력받고, 다음 주소를 이어서 연결 리스트를 생성한다.

```c
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
```

순회노드 즉, `curNode`에 헤더의 주소를 저장한다.

순회노드의 `curNode->next`가 NULL이 될때까지 data를 출력하고, 다음 노드를 순회하기 위해 `curNode `에 `curNode->next`를 저장한다.

마지막으로 `curNode->next`이  NULL일때 데이터를 출력한다.

```c
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
```

5개의 노드를 생성 후 순회 노드 함수를 동작 시킨다.

출력

![image](https://github.com/sc11046/C-programming/assets/121782720/a3feebdc-ad92-4c13-a3f7-a2d4f8869abd)