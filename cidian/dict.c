#include <stdio.h>
#include <string.h>
#include <malloc.h>
typedef struct dict
{
    char word[100];
    char * pExplain[10];
    int count;
    struct dict * next;
}dict_t;
void print_node(dict_t* pDict)
{
    int i = 0;
    if(NULL == pDict)
    {
       printf("invalid print\n");
       return;
    }
    printf("%s\n",pDict->word);
    for(i = 0; i < pDict->count;i++)
       printf("%s ",pDict->pExplain[i]);
    printf("\n");
}
void addWord(dict_t ** phead)
{
    printf("add word...\n");
}
void delWord(dict_t ** phead)
{
    printf("delete word...\n");
}
void searchWord(dict_t ** phead)
{
    dict_t* p = *phead;
    char word[100] = {'\0'};
    printf("search word...\n");
    if(NULL == p)
    {
      printf("no word in list\n");
      return;
    }
    printf("input word:\n");
    scanf("%s",word);
    
    while(p)
    {
       if(!strcmp(p->word,word))
       {
           print_node(p);
           break;
       }
       p = p->next;
    }
    if(NULL == p)
    {
        printf("not found\n");
    }
    
}

int main(int argc, char* argv[])
{
  FILE * p = NULL;
  dict_t * head = NULL;
  dict_t * tail = NULL;
  dict_t * pDict = NULL;
  char ch;
  int i = 0;
  char array[100] = {'\0'};
  char * str = NULL;
  p = fopen("dict.txt", "r");
  while(1)
  {
      if(!head)
      {
        head = (dict_t*)malloc(sizeof(dict_t));
        tail = head;
      }
      else
      {
         tail->next = (dict_t*)malloc(sizeof(dict_t));
         tail = tail->next;
      }
      memset(tail->word, 0, 100);
      if(!fgets(array,100, p))
         break;
      if(array[strlen(array) - 1] == '\n')
         array[strlen(array) - 1] = '\0';
      strcpy(tail->word, array+1);
      printf("%s\n",array);
      
      tail->count = 0;
      memset(tail->pExplain, 0, sizeof(tail->pExplain));
      memset(array, 0, 100);
     
      if(!fgets(array,100, p))
         break;
      str = strtok(array, "@");
      printf("%s\n",str);
      if(strlen(str) > 6)
      {  
         tail->pExplain[tail->count] = (char*)malloc(strlen(str) + 1 - 6);
         strcpy(tail->pExplain[tail->count], str+6);
      tail->count++;
      }
      
      while((str = strtok(NULL, "@")) != NULL)
      {
         printf("%s\n",str);
         tail->pExplain[tail->count] = (char*)malloc(strlen(str) + 1);
         strcpy(tail->pExplain[tail->count], str);
      tail->count++;
      }
  }

  pDict = head;
  while(pDict)
  {
     
     print_node(pDict);
     printf("\n");
     pDict = pDict->next;
  }
  while(1)
  {
      printf("take a choice:\n1 add a new word\n2 delete a word\n3 search a word\nx exit\n");
      scanf("%c", &ch);
      switch(ch)
      {
           case '1':
                 addWord(&head);
                 break;
           case '2':
                 delWord(&head);
                 break;
           case '3':
                 searchWord(&head);
                 break;
           case 'x':
                 printf("exit...\n");
                 return 0;
                 break;
           default:
                 continue;
                 break;
      }
      
        
  }
  return 0;
}
