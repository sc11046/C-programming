# 체스 

![image](https://github.com/sc11046/C-programming/assets/121782720/5e5318bf-625b-46c0-9235-f5072cfcfad2)

```c
#include <stdio.h>
#include <stdlib.h>
int main(){
    int selNum[5];

    printf("숫자 입력 :\n");
    scanf( "%d %d %d %d %d %d", &selNum[0],&selNum[1],&selNum[2],&selNum[3],&selNum[4],&selNum[5]);
    printf(" 부족한 갯수 ? :%d %d %d %d %d %d\n", 1-selNum[0],1-selNum[1],2-selNum[2],2-selNum[3],2-selNum[4],8-selNum[5]);
    
    return 0;

}
```

정해진 갯수의 체스 말에서 **각 배열 별로 하나씩 빼주면** 부족한 숫자가 출력되게 작성했다.