#include <stdio.h>

int main(void)
{
	int a[10] = {-1,5,7,0,-22,7,9,-2,0,5};
	int i = 0;
	int max  = 0;
	int tmp = 0;
	while(i < 10){
		tmp += a[i];
		if(tmp < 0 ){
			tmp = 0;
		}
		else{
			if(tmp > max){
				max = tmp ;
			}
		}
		i++;
	}
	printf("%d\n",max);

	return  0;
}
