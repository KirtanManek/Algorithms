#include<stdio.h>
#include<time.h>
//for mac users also include "stdlib.h" file
//#include<stdlib.h>

void main() {
	long int *fp, *fout, a[100000], total, i, j, temp, choice;

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

	//sorting algorithm
	for(i = 0; i < total; i++) {
		for(j = 0; j < total - i - 1; j++) {
			if(a[j] > a[j+1]) {
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
	
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
