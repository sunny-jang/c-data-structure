#include <stdio.h>

//<stack>
// ������ ���� 
// ������ ����
// ���� ������ �������

/// ����
int stack[10];
int top = 0;
void Push(int data) {
	stack[top] = data;
	top++;
}

int Pop() {
	top--;
	return stack[top];
}
/// Ŭ���̾�Ʈ
int main() {

	Push(10);
	Push(20);
	Push(30);

	printf("%d\n", Pop());
	Push(40);
	Push(50);
	printf("%d\n", Pop());
	printf("%d\n", Pop());
	printf("%d\n", Pop());
	printf("%d\n", Pop());

	return 0;
}