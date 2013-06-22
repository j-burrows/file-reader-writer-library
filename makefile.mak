#makefile
CC = gcc
WARNINGS = -Wall

all: FileReadWrite.dll

FileReadWrite.dll: file_writer.o file_reader.o
	$(CC) -shared -o FileReadWrite.dll file_reader.o file_writer.o -Wl,--out-implib,libmessage.a
	
file_reader.o: file_reader.c file_reader.h
	$(CC) -c -DBUILD_DLL file_reader.c
	
file_writer.o: file_writer.c file_writer.h
	$(CC) -c -DBUILD_DLL file_writer.c
	
clean:
	rm -rf *o FileReadWrite.dll
