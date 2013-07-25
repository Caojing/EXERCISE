#include <stdio.h>

int a[10]={9,1,5,3,9,3,6,7,9,4};

int find(int *a,int length)
{
	int i=0;
	int odd=a[0];
	for(i=1;i<length;i++){
		odd=a[i];
	}
	return odd;
}

int main(void)
{
	printf("%u\n",find(a,sizeof(a)/sizeof(int)));

	return 0;
}
