#include <stdio.h>

int main(void)
{
	int i=1,j=0,k=1;
	char c=0;
	char content[10]={'\0'};
	char name[10]={'\0'};
	//	if(argc!=3){
	//		printf("input error: \n");
	//	}
	FILE *fp2=fopen("data.txt","w");
	if(fp2==NULL)
	{
		perror("open file data.txt");
	}
	for(i=1;i<=10;i++)
	{
		sprintf(name,"%d.txt",i);
		FILE *fp1=fopen(name,"w");
		if(fp1==NULL){
			perror("open file name[i].txt");
		}
		for(j=(i-1)*10+1;j<=i*10;j++)
		{
			fprintf(fp1,"%2d ",j);
		}
		fputc('\n',fp1);
		fclose(fp1);
	}
	FILE *fp1;
	for(i=1;i<=10;i++)
	{
		sprintf(name,"%d.txt",i);
		fp1=fopen(name,"r");
		if(fp1==NULL){
			perror("open file name[i].txt");
		}
		//	while(fgets(content,100,fp1)!=NULL){
		//		fputs(content,fp2);
		//	memset(contene,0,sizeof(content));
		//	}
		//	while(n=fread(content,1,100,fp1)>0){
		//			fwrite(content,1,100,fp2);
		//	}
		while((c=fgetc(fp1))!=EOF)
		{
			fputc(c,fp2);
		}
		fputc('\n',fp2);
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}

