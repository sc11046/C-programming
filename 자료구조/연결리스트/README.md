# 연결리스트

## 연결리스트란?

연결리스트란, 일반적으로 사용하는 배열과 달리

동적으로 각 칸들이 앞, 뒤로 사슬처럼 연결되어 있는 자료구조

![image](https://github.com/sc11046/Capstone/assets/121782720/94edd87b-5035-412c-aad6-17cfac449e07)

연결리스트를 쓰는 이유?



```c
#include <stdio.h>
#include <string.h>
#include <malloc.h>
typedef struct NODE{
	char szData[64];
	struct NODE* next;

} NODE;

NODE* g_pHead = NULL;
//연결 리스트 전체 데이터 출력
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

