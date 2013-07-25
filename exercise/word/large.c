#include <stdio.h>

int main(void)
{
	int str[10]= {2,4,6,8,9,10,3,5,7,1};
	int aver = 0;
	int sum = 0;
	int i = 0;
	for(i = 0; i <10;i++){
		sum+=str[i];
	}
	printf("%d\n",sum);
	aver = sum / 10;
	int count = 0;
	for(i = 0 ;i < 10; i ++){
		if(str[i]>aver){
			count++;
		}
	}
	printf("%d\n",count);
	return 0;
}
