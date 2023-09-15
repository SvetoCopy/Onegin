#include "super_io.h"
#include "assert.h"
#include <sys\stat.h>
#include <stdlib.h>


FileInfo FileInfoCtor(const char* file_name) {
	FileInfo file = {};
	file.name = file_name;
	ReadFile(&file);
	return file;
}

void FileInfoDtor(FileInfo* file) {
	free(file->buff);
	for (size_t i = 0; i < file->n_lines; ++i) {
		file->text[i] = NULL;
	}
	file->buff_size = 0;
	file->n_lines = 0;
	file->buff = NULL;
}

void ReadBuff(FileInfo* file) {
	// sym_count
	// str_count
	size_t i = 0;
	size_t j = 0;

	file->text[j] = file->buff;
	j++;
	while (file->buff[i] != EOF) {
		if (file->buff[i] == '\n') {
			file->text[j] = file->buff + i + 1;
			j++;
			file->buff[i] = '\0';
		}
		i++;
	}
	file->n_lines = j;
}

size_t GetFileSize(FileInfo* file) {
	fseek(file->input_file, 0, SEEK_END);
	size_t file_size = ftell(file->input_file);
	fseek(file->input_file, 0, SEEK_SET);
	return file_size;
}

void ReadFile(FileInfo* file) {
	fopen_s(&file->input_file, file->name, "r");
	file->buff_size = GetFileSize(file);

	file->buff = (char*)calloc(file->buff_size, sizeof(char));

	assert(file->input_file != NULL);
	assert(file->buff != NULL);

	fread(file->buff, sizeof(char), file->buff_size, file->input_file);

	ReadBuff(file);
	//printf("%s %s %s", text[0], text[1], text[2]);
}