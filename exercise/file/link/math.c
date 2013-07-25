#include <stdio.h>
#include <stdlib.h>
typedef struct stu
{
        int data;
        struct stu *next;
        struct stu *prev;
}stu_t;
typedef stu_t * link;
link tail = NULL;
link head = NULL;
link make_node(int c)
{
	link p = malloc(sizeof(*p));
	p->data = c;
	return p;
}
link init(link head,int c)
{
	if(head == NULL){
		head = make_node(c);
		tail = head;
	}
	else{
		link p = make_node(c);
		p->prev = head;
//		head->next = p;
		head = head ->next;
		
	}
	return head;
}
void print_info(link head)
{
	link p =head;
	while(p){
		printf("%d ",p->data);
		p = p->prev;
	}
}
int main(void)
{
	link head = init(head,4);
	print_info(head);
	return 0;
}

