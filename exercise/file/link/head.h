#ifndef LIST_H_
#define LIST_H_
typedef struct stu
{
	char data;
	struct stu *next;
	struct stu *prev;
}stu_t;
typedef stu_t * link;
link make_node(char c);
link init(link head,char c);
void print_info(link head);
/*
link read_info(link head,int *p);
void input_info(link head,int *p);
void print_info(link head,int *p);
void search_info(link head,int *p);
void insert_info(link head,int *p);
void delete_info(link head,int *p);
void sort_info(link head,int *p);
*/
#endif
