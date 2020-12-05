#include <stdio.h>
#include <stdlib.h>
#include <queue>

typedef struct _node {
	int data;
	struct _node* lChild;
	struct _node* rChild;
} Node;


Node* AllocNode(int data) {
	Node* n = (Node*)malloc(sizeof(Node));
	n->data = data;
	n->lChild = NULL;
	n->rChild = NULL;

	return n;
}

void Inorder(Node* root) {
	// 왼쪽 거 다 돌고 
	// 중간 출력
	// 오른쪽 다 돌기

	if (root == NULL) {
		return;
	}

	Inorder(root->lChild);

	printf("%d ", root->data);

	Inorder(root->rChild);
}

void Preorder(Node* root) {
	// 중간 출력
	// 왼쪽 거 다 돌고 
	// 오른쪽 다 돌기

	if (root == NULL) {
		return;
	}

	printf("%d ", root->data);
	Preorder(root->lChild);
	Preorder(root->rChild);
}


void Postorder(Node* root) {
	// 왼쪽 거 다 돌고 
	// 오른쪽 다 돌기
	// 중간 출력

	if (root == NULL) {
		return;
	}

	Postorder(root->lChild);
	Postorder(root->rChild);
	printf("%d ", root->data);
}

void Levelorder(Node* root) {
	//큐를 사용하여 자식노드의 값들을 저장
	if (root == NULL) {
		return;
	}

	std::queue<Node*> q;
	q.push(root);

	while (!q.empty()) {
		Node* front = q.front();
		q.pop();

		printf("%d ", front->data);

		if (front->lChild != NULL)
			q.push(front->lChild);

		if (front->rChild != NULL)
			q.push(front->rChild);
	}
}

Node* AddNode(Node* root, int data) {
	if (root == NULL)
		return AllocNode(data);

	if (data < root->data) {
		root->lChild = AddNode(root->lChild, data);
	}
	else {
		root->rChild = AddNode(root->rChild, data);
	}

	return root;
}

void FreeNode(Node* root) {

	if (root == NULL) {
		return;
	}

	FreeNode(root->lChild);
	FreeNode(root->rChild);
	free(root);
}

Node* SearchNode(Node* root, int data) {
	if (root == NULL) {
		return NULL;
	}

	if(data < root->data) {
		return SearchNode(root->lChild, data);
	}
	else if (data > root->data) {
		return SearchNode(root->rChild, data);
	}
	else {
		return root;
	}
		
}

int main() {
	Node* root = NULL;
	root = AddNode(root, 50);
	root = AddNode(root, 30);
	root = AddNode(root, 70);
	root = AddNode(root, 10);
	root = AddNode(root, 40);
	root = AddNode(root, 60);
	root = AddNode(root, 70);

	Inorder(root);
	printf("inorder\n");

	Preorder(root);
	printf("Preorder\n");

	Postorder(root);
	printf("Preorder\n");

	Levelorder(root);
	printf("Preorder\n");

	Node* p = SearchNode(root, 40);
	if (p != NULL)
		printf("search : %d\n", p->data);
	FreeNode(root);

	return 0;
}


//typedef struct _node {
//	int data;
//	struct _node* lChild;
//	struct _node* rChild;
//} Node;
//
//
//Node* AllocNode(int data) {
//	Node* n = (Node*)malloc(sizeof (Node));
//	n->data = data;
//	n->lChild = NULL;
//	n->rChild = NULL;
//
//	return n;
//}
//
//void Inorder(Node* root) {
//	// 왼쪽 거 다 돌고 
//	// 중간 출력
//	// 오른쪽 다 돌기
//
//	if (root == NULL) {
//		return;
//	}
//
//	Inorder(root->lChild);
//
//	printf("%d ", root->data);
//
//	Inorder(root->rChild);
//}
//
//void Preorder(Node* root) {
//	// 중간 출력
//	// 왼쪽 거 다 돌고 
//	// 오른쪽 다 돌기
//
//	if (root == NULL) {
//		return;
//	}
//
//	printf("%d ", root->data);
//	Preorder(root->lChild);
//	Preorder(root->rChild);
//}
//
//
//void Postorder(Node* root) {
//	// 왼쪽 거 다 돌고 
//	// 오른쪽 다 돌기
//	// 중간 출력
//
//	if (root == NULL) {
//		return;
//	}
//	
//	Postorder(root->lChild);
//	Postorder(root->rChild);
//	printf("%d ", root->data);
//}
//
//void Levelorder(Node* root) {
//	//큐를 사용하여 자식노드의 값들을 저장
//	if (root == NULL) {
//		return;
//	}
//
//	std::queue<Node *> q;
//	q.push(root);
//
//	while (!q.empty()) {
//		Node* front = q.front();
//		q.pop();
//
//		printf("%d ", front->data);
//		
//		if(front->lChild != NULL)
//			q.push(front->lChild);
//
//		if (front->rChild != NULL)
//			q.push(front->rChild);
//	}
//}
//
//Node* AddNode(Node* root, int data) {
//	if (root == NULL)
//		return AllocNode(data);
//
//	if (data < root->data) {
//		root->lChild = AddNode(root->lChild, data);
//	}
//	else {
//		root->rChild = AddNode(root->rChild, data);
//	}
//
//	return root;
//}
//
//int main() {
//	Node* root = NULL;
//	root = AddNode(root, 50);
//	root = AddNode(root, 30);
//	root = AddNode(root, 70);
//	root = AddNode(root, 10);
//	root = AddNode(root, 40);
//	root = AddNode(root, 60);
//	root = AddNode(root, 70);
//
//	Inorder(root);
//	printf("inorder\n");
//
//	Preorder(root);
//	printf("Preorder\n");
//
//	Postorder(root);
//	printf("Preorder\n");
//
//	Levelorder(root);
//	printf("Preorder\n");
//
//
//	return 0;
//}