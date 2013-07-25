#include  <stdio.h>
#include "head.h"
int main(void)
{
	 int option = 0;
        int number = 0;
///////////////////////////////////////////
        stu head;
//        read_info(head, &number);
        while(1)
        {
                printf("Please select the option:\n");
                printf("1.Display\n");
                printf("2.Sort\n");
                printf("3.Insert\n");
                printf("4.Delete\n");
                printf("5.Quit\n");
                scanf("%d",&option);
                switch(option)
                {
                        case 1:
                        //////////
                        print_info(head,&number);
			  break;
                        case 2:
//                        sort_info(head,&number);
                        break;
                        case 3:
//                        insert_info(head,&number);
                        break;
                        case 4:
//                        delete_info(head,&number);
                        break;
                        case 5:
//                        save_info(head,&number);
//                        printf("exit...\n");
//                        return 0;
                        break;
                        default:
                        break;
                }
        }

	return 0;
}
