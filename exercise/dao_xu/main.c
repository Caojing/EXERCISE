#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void cj_math(char *start,char *end)
{	
	char tmp ;
	while(start < end){
		tmp = *start;
		*start = *end;
		*end = tmp ;
		start ++;
		end --;
	}

}
int main(void)
{
	char *p = NULL;
	char str[100]={"happy everyday"};
	char *start = NULL;
	char *end = NULL;
	puts(str);
	start = str;
	end = str+strlen(str)-1;
	cj_math(start,end);
//	puts(str);
	start = str;
	p = str;
	end = NULL;	
	while(*p != '\0'){
		if( *p == ' '){
			end = p - 1;
			cj_math(start,end);
			start = p + 1;	
		}
		p++;
	}
	cj_math(start,p-1);
	puts(str);
	return 0;
}
