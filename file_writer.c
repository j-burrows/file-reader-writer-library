/*
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Filename:	file_writer.c
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Purpose:	Provide functions that writes arrays to a text or binary file.
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Author:		Jonathan Burrows
 *	Date:		November 30th 2012
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Dependancy:	stdio.h
 *				stdlib.h
 === === === === === === === === === === === === === === === === === === === === === === ===
 */
#include "file_writer.h"

/*
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Function:	fwrite_array
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Purpose:	Writes the elements of an integer array to a file, seperated by spaces.
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	@param:		filename,		Location the contents will be written to.
 *				array,			Array whos elements will be written.
 *				array_len,		Length of the array being written.
 *	@return:	1,				Write was successful.
 *				0,				Write was unsucessful.
 === === === === === === === === === === === === === === === === === === === === === === ===
 */
int fwrite_array(char* filename, int* array, size_t array_len){
	FILE* out;
	int i;										/*Loop control.*/
	
	out = fopen(filename, "w");
	
	/*	The array is traversed, and every element printed to file, seperated by a space.*/
	for(i=0; i < array_len; i++){
		fprintf(out, "%d ", array[i]);
	}
	
	/*	Checks if an error occured during writing.	*/
	if(ferror(out)){
		fclose(out);
		return 0;								/*Error has occured, return error value.*/
	}
	fclose(out);
	
	return 1;									/*Return successful value.*/
}

/*
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Function:	fwrite_array_binary
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Purpose:	Writes the contents of a binary array to a binary file.
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	@param:		filename,		Location of the file to be read.
 *				array,			Array whos binary elements will be written.
 *				array_len,		Length of the array being written.
 *	@return:	1,				Write was successful.
 *				0,				Write was unsucessful.
 === === === === === === === === === === === === === === === === === === === === === === ===
 */
int fwrite_array_binary(char* filename, int* array, size_t array_len){
	FILE* out;
	int i;										/*Loop control.*/
	
	out = fopen(filename, "w");
	
	/*	The array is traversed, and every element is converted to binary if not already,
	 *	and printed to file.	*/
	for(i=0; i < array_len; i++){
		fprintf(out, "%d ", array[i]&1);
	}
	
	/*	Checks if an error occured during writing.	*/
	if(ferror(out)){
		fclose(out);
		return 0;								/*Error has occured, return error value.*/
	}
	fclose(out);
	
	return 1;									/*Return successful value.*/
}
