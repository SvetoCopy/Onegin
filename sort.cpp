#include "sort.h"

void DebugPrint(int data[], int left, int right, int size, int mid) {
	int flag = 0;
	for (int i = 0; i < (size); i++) {
		if (i == left) {
			printf("<");
		}
		if (i == (right+1)) {
			printf(">");
			flag++;
		}
		
		printf(" %d ", data[i]);
	}
	if (!flag) printf(">");
	printf("left = %d right = %d mid = %d, data[mid] = %d",left,right, mid, data[mid]);
	printf("\n");
}



int Comparator(const void* x , const void* y) {
	char* a = (char*)x;
	char* b = (char*)y;
	while (*a != '\0' && *b != '\0') {
		if (*a < *b) return -1;
		if (*a > *b) return 1;
		a++;
		b++;
	}
	if (*a == '\0' && *b == '\0') return 0;
	else if (*a == '\0') return -1;
	return 1;
}

void Swap(int* a, int* b) {
	int tmp = *a;
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
	qsort(data, size, sizeof(char*), Comparator);
	printf("After:");
	PrintData(data, size);
}

int Partition(int data[], int left, int right, int size) {
	//int mid = left + (rand() % (right - left + 1));
	int mid = 8;
	int pivot = data[mid];
	printf("%d %d\n", pivot, mid);
	while (left < right) {
		DebugPrint(data, left, right, size, mid);
		while (data[left] < pivot) {
			left++;
			DebugPrint(data, left, right, size,mid);
		}
		while (data[right] > pivot) {
			right--;
			DebugPrint(data, left, right, size, mid);

		}
		if (left < right) {
			
			Swap(data+left, data+right);
			if (left == mid) {
				mid = right;
			}
			else if (right == mid) mid = left;
			left++;
			right--;
		}
		DebugPrint(data, left, right, size, mid);
	}
	return mid;
}