#include <stdio.h>

void Swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}
void PrintList(int arr[]) {
	printf("size: %d", arr[0]);
	printf("\n");
	printf(" [");
	for (int i = 1; i <= arr[0]; i++)
		printf(" %2d", arr[i]);


	printf(" ]");
	for (int i = arr[0] + 1; i <= 8; ++i)
	{
		printf(" %2d", arr[i]);
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

void Push_heap(int list[]) {
	++list[0]; // heap의 사이즈 하나 늘려줌
	int size = list[0]; // 힙의 사이즈
	int child = size; // 현재 선택된 놈 인덱스
	int parent = child / 2; // 부모 인덱스

	while (parent > 0) {
		if (list[child] > list[parent]) // 자식이 부모보다 크면 
			Swap(&list[parent], &list[child]); // 값을 바꿔줌
		else {
			break;
		}

		child = parent; // 자식과 부모 인덱스 값 바꿔줌
		parent = child / 2; // 지금 자식의 반절을 다시 부모로 정해줌

	}
}

void Make_heap(int list[], int size) {
	for (int i = 0; i < size; i++)
	{
		Push_heap(list);
	}
}

void Pop_heap(int list[]) {
	int size = --list[0]; // 사이즈를 하나 줄임
	Swap(&list[1], &list[size + 1]);

	int parent = 1; // 1번 인덱스가 빠지면서 마지막 원소값이 1번 인덱스로 들어옴. 자식이랑 비교해 서 자식이 
	// 더 크면 자리를 바꿔줘야 함
	int child = parent * 2; // 자식은 부모 인덱스의 *2 

	while (child <= size) {
		if (child < size && list[child] < list[child + 1]) {
			child = child + 1;
		}

		if (list[child] > list[parent]) {
			Swap(&list[parent], &list[child]);
		}

		parent = child;
		child = parent * 2;
	}
}

void Sort_heap(int list[]) {
	int size = list[0];
	for (size_t i = 0; i <size ; i++)
	{
		Pop_heap(list);
	}
}

int main() {
	int list[10] = { 0 ,70, 45, 35, 15, 20, 85, 75, 55 };
	int size = 10;

	Make_heap(list, 8);
	PrintList(list);

	Sort_heap(list);
	PrintList(list);
	
}




//void Swap(int* a, int* b) {
//	int t = *a;
//	*a = *b;
//	*b = t;
//}
//void PrintList(int arr[]) {
//	printf("size: %d", arr[0]);
//	printf("\n");
//	printf(" [");
//	for (int i = 1; i <= arr[0]; i++)
//		printf(" %2d", arr[i]);
//
//
//	printf(" ]");
//	for (int i = arr[0] + 1; i <= 8; ++i)
//	{
//		printf(" %2d", arr[i]);
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
//void Push_heap(int list[]) {
//	++list[0]; // heap의 사이즈 하나 늘려줌
//	int size = list[0]; // 힙의 사이즈
//	int child = size; // 현재 선택된 놈 인덱스
//	int parent = child / 2; // 부모 인덱스
//
//	while (parent > 0) {
//		if (list[child] > list[parent]) // 자식이 부모보다 크면 
//			Swap(&list[parent], &list[child]); // 값을 바꿔줌
//		else {
//			break;
//		}
//
//		child = parent; // 자식과 부모 인덱스 값 바꿔줌
//		parent = child / 2; // 지금 자식의 반절을 다시 부모로 정해줌
//
//	}
//}
//
//void Make_heap(int list[], int size) {
//	for (int i = 0; i < size; i++)
//	{
//		Push_heap(list);
//	}
//}
//
//void Pop_heap(int list[]) {
//	int size = --list[0]; // 사이즈를 하나 줄임
//	Swap(&list[1], &list[size + 1]);
//
//	int parent = 1; // 1번 인덱스가 빠지면서 마지막 원소값이 1번 인덱스로 들어옴. 자식이랑 비교해 서 자식이 
//	// 더 크면 자리를 바꿔줘야 함
//	int child = parent * 2; // 자식은 부모 인덱스의 *2 
//
//	while (child <= size) {
//		if (child < size && list[child] < list[child + 1]) {
//			child = child + 1;
//		}
//
//		if (list[child] > list[parent]) {
//			Swap(&list[parent], &list[child]);
//		}
//
//		parent = child;
//		child = parent * 2;
//	}
//}
//
//
//int main() {
//	int list[10] = { 0 ,70, 45, 35, 15, 20, 85, 75, 55 };
//	int size = 10;
//	
//	Make_heap(list, 8);
//	PrintList(list);
//	Pop_heap(list);
//	PrintList(list);
//	Pop_heap(list);
//	PrintList(list);
//	Pop_heap(list);
//	PrintList(list);
//	Pop_heap(list);
//	PrintList(list);
//	Pop_heap(list);
//	PrintList(list);
//	Pop_heap(list);
//	PrintList(list);
//	Pop_heap(list);
//	PrintList(list);
//}



//void Swap(int* a, int* b) {
//	int t = *a;
//	*a = *b;
//	*b = t;
//}
//void PrintList(int arr[]) {
//	printf("size: %d", arr[0]);
//	printf("\n");
//	printf(" [");
//	for (int i = 1; i <= arr[0]; i++)
//		printf(" %2d", arr[i]);
//
//
//	printf(" ]");
//	for (int i = arr[0] + 1; i <= 8; ++i)
//	{
//		printf(" %2d", arr[i]);
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
//void Push_heap(int list[]) {
//	++list[0]; // heap의 사이즈 하나 늘려줌
//	int size = list[0]; // 힙의 사이즈
//	int child = size; // 현재 선택된 놈 인덱스
//	int parent = child / 2; // 부모 인덱스
//
//	while (parent > 0) {
//		if (list[child] > list[parent]) // 자식이 부모보다 크면 
//			Swap(&list[parent], &list[child]); // 값을 바꿔줌
//		else {
//			break;
//		}
//
//		child = parent; // 자식과 부모 인덱스 값 바꿔줌
//		parent = child / 2; // 지금 자식의 반절을 다시 부모로 정해줌
//
//	}
//}
//
//int main() {
//	int list[10] = { 0 ,70, 45, 35, 15, 20, 85, 75, 55 };
//	int size = 10;
//
//	PrintList(list);
//	Push_heap(list);
//	PrintList(list);
//	Push_heap(list);
//	PrintList(list);
//	Push_heap(list);
//	PrintList(list);
//	Push_heap(list);
//	PrintList(list);
//	Push_heap(list);
//	PrintList(list);
//	Push_heap(list);
//	PrintList(list);
//	Push_heap(list);
//	PrintList(list);
//	Push_heap(list);
//	PrintList(list);
//}




//void Swap(int* a, int* b) {
//	int t = *a;
//	*a = *b;
//	*b = t;
//}
//void PrintList(int arr[]) {
//	printf("size: %d", arr[0]);
//	printf("\n");
//	printf(" [");
//	for (int i = 1; i <= arr[0]; i++)
//		printf(" %2d", arr[i]);
//
//
//	printf(" ]");
//	for (int i = arr[0] + 1; i <= 8; ++i)
//	{
//		printf(" %2d", arr[i]);
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
//void Push_heap(int list[]) {
//	++list[0]; // heap의 사이즈 하나 늘려줌
//	int size = list[0]; // 힙의 사이즈
//	int child = size; // 현재 선택된 놈 인덱스
//	int parent = child / 2; // 부모 인덱스
//
//	while(parent > 0) {
//		if (list[child] > list[parent]) // 자식이 부모보다 크면 
//			Swap(&list[parent], &list[child]); // 값을 바꿔줌
//		else {
//			break;
//		}
//
//		child = parent; // 자식과 부모 인덱스 값 바꿔줌
//		parent = child / 2; // 지금 자식의 반절을 다시 부모로 정해줌
//
//	}
//}
//
//int main() {
//	int list[10] = { 5 ,70, 45, 35, 15, 20, 85, 75, 21 };
//	int size = 10;
//	
//	PrintList(list);
//	Push_heap(list);
//	PrintList(list);
//	Push_heap(list);
//	PrintList(list);
//	Push_heap(list);
//	PrintList(list);
//}

//void Swap(int* a, int* b) {
//	int t = *a;
//	*a = *b;
//	*b = t;
//}
//void PrintList(int arr[]) {
//	printf("size: %d", arr[0]);
//	printf("\n");
//	printf(" [");
//	for (int i = 1; i <= arr[0]; i++) 
//		printf(" %2d", arr[i]);
//	
//	
//	printf(" ]");
//	for (int i = arr[0] + 1; i <= 8; ++i)
//	{
//		printf(" %2d", arr[i]);
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
//int main() {
//	int list[10] = { 5 ,70, 45, 35, 15, 20, 85, 75, 55};
//	int size = 10;
//	PrintList(list);
//}