#include <stdio.h>
#include <malloc.h>
typedef struct node
{
	int data;
	struct node *next;

}node_t;
typedef node_t *link;
link head=NULL;
void del_node(link p)
{
	free(p);
}
link make_node(int d)
{
	link p=malloc(sizeof(*p));
	p->data=d;
	p->next=NULL;
	return p;
}
void cj_math(int n,int m)
{
	int i=0;
	int x=0;
	link p=NULL;
	link head=NULL;
	link tail=NULL;
	link r=NULL;
	for(i=0;i<n;i++){
		p=make_node(n-i);
		if(!head){
			head=p;
			tail=p;
		}
		else{
			p->next=head;
			head=p;
		}
	}
	tail->next=head;
	p=head;
	while(p->next!=p){
		x=0;
		while(x!=m-1){
			r=p;
			p=p->next;
			x++;
		}
		r->next=p->next;
		free(p);
		p=r->next;
	}
	printf("%d\n",p->data);
	free(p);
}
int main(void)
{
	cj_math(10,3);
	return 0;
}







