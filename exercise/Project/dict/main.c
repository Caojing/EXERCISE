#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"

int main(void)
{
	FILE *fp = fopen("dict.txt", "r");      //以读的方式打开文件“dict.tx    t”
	if(fp == NULL)
	{
		perror("open file dict.txt\n");
		exit(0);
	}

	while(1)
	{
		char content[1000];
		char Ess[1000];
		char *token;
		link p = make_node();

		if(!fgets(content, 1000, fp))   //从文件读一行（单词），如果到末尾则跳出循环
			break;
		if(!fgets(Ess, 1000, fp))       //从文件读一行（内容），如果到末尾了跳出寻环
			break;

		if(head == NULL)        //初始化链表
		{
			head = p;
			tail = head;
		}
		else
		{
			tail -> next = p;
			tail = tail -> next;
		}

		//              fgets(content,100,fp);
		if(content[strlen(content) - 1] == '\n')        //如果数组到最后一个元素时候将‘\n’变为'\0'
			content[strlen(content) - 1] = '\0';

		strcpy(p -> word, content + 1);  //由于第一个为#所以把第二个以后的元素复制给p -> word
		//              printf("%s\n",p->word);
		//              fgets(Ess,100,fp);
		token = strtok(Ess, ":");       //截取：以前的内容
		//              printf("%s\n",token);

		p->count = 0;   //初始化

		while((token = strtok(NULL, "@"))!=NULL)
		{
			p -> Explain[p -> count] = (char *)malloc(strlen(token) + 1);
			strcpy(p -> Explain[p -> count], token);

			p->count++;
		}

		print_word(p);
	}

	fclose(fp);

	int i = 0;

	while(1)
	{
		printf("take a choice:\n0 printf_word\n1 add a new word\n2 delete a word\n3 search a word\n4 write a 2file\n5 read_2file\n6 exit\n");
		scanf("%d", &i);

		switch(i)
		{
			case 0 :
				printf_word(head);
				break;
			case  1:
				add_word(head);
				break;
			case  2:
				head = delete_word(head);
				break;
			case  3:
				search_word(head);
				break;
			case  4:
				write_2file(head);
				break;
			case  5:
				read_2file();
				break;
			case  6:
				printf("exit...\n");
				save_word(head);
				return 0;
				break;
			default:
				continue;
				break;
		}
	}

	return 0;
}


