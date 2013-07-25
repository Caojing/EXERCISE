#include <stdio.h>
#include "head.h"

int main(void)
{
	int number = 0;
	Chengji a[10];
//	input_info(a,&number);
	read_info(a,&number);
	int i = 0;
	while(1){
		printf("<<<<<<<<<<<<<1.print_info>>>>>>>>>>>>>\n");
		printf("<<<<<<<<<<<<<2.search_info>>>>>>>>>>>>\n");
		printf("<<<<<<<<<<<<<3.insert_info>>>>>>>>>>>>\n");
		printf("<<<<<<<<<<<<<4.sort_info>>>>>>>>>>>>>>\n");
		printf("<<<<<<<<<<<<<5.delete_info>>>>>>>>>>>>\n");
		printf("<<<<<<<<<<<<<6.exit and save>>>>>>>>>>>\n");
		printf("please input your choose:\n");
		scanf("%d",&i);
		switch (i){
			case 1:
				print_info(a,&number);
				break;
			case 2:
				search_info(a,&number);
				break;
			case 3:
				insert_info(a,&number);
				break;
			case 4:
				sort_info(a,&number);
				break;
			case 5:
				delete_info(a,&number);
				break;
			case 6:
				save_info(a,&number);
				printf("exit...\n");
				return ;
				break;
			default: 
				break;
		}
	}
	return 0;
}
