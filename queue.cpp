#include <stdio.h>;
#include <stdlib.h>;

////서버


typedef struct q_ {
	int *queue;
	int front, rear;
	int capacity;
} Queue;

void InitQueue(Queue* q, int cap) {
	q->queue = (int*)malloc(sizeof(int) * cap);
	q->rear = q->front = 0;
	q->capacity = cap;
}

void UnInitQueue(Queue* q) {
	free(q->queue);
	q->rear = q->front = q->capacity = 0;
}

void Push(Queue* q, int data) {
	if ((q->rear + 1)%q->capacity == q->front)
		return;
	
	q->rear = (q->rear + 1) % q->capacity;
	q->queue[q->rear] = data;
}

int Pop(Queue* q) {
	if (q->front == q->rear)
		return 0xffffff;
	q->front = (q->front + 1) % q->capacity;
	return q->queue[q->front];
}

///클리이언트
int main() {

	Queue q1;
	Queue q2;
	InitQueue(&q1, 5);

	Push(&q1, 10);
	Push(&q1, 20);
	Push(&q1, 30);


	printf("%d\n", Pop(&q1));
	printf("%d\n", Pop(&q1));
	printf("%d\n", Pop(&q1));

	UnInitQueue(&q1);
	InitQueue(&q2, 100);

	Push(&q2, 10);
	Push(&q2, 20);
	Push(&q2, 30);


	printf("%d\n", Pop(&q2));
	printf("%d\n", Pop(&q2));
	printf("%d\n", Pop(&q2));

	UnInitQueue(&q2);


	return 0;

}



//////서버
//void Push(int data) {
//
//}
//
//int Pop() {
//	return 0;
//}
//
/////클리이언트
//int main() {
//	return 0;
//
//	Push(10);
//	Push(20);
//	Push(30);
//
//	Pop();
//	Pop();
//	Pop();
//}