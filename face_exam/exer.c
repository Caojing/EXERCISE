#include <stdio.h>

int main(void)
{

	typedef int (*a)[10];
	char* b[10];
	printf("%d,%d\n",sizeof(a),sizeof(b));
	return 0;
}
