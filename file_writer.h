/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Filename:	file_writer.h
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Purpose:	Provide functions that writes arrays to a text or binary file.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Author:		Jonathan Burrows
 |	Date:		November 30th 2012
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
#ifndef FILE_WRITER_H
#define FILE_WRITER_H 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Function:	fwrite_array
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Purpose:	Writes the elements of an integer array to a file, seperated by spaces.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	@param:		filename,		Location the contents will be written to.
 |				array,			Array whos elements will be written.
 |				array_len,		Length of the array being written.
 |	@return:	1,				Write was successful.
 |				0,				Write was unsucessful.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
extern int fwrite_array(char* filename, int* array, size_t array_len);

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Function:	fwrite_array_binary
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Purpose:	Writes the contents of a binary array to a binary file.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	@param:		filename,		Location of the file to be read.
 |				array,			Array whos binary elements will be written.
 |				array_len,		Length of the array being written.
 |	@return:	1,				Write was successful.
 |				0,				Write was unsucessful.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
extern int fwrite_array_binary(char* filename, int* array, size_t array_len);

#endif
