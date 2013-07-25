#include <stdio.h>
#include <stdlib.h>
/*
typedef struct stu
{
	char data;
	int bused;
}stu;
stu queue[512];

int head = 0;
int tail = 0;
char c= 0;
void enqueue(c)
{
	if(queue[tail].bused == 0){
		queue[tail].data = c;
		queue[tail].bused = 1;
		tail = tail + 1;
		
	}
}
char dequeue(void)
{
	if(queue[head].bused == 1){
		c = queue[head].data;
		queue[head].bused = 0;
		head = head + 1;
	}
	return c;
}
int is_empty()
{
	return head == tail && queue[tail].bused == 0;
}
int is_full()
{
	return head == tail && queue[head].bused == 1;	
}
*/
typedef struct stu
{
	char data;
	struct stu *next;
	struct stu *prev;
}stu_t;
typedef stu_t* link;
link head = NULL;
link tail = NULL;
char c = 0;
link make_node(c)
{
	link p = malloc (sizeof(*p));
	p->data = c;
	p->next = NULL;
	p->prev = NULL;
	return p;
}
void enqueue(c)
{
	link p =make_node(c);
	if(head == NULL){
		head = tail = p;
		tail->next = NULL;
	}
	else{
		p->next = head;
		head ->prev = p;
		head = p;
	}
}
char dequeue(void)
{
	if(head  == tail){
		c = tail -> data;
		free(tail);	
		tail = head = NULL;
	}
	else{
		link p =tail;	
		c = p->data;
		tail = tail -> prev;
		free(p);
		tail -> next = NULL;
	}
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

int main(void)
{
	if(!is_full())
	{
		enqueue ('a');	
		enqueue ('b');
		enqueue ('c');
	}
	while(!is_empty()){
		printf("%c",dequeue());
	}
	putchar ('\n');
	return 0;
}
