# 이중 연결리스트(제일 앞에서 부터 삽입)

## 원문 코드 : code.c 참고

![image](https://github.com/sc11046/C-programming/assets/121782720/026a235e-f10c-4533-8d15-92a4a0afe82d)

```c
typedef struct DNODE {
	int data;
	struct DNODE* next;
	struct DNODE* prev;
} DNODE;

DNODE* Head = NULL;
DNODE* Tail = NULL;
```

위와 같이 이중 연결리스트는 단일 연결리스트와 달리 다음 주소 뿐 아니라 이전 주소도 포함되는 노드들의 연결리스트이다.

Head, Tail을 NULL로 초기화 해준다.

```c
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
```

새로운 노드를 동적할당하고 노드의 데이터와 주소를 초기화 해준다.

`HEAD==NULL` 즉, 노드가 아무것도 연결되어있지 않을 때 새로운 노드가 첫 번째 노드가 된다.

노드가 있을시에는 새로운 노드가 첫번째로 가기위해 `NewNode->next = Head;`  새로운 노드의 Next주소와 이전 노드를 연결한다.

`Head->prev = NewNode;` HEAD의 이전 노드를 새로운 노드와 연결한다.

`	Head = NewNode;`이 후 HEAD와 새로운 노드를 같게 해서 새로운 노드가 올때마다 HEAD를 저장한다.

출력

![image](https://github.com/sc11046/C-programming/assets/121782720/485b66d7-fb4d-4239-9adb-8b8962c27f21)