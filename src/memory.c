/*-----------------------------------------------------------------------------
 * [FILENAME]:		memory.c
 * [MODULE]:		Memory Manipulation Module.
 * [CREATED ON]:	Dec. 07, 2019.
 * [AUTHOR]:		Mohanad M. Marzouk
 * [DESCRIPTION]:
 * 	_ memory implementation file for memory manipulation module
 * 	_ the file contains functions that can manipulate memory regions
 * 	_ by moving or copying pieces of data between memory addresses and
 * 	_ other procedures done on data memory.
 * --------------------------------------------------------------------------*/

/* Includes */
#include "memory.h"

/* Function Definitions */

/***
 * Functions Defined Previously and provided in the course material.
 * Copyright (C) 2017 by Alex Fosdick.
 * */
void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

/***
 * New User Defined functions.
 * */

uint8_t * my_memmove(uint8_t *src, uint8_t *dst, size_t length){
	/* local variables */
	int i;

	uint8_t *temp = (uint8_t *)malloc(length * sizeof(uint8_t));
	for( i = 0 ; i < length ; i++ ){
		*(temp+i) = *(src+i);
	}
	for( i = 0 ; i < length ; i++ ){
		*(dst+i) = *(temp+i);
	}
	free(temp);
	return dst;
}

uint8_t * my_memcopy(uint8_t *src, uint8_t *dst, size_t length){
	/* local variables */
	uint8_t i;

	uint8_t *temp = (uint8_t *)malloc(length * sizeof(uint8_t));
	for( i = 0 ; i < length ; i++ ){
		*(temp+i) = *(src+i);
	}
	for( i = 0 ; i < length ; i++ ){
		*(dst+i) = *(temp+i);
	}
	free(temp);
	return dst;
}

uint8_t * my_memset(uint8_t *src, size_t length, uint8_t value){
	/* local variables */
	int i;

	for( i = 0 ; i < length ; i++ ){
		*(src+i) = value;
	}
	return src;
}

uint8_t * my_memzero(uint8_t *src, size_t length){
	/* local variables */
	int i;

	for( i = 0 ; i < length ; i++ ){
		*(src+i) = 0;
	}
	return src;
}

uint8_t * my_reverse(uint8_t *src, size_t length){
	/* local variables */
	int i;
	uint8_t temp;

	for( i = 0 ; i < (length/2) ; i++ ){
		temp = *(src+i);
		*(src+i) = *(src+length-1-i);
		*(src+length-1-i) = temp;
	}
	return src;
}

int32_t * reserve_words(size_t length){
	int32_t *src = (int32_t *)malloc(length * sizeof(int32_t));
	return src;
}

void free_words(uint32_t *src){
	free(src);
}




/* End of File */		/* _memory.c_ */
