#include<stdio.h>
#include<time.h>

void main(){
	int i;
	clock_t start, end;
	double cpu_time_used;
	start = clock();
	
	
	//Algorithm logic
	
	
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("\nThe Time taken is : %lf \n",cpu_time_used);
}
