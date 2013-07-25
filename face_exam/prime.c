#include <stdio.h>

int main(void)
{
	unsigned int n;
	printf("please input number:\n");
	scanf("%d",&n);
	while(n % 2 == 0){
		n = n / 2;
	}
	if(n == 1){
		printf("this number is right:\n");
	}
	else 
		printf("error\n");

	return 0;
}
int main(void)
{
	unsigned int n;
	if(n & (n-1) == 0){
		printf("OK\n");
	}
	else{
		printf("error\n");
	}
	return 0;
}
