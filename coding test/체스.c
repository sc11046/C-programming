#include <stdio.h>
#include <stdlib.h>
int main(){
    int selNum[5];

    printf("���� �Է��ض� ����\n");
    scanf( "%d %d %d %d %d %d", &selNum[0],&selNum[1],&selNum[2],&selNum[3],&selNum[4],&selNum[5]);
    printf(" �Է��� ���ڴ�? :%d %d %d %d %d %d\n", 1-selNum[0],1-selNum[1],2-selNum[2],2-selNum[3],2-selNum[4],8-selNum[5]);
    
    return 0;

}