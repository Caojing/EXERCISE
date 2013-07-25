#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}node_t;
typedef node_t * link;
link head = NULL;
link make_node(int c)
{
	link p = malloc(sizeof(*p));
	p -> data = c;
	p -> next = NULL;
}
void insert(int c)
{
	link p = make_node(c);
	link q = head;
	if(head == NULL){
		q = head =  p;
		q -> next = NULL;

		return ;
	}
	while(q){
		if(c > q->data){
			if(q->next && c <= q->next->data){
				p->next = q->next;
				q->next = p;
				break;
			}
			else{
				if(q->next == NULL){
					q->next = p;
					break;
				}
			}
		}
		else{
			if(q == head){
				p->next = head;
				head = p;
				break;
			}
		}
		q = q->next;
	}
	
	
}
void print_item()
{
	link p = head;
	while(p){
		printf("%d ",p->data);
		p = p->next;
	}
	putchar ('\n');
}
int main(void)
{
	int i = 0;
	while(1){
		printf("please input number \n");
		scanf("%d",&i);
		if(i == 0)
			break;
		insert(i);
		print_item();
	}
	return 0;
}
