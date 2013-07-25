#ifndef MATH_H_
#define MATH_H_
typedef struct stu
{
	int num;
	char name[20];
	char sex;
	float chinese;
	float math;
	float english;
	float aver;
	struct stu *next;
}Chengji;
typedef Chengji * stu;
void read_info(stu head,int *p);
void print_info(stu head,int *p);
void add_info(stu head,int *p);
void delete_info(stu head,int *p);
void save_info(stu head,int *p);
#endif
