
#include <stdio.h>

//퀵 정렬
// 피봇을 정해 앞에는 작은 수, 뒤에는 큰 수들로 정렬을 반복함
// 아무리 가운데 있는 수를 정하더라도 랜덤의 숫자가 골라지므로 첫 반복에서는 1번째 인덱스를 피봇으로 
// 설정하여 돌림
// i 번째는 피봇보다 큰 숫자들을 찾고
// j 번째는 피봇보다 작은 숫자를 찾는다
// i 가 큰 숫자를 찾으면 j 에서 찾은 작은 숫자와 swap 한다.
// j가 i보다 작아지면 j번째와 첫번째 인덱스(피봇)를 교환
// 그럼 피봇보다 작은 숫자들이 피봇 왼쪽, 큰 숫자들은 오른쪽으로 붙는다.
// 계속반복

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