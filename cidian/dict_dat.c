#include <stdio.h>
#include <string.h>
#include <malloc.h>
typedef struct dict
{
    char word[100];
    char * pExplain[40];
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
void readTxtFile(char* filename, dict_t** phead)
{
  FILE * p = NULL;
  dict_t * head = *phead;
  dict_t * tail = NULL;
  dict_t * pDict = NULL;
  char ch;
  int i = 0;
  int j = 0,number;
  char array[1001] = {'\0'};
  char * str = NULL;
  p = fopen(filename, "r");
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
      memset(tail, 0, sizeof(*tail));
      if(!fgets(array,100, p))
         break;
      if(array[strlen(array) - 1] == '\n')
         array[strlen(array) - 1] = '\0';
      strcpy(tail->word, array+1);
      printf("%s\n",array);
      
      memset(array, 0, 1001);
      j = 0;
      while(fgets(array + j,100, p))
      {   
          if(array[j] == '#')
          {
               break;
          }
          j = strlen(array);
      }
      number = strlen(array);
      //number = fread(array,1,1000, p);
      //if(0 >= number)
      //   break;
      
      //while(j<number)
      //{
      //   if(array[j] == '#')
      //     break;
      //   j++;
      //}
      if(j <= number - 1)
      {
         array[j] = '\0';
         fseek(p,-(number - j),SEEK_CUR);
      }
      str = strtok(array, "@");
      printf("%s\n",str);
      if(strlen(str) > 6)
      {  
         tail->pExplain[tail->count] = (char*)malloc(strlen(str) + 1 - 6);
         strcpy(tail->pExplain[tail->count], str+6);
         tail->count++;
      
      while((str = strtok(NULL, "@")) != NULL)
      {
         printf("%s\n",str);
         tail->pExplain[tail->count] = (char*)malloc(strlen(str) + 1);
         strcpy(tail->pExplain[tail->count], str);
      tail->count++;
      }
      }
  }
  *phead = head;
  fclose(p);
}
void writeTxtFile(char* filename, dict_t** phead)
{
    dict_t * head = NULL;
    dict_t * p = NULL;
    char strlength[10] = {'\0'};
    char top[11] = {'\0'};
    int num = 0;
    int i = 0;
    int j = 0;
    int c = 0;
    FILE* fp = NULL;

    head = *phead;
     
    if(NULL == head)
    {
        printf("empty list\n");
        return;
    }
    
    fp = fopen(filename, "w");
    p = head;
    while(p)
    {
         fprintf(fp, "#%s\n",p->word);
        
         if(p->count > 0)
            fprintf(fp,"%s","Trans:");
         for(i = 0; i < p->count;i++)
         {
              fprintf(fp,"%s",p->pExplain[i]);
              if(i < p->count - 1)
                fputc('@',fp);
         }
         fputc('\n',fp);
          p = p->next;
    }
}
void writeFile(char* filename, dict_t** phead)
{
    dict_t * head = NULL;
    dict_t * p = NULL;
    char strlength[10] = {'\0'};
    char top[11] = {'\0'};
    int num = 0;
    int i = 0;
    int j = 0;
    int c = 0;
    FILE* fp = NULL;

    head = *phead;
     
    if(NULL == head)
    {
        printf("empty list\n");
        return;
    }
    
    fp = fopen(filename, "w");
    if(10 > fwrite("AKAEDUAK47",1,10,fp))
        return;
    p = head;
    c = 0;
    while(p)
    {
       c++;
       p = p->next;
    }
    fprintf(fp, "%08d",c);
    p = head;
    while(p)
    {
        fprintf(fp, "%04d",strlen(p->word));
        fwrite(p->word,1,strlen(p->word),fp);
        fprintf(fp, "%04d",p->count);
        for(i = 0; i < p->count; i++)
        {
          fprintf(fp, "%04d",strlen(p->pExplain[i]));
          fwrite(p->pExplain[i],1,strlen(p->pExplain[i]),fp);          
        }
        p = p->next;
    }
    fclose(fp);
    
    
}
void readFile(char* filename, dict_t** phead)
{
    dict_t * head = NULL;
    dict_t * tail = NULL;
    char strlength[10] = {'\0'};
    char top[11] = {'\0'};
    int num = 0;
    int i = 0;
    int j = 0;
    int c = 0;
    FILE* fp = fopen(filename, "r");
    if(0 >= fread(top,1,10,fp))
        return;
    printf("%s\n", top);
    if(0 >= fread(strlength,1,8,fp))
        return;
    num = atoi(strlength);
    for(i = 0; i < num; i++)
    {
      if(!head)
      {
        head = (dict_t*)malloc(sizeof(dict_t));
        tail = head;
        *phead = head;
      }
      else
      {
         tail->next = (dict_t*)malloc(sizeof(dict_t));
         tail = tail->next;
      }
      memset(tail->word, 0, 100);
      memset(tail->pExplain, 0, sizeof(tail->pExplain));
      memset(strlength,0,5);      
      if(0 >= fread(strlength,1,4,fp))
         return;
      j = atoi(strlength);
      if(0 >= fread(tail->word,1,j,fp))
         return;
      memset(strlength,0,5);            
      if(0 >= fread(strlength,1,4,fp))
         return;
      tail->count = atoi(strlength);
      for(j = 0; j < tail->count;j++)
      {
           memset(strlength,0,5);      
           if(0 >= fread(strlength,1,4,fp))    
               return;
           c = atoi(strlength);

           tail->pExplain[j] = (char*)malloc(c+1);
           if(0 >= fread(tail->pExplain[j],1,c,fp))
               return;
           tail->pExplain[j][c] = '\0';
      }
    }
fclose(fp);
}
void reverseSearchWord(dict_t** phead,dict_t** phead2)
{
    dict_t * p = NULL;
    dict_t * q = NULL;
    dict_t * r = NULL;
    char strChar[100] = {'\0'};
    int flag = 0;
    int i = 0;

    printf("Input explanation:\n");
    scanf("%s", strChar);
    p = *phead;
    while(p)
    {
       i = p->count;
       while(i > 0)
       {
           if(NULL != strstr(p->pExplain[i - 1], strChar))
           {
               flag = 1;
               printf("Match word: %s\n", p->word);
               printf("%s\n", p->pExplain[i - 1]);
               break;
           }
          i--;
       }
       p = p->next;
    }
    if(0 == flag)
    {
       p = *phead2;
       while(p)
    {
       i = p->count;
       while(i > 0)
       {
           if(NULL != strstr(p->pExplain[i - 1], strChar))
           {
               flag = 1;
               printf("Match word: %s\n", p->word);
               printf("%s\n", p->pExplain[i - 1]);
               break;
           }
          i--;
       }
       p = p->next;
    }
       
    }
    if(0 == flag)
        printf("not found\n");
}
void searchWord(dict_t** phead, dict_t** phead2)
{
    dict_t * p = *phead;
    dict_t * q = NULL;
    dict_t * r = NULL;
    char strChar[100] = {'\0'};
    char top[11] = {'\0'};
    int num = 0;
    int i = 0;
    int j = 0;
    int c = 0;

    printf("searching word...\n");
    printf("Input word:\n");
    scanf("%s", strChar);
    p = *phead;
    while(p)
    {
            if(!strcmp(p->word, strChar))
            {
                for(c = 0; c < p->count; c++)
                {
                    if(p->pExplain[c])
                    {
                       printf("%s ", p->pExplain[c]);
                    }
                    
                }
                printf("\n");
                return;
            }
    }
    p = *phead2;
    while(p)
    {
        if(!strcmp(p->word, strChar))
            {
                for(c = 0; c < p->count; c++)
                {
                    if(p->pExplain[c])
                    {
                       printf("%s ", p->pExplain[c]);
                    }
                    
                }
                printf("\n");
                return;
            }
    }
    printf("not found\n");
    
    return;
}

void delWord(dict_t** phead)
{
    printf("delete word...\n");
}       
void addWord(dict_t** phead)
{
    dict_t * p = *phead;
    dict_t * q = NULL;
    dict_t * r = NULL;
    char strChar[100] = {'\0'};
    char top[11] = {'\0'};
    int num = 0;
    int i = 0;
    int j = 0;
    int c = 0;

    printf("Input new word:\n");
    scanf("%s", strChar);
    p = *phead;
    while(p)
    {
       i = strcmp(p->word, strChar);
       if(i == 0)
       {
           printf("word %s exists!\n",strChar);
           return;
       }
       if(i > 0)
       {
           break;
       }
       q = p;
       p = p->next;
    }
    
       r = (dict_t*)malloc(sizeof(dict_t));
       memset(r, 0, sizeof(*r));
       if(NULL == q)
       {
          if(!*phead)
         {
            *phead = r;
         }
         else
         {
            q = *phead;
            *phead = r;
            (*phead)->next = q;
         }
       }
       else
       {
           q->next = r;
           r->next = p;
       }
       i = 0;
       strcpy(r->word, strChar);
       printf("Input explanations:\n");
       while(1)
       {
           memset(strChar, 0, 100);
           scanf("%s", strChar);
           if(strstr(strChar, "$") != NULL)
           {
               if(r->count > 0)
               {
                 c = strlen(r->pExplain[r->count - 1]);
                 r->pExplain[r->count - 1][c] = '\n';
                 r->pExplain[r->count - 1][c+1] = '\0';
               }
               break;
           }
           r->pExplain[r->count] = (dict_t*)malloc(strlen(strChar) + 2);
           strcpy(r->pExplain[r->count],strChar);
           r->count++;
       }
}

int main(int argc, char * argv[])
{
   dict_t* head = NULL;
   dict_t* head2 = NULL;
   dict_t* pDict = NULL;
   char ch = '\0';
   //readFile(argv[1], &head);
//readFile("x.dat", &head);
   readTxtFile("dict.txt", &head);
   readTxtFile("dict2.txt", &head2);
   pDict = head;
  while(pDict)
  {
     
     print_node(pDict);
     printf("\n");
     pDict = pDict->next;
  }
  while(1)
  {
      printf("take a choice:\n1 add a new word\n2 delete a word\n3 search a word\n4 reverse to search a word\nx exit\n");
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
           case '4':
                 reverseSearchWord(&head);
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
  //writeFile("x.dat", &head);
   return 0;
}
