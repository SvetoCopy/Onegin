#ifndef SORT_DED
#define SORT_DED
#include "stdlib.h"
#include "stdio.h"
#include <string.h>
#include "super_io.h"
#include <assert.h>

int ComparatorLR(const void* p1, const void* p2);
int ComparatorRL(const void* p1, const void* p2);

void Swap(char** a, char** b);

void QSort(char* data[], int left, int right, int Comparator(const void* p1, const void* p2));
int Partition(char* data[], int left, int right, int Comparator(const void* p1, const void* p2));

#endif // !SORT_DED