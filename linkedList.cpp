#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int data;
	struct _node* link;
} Node;

void FreeNode(Node* head) {// 노드들 메모리를 닫아줌
	for (Node* p = head ; p != NULL;)
	{
		Node* np = p->link; // np라는 변수에 다음 노드의 링크를 넣어놓고
		free(p); // 현 노드를 삭제한다. 메모리 닫음
		p = np;// 위치를 삭제된 노드 다음번의 노드를 가리키게 변경

	}
}

Node* AllocNode(int data) {
	Node* n = (Node*)malloc(sizeof(Node));
	n->data = data;
	n->link = NULL;

	return n;
}

int main() {
	// 메모리의 힙 메모리를 하나 만둘어서 헤드에 넣음
	Node* head = NULL;
	Node* tail = NULL;
	Node* n;
	n = AllocNode(10);
	tail = head = n;

	n = AllocNode(20);
	tail->link = n;
	tail = n;

	n = AllocNode(30);
	tail->link = n;
	tail = n;

	n = AllocNode(40);
	tail->link = n;
	tail = n;

	n = AllocNode(50);
	tail->link = n;
	tail = n;

	Node* p = head;
	p = p->link;
	Node* pp = p;
	p = p->link;
	//p 노드 삭제 -> pp로 이전 노드 저장, np로 다음 노드를 저장해 연결하고 메모리 없앰
	Node* np = p->link;
	pp->link = np;
	free(p);

	for (Node* p = head; p != NULL; p = p->link)
	{
		printf("%d\n", p->data);

	}
	//malloc free
	FreeNode(head);

	return 0;
}


//typedef struct _node {
//	int data;
//	struct _node* link;
//} Node;
//
//void FreeNode(Node* head) {// 노드들 메모리를 닫아줌
//	for (Node* p = head; p != NULL;)
//	{
//		Node* np = p->link; // np라는 변수에 다음 노드의 링크를 넣어놓고
//		free(p); // 현 노드를 삭제한다. 메모리 닫음
//		p = np;// 위치를 삭제된 노드 다음번의 노드를 가리키게 변경
//
//	}
//}
//
//Node* AllocNode(int data) {
//	Node* n = (Node*)malloc(sizeof(Node));
//	n->data = data;
//	n->link = NULL;
//
//	return n;
//}
//
//int main() {
//	// 메모리의 힙 메모리를 하나 만둘어서 헤드에 넣음
//	Node* head = NULL;
//	Node* tail = NULL;
//	Node* n;
//	n = AllocNode(10);
//	tail = head = n;
//
//	n = AllocNode(20);
//	tail->link = n;
//	tail = n;
//
//	n = AllocNode(30);
//	tail->link = n;
//	tail = n;
//
//	n = AllocNode(40);
//	tail->link = n;
//	tail = n;
//
//	n = AllocNode(50);
//	tail->link = n;
//	tail = n;
//	for (Node* p = head; p != NULL; p = p->link)
//	{
//		printf("%d\n", p->data);
//
//	}
//	//malloc free
//	FreeNode(head);
//
//	return 0;
//}



//typedef struct _node {
//	int data;
//	struct _node* link;
//} Node;
//
//void FreeNode(Node* head) {// 노드들 메모리를 닫아줌
//	for (Node* p = head; p != NULL;)
//	{
//		Node* np = p->link; // np라는 변수에 다음 노드의 링크를 넣어놓고
//		free(p); // 현 노드를 삭제한다. 메모리 닫음
//		p = np;// 위치를 삭제된 노드 다음번의 노드를 가리키게 변경
//
//	}
//}
//
//int main() {
//	// 메모리의 힙 메모리를 하나 만둘어서 헤드에 넣음
//	Node* head = NULL;
//	Node* tail = NULL;
//	Node* n;
//	n = (Node*)malloc(sizeof(Node));
//	n->data = 10;
//	n->link = NULL;
//	tail = head = n;
//
//	n = (Node*)malloc(sizeof(Node));
//	n->data = 20;
//	n->link = NULL;
//	tail->link = n;
//	tail = n;
//
//	n = (Node*)malloc(sizeof(Node));
//	n->data = 30;
//	n->link = NULL;
//	tail->link = n;
//	tail = n;
//	for (Node* p = head; p != NULL; p = p->link)
//	{
//		printf("%d\n", p->data);
//
//	}
//	//malloc free
//	FreeNode(head);
//
//	return 0;
//}


//typedef struct _node {
//	int data;
//	struct _node* link;
//} Node;
//
//void FreeNode(Node* head) {// 노드들 메모리를 닫아줌
//	for (Node* p = head; p != NULL;)
//	{
//		Node* np = p->link; // np라는 변수에 다음 노드의 링크를 넣어놓고
//		free(p); // 현 노드를 삭제한다. 메모리 닫음
//		p = np;// 위치를 삭제된 노드 다음번의 노드를 가리키게 변경
//
//	}
//}
//
//int main() {
//	// 메모리의 힙 메모리를 하나 만둘어서 헤드에 넣음
//	Node* head = NULL;
//	Node* n;
//	n = (Node*)malloc(sizeof(Node));
//	n->data = 10;
//	n->link = NULL;
//	head = n;
//
//	n = (Node*)malloc(sizeof(Node));
//	n->data = 20;
//	n->link = NULL;
//	head->link = n;
//
//	n = (Node*)malloc(sizeof(Node));
//	n->data = 30;
//	n->link = NULL;
//	head->link->link = n;
//
//	for (Node* p = head; p != NULL; p = p->link)
//	{
//		printf("%d\n", p->data);
//
//	}
//	//malloc free
//	FreeNode(head);
//
//	return 0;
//}



//typedef struct _node {
//	int data;
//	struct _node* link;
//} Node;
//
//void FreeNode(Node* head) {// 노드들 메모리를 닫아줌
//	for (Node* p = head; p != NULL;)
//	{
//		Node* np = p->link; // np라는 변수에 다음 노드의 링크를 넣어놓고
//		free(p); // 현 노드를 삭제한다. 메모리 닫음
//		p = np;// 위치를 삭제된 노드 다음번의 노드를 가리키게 변경
//
//	}
//}
//
//int main() {
//	// 메모리의 힙 메모리를 하나 만둘어서 헤드에 넣음
//	Node* head = (Node*)malloc(sizeof(Node));
//
//	head->data = 10;
//	head->link = NULL;
//
//
//	head->link = (Node*)malloc(sizeof(Node));
//	head->link->data = 20;
//	head->link->link = NULL;
//
//	head->link->link = (Node*)malloc(sizeof(Node));
//	head->link->link->data = 30;
//	head->link->link->link = NULL;
//	
//	for (Node* p = head; p != NULL ; p = p->link)
//	{
//		printf("%d\n", p->data);
//
//	}
//	//malloc free
//	FreeNode(head);
//
//	return 0;
//}


//typedef struct _node {
//	int data;
//	struct _node* link;
//} Node;
//
//struct _node node;
//
//int main() {
//	// 메모리의 힙 메모리를 하나 만둘어서 헤드에 넣음
//	Node* head = (Node*)malloc(sizeof(Node));
//
//	head->data = 10;
//	head->link = NULL;
//
//
//	head -> link = (Node*)malloc(sizeof(Node));
//	head->link->data = 20;
//	head->link->link = NULL;
//
//	head->link->link = (Node*)malloc(sizeof(Node));
//	head->link->link->data = 30;
//	head->link->link->link = NULL;
//	return 0;
//}


//typedef struct _node {
//	int data;
//	struct _node* link;
//} Node;
//
//struct _node node;
//
//int main() {
//	// 노드세개 만듬
//	Node n1 = { 10, NULL };
//	Node n2 = { 20, NULL };
//	Node n3 = { 30, NULL };
//	Node* head = NULL;
//	Node* p = NULL;
//
//
//	head = &n1; // 헤드에 첫 노드를 넣으면
//	p = head;// 헤드랑 똑같은 주소를 가지는 p라는 놈을 만든다.
//
//	n1.link = &n2;
//	n2.link = &n3;
//
//	// p를 값을 하나씩 옮겨가며 담으면
//	// 이렇게 같은 코드로 모든 데이터를 조회할 수 있다.
//	for (Node* p = head; p != NULL; p = p->link) 
//	{// p는 여기서만 쓰고 말 변수라 for문안에 넣어주고 안에서
//		//전진코드를 작성해줌
//		printf("%d\n", p->data);
//	}
//
//	return 0;
//}


//typedef struct _node {
//	int data;
//	struct _node* link;
//} Node;
//
//struct _node node;
//
//int main() {
//	Node n1 = { 10, NULL };
//	Node n2 = { 20, NULL };
//	Node n3 = { 30, NULL };
//	Node* head = NULL;
//	Node* p = NULL;
//
//
//	head = &n1; // 헤드에 첫 노드를 넣으면
//	p = head;// 헤드랑 똑같은 주소를 가지는 p라는 놈을 만든다.
//
//	n1.link = &n2;
//	n2.link = &n3;
//
//	// p를 값을 하나씩 옮겨가며 담으면
//	// 이렇게 같은 코드로 모든 데이터를 조회할 수 있다.
//	printf("%d\n", p->data);
//	p = p->link; // 전진코드
//	printf("%d\n", p->data);
//	p = p->link;
//	printf("%d\n", p->data);
//
//	return 0;
//}





//// 이렇게 하면 struct _node 라고 안쓰고 node라고 쓸 수 있음 
////방법2
//typedef struct _node {
//	int data;
//	struct _node* link;
//} Node;
//
//struct _node node;
//
//int main() {
//	Node n1 = { 10, NULL };
//	Node n2 = { 20, NULL };
//	Node n3 = { 30, NULL };
//	Node* head = NULL;
//
//	head = &n1;
//
//	n1.link = &n2;
//	n2.link = &n3;
//
//	printf("%d\n", head->data);
//	printf("%d\n", head->link->data);
//	printf("%d\n", head->link->link->data);
//
//	return 0;
//}



//// 이렇게 하면 struct _node 라고 안쓰고 node라고 쓸 수 있음 
////방법2
//typedef struct _node {
//	int data;
//	struct _node* link;
//} Node;
//
//struct _node node;
//
//int main() {
//	Node n1 = { 10, NULL };
//	Node n2 = { 20, NULL };
//	Node n3 = { 30, NULL };
//
//	n1.link = &n2;
//	n2.link = &n3;
//
//	printf("%d\n", n1.data);
//	printf("%d\n", n2.data);
//	printf("%d\n", n3.data);
//
//	return 0;
//}


//
//struct _node {
//	int data;
//	struct _node* link;
//};
//// 이렇게 하면 struct _node 라고 안쓰고 node라고 쓸 수 있음 
//typedef struct _node node;
//
//int main() {
//	node n1 = { 10, NULL };
//
//	printf("%d\n", n1.data);
//	return 0;
//}




//struct _node {
//	int data;
//	struct _node* link;
//};
// 이렇게 하면 struct _node 라고 안쓰고 node라고 쓸 수 있음 
//typedef struct _node node;
//
//int main() {
//	node n1 = { 10, NULL};
//
//	printf("%d\n", n1.data);
//	return 0;
//} 


