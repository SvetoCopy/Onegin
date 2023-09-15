#include "sort.h"
#include <assert.h>

void DebugPrint(char* data[], int left, int right, int size, int mid) {
	int flag = 0;
	for (int i = 0; i < (size); i++) {
		if (i == left) {
			printf("<");
		}
		if (i == (right+1)) {
			printf(">");
			flag++;
		}
		
		printf(" %s ", data[i]);
	}
	if (!flag) printf(">");
	printf("left = %d right = %d mid = %d, data[mid] = %s",left,right, mid, data[mid]);
	printf("\n");
}

int Comparator(const void* p1, const void* p2)
{
	char* s1 = *(char**)p1;
	char* s2 = *(char**)p2;

	return strcmp(s1, s2);
}

void Swap(const char** a,const char** b) {
	const char* tmp = *a;
	*a = *b;
	*b = tmp;
}

void PrintData(char* data[], int size) {
	printf("\n");
	for (int i = 0; i < size; i++) {
		printf("%s\n", data[i]);
	}
}

void Sort(char* data[], int size) {
	printf("Before:");
	PrintData(data, size);

	qsort(data, size, sizeof(data[0]), Comparator);

	printf("After:");
	PrintData(data, size);
}

void QSort(char* data[], int left, int right) {
	printf("\nQSORT FROM: %d TO: %d\n", left, right);
	if (left >= right) return;
	if (left - right == 1) {
		if (Comparator(&data[left], &data[right]) == -1) {
			char* tmp = data[left];
			data[left] = data[right];
			data[right] = tmp;
		}
		else if (Comparator(&data[left], &data[right]) == 1) {
			char* tmp = data[left];
			data[left] = data[right];
			data[right] = tmp;
		}
		return;
	}
	int mid = Partition(data, left, right);
	QSort(data, left, mid-1);
	QSort(data, mid+1, right);
	
}

int Partition(char* data[], int left, int right) {
	int mid = left + (rand() % (right - left + 1));
	char* pivot = data[mid];
	int size = 7;

	//printf("%d %d\n", pivot, mid);
	while (left < right) {
		DebugPrint(data, left, right, size, mid);
		while (Comparator(&data[left], &pivot) == -1) {
			left++;
			DebugPrint(data, left, right, size, mid);
		}
		while (Comparator(&data[right], &pivot) == 1) {
			right--;
			DebugPrint(data, left, right, size, mid);

		}
		if (left < right) {
			
			char* tmp = data[left];
			data[left] = data[right];
			data[right] = tmp;

			if (left == mid) {
				mid = right;
			}
			else if (right == mid) mid = left;
			
		}
		DebugPrint(data, left, right, size, mid);
	}
	return mid;
}