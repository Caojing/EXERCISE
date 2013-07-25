#include <stdio.h>

int str[10]={1,3,3,4,6,6,6,7,8,8};
int find_math(int num)
{
	int start = 0;
	int end = 9;
	while(start <= end ){
		int mid = (start + end ) / 2;
		if(num > str[mid] ){
			start = mid + 1;
		}
		else if(num < str[mid]){
			end = mid - 1;
		}
		else {
			return mid;
		}
	}
	return -1;
}
int main(void)
{
	int c = 0;
	c = find_math(6);
	printf("%d\n",c);
	return 0;
}
