#include <stdio.h>

int main(void)
{
	unsigned int n;
	int count=0;
	printf("please input number :\n");
	scanf("%d",&n);
	while(n != 0){
		if(n % 2 != 0)
			count++;
		n = n >> 1;
	}
	printf("%d\n",count);
	return 0;
}
