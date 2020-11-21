
#include <stdio.h>

//�� ����
// �Ǻ��� ���� �տ��� ���� ��, �ڿ��� ū ����� ������ �ݺ���
// �ƹ��� ��� �ִ� ���� ���ϴ��� ������ ���ڰ� ������Ƿ� ù �ݺ������� 1��° �ε����� �Ǻ����� 
// �����Ͽ� ����
// i ��°�� �Ǻ����� ū ���ڵ��� ã��
// j ��°�� �Ǻ����� ���� ���ڸ� ã�´�
// i �� ū ���ڸ� ã���� j ���� ã�� ���� ���ڿ� swap �Ѵ�.
// j�� i���� �۾����� j��°�� ù��° �ε���(�Ǻ�)�� ��ȯ
// �׷� �Ǻ����� ���� ���ڵ��� �Ǻ� ����, ū ���ڵ��� ���������� �ٴ´�.
// ��ӹݺ�

void Swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void _Sort(int list[], int left, int right) {
	if (left <= right) {
		int pivot = left;
		int i = left + 1;
		int j = right;

		do {
			while (list[pivot] > list[i])
				++i;
			while (list[pivot] < list[j])
				--j;

			if (i <= j) {
				Swap(&list[i], &list[j]);
				++i;
				--j;
			}
		} while (i <= j);
		Swap(&list[pivot], &
			list[j]);
		_Sort(list, left, j - 1);
		_Sort(list, j+1, right);
	}

}

void Sort(int list[], int size) {
	_Sort(list, 0, size - 1);
}

int main() {
	int list[10] = { 50, 20, 70, 80, 60, 90, 40, 30, 45, 75 };

	Sort(list, 10);

	for (int i = 0; i < 10; i++)
	{
		printf("%5d",list[i]);
	}

}