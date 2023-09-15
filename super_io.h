#ifndef SUPER_IO
#define SUPER_IO
#include "super_io.h"
#include "assert.h"
#include <stdio.h>

// ??

struct FileInfo {
	// input_file 
	FILE* input_file;
	const char* name;
	char* text[200];
	char* buff;
	// n_lines
	size_t n_lines;
	size_t buff_size;
};

// FileInfoCtor(char* file_name)
// FileInfoDtor

void FileInfoDtor(FileInfo* file);
FileInfo FileInfoCtor(const char* file_name);
void ReadFile(FileInfo* file);
void ReadBuff(FileInfo* file);
size_t GetFileSize(FileInfo* file);
#endif
