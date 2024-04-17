# 단일 연결리스트 정렬 (오름차순)

## 원문 코드 : code.c 참고

정렬할때 4가지 조건이 필요하다.

1. Head가 null일때
2. 새로운 노드가 가장 작을 때
3. 일반적인 경우
4. 새로운 노드가 가장 클 때 1

1의 경우는 아무런 노드가 없을 때 이므로 그림은 생략.

![image](https://github.com/sc11046/C-programming/assets/121782720/ad28313f-9fca-4d5b-be42-14bce9a50195)

![image](https://github.com/sc11046/C-programming/assets/121782720/0e951b3b-defc-4de3-88b2-cca04c5aa8c3)



![image](https://github.com/sc11046/C-programming/assets/121782720/9b4e880e-0a16-4552-b0ac-41c71b42a658)

![image](https://github.com/sc11046/C-programming/assets/121782720/0a230f04-1273-433a-bd21-f46b45af6a92)

![image](https://github.com/sc11046/C-programming/assets/121782720/bb5c5d8e-1de4-4004-bb37-266a50d02977)

정렬 함수 코드

```c
void InsertNodeSort()
{
	NODE* NewNode = (NODE*)malloc(sizeof(NODE));
	printf("노드 데이터 입력 : ");
	scanf_s("%d", &NewNode->data);
	NewNode->next = NULL;
	if (Head == NULL)//1. Head가 null일때
	{
		Head = NewNode;
		return;
	}	
	if (NewNode->data < Head->data)//2. 새로운 노드가 가장 작을 때
	{
		NewNode->next = Head;
		Head = NewNode;
		return;
	}
	NODE* CurNode = Head;//3. 일반적인 경우
	NODE* PreNode = Head;
	while (CurNode->next != NULL)
	{
		CurNode = CurNode->next;
		if (CurNode->data > NewNode->data)
		{
			NewNode->next = CurNode;
			PreNode->next = NewNode;
			return;
		}
		PreNode = PreNode->next;
	}
	CurNode->next = NewNode;//4. 새로운 노드가 가장 클 때
}
```

```c
	while (CurNode->next != NULL)
	{
		CurNode = CurNode->next;
		if (CurNode->data > NewNode->data)
		{
			NewNode->next = CurNode;
			PreNode->next = NewNode;
			return;
		}
		PreNode = PreNode->next;
	}
```

PreNode가 한 박자씩 늦게 CurNode를 따라가면서 비교하는게 중요하다.

출력

![image](https://github.com/sc11046/C-programming/assets/121782720/5cc89107-560f-48f9-aa23-fd71a48ae9bc)