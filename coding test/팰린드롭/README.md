# 팰린드롭

![image](https://github.com/sc11046/C-programming/assets/121782720/0b581e95-fe49-4433-9d3a-f3dfdabbf7a1)

```c
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
```

