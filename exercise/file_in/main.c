#include <stdio.h>

int main(void)
{
//	FILE *fp = fopen ("a.txt","w");
	FILE *fp = fopen ("a.txt","r");
	if(fp == NULL){
		perror("open file a.txt\n");
	}
	int a,b,c,i = 0;
/*	for(i = 0;i< 4;i++){
		printf("please input number (12 13 14)\n");
		scanf("%d %d %d",&a,&b,&c);
		fprintf(fp,"%d %d %d\n",a,b,c);
	}
*/
/* 1	char content[100];
	while (fgets(content,100,fp)!=NULL){
		sscanf(content,"%d %d %d",&a,&b,&c);
		puts(content);
	}
*/
/*2	c = 0;
	while((c = fgetc(fp))!=EOF){
		putc(c,fp);
	}
*/
	char content[100];
	while(fread(content,1,100,fp)){
		puts(content);
	}
	fclose(fp);
	return 0;
}
