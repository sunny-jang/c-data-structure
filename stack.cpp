#include <stdio.h>
#include <stdlib.h>

//<stack>
// 스텍의 이해 
// 스텍의 구현
// 스텍 구현의 고려사항

/// 서버
struct Stack {
	int* stack;
	int top;
};

void InitStack(Stack* st, int cap) {
	st->stack = (int*)malloc(sizeof(int) * cap);
	st->top = 0;
}

void UninitStack(Stack* st) {
	free(st -> stack);
	st->top = 0;
}

void Push(Stack* st, int data) {
	st->stack[st->top] = data;
	++st->top;
}

int Pop(Stack* st) {
	--st->top;
	return st->stack[st->top];
}
/// 클라이언트
int main() {

	Stack st;
	Stack st2;

	InitStack(&st, 500);
	InitStack(&st2, 300);

	Push(&st, 10);
	Push(&st, 20);
	Push(&st, 30);

	Push(&st, 100);
	Push(&st, 200);
	Push(&st, 300);

	printf("%d\n", Pop(&st));
	printf("%d\n", Pop(&st));
	printf("%d\n", Pop(&st));

	UninitStack(&st);
	UninitStack(&st2);

	return 0;
}


///// 서버
//struct Stack {
//	int stack[10];
//	int top;
//};
//
//void InitStack(Stack *st) {
//	st->top = 0;
//}
//
//void UninitStack(Stack* st) {
//	st->top = 0;
//}
//
//void Push(Stack *st, int data) {
//	st->stack[st->top] = data;
//	++st->top;
//}
//
//int Pop(Stack *st) {
//	--st->top;
//	return st->stack[st->top];
//}
///// 클라이언트
//int main() {
//
//	Stack st;
//	Stack st2;
//
//	InitStack(&st);
//	InitStack(&st2);
//
//	Push(&st, 10);
//	Push(&st, 20);
//	Push(&st, 30);
//
//	Push(&st, 100);
//	Push(&st, 200);
//	Push(&st, 300);
//
//	printf("%d\n", Pop(&st));
//	printf("%d\n", Pop(&st));
//	printf("%d\n", Pop(&st));
//
//	UninitStack(&st);
//	UninitStack(&st2);
//
//	return 0;
//}



///// 서버
//void Push(int stack[], int* top, int data) {
//	stack[*top] = data;
//	++*top;
//}
//
//int Pop(int stack[], int* top) {
//	--*top;
//	return stack[*top];
//}
///// 클라이언트
//int main() {
//
//	int stack[10];
//	int top = 0;
//
//	int stack2[10];
//	int top2 = 0;
//
//	Push(stack, &top, 10);
//	Push(stack, &top, 20);
//	Push(stack, &top, 30);
//
//	Push(stack2, &top2, 100);
//	Push(stack2, &top2, 200);
//
//	
//	printf("%d\n", Pop(stack, &top));
//	printf("%d\n", Pop(stack, &top));
//	printf("%d\n", Pop(stack, &top));
//
//	printf("%d\n", Pop(stack2, &top2));
//	printf("%d\n", Pop(stack2, &top2));
//
//	return 0;
//}