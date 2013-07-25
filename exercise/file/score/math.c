#include <stdio.h>
#include "head.h"
#include <stdlib.h>

void read_info(stu head,int *p)
{
	printf("read_info<<<<<<<<<<<<<<<<<\n");
	FILE *fp = fopen("a.txt","r");
	if(fp == NULL){
		perror("open file a.txt\n");
	}
	stu s = malloc(sizeof(*s));
	s = head;
	int i = 0;
//	char content[100];
	while(fgets(&s,100,fp)){
		sscanf(&s,"%d %s %c %f %f %f %f",&s->num,s->name,&s->sex,\
			&s->chinese,&s->math,&s->english,&s->aver);
		s = s->next;
		i++;
	}
	*p = i;
	fclose(fp);
}

void print_info(stu head, int *p)
{
	stu s;
	printf("print_info <<<<<<<<<<<<<<<<<\n");
	int i= 0;
	for(i = 0; i < *p; i++){
		printf("%2d %d %s %c %2.1f %2.1f %2.1f %2.1f\n",i+1,s->num,s->name,s->sex,s->chinese,s->math,s->english,s->aver);
	}
}
void insert_info(stu head, int *p)
{
		printf("insert_info <<<<<<<<<<<<<<<<<\n");
		printf("input new num and name(0101,)\n");
}
/*void sort_info(stu head,int *p)
{
	printf("sort_info <<<<<<<<<<<<<<<<\n");
	int i = 0;
	int j = 0;
	stu p = head;
	stu q =NULL;
	for( i=0;i<*p;i++){
		for(j=0;j<*p;j++){
			q = malloc(sizeof(*q));
			q = p;
			p = p->next;
			if(q->aver > p->aver){
				q->num = p->num;	
				strcpy(q->name,p->name);
				q->sex=p->sex;
				q->chinese=p->chinese;
				q->math=p->math;
				q->english = p->english;
				q->aver = p->aver;
			}
		}
	}
}
void delete_info(stu head, int *p)
{
	stu p =NULL;
	char name[20];
	printf("delete_info<<<<<<<<<<<<<<<<<<\n");
	printf("please input new name\n");
	scanf("%s",name);
	stu q;
	for(i = 0;i< *p;i++){
		q = p;
		p = p->next;
		if(strcmp(p->name,name) == 0){
			for(j = i;j < *p;j++){
				q->num = p->num;
                                strcpy(q->name,p->name);
                                q->sex=p->sex;
                                q->chinese=p->chinese;
                                q->math=p->math;
                                q->english = p->english;
                                q->aver = p->aver;

			}
			break;
		}
	}
	printf("not found \n");
}
void save_info(stu head, int *p)
{
	printf("save_info <<<<<<<<<<<<<<<<<<\n");
	FILE *fp=fopen("a.txt","w");
	if(fp == NULL){
		perror("open file a.txt\n");
	}
	for(i = 0;i < *p; i++){
		fprintf(fp,"%d %s %c %f %f %f %f\n",p->num,p->name,p->sex,p->chinese,p->math,p->english,p->aver);
	}
	
	fclose(fp);
}
*/
