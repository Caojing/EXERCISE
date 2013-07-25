#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"
#if 0
typedef struct dict
{
	char word[1000];
	char *Explain[1000];
	int count;
	struct dict *next;
}dict_t;
typedef dict_t * link;

link head = NULL;
link tail = NULL;

void print_word(link head);
void search_word(link head);
void add_word(link head);
void printf_word(link head);
link delete_word(link head);
void save_word(link head);
void write_2file(link head);
void read_2file();

#endif

link make_node()	//创建节点
{
	link p = malloc(sizeof(*p));
	memset(p, 0, sizeof(*p));	//清0

	return p;
}
#if 0
int main(void)
{
	FILE *fp = fopen("dict.txt", "r");	//以读的方式打开文件“dict.txt”
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

		if(!fgets(content, 1000, fp))	//从文件读一行（单词），如果到末尾则跳出循环
			break;
		if(!fgets(Ess, 1000, fp))	//从文件读一行（内容），如果到末尾了跳出寻环
			break;

		if(head == NULL)	//初始化链表
		{
			head = p;
			tail = head;
		}
		else
		{
			tail -> next = p;
			tail = tail -> next;
		}

		//		fgets(content,100,fp);
		if(content[strlen(content) - 1] == '\n')	//如果数组到最后一个元素时候将‘\n’变为'\0'
			content[strlen(content) - 1] = '\0';

		strcpy(p -> word, content + 1);	 //由于第一个为#所以把第二个以后的元素复制给p -> word
		//		printf("%s\n",p->word);
		//		fgets(Ess,100,fp);
		token = strtok(Ess, ":");	//截取：以前的内容
		//		printf("%s\n",token);
		p->count = 0;	//初始化

		while((token = strtok(NULL, "@"))!=NULL)
		{
			p->Explain[p->count] = (char *)malloc(strlen(token) + 1);
			strcpy(p->Explain[p->count], token);

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

#endif

void print_word(link head)	//打印单词
{
	printf("<<<<<<<<<<<<<<<<print_word>>>>>>>>>>>>>>>>\n");
	int i = 0;
	link p = head;

	if(p == NULL)
	{
		printf("the list is NULL:\n");
		return ;
	}

	printf("%s\n",p -> word);

	for(i = 0;i < p -> count; i++)
	{
		printf("%s ",p -> Explain[i]);
	}
	putchar ('\n');

	return ;
}

void search_word(link head)	//查找单词
{
	printf("<<<<<<<<<<<<<<<<<search_word>>>>>>>>>>>>>\n");
	char word[20];
	link p = head;

	if(p == NULL)
	{
		printf("the list is NULL:\n");
	}

	printf("please input find word:\n");
	scanf("%s",word);

	while(p)
	{
		if(strcmp(p->word,word) == 0)
		{
			print_word(p);
			break;
		}

		p = p->next;
	}
	
	if(p == NULL)
	{
		printf("not found:\n");
	}
	
	return ;
}

void add_word(link head)	//添加新单词
{
	printf("<<<<<<<<<<<<<<<<<<add_word>>>>>>>>>>>>>>>>>\n");
	link q = head;
	char word[100];

	link p = make_node();

	if(head == NULL)
	{
		head = p;
	}

	printf("please input new word:\n");	
	scanf("%s", word);

	strcpy(p -> word, word);	

	while(1)
	{
		printf("please input Explain:\n");
		scanf("%s", word);

		if(strstr(word, "$"))
			break;

		p -> Explain[p -> count] = malloc(strlen(word) + 1);
		strcpy(p -> Explain[p -> count], word);

		p->count++;
	}
	putchar ('\n');
	print_word(p);

	for(q = head; q != NULL; q = q->next)
	{
		if(strcmp(p -> word, q -> word) > 0)
		{
			if(q -> next && strcmp(p -> word, q -> next -> word) < 0)
			{
				p -> next = q -> next;
				q -> next = p;
				break;
			}
			else
			{
				if(q -> next == NULL){
					q -> next = p;
					break;
				}
			}
		}
		else
		{
			if(q == head)
			{
				p -> next = head;
				head = p;
				break;
			}
		}
	}

	putchar ('\n');

	return ;
}

void printf_word(link head)	//打印文件内容
{
	printf("<<<<<<<<<<<<<printf_word>>>>>>>>>>>>>>>>>>\n");
	link p = head;
	int i = 0;

	if(head == NULL)
	{
		printf("the list is NULL:\n");
		exit(0);
	}

	while(p)
	{
		printf("%s\n", p -> word);

		for(i = 0; i < p -> count; i++)
		{
			printf("%s ", p -> Explain[i]);
		}

		p = p->next;
		putchar ('\n');
	}
	
	return ;
}

link delete_word(link head)	//删除单词
{
	printf("<<<<<<<<<<<<<<<delete_word:>>>>>>>>>>>>>>>>>\n");
	printf("<<<<<<<<<<<<<<<please input dele word>>>>>>>\n");
	char word[20];
	scanf("%s", word);

	link p = head;
	link r = NULL;

	if(head == NULL)
	{
		printf("<<<<<<<the list is NULL:>>>>>>>>>>\n");
		return NULL;
	}

	if(p == head && !strcmp(head -> word, word))
	{
		head = p -> next;
		print_word(p);

		free(p);
		p = NULL;

		return head;
	}

	while(p)
	{
		r = p;
		p = p -> next;

		if(p -> next && !strcmp(p -> word, word))
		{
			r -> next = p -> next;
			print_word(p);

			free(p);
			p = NULL;

			break;
		}
		else
		{
			if(p -> next == NULL && !strcmp(p -> word, word))
			{
				r -> next = NULL;
				print_word(p);

				free(p);
				p = NULL;

				break;
			}
		}
	}

	if(p == NULL)
	{
		printf("<<<<<<<<<<<not found>>>>>>>>>>>>>>>>> \n");
	}

	return head;

}

void save_word(link head)	//保存修改后的新内容
{
	link p = head;
	int i = 0;

	if(p == NULL)
	{
		printf("the list is NULL:\n");
		return ;
	}

	FILE *fp1 = fopen("dict.txt", "w");
	if(fp1 == NULL)
	{
		perror("open file dict.txt\n");
		exit(1);
	}

	while(p)
	{
		fprintf(fp1,"#%s\n",p -> word);
		fputs("Trans:", fp1);

		for(i = 0; i < p -> count; i++)
		{
			fprintf(fp1, "%s", p->Explain[i]);
			if(i != (p -> count - 1))
			{
				fputs("@", fp1);
			}
		}
		p = p -> next;
	}

	fclose(fp1);

	return ;
}

void write_2file(link head)	//以二进制文件写
{
	FILE *fp = fopen("write_2.dat", "w");
	if(fp == NULL)
	{
		perror("open file write_2.dat\n");
		exit(0);
	}

	link p = head;
	int c = 0;
	int i = 0;
	int m = 0;

	if(fwrite("SXLGDX", 1, 6, fp) < 6)	// 索引头
		return ;

	while(p)
	{
		c++;
		p = p -> next;	
	}

	fwrite(&c, 1, 4, fp);	// 单词个数---4个字节
	p = head;
	while(p)
	{
		c = strlen(p -> word);
		fwrite(&c, 1, 4, fp);	// 单词的长度----4字节

		fwrite(p -> word, 1, strlen(p -> word), fp); // 单词内容

		m = p -> count;
		fwrite(&m, 1, 4, fp);	// 解释个数----4字节

		for(i = 0;i < p -> count; i++)
		{
			c = strlen(p -> Explain[i]);
			fwrite(&c, 1, 4, fp);	//解释长度

			fwrite(p -> Explain[i], 1, strlen(p -> Explain[i]), fp);//解释内容
		}
		p = p -> next;
	}

	fclose(fp);

	return ;
}

void read_2file()	//读二进制文件内容
{
	link p = NULL;
	link head = NULL;

	FILE *fp = fopen("write_2.dat", "r");
	if(fp == NULL)
	{
		perror("open file write_2.dat\n");
		exit(0);
	}
	
	int length = 0;
	int num = 0;
	int i = 0;
	int c = 0;
	int j = 0;

	fseek(fp, 6, SEEK_SET);	//	索引头

	if(fread(&length, 1, 4, fp) <= 0)	//	单词个数	
		return ;

	num = length;
	for(i = 0;i < num; i++)
	{
		p = make_node();

		if(!head)
		{
			head = p;
			tail = head;
		}
		else
		{
			tail -> next = p;
			tail = tail -> next;
		}

		if(fread(&length, 1, 4, fp) <= 0)	// 单词长度
			break;

		c = length;
		printf("%d\n", c);

		if(fread(p->word, 1, c, fp) <= 0)	// 单词内容
			break;
		if(fread(&length, 1, 4, fp) <= 0)	// 解释个数
			break;
		p -> count = length;
		for(j = 0;j < p -> count; j++)
		{
			memset(&length, 0, 5);

			if(fread(&length, 1, 4, fp) <= 0)	// 解释长度
				break;

			c = length;
			p -> Explain[j] = malloc(c + 1);

			if(fread(p -> Explain[j], 1, c, fp) <= 0)	// 解释长度
				break;

			p -> Explain[j][c] = '\0';
		}

		print_word(p);

	}

	fclose(fp);

	return ;
}
