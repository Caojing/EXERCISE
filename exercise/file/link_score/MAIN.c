#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct stu
{
	char name[20];
	float chinese;
	float math;
	float aver;
	struct stu *next;
}stu_t;
typedef stu_t* link;
link head = NULL;
link tail = NULL;
link make_node()
{
	link p = malloc(sizeof(*p));
	memset(p,'\0',sizeof(*p));
	return p;
}
void init_info(link head)
{
	FILE *fp = fopen("stu_info.txt","w");
	while(1){
		link p = make_node();
		if(!head){
			head = p;
			tail = head;
		}
		else{
			tail->next = p;
			tail = tail->next;
		}
		scanf("%s",p->name);
		getchar ();	
		scanf("%f,%f",&p->chinese,&p->math);
		p->aver = (p->chinese + p->math)/2;
		if(strstr(p->name,"$"))
			break;
		fprintf(fp,"%s %2.1f %2.1f %2.1f\n",p->name,p->chinese,p->math,p->aver);
	}
	fclose(fp);
}
void print_info(link head)
{
	link p = head;
	while(p){
		printf("%s %2.1f %2.1f %2.1f\n",p->name,p->chinese,p->math,p->aver);
		p = p->next;
	}
}
int main(void)
{
//	init_info(head);
	FILE *fp = fopen("stu_info.txt","r");
	char content[100];
	while(1){
		if(!fgets(content,100,fp))
			break;
		link p = make_node();
		if(!head){
			head = p;
			tail = head;
		}
		else{
			tail->next = p;
			tail = tail->next;
		}
		if(content[strlen(content)+1] == '\n')
			content[strlen(content)+1] = '\0';
		memcpy(p,content,strlen(content)+1);
	}
	print_info(head);	
	fclose(fp);
	return 0;
}
