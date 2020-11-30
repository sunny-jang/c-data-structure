#include <stdio.h>
#include <algorithm> // c++ �˰��� ������ ��� 

using namespace std; // ���ӽ����̽� std�� ����� ����� algoritm �� ��� ����


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
void heapSort() {
	printf("%d", 1);
}

int main() {
	int list[10] = { 50 ,20, 70, 80, 60, 90, 40, 30, 45, 75 };
	int size = 0;


	for (size_t i = 0; i < 10; i++)
	{
		++size;
		push_heap(list, list + size);
	}
	
	sort_heap(list, list + size);
	PrintList(list, size);
}


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
//void heapSort() {
//	printf("%d", 1);
//}
//
//int main() {
//	int list[10] = { 50 ,20, 70, 80, 60, 90, 40, 30, 45, 75 };
//	int size = 0;
//
//	push_heap(list, list + 1);
//	++size;
//
//	push_heap(list, list + 2);
//	++size;
//
//	push_heap(list, list + 3);
//	++size;
//	PrintList(list, size);
//}



//
//using namespace std; // ���ӽ����̽� std�� ����� ����� algoritm �� ��� ����
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
//void heapSort() {
//	printf("%d", 1);
//}
//
//int main() {
//	int list[10] = { 50 ,20, 70, 80, 60, 90, 40, 30, 45, 75 };
//	int size = 10;
//
//	PrintList(list, size);
//	make_heap(list, list + size);
//	// list���� list+size���� �� ������ ������ 
//	PrintList(list, size);
//	pop_heap(list, list + size);
//	--size;
//	pop_heap(list, list + size);
//	--size;
//	pop_heap(list, list + size);
//	--size;
//	pop_heap(list, list + size);
//	--size;
//	pop_heap(list, list + size);
//	--size;
//	pop_heap(list, list + size);
//	--size;
//	pop_heap(list, list + size);
//	--size;
//	pop_heap(list, list + size);
//	--size;
//	PrintList(list, 10);
//
//}


//#include <stdio.h>
//#include <algorithm> // c++ �˰��� ������ ��� 
//
//using namespace std; // ���ӽ����̽� std�� ����� ����� algoritm �� ��� ����
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
//void heapSort(){
//	printf("%d", 1);
//}
//
//int main() {
//	int list[10] = { 50 ,20, 70, 80, 60, 90, 40, 30, 45, 75 };
//	int size = 10;
//
//	//make_heap(list, list + size);
//	// list���� list+size���� �� ������ ������ 
//	PrintList(list, size);
//	sort_heap(list, list+size);
//	PrintList(list, size);
//	sort_heap(list, list + size);
//	PrintList(list, size);
//	 
//}