#include <stdio.h>
int max_n(int n,...)
{
	int i=0;
	int *p=&n+1;
	int max=*p;
	for(i=1;i<n;i++){
		if(p[i] > max){
			max=p[i];	
		}
	}
	printf("%d\n",max);
}
int main(void)
{
	max_n(3,1,2,3);
	max_n(5,2,4,6,5,3);
	return 0;
}
