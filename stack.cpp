#include <stdio.h>

//<stack>
// 스텍의 이해 
// 스텍의 구현
// 스텍 구현의 고려사항

/// 서버
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
/// 클라이언트
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