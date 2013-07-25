#include <stdio.h>
#include <malloc.h>
typedef struct stu
{
	char data;
	struct stu *next;
}stu_t;
typedef stu_t * link;
link head = NULL;
link p = NULL; 
char c = 0;
link make_node(c)
{
	link p = malloc(sizeof(*p));
	p ->data = c;
	p ->next = NULL;
	return p;
}
void push(c)
{
	p = make_node(c);
	if(head == NULL){
		head = p;
		p->next = NULL;
	}
	else{
		p->next = head;
		head = p;
	}
}
char pop(void)
{	
	p = head;
	head = head->next;
	c = p->data;
	free(p);
	return c;
}
int is_empty()
{
	return head == NULL;
}
int is_full()
{
	return 0;
}
/*
char str[512]={'\0'};
int top = 0;
char c = 0;
void push(char c)
{
	str[top] = c;
	top ++;
}
char pop(void)
{
	top --;
	c = str[top];
	return c;
}
int is_empty()
{
	return top == 0;
}
int is_full()
{
	return top == 512;
}
*/
int main(void)
{
	if(!is_full()){
		push ('a');
		push ('b');
		push ('c');
	}
	while(!is_empty()){
		printf("%c",pop());
	}
	putchar ('\n');
	return 0;
}
