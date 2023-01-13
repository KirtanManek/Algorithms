#include<stdio.h>
#include<time.h>
//For mac users also include stdlib.h file

long int a[1000000], t[1000000];

void merge_sort(long int low, long int mid, long int high) {
	long int i, j, k;
	i = low;
	j = mid + 1;
	k = low;
	
	while(i <= mid && j <= high) {
		if(a[i] >= a[j]) {
			t[k++] = a[j++];
		}
		else {
			t[k++] = a[i++];
		}
	}
	
	while(i <= mid) {
		t[k++] = a[i++];
	}
	
	while(j <= high) {
		t[k++] = a[j++];
	}
	
	for(i = low; i <= high; i++) {
		a[i] = t[i];
	}
}

void merge_sort_div(long int low, long int high) {
	long int mid;
	if(low != high) {
		mid = ((low + high) / 2);
		merge_sort_div(low, mid);
		merge_sort_div(mid + 1, high);
		merge_sort(low, mid, high);
	}
}

void main(){
	long int *fp, *fout, total, i, j, temp, choice;

	//in which case you want to sort
	printf("Enter your choice : \n1.Best case\n2.Worst case\n3.Average case\nChoice : ");
	scanf("%ld",&choice);
	printf("\n");

	//reading the specific file as per user's choice
	switch(choice) {
		case 1:
			fp = fopen("best.txt", "r");
			break;
		case 2:
			fp = fopen("worst.txt", "r");
			break;
		case 3:
			fp = fopen("average.txt", "r");
			break;
		default :
			printf("Invalid choice");
			exit(0);
	}

	//select how many elements you want sort from file
	printf("\nHow many elements you want to sort from top? :: ");
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
	merge_sort_div(0, total - 1);



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
