# 연결리스트

## 1. 연결리스트란?

연결리스트란, 일반적으로 사용하는 배열과 달리

동적으로 각 칸들이 앞, 뒤로 사슬처럼 연결되어 있는 자료구조

![image](https://github.com/sc11046/Capstone/assets/121782720/94edd87b-5035-412c-aad6-17cfac449e07)

연결리스트를 쓰는 이유?

![image](https://github.com/sc11046/Capstone/assets/121782720/4e879c27-f5be-45d4-aba3-255a58f5f735)

기존 배열에서는 arr[1]의 5를 삭제하고 싶다면 0으로 삭제임을 표시를 해줄 뿐 데이터가 들어있던 칸을 삭제 할 수 없다.

![image](https://github.com/sc11046/Capstone/assets/121782720/5f512c80-f2a6-497c-a878-5e37b1cfed28)

반면, 연결리스트는 각 칸들을 동적으로 구현하고 포인터를 통해 다음 칸의 주소를 저장하는 구조이다

5를 카리키는 칸의 주소를 없애고 다음 10을 가리키는 주소로 연결시켜 삭제 할 수 있다.

이를 활용해 맨 앞과 맨뒤가 연결되어있는 원형 연결 리스트, 포인터가 이전 칸을 가리키는 양방향 연결리스트를 구현 할 수 있다.

![image](https://github.com/sc11046/Capstone/assets/121782720/648f0bff-927f-4430-ac38-fc374c52dd66)

## 2. 원리

각 칸을 Node라고 하며 아래와 같이 구조체로 선언한다.

구조체 : 직접 변수의 형태를 만들 수 있는 문법

```c
typedef struct NODE
{
	int ndata;//관리될 데이터

	struct NODE* next;//데이터 관리를 위한 포인터
	
} NODE;
```

데이터와 다음 주소를 담을 변수를 구조체에 선언한다.

```c
struct NODE* next;
```

다음 노드의 주소를 저장하기 위해 같은 구조체 타입을 가리킬 수 있는 포인터이기 때문에 다른 형태가 아닌 구조체 타입으로 선언한다.

```c
int main()
{
	NODE list[5];
	//값초기화
	list[0].ndata = 100;
	list[1].ndata = 200;
	list[2].ndata = 300;
	list[3].ndata = 400;
	list[4].ndata = 500;
	//연결 리스트 구조화
	list[0].next = &list[3];
	list[1].next = &list[4];
	list[2].next = NULL;
	list[3].next = &list[1];
	list[4].next = &list[2];

	for (int i = 0;i < 5;i++)
	{
		printf("list[%d] : %d\n", i, list[i].ndata);
	}
	
	NODE* pTmp = &list[0];
	while (pTmp != NULL)
	{
		printf("%p,%d\n", pTmp, pTmp->ndata);
		pTmp = pTmp->next;
	}
	return 0;
}
```

list[5]를 만들어 준 뒤 각 NODE별로 데이터와 다음 노의 주소를 저장하고 헤드를 list[0]으로 고정한다.

![image](https://github.com/sc11046/Capstone/assets/121782720/2c354876-c7bc-41d6-95f7-84c77df3e196)

![image](https://github.com/sc11046/Capstone/assets/121782720/558a2e99-9249-4772-8e60-24b7c2b537a5)

노드를 원하고 만큼 생성하고 삭제 할 수 있어야 되므로 동적으로 연결리스트를 만들어야 한다.

