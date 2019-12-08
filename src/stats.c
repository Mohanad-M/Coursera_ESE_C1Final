/*-----------------------------------------------------------------------------
 * [FILENAME]:		stats.c
 * [PROJECT]:		Coursera ESE Week.1 Assignment
 * [CREATED ON]:	Dec 03, 2019.
 * [AUTHOR]:		Eng. Mohanad M. Marzouk
 * [DESCRIPTION]:
 * 	_ main implementation file for week.1 assignment.
 * 	_ the file contains function definitions and main routine to run
 * 	_ the statistical analysis purposed for the project.
 * --------------------------------------------------------------------------*/

/* Includes */
#include <stdio.h>
#include "stats.h"
#include "platform.h"

/* User_defined Functions */
unsigned char find_median(unsigned char *a_array, unsigned char a_size){
	/* local variables */
	unsigned char median = 0;

	/* for arrays with even number of elements */
	if( a_size%2 == 0 ){
		median = (a_array[(a_size-1)/2] + a_array[a_size/2]) / 2;
	}
	else{
		median = a_array[a_size/2];
	}
	return median;
}

unsigned char find_mean(unsigned char *a_array, unsigned char a_size){
	/* local variables */
	unsigned char i, sum = 0;
	unsigned char mean = 0;

	/* summing array elements */
	for( i = 0 ; i < a_size ; i++ ){
		sum += a_array[i];
	}
	mean = sum / a_size;
	return mean;
}

unsigned char find_maximum(unsigned char *a_array, unsigned char a_size){
	/* local variables */
	unsigned char i, maximum = 0;
	
	maximum = a_array[0];
	/* iterating through array elements */
	for( i = 0 ; i < a_size ; i++ ){
		if( a_array[i] > maximum ){
			maximum = a_array[i];
		}
	}
	return maximum;
}

unsigned char find_minimum(unsigned char *a_array, unsigned char a_size){
	/* local variables */
	unsigned char i, minimum = 0;

	minimum = a_array[0];
	/* iterating through array elements */
	for( i = 0 ; i < a_size ; i++ ){
		if ( a_array[i] < minimum ){
			minimum = a_array[i];
		}
	}
	return minimum;
}

void print_statistics(unsigned char *a_array, unsigned char a_size){
	/* local variables */
	unsigned char median = 0, mean = 0;
	unsigned char maximum = 0, minimum = 0;

	/* getting calculated results from functions */
	median = find_median(a_array,SIZE);
	mean = find_mean(a_array,SIZE);
	maximum = find_maximum(a_array,SIZE);
	minimum = find_minimum(a_array,SIZE);

	/* prinitng statistics on screen */
	PRINTF("The Calculated Statistics are:\n");
	PRINTF("***************\n");
	PRINTF("Median Element  = %d\n", median);
	PRINTF("Mean Value      = %d\n", mean);
	PRINTF("Maximum Element = %d\n", maximum);
	PRINTF("Minimum Element = %d\n", minimum);
	PRINTF("****************************************\n\n");
}

void print_array(unsigned char *a_array, unsigned char a_size){
#ifdef VERBOSE
	/* local variables */
	unsigned char i;

	PRINTF("\n************************************************************\n");
	/* iterarting through array elements */
	for( i = 0 ; i < a_size ; i++ ){
		PRINTF("%3d\t", a_array[i]);
		if( (i+1)%8 == 0 ){
			PRINTF("\n");
		}
	}
	PRINTF("************************************************************\n");
#endif
}

void sort_array(unsigned char *a_array, unsigned char a_size){
	/* local variables */
	unsigned char i, j, min_index = 0;

	/*---
	 * Local Function to swap array elements
	 * --*/
	void swap(unsigned char *x_ptr, unsigned char *y_ptr){
		unsigned char temp = 0;
		temp = *x_ptr;
		*x_ptr = *y_ptr;
		*y_ptr = temp;
	}

	/* iterating through array elements */
	for( i = 0 ; i < (a_size-1) ; i++ ){
		min_index = i;
		for( j = i+1 ; j < a_size ; j++ ){
			if( a_array[j] < a_array[min_index] ){
				min_index = j;
			}
		}
		swap(&a_array[min_index], &a_array[i]);
	}
}




/* End of File */			/* _stats.c_ */
