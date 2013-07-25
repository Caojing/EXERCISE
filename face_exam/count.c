#include <stdio.h>

int main(void)
{
	unsigned int n;
	int count = 0;
	scanf("%d",&n);
	while(n != 0){
		n = n & (n-1);
		count++;
	}
	printf("%d\n",count);
	return 0;
}
