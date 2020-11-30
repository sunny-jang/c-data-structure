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
	++list[0]; // heap�� ������ �ϳ� �÷���
	int size = list[0]; // ���� ������
	int child = size; // ���� ���õ� �� �ε���
	int parent = child / 2; // �θ� �ε���

	while (parent > 0) {
		if (list[child] > list[parent]) // �ڽ��� �θ𺸴� ũ�� 
			Swap(&list[parent], &list[child]); // ���� �ٲ���
		else {
			break;
		}

		child = parent; // �ڽİ� �θ� �ε��� �� �ٲ���
		parent = child / 2; // ���� �ڽ��� ������ �ٽ� �θ�� ������

	}
}

void Make_heap(int list[], int size) {
	for (int i = 0; i < size; i++)
	{
		Push_heap(list);
	}
}

void Pop_heap(int list[]) {
	int size = --list[0]; // ����� �ϳ� ����
	Swap(&list[1], &list[size + 1]);

	int parent = 1; // 1�� �ε����� �����鼭 ������ ���Ұ��� 1�� �ε����� ����. �ڽ��̶� ���� �� �ڽ��� 
	// �� ũ�� �ڸ��� �ٲ���� ��
	int child = parent * 2; // �ڽ��� �θ� �ε����� *2 

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
//	++list[0]; // heap�� ������ �ϳ� �÷���
//	int size = list[0]; // ���� ������
//	int child = size; // ���� ���õ� �� �ε���
//	int parent = child / 2; // �θ� �ε���
//
//	while (parent > 0) {
//		if (list[child] > list[parent]) // �ڽ��� �θ𺸴� ũ�� 
//			Swap(&list[parent], &list[child]); // ���� �ٲ���
//		else {
//			break;
//		}
//
//		child = parent; // �ڽİ� �θ� �ε��� �� �ٲ���
//		parent = child / 2; // ���� �ڽ��� ������ �ٽ� �θ�� ������
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
//	int size = --list[0]; // ����� �ϳ� ����
//	Swap(&list[1], &list[size + 1]);
//
//	int parent = 1; // 1�� �ε����� �����鼭 ������ ���Ұ��� 1�� �ε����� ����. �ڽ��̶� ���� �� �ڽ��� 
//	// �� ũ�� �ڸ��� �ٲ���� ��
//	int child = parent * 2; // �ڽ��� �θ� �ε����� *2 
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
//	++list[0]; // heap�� ������ �ϳ� �÷���
//	int size = list[0]; // ���� ������
//	int child = size; // ���� ���õ� �� �ε���
//	int parent = child / 2; // �θ� �ε���
//
//	while (parent > 0) {
//		if (list[child] > list[parent]) // �ڽ��� �θ𺸴� ũ�� 
//			Swap(&list[parent], &list[child]); // ���� �ٲ���
//		else {
//			break;
//		}
//
//		child = parent; // �ڽİ� �θ� �ε��� �� �ٲ���
//		parent = child / 2; // ���� �ڽ��� ������ �ٽ� �θ�� ������
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
//	++list[0]; // heap�� ������ �ϳ� �÷���
//	int size = list[0]; // ���� ������
//	int child = size; // ���� ���õ� �� �ε���
//	int parent = child / 2; // �θ� �ε���
//
//	while(parent > 0) {
//		if (list[child] > list[parent]) // �ڽ��� �θ𺸴� ũ�� 
//			Swap(&list[parent], &list[child]); // ���� �ٲ���
//		else {
//			break;
//		}
//
//		child = parent; // �ڽİ� �θ� �ε��� �� �ٲ���
//		parent = child / 2; // ���� �ڽ��� ������ �ٽ� �θ�� ������
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