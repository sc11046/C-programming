#include <stdio.h>
#include <stdlib.h>
#include <string.h>  

int main(){
    char input[101];
    scanf( "%100s", input);
    int osc=0;
        for(int i=0;i<strlen(input)/2;i++)
        {
            int oc=strlen(input);
            oc=oc-i;
            if(input[i]==input[oc-1])
            {
                if(i==((strlen(input)/2)-1))
                {
                    osc=1;
                }
            }
            else
            {
                osc=0;
                break;
            }
        }
    if(osc==1)
    {
        printf("1");
    }
    else{
         printf("0");
    }
    return 0;

}