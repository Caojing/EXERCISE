#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	unsigned char item;
	struct node *left;
	struct node *right;
}node_t;
typedef node_t * link;
link make_node(unsigned char c)
{
	link p = malloc(sizeof(*p));
	p->item = c;
	p->left = NULL;
	p->right = NULL;
}
link init(unsigned char LVR[],unsigned char VLR[],int n)
{
	if(n<=0){
		return NULL;
	}
	link t = make_node(LVR[0]);
	int i =0;
	for(i = 0;LVR[0]!=VLR[i];i++);
	t->left = init(LVR+1,VLR,i);
	t->right = init(LVR+i+1,VLR+i+1,n-i-1);
	return t;
}
link search_tree(link t,unsigned char key)
{
	if(!t){
		return NULL;
	}
	if(t->item == key){
		return t;
	}
	else if(t->item > key){
		return search_tree(t->left,key);
	}
	else {
		return search_tree(t->right,key);
	}
}
link insert_node(link t,unsigned char key)
{
	link p = make_node(key);
	if(t == NULL){
		t = p;
	}
	if(t->item > key){
		t->left = insert_node(t->left,key);
	}
	else if(t->item < key){
		t->right = insert_node(t->right,key);
	}
	return t;
}
link delete_node(link t,unsigned char key)
{
	link s = NULL;
	link q = NULL;
	if(t == NULL){
		return NULL;
	}
	else{
		if(t->item > key){
			t->left = delete_node(t->left,key);
		}
		else if(t->item < key){
			t->right = delete_node(t->right,key);
		}
		else/*if(t->item == key)*/{
			if(t->left == NULL && t->right == NULL){
				free(t);
				t = NULL;
				return t;
			}
			else if(t->left){
				q = t->left;
				if(!(q->right)){
					t->item = q->item;
					t->right = delete_node(q,q->item);
				}
				else{
					while(q->right){
						s = q;
						q = q->right;
					}
					t->item = q-> item;
					s->right = delete_node(q,q->item);
				}
			}
			else/*if(p->right!=NULL)*/{
				q = t->right;
				if(!(q->left)){
					t->item = q->item;
					t->left = delete_node(q,q->item);
				}
				while(q->left){
					s = q;
					q = q->left;
				}
				t->item = q->item;
				s->left = delete_node(q,q->item);
			}
		}
	}
	return t;
}
void print_tree(link t)
{
	if(t){
		print_tree(t->left);	
		printf("%d ",t->item);
		print_tree(t->right);
	}
	return ;
}
int main(void)
{
	unsigned char prev_seq[]={4,2,1,3,6,5,7};
	unsigned char in_seq[]={1,2,3,4,5,6,7};
	link root = init(prev_seq,in_seq,7);
	root = insert_node(root,8);
	print_tree(root);	
	putchar ('\n');
/*	link p = search_tree(root,8);
	if(p == NULL){
		printf("not found\n");
	}
	else{
		printf("%d ",p->item);
	}
	putchar ('\n');
*/
//	print_tree(root);	
	root = delete_node(root,7);
	print_tree(root);	
	putchar ('\n');
	return 0;
}
