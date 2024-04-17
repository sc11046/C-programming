# 단일 연결리스트(원하는 노드 삭제)

## 원문 코드 : code.c 참고

![image](https://github.com/sc11046/C-programming/assets/121782720/cd1c2ae4-bf79-4887-9365-5a287999dd38)



![image](https://github.com/sc11046/C-programming/assets/121782720/318ba021-7886-4d14-bbdb-eafc751ac0d0)



![image](https://github.com/sc11046/C-programming/assets/121782720/a8f5b2f8-7ada-4df5-ae16-75cdf62e40a6)

```c
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
	}

	free(curNode);
	printf("노드 %d를 삭제했습니다.\n", sc);
}
```

원하는 노드의 순서를 scanf로 받아와 카운트를 설정한다.

```c
while (curNode != NULL && count != sc)
	{
		prevNode = curNode;	
		curNode = curNode->next;
		count++;
		printf("이전 주소 :%p,현재 주소 :%p, 현재 값 : %d, 넘어갈 주소 : %p\n",prevNode, curNode,curNode->data, curNode->next);
	}
```



여기 코드에서 이전 노드에 순회 노드를 저장하고 순회 노드는 다음 노드로 이동한다.

이후 원하는 노드에 도착하게 되면 반복문을 빠져나온다.

```c
if (prevNode == NULL) // 삭제하려는 노드가 첫 번째 노드일 경우
	{
		Head = curNode->next;
	}
	else
	{
		prevNode->next = curNode->next;
	}
	free(curNode);
```

이전 노드를 삭제하고자 하는 다음 노드로 이동시키고 순회 노드가 가르키던 노드를 삭제시킨다.

출력

![image](https://github.com/sc11046/C-programming/assets/121782720/23c35566-a911-4348-aa5a-5c1c32e6aff3)