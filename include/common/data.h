/*-----------------------------------------------------------------------------
 * [FILENAME]:		data.h
 * [MODULE]:		Data Manipulation Module.
 * [CREATED ON]:	Dec. 07, 2019.
 * [AUTHOR]:		Mohanad M. Marzouk
 * [DESCRIPTION]:
 * 	_ main header file for Data Manipulation module.
 * 	_ the file contains functions to manipulate the form of given data
 * 	_ and return the new data after manipulation.
 * --------------------------------------------------------------------------*/
#ifndef _DATA_H_
#define _DATA_H_

/* Includes */
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>

/* Function Prototypes & Description */

/*--
 * [FUNCTION]:		my_itoa().
 * [DESCRIPTION]:
 * 	_ given an integer number and conversion base, this function will
 * 	_ convert the given number into it's corresponding ASCII value, then
 * 	_ return the length of the converted ASCII string.
 * 	_ NOTE: this function can handle signed data.
 * [ARGUMENTS]:
 * [IN]
 * 	_ int32_t data : The integer number to be converted.
 * 	_ uint8_t *ptr : Pointer to the converted character string.
 * 	_ uint32_t base : Desired Conversion base ( 2 -> 16 ).
 * [OUT]
 * 	_ length of the converted ASCII string.
 * [RETURN TYPE]:
 * 	_ uint8_t.
 * --*/
uint8_t my_itoa(int32_t data, uint8_t *ptr, uint32_t base);

/*--
 * [FUNCTION]:		my_atoi().
 * [DESCRIPTION]:
 * 	_ given a pointer to an ASCII character set, this function will
 * 	_ convert the string into an integer type, then return the converted
 * 	_ integer value.
 * 	_ NOTE: this function can handle signed data.
 * [ARGUMENTS]:
 * [IN]
 * 	_ uint8_t *ptr : Pointer to the string to be converted.
 * 	_ uint8_t digits : Number of digits of the character set.
 *	_ uint32_t base : Desired conversion base ( 2 -> 16 ).
 * [OUT]
 * 	_ the converted 32-bit signed integer.
 * [RETURN TYPE]:
 * 	_ int32_t.
 * --*/
int32_t my_atoi(uint8_t *ptr, uint8_t digits, uint32_t base);




#endif		/* __DATA_H__ */
