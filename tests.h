#ifndef TESTS_DED
#include "sort.h"
#include "super_io.h"
#include <assert.h>
bool isEqualLines(char* txt1, char* txt2);
bool isEqualFiles(FileInfo file1, FileInfo file2);
void TestQSort(const char* test1_name_inp, const char* test1_name_res, size_t num);
void runTests();
#endif