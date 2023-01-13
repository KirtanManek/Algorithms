#include<stdio.h>
#include<time.h>
//For mac users also include stdlib.h file
long int a[1000000];

// Binary search function that will return index of element
long int binary_search(long int a[], long int x) {
	return binary_reccursion(a, 0, sizeof(a) - 1, x);
}

long int binary_reccursion(long int a[], long int start, long int end, long int x) {
	if(end >= start) {
		long int mid = start + (end - start) / 2;
		if(a[mid] == x) return mid;
		if(a[mid] > x) return binary_reccursion(a, mid + 1, end, x);
	}
	return -1;
}


void main(){
	long int *fp, *fout, total, i, j, temp, choice;

	//opening file containing sorted elements from 1 to 1,000,000
	fp = fopen("best.txt", "r");

	//select how many elements you want sort from file
	printf("\nHow many elements you want to search in from top? :: ");
	scanf("%ld", &total);

	//saving the values from file to array "a"
	for(i = 0; i < total; i++) {
		fscanf(fp, "%ld", &a[i]);
	}
	
	//Clock to calculate time taken by algorithm
	clock_t start, end;
	double cpu_time_used;
	start = clock();



	// Algorithm Logic



	//Calculating the time at the end of algorithm 
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

	//printing sorted algorithm in console
	for(i = 0; i < total; i++) {
		printf("%ld\n",a[i]);
	}

	//saving sorted algorithm in "output.txt" file
	fout = fopen("output.txt", "w");
	for(i = 0; i < total; i++) {
		fprintf(fout, "%ld\n", a[i]);
	}
	
	//Printing the calculated time.
	printf("\nThe Time taken by your algorithm to sort elements is : %lf \n",cpu_time_used);
}
