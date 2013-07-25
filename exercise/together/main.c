#include <stdio.h>
/*
int main(void)
{
	int i = 0;
	int j = 0;
	char name[10];
	for(i = 0 ;i < 10 ; i++){
		sprintf(name,"%d.txt",i+1);
		FILE *fp =fopen(name,"w");
		if(fp == NULL){
			perror("open file a.txt\n");
		}
		for(j = i * 10;j < (i+1) * 10 ; j = j ++){
			fprintf(fp,"%2d ",j+1);
		}
		fputc('\n',fp);
		fclose(fp);
	}
	return 0;
}
*/
int main(void)
{
	int i =0;
	int j= 0;
	char c;
	char content[100];
	char name[10];
	FILE *fp = fopen("data.txt","w");
	if(fp == NULL){
		perror("open file data.txt\n");
	}
	for(i = 0;i < 10;i++){
		sprintf(name,"%d.txt",i+1);
		FILE *fp1 = fopen (name,"r");
		if(fp == NULL){
			perror("open file .txt\n");
		}
/*		while((c = fgetc(fp1))!=EOF){
			fputc(c,fp);
		}
*/
/*		while(fgets(content,100,fp1)){
			fputs(content,fp);
		}
*/
		int n;
		while((n = fread(content,1,100,fp1))){
			fwrite(content,1,n,fp);
		}
		fclose(fp1);
	}
	fclose(fp);
	return 0;
}

