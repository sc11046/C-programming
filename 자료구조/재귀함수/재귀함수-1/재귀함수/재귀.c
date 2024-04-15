#include <stdio.h>

int test(int a)
{
	if (a <= 0)
		return;
	printf("test : (%d)\n", a);
	return test(a - 1);
}
/*int main()
{
	//test(5);
	printf("test : (%d)\n", 1/10);
	return 0;
}*/