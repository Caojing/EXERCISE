#include <stdio.h>
#include <stdlib.h>
typedef struct stu
{
	int num;
	char name[20];
	char sex;	
	float chinese;
	float math;
	float english;
	float aver;
}stu_t;
typedef stu_t* stu;
int main(void)
{
	int i= 0;
//	stu_t a[10];
	FILE *fp =fopen ("a.txt","w");
        if(fp == NULL){
                perror("open file a.txt \n");
        }
        while(1){
                printf("please inpu(num,name)\n");
        	stu p = malloc(sizeof(*p));
		scanf("%d,%s",&p->num,p->name);
		getchar();
		printf("please input (sex,chinese,math,english)\n");
                scanf("%c,%f,%f,%f",&p->sex,&p->chinese,&p->math,&p->english);
                p->aver = (p->chinese + p->math + p->english)/3;
		printf("%2.1f\n",p->aver);
		if(p->num == 0)
			break;
                fprintf(fp,"%d %s %c %2.1f %2.1f %2.1f %2.1f\n",p->num,\
			p->name,p->sex,p->chinese,p->math,p->english,p->aver);
        }
        fclose(fp);
}

