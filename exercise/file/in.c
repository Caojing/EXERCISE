#include <stdio.h>
#include <stdlib.h>
typedef struct stu
{
	int num;
	char name[20];
	char sex;
	float score;
}stu_t;
typedef stu_t* ss;

int main(void)
{
	ss p = malloc(sizeof(*p));
	FILE * fp = fopen ("a.txt","w");
	if(fp == NULL){
		perror("open a.c\n");
	}
	while(1)
	{	
		printf("please input number(num name sex score):\n");
		scanf("%d %s %c %f",&p->num,p->name,&p->sex,&p->score);
		if(p->num == 0)
			break;
		fprintf(fp,"%d %s %c %2.1f\n",p->num,p->name,p->sex,p->score);
	}
	fclose(fp);
	return 0;
}
