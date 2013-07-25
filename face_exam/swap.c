#include <stdio.h>
#include <string.h>
void cj_math(char *start,char *end)
{
	char c;
	while(start<end){
		c=*start;
		*start=*end;
		*end=c;
		start++;
		end--;
	}
}
int main(void)
{
	char *p=NULL;
	char *end=NULL;
	char *start=NULL;
	char content[100]={'\0'};
	gets(content);
	cj_math(content,content+strlen(content)-1);
	puts(content);
	p=content;
	end=NULL;
	start=content;
	while(*p!='\0'){
		if(*p == ' '){
			end=p-1;
			cj_math(start,end);
			start=p+1;
		}
		p++;
	}
	cj_math(start,p-1);
	puts(content);
//	char *p="AKAEDU";
//	printf("%d,%d\n",sizeof(p),strlen(p));
//	char str[]="AKAEDU";
//	printf("%d,%d\n",sizeof(str),strlen(str));
//	char *q="AKAEDU";
//	char str[]="AKAEDU";
//	printf("p=%p,q=%p,str=%p\n",p,q,str);
	return 0;
}
