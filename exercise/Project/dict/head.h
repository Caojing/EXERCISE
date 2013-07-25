#ifndef DICT_H_
#define DICT_H_
typedef struct dict
{
        char word[1000];
        char *Explain[1000];
        int count;
        struct dict *next;
}dict_t;
typedef dict_t * link;
link head;
link tail;

link make_node();
void print_word(link head);
void search_word(link head);
void add_word(link head);
void printf_word(link head);
link delete_word(link head);
void save_word(link head);
void write_2file(link head);
void read_2file();

#endif
