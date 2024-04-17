# 별 찍기

![image](https://github.com/sc11046/C-programming/assets/121782720/2105811a-1cac-4460-87dd-96223e074e26)

```c
    int selNum;
    scanf("%d", &selNum);
    // 윗부분 출력
    for (int i = 0; i < selNum; i++) {
        for (int j = selNum - 1; j >= i; j--) {
            printf(" ");         
        }
        for (int s = 0; s < (2 * i) + 1; s++) {
            printf("*");  
        }
        printf("\n");
    }
```

![image](https://github.com/sc11046/C-programming/assets/121782720/13f99a22-765f-4beb-b6cf-2d9ad6b2c082)