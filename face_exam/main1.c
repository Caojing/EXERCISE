#include <stdio.h>
/*
int main(void)
{
	int i=0;
	int sum=1;
	int count=0;
	for(i=1;i<=10;i++){
		sum*=i;
	}
	printf("sum:%d\n",sum);
	while(1){
		if(sum % 10 != 0){
			break;
		}
		else{
			sum = sum / 10;
			count++;
		}
	}
	printf("count:%d\n",count);
	return 0;
}*/
int main(void)
{
	int n;
	int count=0;
	scanf("%d",&n);
	while(n>0){
		n=n/5;
		count+=n;
	}
	printf("%d\n",count);
	return 0;

}
