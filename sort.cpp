
#include <stdio.h>

void Swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}
void PrintList(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%5d", arr[i]);
	}
	printf("\n");
}

int Min(int list[], int s, int e) {

	int min = s;
	for (int i = s + 1; i < e; ++i) {
		if (list[min] > list[i])
			min = i;
	}

	return min;

}

void SelectionSort(int list[], int size) {
	for (int i = 0; i < size - 1; ++i) {
		int min = Min(list, i, size);
		Swap(&list[i], &list[min]);
	}

	PrintList(list, size);

}

void InsertionSort(int list[], int size) {

	for (int i = 1; i < size; ++i) {
		int value = list[i];
		int j;

		for (j = i - 1; j >= 0; --j) {
			if (list[j] > value)
				list[j + 1] = list[j];
			else {
				break;
			}
		}
		list[j + 1] = value;
	}



	PrintList(list, size);

}

int main() {
	//int list[10] = { 80, 20, 70, 50, 60, 90, 40, 30 };
	int list[10] = { 20, 70, 80, 50, 60, 90, 40, 30 };
	int size = 8;

	PrintList(list, size);
	InsertionSort(list, size);

	return 0;
}


//삽입정렬
// 앞에가 정렬되어있으면 그 앞의 요소들은 비교할 필요가 없다는것을 이용
// 앞에서부터 정렬해나감.

//#include <stdio.h>
//
//void Swap(int* a, int* b) {
//	int t = *a;
//	*a = *b;
//	*b = t;
//}
//void PrintList(int arr[], int size) {
//	for (int i = 0; i < size; i++) {
//		printf("%5d", arr[i]);
//	}
//	printf("\n");
//}
//
//int Min(int list[], int s, int e) {
//
//	int min = s;
//	for (int i = s + 1; i < e; ++i) {
//		if (list[min] > list[i])
//			min = i;
//	}
//
//	return min;
//
//}
//
//void SelectionSort(int list[], int size) {
//	for (int i = 0; i < size - 1; ++i) {
//		int min = Min(list, i, size);
//		Swap(&list[i], &list[min]);
//	}
//
//	PrintList(list, size);
//
//}
//
//void InsertionSort(int list[], int size) {
//
//	for (int i = 1; i < size; ++i) {
//		int value = list[i];
//		int j;
//
//		for (j = i - 1; j >= 0; --j) {
//			if (list[j] > value)
//				list[j + 1] = list[j];
//			else {
//				break;
//			}
//		}
//		list[j + 1] = value;
//	}
//	
//	
//
//	PrintList(list, size);
//
//}
//
//int main() {
//	//int list[10] = { 80, 20, 70, 50, 60, 90, 40, 30 };
//	int list[10] = { 20, 70, 80, 50, 60, 90, 40, 30 };
//	int size = 8;
//
//	PrintList(list, size);
//	InsertionSort(list, size);
//
//	return 0;
//}

//------선택정렬
//Min 값을 가진 인덱스를 가장 앞에 있는 인덱스에 넣고 인덱스값을 올려주고 넣고 반복.

//#include <stdio.h>
//
//void Swap(int* a, int* b) {
//	int t = *a;
//	*a = *b;
//	*b = t;
//}
//void PrintList(int arr[], int size) {
//	for (int i = 0; i < size; i++) {
//		printf("%5d", arr[i]);
//	}
//	printf("\n");
//}
//
//int Min(int list[], int s, int e) {
//	
//		int min = s;
//		for (int i = s+1; i < e; ++i) {
//			if (list[min] > list[i])
//				min = i;
//		}
//
//		return min;
//	
//}
//
//void SelectionSort(int list[], int size) {
//	for (int i = 0; i < size-1; ++i) {
//		int min = Min(list, i, size);
//		Swap(&list[i], &list[min]);
//	}
//
//	PrintList(list, size);
//
//}
//
//int main() {
//	int list[10] = { 80, 20, 70, 50, 60, 90, 40, 30 };
//	int size = 8;
//
//	PrintList(list, size);
//	SelectionSort(list, size);
//
//	return 0;
//}


//#include <stdio.h>
//
//void Swap(int* a, int* b) {
//	int t = *a;
//	*a = *b;
//	*b = t;
//}
//void PrintList(int arr[], int size) {
//	for (int i = 0; i < size; i++) {
//		printf("%5d", arr[i]);
//	}
//	printf("\n");
//}
//
//int main() {
//	int list[10] = { 80, 20, 70, 50, 60, 90, 40, 30 };
//	int size = 8;
//
//	PrintList(list, size);
//	Swap(&list[0], &list[1]);
//	PrintList(list, size);
//
//	return 0;
//}

//#include <stdio.h>
//void PrintList(int arr[], int size) {
//	for (int i = 0; i < size; i++) {
//		printf("%5d", arr[i]);
//	}
//}
//int main() {
//	int list[10] = { 80, 20, 70, 50, 60, 90, 40, 30 };
//	int size = 8;
//
//	PrintList(list, size);
//	return 0;
//}