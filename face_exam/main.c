#include <stdio.h>

int add(int x,int y)
{
	return x+y;
}
int sub(int x,int y)
{
	return x-y;
}
int mul(int x,int y)
{
	return x*y;
}
int dev(int x,int y)
{
	if(y==0){
		return 0;
	}
	else{
		return x/y;
	}
}
int qiuyu(int x,int y)
{
	if(y==0){
		return 0;
	}
	else{
		return x%y;
	}
	
}
typedef int (*PF)(int ,int );
int main(void)
{
	int m,n,i=0;
	char c=0;
	PF a[5]={add,sub,mul,dev,qiuyu};
	scanf("%d %c %d",&m,&c,&n);
//	printf("%d\n",(*a[i])(m,n));
	switch(c){
		case '+':
			i=0;
			break;
		case '-':
			i=1;
			break;
		case '*':
			i=2;
			break;
		case '/':
			i=3;
			break;
		case '%':
			i=4;
			break;
		default:
			break;
	}
	printf("%d\n",a[i](m,n));

	return 0;
}
