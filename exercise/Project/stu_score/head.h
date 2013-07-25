#ifndef SCORE_H_
#define SCORE_H_
typedef struct stu
{
	char name[20];
	float chinese;
	float math;
	float english;
	float aver;
	struct stu *next;
}Chengji;
void input_info(Chengji *a,int *p);
void read_info(Chengji *a,int *p );
void print_info(Chengji *a,int *p);
void insert_info(Chengji *a,int *p);
void search_info(Chengji *a,int *p);
void sort_info(Chengji *a,int *p);
void delete_info(Chengji *a,int *p);
void save_info(Chengji *a,int *p);
void cp_info(Chengji *p,Chengji *q);
#endif
