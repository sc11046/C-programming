#include <stdio.h>
#include <stdlib.h>

int main() {
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

    // 아랫부분 출력
    for (int i = 0; i < selNum - 1; i++) {
        for (int j = 0; j <= i + 1; j++) {
            printf(" ");
        }                          
        for (int s = 0; s < (2 * (selNum - i - 1)) - 1; s++) {
            printf("*");   
        }
        printf("\n");
    }

    return 0;
}