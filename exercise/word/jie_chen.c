#include <stdio.h>
/*
int main(void)
{
	int i = 0;
	int count = 0;
	int sum = 1;
	for(i = 1; i <= 10;i++){
		sum*=i;
	}
	printf("%d\n",sum);
	while(sum > 1){
		if(sum % 10 == 0){
			count ++;
		}
		sum  = sum / 10;
	}
	printf("%d\n",count);
	return 0;
}
*/
int main(void)
{
	int i ;
	scanf("%d",&i);
	int count = 0;
	while(i > 0){
		i = i / 5;
		count += i;
	}
	printf("%d\n",count);
	return 0;
}
