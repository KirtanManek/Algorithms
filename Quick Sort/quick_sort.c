#include<stdio.h>
#include<time.h>
//For mac users also include stdlib.h file

void swap(long int* a, long int* b) {
    long int temp = *a;
    *a = *b;
    *b = temp;
}

long int pivot(long int a[], long int start, long int end) {
    long int p = a[start], k = start, l = end + 1;
    do {
        k++;
    } while(a[k] <= p && k < end);

    do {
        l--;
    } while (a[l] > p);

    while(k < l) {
        swap(a[k], a[l]);
        do {
            k++;
        } while (a[k] <= p);
        
        do {
            l--;
        } while (a[l] > p);
    }

    swap(a[start], a[l]);
    return l;
}

void quick_sort(long int a[], long int start, long int end) {
    if(start < end) {
        long int position = pivot(a, start, end);
        quick_sort(a, start, position - 1);
        quick_sort(a, position + 1, end);
    }
}

void main(){
    long int a[100000], *fp, *fout, total, i, j, temp, choice;

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
    quick_sort(a, 0, total - 1);



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
