# 단일 연결리스트-1

```c
typedef struct NODE{
	char szData[64];
	struct NODE* next;

} NODE;
NODE* g_pHead = NULL;
```

문자열 형태의 배열을 선언 한 뒤 **다음 노드의 주소를 저장** 할 수 있는 **next변수를 선언**한다.

전역으로 **연결 리스트의 시작점**을 나타내는 헤드 포인터를 선언하고 , 이 헤드 포인터는 연결 리스트의 첫 번째 노드를 가리키는 역할로 **Null로 초기화**한다.

```c
void Printlist(void)
{
	NODE* pHead = g_pHead;
	while (pHead != NULL)
	{
		printf("[%p] %s, next[%p]\n", pHead, pHead->szData, pHead->next);
		pHead = pHead->next;
	}
	putchar('\n');
}
```

Printlist함수에서는 반환형은 없고, 다음 노드의 주소가 **Null이 될때까지 출력**한다.

다음 노드의 주소를 저장시켜 반복적으로 **현재 노드의 주소, 데이터, 다음 노드의 주소를 출력**한다.

```c
int InsertNewNode(char* pszData)
{
	NODE* pNode = (NODE*)malloc(sizeof(NODE));
	memset(pNode, 0, sizeof(NODE));
	strcpy_s(pNode->szData, sizeof(pNode->szData), pszData);
	if (g_pHead == NULL)
		g_pHead = pNode;
	else {
		pNode->next = g_pHead;
		g_pHead = pNode;
	}	
	return 1;
}
```

데이터 삽입 성공 유무를 확인하기 위해 int반환형으로 함수를 생성한다.

**Node구조체의 크기만큼 pNode를 동적 할당**을 하고 memset함수를 통해 Node크기만큼 0으로 pNode를 초기화한다.

 `pszData`에 있는 문자열을 `pNode->szData`에 복사한다.

`	if (g_pHead == NULL)g_pHead = pNode;` **Head의 주소가 없다면 새로 생성된 노드의 주소**로 한다.

`	else {		pNode->next = g_pHead;
				g_pHead = pNode;	}` **가장 중요한 부분**

![image](https://github.com/sc11046/Capstone/assets/121782720/8d9718b9-d735-42d5-8090-ef079b4a0ee2)

**오버라이트로 인해 기존 노드의 주소가 손실 방지를 위해** 새로운 노드의 주소를 **먼저 기존 노드랑 연결**한다.

이후 헤더를 **새로운 노드랑 연결** 해 그림과 같이 연결한다.

삽입에 성공하면 1을 반환한다.

```c
int main()
{
	//list 테스트를 위한 코드
	InsertNewNode("Test1");
	Printlist();
	InsertNewNode("Test2");
	Printlist();
	InsertNewNode("Test3");
	Printlist();
	return 0;

}
```

이후 출력을 통해 확인한다.

![image](https://github.com/sc11046/Capstone/assets/121782720/6d3a2b79-8301-4cdb-910b-bd2487deb4ff)