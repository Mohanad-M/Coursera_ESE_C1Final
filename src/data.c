/*-----------------------------------------------------------------------------
 * [FILENAME]:		data.c
 * [MODULE]:		Data Manipulation Module.
 * [CREATED ON]:	Dec. 07, 2019.
 * [AUTHOR]:		Mohanad M. Marzouk
 * [DESCRIPTION]:
 * 	_ main implementation file for Data Manipulation module.
 *      _ the file contains some basic data manipulation functions to be used
 *      _ in the project.
 * --------------------------------------------------------------------------*/

/* Includes */
#include "data.h"

/* Function Definitions */

uint8_t my_itoa(int32_t data, uint8_t *ptr, uint32_t base){
	/* local variables */
	uint8_t i = 0, j, rem, is_negative = 0;
	
	/* checking for negative values */
	if( data < 0 ){
		is_negative = 1;
		data *= (-1);
	}
	
	/* iterating through number digits */
	do{
		rem = data % base;
		data = data / base;
		if (rem > 9){
			*(ptr+i) = rem + 65 - 10;
		}
		else{
			*(ptr+i) = rem + 48 ;
		}
		i++;
	}while( data != 0 );

	/* reversing string */
	for( j = 0 ; j < (i/2) ; j++ ){
		*(ptr+i) = *(ptr+j);
		*(ptr+j) = *(ptr-j+i-1);
		*(ptr-j+i-1) = *(ptr+i);
	}
	/* adding terminating NULL character to the end of string */
	*(ptr+i) = '\0';

	/* handling negative values */
	if(is_negative){
		int k = i;
		for( ; k >= 0 ; k-- ){
			*(ptr+k+1) = *(ptr+k);
		}
		i++;
		*ptr = 45;
	}

	/* returning number of digits */
	return i+1;
}


int32_t my_atoi(uint8_t *ptr, uint8_t digits, uint32_t base){
	/* local variables */
	uint8_t is_negative = 0, i = 0, j;
	int32_t number = 0;
	uint32_t mux = 1;

	/* decrementing digits to ignore the terminating NULL character '\0' */
	digits--;

	/* checking for -ve sign */
	if( *ptr == 45 ){
		is_negative = 1;
		i = 1;
		digits--;
	}

	/* assigning multiplier value to add the numbers in right place */
	for( j = 0 ; j < (digits-1) ; j++ ){
		mux *= base;
	}

	/* assigning index to the 1st number after sign */
	ptr = ptr + i;
	/* iterating theough string characters until the NULL character */
	while( *ptr != '\0' ){
		/* if the character is a number ASCII ( 48 -> 57 ) */
		if( *ptr < 58 ){
			number += (*ptr - 48) * mux;
		}
		else{
			number += (*ptr - 55) * mux;
		}
		ptr++;
		/* dividing mux/base to get the next index */
		mux /= base;
	}

	/* handling negative numbers */
	if( is_negative ){
		number *= -1;
	}

	return number;
}




/* End of File */		/* _data.c_ */
