#include <stdio.h>

int a[8]={3,4,7,9,2,6,1,5};
void part_info(int start,int mid,int end)
{
	int i =0;
	int n1 = 0;
	int n2 = 0;
	int j= 0;
	int k = 0;
	n1 = mid - start + 1;
	n2 = end - mid;
	int left[n1];
	int right[n2];
	for(i = 0;i < n1; i++){
		left[i] = a[start + i];
	}
	for(j = 0; j< n2 ; j ++){
		right[j] = a[mid+j+1];
	}
	i = 0;
	j = 0;
	k = start ;
	while(i < n1 && j < n2){
		a[k++] =( left[i] < right[j]) ? left[i++] : right[j++];
	}
	while(i<n1){
		a[k++] = left[i++];
	}
	while(j<n2){
		a[k++]=right[j++];
	}
}
void two_sort(int start,int end)
{
	int i= 0;
	if(start < end){
		int mid = (start + end)/2;
		two_sort(start,mid);
		two_sort(mid+1,end);
		for(i = 0;i < 8; i++){
			printf("%d ",a[i]);
		}
		putchar ('\n');
		part_info(start,mid,end);
		for(i = 0;i < 8; i++){
			printf("%d ",a[i]);
		}
		putchar ('\n');
			
	}	
}
int main(void)
{
	two_sort(0,7);
	return 0;
}
