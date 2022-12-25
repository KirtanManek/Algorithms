#include <stdio.h>
//for mac users include stdlib.h file also
//#include<stdlib.h>

void main(){
	long int i, total;
	FILE *fb, *fw, *fa;
	
	//saving values of 1 to 100000 in 3 different form in different files.
	fb = fopen("best.txt", "w");
	fw = fopen("worst.txt", "w");
	fa = fopen("average.txt", "w");
	
	for(i = 1; i <= 1000000; i++){
		fprintf(fb, "%ld\n", i); //best case
		fprintf(fw, "%ld\n", 1000000 - i + 1); //worst case
		fprintf(fa, "%ld\n", rand()); //average case
	}
}
