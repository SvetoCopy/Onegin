#include "super_io.h"
#include "assert.h"
#include <sys\stat.h>
#include <stdlib.h>

void ReadBuff(char* buff, char* text[]) {
	size_t i = 0;
	size_t j = 0;

	text[j] = buff;
	j++;
	while (buff[i] != EOF) {
		if (buff[i] == '\n') {
			text[j] = buff + i + 1;
			j++;
			buff[i] = '\0';
		}
		i++;
	}
}

void ReadFile(const char* file_name, char* text[]) {
	FILE* f = NULL;
	fopen_s(&f, file_name, "r");

	struct stat stats;
	stat(file_name, &stats);

	char* buff = (char*)calloc(stats.st_size, sizeof(char));

	assert(f != NULL);
	assert(buff != NULL);

	fread(buff, sizeof(char), stats.st_size, f);

	ReadBuff(buff, text);
	//printf("%s %s %s", text[0], text[1], text[2]);
}