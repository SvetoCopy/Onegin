#include "tests.h"


bool isEqualLines(char* txt1, char* txt2) {
	size_t size1 = strlen(txt1);
	size_t size2 = strlen(txt2);
	if (size1 != size2) return false;
	for (int i = 0; i < size1; ++i) {
		if (txt1[i] != txt2[i]) return false;
	}
	return true;

}

bool isEqualFiles(FileInfo file1, FileInfo file2) {
	if (file1.n_lines != file2.n_lines) return false;
	char** arr1 = file1.text;
	char** arr2 = file2.text;

	for (int i = 0; i < file1.n_lines; ++i) {
		if (isEqualLines(arr1[i], arr2[i]) == false) {
			FileInfoDtor(&file1);
			FileInfoDtor(&file2);
			return false;
		}
	}
	FileInfoDtor(&file1);
	FileInfoDtor(&file2);
	return true;
}

void TestQSort(const char* test_name_inp, const char* test_name_res, size_t num) {
	FileInfo test_inp = FileInfoCtor(test_name_inp);
	QSort(test_inp.text, 0, test_inp.n_lines - 1, ComparatorLR);

	FileInfo test_res = FileInfoCtor(test_name_res);
	PrintData(test_inp.text, test_inp.n_lines);
	PrintData(test_res.text, test_res.n_lines);
	if (isEqualFiles(test_inp, test_res)) printf("Test #%zu PASSED\n", num);
	else printf("Test #%zu FAILED\n", num);
	FileInfoDtor(&test_inp);
	FileInfoDtor(&test_res);
}

void runTests() {
	TestQSort("test1_inp.txt", "test1_res.txt", 1);
	TestQSort("test2_inp.txt", "test2_res.txt", 2);
	TestQSort("test3_inp.txt", "test3_res.txt", 3);
}