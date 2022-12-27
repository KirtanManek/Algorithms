#include<stdio.h>
#include<time.h>
#include<unistd.h>
//For mac users also include stdlib.h file

long int a[1000000]; //Declaring the array globally in order to sort bigger values.

//swap function
void swap(long int* a, long int* b) {
    long int temp = *a;
    *a = *b;
    *b = temp;
}

//max-heap function
void heapify(long int arr[], long int N, long int i) {
    // Find largest among root, left child and right child
 
    // Initialize largest as root
    long int largest = i;
 
    // left = 2*i + 1
    long int left = 2 * i + 1;
 
    // right = 2*i + 2
    long int right = 2 * i + 2;
 
    // If left child is larger than root
    if (left < N && arr[left] > arr[largest])
 
        largest = left;
 
    // If right child is larger than largest
    // so far
    if (right < N && arr[right] > arr[largest])
 
        largest = right;
 
    // Swap and continue heapifying if root is not largest
    // If largest is not root
    if (largest != i) {
 
        swap(&arr[i], &arr[largest]);
 
        // Recursively heapify the affected
        // sub-tree
        heapify(arr, N, largest);
    }
}

//Heap Sort function
void heapSort(long int arr[], long int N) {
 	long int i;
    // Build max heap
    for (i = N / 2 - 1; i >= 0; i--) heapify(arr, N, i);
 
    // Heap sort
    for (i = N - 1; i >= 0; i--) {
 
        swap(&arr[0], &arr[i]);
 
        // Heapify root element to get highest element at
        // root again
        heapify(arr, i, 0);
    }
}

//printing sorted algorithm in console
void printArray(long int arr[], long int N) {
	long int i;
    for (i = 0; i < N; i++) printf("%d\n", arr[i]);
    printf("\n");
}


void main(){
	long int total, i, j, temp, choice;
	FILE *fp, *fout;

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
	
	long int N = sizeof(a) / sizeof(a[0]);
	
	//Clock to calculate time taken by algorithm
	clock_t start, end;
	double cpu_time_used;
	start = clock();



	// Algorithm Logic
	heapSort(a, N); // Calling function that will sort elements



	//Calculating the time at the end of algorithm 
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	
	
	// Printing in console
	printf("Sorted array is\n");
    printArray(a, N);
	

	//saving sorted algorithm in "output.txt" file
	fout = fopen("output.txt", "w");
	for(i = 0; i < total; i++) {
		fprintf(fout, "%ld\n", a[i]);
	}
	
	//Printing the calculated time.
	printf("\nThe Time taken by your algorithm to sort elements is : %lf \n",cpu_time_used);
}
