#ifndef SORT_DED
#define SORT_DED
#include "stdlib.h"
#include "stdio.h"
#include <string.h>

int Comparator(const void* p1, const void* p2);
void Swap(const char** a, const char** b);
void QSort(char* data[], int left, int right);
void Sort(char* data[], int size);
int Partition(char* data[], int left, int right);

#endif // !SORT_DED
