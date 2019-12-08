/*-----------------------------------------------------------------------------
 * [FILENAME]:		memory.h
 * [MODULE]:		Memory Manipulation Module.
 * [CREATED ON]:	Dec. 07, 2019.
 * [AUTHOR]:		Mohanad M. Marzouk
 * [DESCRIPTION]:
 * 	_ header file for memory manipulation module
 * 	_ the file contains function prototypes and description for the
 * 	_ memory manipulation module.
 * --------------------------------------------------------------------------*/
#ifndef __MEMORY_H__
#define __MEMORY_H__

/* Includes */
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>

/* Function Prototypes & Description */

/***
 * Functions Defined Previously and provided in the course material.
 * Copyright (C) 2017 by Alex Fosdick.
 * */

/*--
 * [FUNCTION]:		set_value().
 * [DESCRIPTION]:
 * 	_ given a pointer to a char data set, this function will set a provided
 * 	_ index of that data set to the value provided.
 * [ARGUMENTS]:
 * [IN]
 * 	_ char *ptr : Pointer to the data array.
 * 	_ unsigned int index : Index of the pointer array to set value.
 * 	_ char value : New index value.
 * [OUT]
 * 	_ the index value will be assigned to the new value.
 * [RETURN TYPE]:
 * 	_ void.
 * --*/
void set_value(char * ptr, unsigned int index, char value);

/*--
 * [FUNCTION]:		clear_value().
 * [DESCRIPTION]:
 * 	_ given a pointer to a char data set, this will clear the provided
 * 	_ index into that data set to the value zero
 * [ARGUMENTS]:
 * [IN]
 * 	_ char *ptr : Pointer to data array.
 * 	_ unsigned int index : Index of pointer array to set value.
 * [OUT]
 * 	_ the index value will be cleared.
 * [RETURN TYPE]:
 * 	_ void.
 * --*/
void clear_value(char * ptr, unsigned int index);

/*--
 * [FUNCTION]:		get_value().
 * [DESCRIPTION]:
 * 	_ given a pointer to a char data set, this will read the providd
 * 	_ index to that data set and return the value.
 * [ARGUMENTS]:
 * [IN]
 * 	_ char *ptr : Pointer to the data array.
 * 	_ unsigned int index : Index into pointer array to set value.
 * [OUT]
 * 	_ the pointer index value.
 * [RETURN TYPE]:
 * 	_ char.
 * --*/
char get_value(char * ptr, unsigned int index);

/*--
 * [FUNCTION]:		set_all().
 * [DESCRIPTION]:
 * 	_ given a pointer to a char data set. this will set a number of elements
 * 	_ from the provided data array to the given value. The length is
 * 	_ determined by the provided size parameter.
 * [ARGUMENTS]:
 * [IN]
 * 	_ char *ptr : Pointer to data array.
 * 	_ char value : Value to be set to elements.
 * 	_ unsigned int size : Number of elements to set to value.
 * [OUT]
 * 	_ elements will be set to the new value.
 * [RETURN TYPE]:
 * 	_ void.
 * --*/
void set_all(char * ptr, char value, unsigned int size);

/*--
 * [FUNCTION]:		clear_all().
 * [DESCRIPTION]:
 * 	_ given a pointer to a char data set, this will clear a number
 * 	_ of elements given the size provided.
 * [ARGUMENTS]:
 * [IN]
 * 	_ char *ptr : Pointer to data array.
 * 	_ unsigned int size : Number of elements to set to zero.
 * [OUT]
 * 	_ the specified number of elements will be set to zero.
 * [RETURN TYPE]:
 * 	_ void.
 * --*/
void clear_all(char * ptr, unsigned int size);

/***
 * New User Defined functions.
 * */

/*--
 * [FUNCTION]:		my_memmove().
 * [DESCRIPTION]:
 * 	_ given a source pointer and a destination pointer, this function
 * 	_ moves a set of data from source to destination and handles the
 * 	_ overlap between data in source and destination then returns a pointer
 * 	_ to the destination where the data is moved.
 * [ARGUMENTS]:
 * [IN]
 * 	_ uint8_t *src : Pointer to the source location of data.
 * 	_ uint8_t *dst : Pointer to the destination where the data moved.
 * 	_ size_t length : The length of data to be moved.
 * [OUT]
 * 	_ a pointer to the location where data is moved.
 * [RETURN TYPE]:
 * 	_ uint8_t *.
 * --*/
uint8_t * my_memmove(uint8_t *src, uint8_t *dst, size_t length);

/*--
 * [FUNCTION]:		my_memcopy().
 * [DESCRIPTION]:
 * 	_ give a source pointer and a destinantion pointer, this function
 * 	_ copies a set of data from source to the destination without handling
 * 	_ of the overlap between source and destination, then returns a pointer
 * 	_ to the destination where the data is copied.
 * [ARGUMENTS]:
 * [IN]
 * 	_ uint8_t *src : Pointer to the source location of data.
 * 	_ uint8_t *dst : Pointer to the destination where the data copied.
 * 	_ size_t length : The length of data to be copied.
 * [OUT]
 * 	_ a pointer to the location where data is copied.
 * [RETURN TYPE]:
 * 	_ uint8_t *.
 * --*/
uint8_t * my_memcopy(uint8_t *src, uint8_t *dst, size_t length);

/*--
 * [FUNCTION]:		my_memset().
 * [DESCRIPTION]:
 * 	_ given a source pointer and a value, this function set all locations
 * 	_ of the data in the source location to the value given, then returns
 * 	_ a pointer to the source location.
 * [ARGUMENTS]:
 * [IN]
 * 	_ uint8_t *src : Pointer to the source location of data.
 * 	_ size_t length : The length of data in the source location.
 * 	_ uint8_t value : The value to be assigned to data.
 * [OUT]
 * 	_ a pointer to the location of the source data after assignment.
 * [RETURN TYPE]:
 * 	_ uint8_t *.
 * --*/
uint8_t * my_memset(uint8_t *src, size_t length, uint8_t value);

/*--
 * [FUNCTION]:		my_memzero().
 * [DESCRIPTION]:
 * 	_ given a source pointer and length, this function will zero out
 * 	_ all data in the given source location, then returns a pointer to
 * 	_ the source location.
 * [ARGUMENTS]:
 * [IN]
 * 	_ uint8_t *src : Pointer to the source location of data.
 * 	_ size_t length : The length of data in the source location.
 * [OUT]
 * 	_ a pointer to the location of the source data after clearing.
 * [RETURN TYPE]:
 * 	_ uint8_t *.
 * --*/
uint8_t * my_memzero(uint8_t *src, size_t length);

/*--
 * [FUNCTION]:		my_reverse().
 * [DESCRIPTION]:
 * 	_ given a source pointer and length, this function will reverse the
 * 	_ byte order of data in the source location, then return a pointer to
 * 	_ the source location after reversing.
 * [ARGUMENTS]:
 * [IN]
 * 	_ uint8_t *src : Pointer to the source location of data.
 * 	_ size_t length : The length of data in source location.
 * [OUT]
 * 	_ a pointer to source data after reversing the byte order.
 * [RETURN TYPE]:
 * 	_ uint8_t *.
 * --*/
uint8_t * my_reverse(uint8_t *src, size_t length);

/*--
 * [FUNCTION]:		reserve_words().
 * [DESCRIPTION]:
 * 	_ given a number of words, this function will allocate that number of
 * 	_ words in the dynamic data memory, then return a pointer to the
 * 	_ allocated data if successful, or a NULL pointer if unsuccessful.
 * [ARGUMENTS]:
 * [IN]
 * 	_ size_t length : The length of data to be allocated.
 * [OUT]
 * 	_ a pointer to memory location of the allocated data if successful.
 * 	_ a NULL pointer if data allocation was not successful.
 * [RETURN TYPE]:
 * 	_ int32_t *.
 * --*/
int32_t * reserve_words(size_t length);

/*--
 * [FUNCTION]:		free_words().
 * [DESCRIPTION]:
 * 	_ given a source pointer, this function will free the allocated data
 * 	_ in that location.
 * [ARGUMENTS]:
 * [IN]
 * 	_ uint32_t *src : Pointer to dynamic data to be freed.
 * [OUT]
 * 	_ the dynamic data in the given location will be freed.
 * [RETURN TYPE]:
 * 	_ void.
 * --*/
void free_words(uint32_t *src);




#endif /* __MEMORY_H__ */
