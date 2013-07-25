#include <stdio.h>
#include "head.h"
#include <stdlib.h>
#include <string.h>
void input_info(Chengji *a,int *p)
{
	FILE *fp = fopen("score.txt","w");
	if(fp == NULL){
		perror("open file score.txt\n");
	}
	int i = 0;
	while(1){
		printf("please input info(wang)\n");
		scanf("%s",a[i].name);
		printf("please input info(67,78,89)\n");
		scanf("%f,%f,%f",&a[i].chinese,&a[i].math,&a[i].english);
		a[i].aver = (a[i].chinese + a[i].math + a[i].english)/3;
		if(strstr(a[i].name,"$"))
			break;
		fprintf(fp,"%10s %2.1f %2.1f %2.1f %2.1f\n",a[i].name,\
a[i].chinese,a[i].math,a[i].english,a[i].aver);
		i++;
	}
	*p = i;
	fclose(fp);
}
void read_info(Chengji *a,int *p)
{
	FILE *fp = fopen("score.txt","r");
	if(fp == NULL){
		perror("open file score.txt\n");
	}
	char content[100];
	int i = 0;
	while(fgets(content,100,fp)!=NULL){
		sscanf(content,"%s %f %f %f %f",a[i].name,\
			&a[i].chinese,&a[i].math,&a[i].english,&a[i].aver);
		i++;
	}
	*p = i;
	fclose(fp);
}
void print_info(Chengji *a,int *p)
{
	int i = 0;
	for(i = 0; i < *p; i++){
		printf("%2d %10s %2.1f %2.1f %2.1f %2.1f\n",i+1,a[i].name,\
				a[i].chinese,a[i].math,a[i].english,a[i].aver);
	}
}
void insert_info(Chengji *a,int *p)
{
	printf("insert_info <<<<<<<<<<<<<<<<\n");
	printf("please input new info(wang):\n");
	int i = *p;
	scanf("%s",a[i].name);
	printf("please input new info (67,78,89):\n ");
	scanf("%f,%f,%f",&a[i].chinese,&a[i].math,&a[i].english);
	a[i].aver = (a[i].chinese + a[i].math + a[i].english) / 3;
	printf("%2d %s %2.1f %2.1f %2.1f %2.1f\n",i+1,a[i].name,a[i].chinese,\
				a[i].math,a[i].english,a[i].aver);
	*p = *p + 1;
}
void search_info(Chengji *a,int *p)
{
	printf("search_info <<<<<<<<<<<<<\n");
	printf("please input new info(wang)\n");
	char name[20];
	int i = 0;
	scanf("%s",name);
	for(i = 0; i < *p ;i++){
		if(!strcmp(a[i].name,name)){
			printf("%d %s %2.1f %2.1f %2.1f %2.1f\n",i+1,a[i].name,\
a[i].chinese,a[i].math,a[i].english,a[i].aver);
		return ;
		}
	}
	printf("%s not found \n",name);	
}
void delete_info(Chengji *a,int *p)
{
	printf("delete_info <<<<<<<<<<<<<<<<\n");
	printf("please input delete name:\n");
	char name[20];
	scanf("%s",name);
	int i = 0;
	int j = 0;
	for(i = 0 ;i < *p;i++){
		if(!strcmp(a[i].name,name)){
			for(j = i; j < *p - 1;j++){
				cp_info(a+j,a+j+1);		
			}
			*p = *p - 1;
			return ;
		}
	}
	printf("%s not found\n",name);
}
void cp_info(Chengji *p,Chengji *q)
{
	strcpy(p->name,q->name);
	p->chinese = q->chinese;
	p->math = q->math;
	p->english = q->english;
	p->aver = q->aver;
		
}
void sort_info(Chengji *a,int *p)
{
	int i = 0;
	int j = 0;
	Chengji b;
	for(i = 0;i < *p;i++){
		for(j = 0; j < *p - 1 ; j ++){
			if(a[j].aver > a[j+1].aver){
				cp_info(&b,a+j);
				cp_info(a+j,a+j+1);
				cp_info(a+j+1,&b);
			}
		}
	}
}
void save_info(Chengji *a,int *p)
{
	FILE *fp = fopen ("score.txt","w");
	if (fp == NULL){
		perror("open file score.txt\n");
	}
	int i = 0;
	for(i = 0;i < *p;i++){
		fprintf(fp,"%s %2.1f %2.1f %2.1f %2.1f\n",a[i].name,\
				a[i].chinese,a[i].math,a[i].english,a[i].aver);
	}
	fclose(fp);
}

