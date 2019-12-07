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
}

uint8_t * my_memcopy(uint8_t *src, uint8_t *dst, size_t length){
}

uint8_t * my_memset(uint8_t *src, size_t length, uint8_t value){
}

uint8_t * my_memzero(uint8_t *src, size_t length){
}

uint8_t * my_reverse(uint8_t *src, size_t length){
}

int32_t * reserve_words(size_t length){
}

void free_words(int32_t *src){
}




/* End of File */		/* _memory.c_ */

