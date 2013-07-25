#include <stdio.h>
#include <string.h>
int main(void)
{
	char str[10]={'\0'};
	scanf("%s",str);
	unsigned int d=0;
	unsigned int sum=0;
	int i=1;
	char *p=str+strlen(str)-1;
	while(p >= str){
		if(*p >= '0' &&  *p <='9')
			d= *p -'0';
		if( *p >= 'a'&&  *p <='f')
			d= *p -'a'+10;
		if(*p >= 'A'&&  *p  <='F')
			d=*p -'A'+10;
		p--;
		sum+=d*i;
		i=i*16;
	}
	printf("0x%x\n",sum);
	return 0;
}
