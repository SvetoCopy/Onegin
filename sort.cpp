#include "sort.h"


int ComparatorLR(const void* p1, const void* p2)
{
	char* s1 = *(char**)p1;
	char* s2 = *(char**)p2;

	return strcmp(s1, s2);
}

int ComparatorRL(const void* p1, const void* p2)
{
	char* s1 = *(char**)p1;
	char* s2 = *(char**)p2;
	size_t size_s1 = strlen(s1);
	size_t size_s2 = strlen(s2);
	size_t min_size = 0;

	if (size_s1 > size_s2) min_size = size_s2;
	else min_size = size_s1;
	//ERRRROROROROROROOROR
	int i = size_s1 - 1;
	int j = size_s2 - 1;
	while (i >= 0 && j >= 0) {
		if (s1[i] > s2[j]) return 1;
		if (s1[i] < s2[j]) return -1;
		i--;
		j--;
	}

	if (size_s1 == size_s2) return 0;
	else return size_s1 > size_s2 ? 1 : -1;
}


void Swap(char** a, char** b) {
	char* tmp = *a;
	*a = *b;
	*b = tmp;
}

void QSort(char* data[], int left, int right, int Comparator(const void* p1, const void* p2)) {
	printf("\nQSORT FROM: %d TO: %d\n", left, right);
	if (left >= right) return;

	int mid = Partition(data, left, right, Comparator);
	QSort(data, left, mid - 1, Comparator);
	QSort(data, mid + 1, right, Comparator);

}

int Partition(char* data[], int left, int right, int Comparator(const void* p1, const void* p2)) {
	int mid = left + (rand() % (right - left + 1));
	char* pivot = data[mid];
	int size = 7;
	//int size = right - left + 1;

	while (left < right) {

		DebugPrint(data, left, right, size, mid);
		if (Comparator(&data[left], &data[right]) == 0) left++;

		while (Comparator(&data[left], &pivot) == -1) {
			left++;
			DebugPrint(data, left, right, size, mid);
		}

		while (Comparator(&data[right], &pivot) == 1) {
			right--;
			DebugPrint(data, left, right, size, mid);
		}

		if (left < right) Swap(data + left, data + right);
		DebugPrint(data, left, right, size, mid);
	}
	return right;
}