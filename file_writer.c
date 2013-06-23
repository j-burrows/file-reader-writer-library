/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Filename:	file_writer.c
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
#include "file_writer.h"

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Function:	fwrite_array
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
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

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Function:	fwrite_array_binary
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
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
