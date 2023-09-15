#ifndef SORT_DED
#define SORT_DED
#include "stdlib.h"
#include "stdio.h"

int Comparator(const char* a,const char* b);
void Swap(int* a, int* b);
void Sort(char* data[], int size);
int Partition(int data[], int left, int right, int size);

#endif // !SORT_DED
