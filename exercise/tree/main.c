#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int item;
	struct node *left;
	struct node *right;
}node_t;
typedef node_t * link;
link head = NULL;
link make_node(unsigned char item)
{
	link p = malloc (sizeof(*p));
	p -> item = item;
	p ->left = NULL;
	p ->right = NULL;
	return p;
}
link init(unsigned char LVR[],unsigned char VLR[],int n)
{
	if(n <= 0){
		return NULL;
	}
	link t;	
	t = make_node(LVR[0]);
	int i = 0;
	for(i = 0;VLR[i]!=LVR[0]; i++);
	t->left = init(LVR+1,VLR,i);
	t->right =init(LVR+i+1,VLR+i+1,n - i - 1 );
	return t;
}
link insert_node(link t,unsigned char key)
{
	if(t == NULL){
		link p = make_node(key);
		return p;
	}
	if(t->item > key){
		t->left = insert_node(t->left,key);
	}
	if(t->item < key){
		t->right = insert_node(t->right,key);
	}
	return t;
}
link search_tree(link t,int key)
{
	if(t == NULL){
		return NULL;
	}
	if(t->item == key){
		return t;
	}
	if(t->item>key){
		return search_tree(t->left,key);
	}
	if(t->item<key){
		return search_tree(t->right,key);
	}
}
/*
link delete_node(link root,unsigned char key)
{
	link s = NULL;
	link q = NULL;
	link p = search_tree(root,key);
	if(p == NULL){
		printf("not found  : \n");
		return root;
	}
	if(p ->left){
		q = p->left;
		if(!(q->right) ){
			p->item = q->item;
			p->left = delete_node(q,q->item);
		}
		else {
			while(q->right){
				s = q;
				q = q->right;
			}
			p->item = q->item;
			s->right = delete_node(q,q->item);
		}
		return root;
	}
	else if (p->right){
		q = p->right;
		if(!(q->left)){
			p->item = q->item;
			p->right = delete_node(q,q->item); 
		}
		else{
			while(q->left){
				s =q ;
				q = q->left;
			}
			p->item = q->item;
			s->left = delete_node(q,q->item); 
		}
		return root;
	}
	else {
		free(p);
		return NULL;
	}
	
}
*/
link delete_node(link t,unsigned char key)
{
	link p = search_tree(t,key);
	link s = NULL;
	link q = NULL;
	if(!p){
		printf("not found \n");
		return t;
	}
	if(p->left == NULL && p->right == NULL){
		free(p);
		p = NULL;
//		return t;
	}
	else if(p->left){
		q = p->left;
		if(!(q->right)){
			p->item = q->item;
			p->right = delete_node(q,q->item);
		}
		else{
			while(q->right){
				s = q;
				q = q->right;
			}
			p->item = q->item;
			s->right = delete_node(q,q->item);
		}
//		return t;
	}
	else{
		q = p->right;
		if(!(q->left)) {
			p->item = q->item ;
			p->left = delete_node(q,q->item);
		}
		else{
			while(q->left)	{
				s = q;
				q = q->left;
			}
			p->item = q->item;
			s->left = delete_node(q,q->item);
		}
//		return t;
	}
	return t;
}
void print_item(link t )
{
	if(t){
		print_item(t->left);
		printf("%d ",t->item);
		print_item(t->right);
	}
}

int main(void)
{
	unsigned char prev_seq[] = {4,2,1,3,6,5,7};
	unsigned char in_seq[] = {1,2,3,4,5,6,7};
//	unsigned char out_seq={1,3,2,5,7,6,4};
	link root = init(prev_seq,in_seq,7);
//	printf("%d\n",root->item);
	root = insert_node(root,8);
//	link p = search_tree(root,9);
//	if(p == NULL){
//		printf("not found \n");
//	}
//	else{
//		printf("%d ",p->item);
//	}
//	putchar ('\n');
	root = delete_node(root,3);
	print_item(root);
	putchar ('\n');
	return 0;
}
