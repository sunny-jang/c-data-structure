
#include <stdio.h>
#include <stdlib.h>


typedef struct {
	int capacity; // ������ �ִ� ũ��
	int size; // ������ ����
	int* buf; // ���� �迭�� �ּ�
} Set;
// ���� �ʱ�ȭ
int Initialize(Set* s, int cap);

// ���� ���� Ȯ��
int IsMember(const Set* s, int data);

// ���� �߰�
void Add(Set* s, int data);

// ���� ����
void Remove(Set* s, int data);

// ������ ���� ���� �ִ� ������ ����
int Capacity(const Set* s);

// ������ ����
int Size(const Set* s);

// ���� s2�� s1���� ����
void Assgin(Set* s1, const Set* s2);

//���� s1, s2 �� ������ Ȯ��
int Equal(const Set* s1, const Set* s2);

// ���� s2, s3�� �������� s1�� ����
Set* Union(Set* s1, const Set* s2, const Set* s3);

// ���� s2, s3�� �������� s1�� ����
Set* Intersection(Set* s1, const Set* s2, const Set* s3);

//���� s2, s3�� ������ s1�� ����
Set* Diffrence(Set* s1, const Set* s2, const Set* s3);

//���� s�� ��� ���Ҹ� ���
void Print(const Set* s);

// ������ �޸𸮿��� ����
void Terminate(Set* s);
////////////////////////////
int Initialize(Set* s, int cap) {
	s->capacity = cap;
	s->size = 0;
	s->buf = (int*)malloc(sizeof(int) * cap);

	return 0; // ���� -1; ���� 1; �� ���� ��ȯ�Ѵ�
}

void Terminate(Set* s) {
	free(s->buf); // free�� �ؼ� malloc()����
	s->capacity = s->size = 0;
}

void Add(Set* s, int data) {
	/////�̹� data ����?
	if (IsMember(s, data) != -1)
		return;

	if (s->size < s->capacity)
		s->buf[s->size++] = data;
};

void Print(const Set* s) {
	printf("size: %d", s->size);
	printf("   { ");
	for (int i = 0; i < s->size; i++)
	{
		printf("%d", s->buf[i]);
		printf(", ");

	}
	printf(" } ");
	printf("\n");
};

int Capacity(const Set* s) {
	return s->capacity;
};

int IsMember(const Set* s, int data) {
	for (int i = 0; i < s->size; i++)
	{
		if (data == s->buf[i])
			return i;
	}
	return -1; // ��� X
};

void Remove(Set* s, int data) {
	int index;
	if ((index = IsMember(s, data) != 1))
		s->buf[index] = s->buf[--s->size];
};

int Size(const Set* s) {
	return s->size;
};

void Assign(Set* s1, const Set* s2) {
	int max = s1->capacity < s2->size ? s1->capacity : s2->size;
	for (int i = 0; i < s2->size; i++)
	{
		s1->buf[i] = s2->buf[i];
	}
	s1->size = s2->size;
};

int Equal(const Set* s1, const Set* s2) {
	for (int i = 0; i < s1->size; i++)
	{
		int j;
		for (j = 0; j < s2->size; j++)
		{
			if (s1->buf[i] == s2->buf[j])
				break;
		}
		if (j == s2->size)
			return 0;
	}

	return 1;
};

Set* Union(Set* s1, const Set* s2, const Set* s3) {
	Assign(s1, s2);

	for (int i = 0; i < s3->size; i++)
	{
		Add(s1, s3->buf[i]);
	}
	return s1;
};

Set* Intersection(Set* s1, const Set* s2, const Set* s3) {
	s1->size = 0;

	for (int i = 0; i < s2->size; i++)
		for (int j = 0; j < s3->size; j++)
			if (s2->buf[i] == s3->buf[j]) 
				Add(s1, s2->buf[i]);
	return s1;
};


Set* Diffrence(Set* s1, const Set* s2, const Set* s3) {
	s1->size = 0;
	for (int i = 0; i < s2->size; i++)
	{
		int j;
		for (j = 0; j < s3->size; j++)
		{
			if (s2->buf[i] == s3->buf[i])
				break;
		}
		if (j == s3->size)
			Add(s1, s2->buf[i]);
	}
	return s1;
};

int main() {
	Set A;
	Set B;
	Set C;
	Initialize(&A, 10);
	Initialize(&B, 10);
	Initialize(&C, 10);
	Add(&A, 1);
	Add(&A, 3);
	Add(&A, 5);
	Add(&A, 3);

	Add(&B, 1);
	Add(&B, 4);
	Add(&B, 6);


	Diffrence(&C, &A, &B);
	Print(&A);
	Print(&B);
	Print(&C);

	Terminate(&A);
	Terminate(&B);
	return 0;

}





//typedef struct {
//	int capacity; // ������ �ִ� ũ��
//	int size; // ������ ����
//	int* buf; // ���� �迭�� �ּ�
//} Set;
//
//// ���� �ʱ�ȭ
//int Initialize(Set* s, int cap);
//
//// ���� ���� Ȯ��
//int IsMember(const Set* s, int data);
//
//// ���� �߰�
//void Add(Set* s, int data);
//
//// ���� ����
//void Remove(Set* s, int data);
//
//// ������ ���� ���� �ִ� ������ ����
//int Capacity(const Set* s);
//
//// ������ ����
//int Size(const Set* s);
//
//// ���� s2�� s1���� ����
//void Assgin(Set* s1, const Set* s2);
//
////���� s1, s2 �� ������ Ȯ��
//int Equal(const Set* s1, const Set* s2);
//
//// ���� s2, s3�� �������� s1�� ����
//Set* Union(Set* s1, const Set* s2, const Set* s3);
//
//// ���� s2, s3�� �������� s1�� ����
//Set* Intersection(Set* s1, const Set* s2, const Set* s3);
//
////���� s2, s3�� ������ s1�� ����
//Set* Diffrence(Set* s1, const Set* s2, const Set* s3);
//
////���� s�� ��� ���Ҹ� ���
//void Print(const Set* s);
//
//// ������ �޸𸮿��� ����
//void Terminate(Set* s);
//
////////////////////////////////
//
//int Initialize(Set* s, int cap) {
//	s->capacity = cap;
//	s->size = 0;
//	s->buf = (int*)malloc(sizeof(int) * cap);
//
//	return 0; // ���� -1; ���� 1; �� ���� ��ȯ�Ѵ�
//}
//
//void Terminate(Set* s) {
//	free(s->buf); // free�� �ؼ� malloc()����
//	s->capacity = s->size = 0;
//}
//
//
//void Add(Set* s, int data) {
//	/////�̹� data ����?
//	if (IsMember(s, data) != -1)
//		return;
//
//	if (s->size < s->capacity)
//		s->buf[s->size++] = data;
//};
//
//void Print(const Set* s) {
//	printf("size: %d", s->size);
//	printf("   { ");
//	for (int i = 0; i < s->size; i++)
//	{
//		printf("%d", s->buf[i]);
//		printf(", ");
//
//	}
//	printf(" } ");
//	printf("\n");
//};
//
//int Capacity(const Set* s) {
//	return s->capacity;
//};
//
//int IsMember(const Set* s, int data) {
//	for (int i = 0; i < s->size; i++)
//	{
//		if (data == s->buf[i])
//			return i;
//	}
//	return -1; // ��� X
//};
//
//void Remove(Set* s, int data) {
//	int index;
//	if((index =  IsMember(s, data) != 1))
//	s->buf[index] = s->buf[--s->size];
//};
//
//int Size(const Set* s) {
//	return s->size;
//};
//
//void Assgin(Set* s1, const Set* s2) {
//	int max = s1->capacity < s1->size ? s1->capacity : s2->size;
//	for (int i = 0; i < s2->size; i++)
//	{
//		s1->buf[i] = s2->buf[i];
//	}
//	s1->size = s2->size;
//};
//
//int main() {
//	Set A;
//	Initialize(&A, 10);
//	Add(&A, 1);
//	Add(&A, 3);
//	Add(&A, 5);
//	Add(&A, 3);
//
//	Remove(&A, 1);
//	Print(&A);
//	Terminate(&A);
//	return 0;
//
//}



//typedef struct {
//	int capacity; // ������ �ִ� ũ��
//	int size; // ������ ����
//	int* buf; // ���� �迭�� �ּ�
//} Set;
//
//// ���� �ʱ�ȭ
//int Initialize(Set* s, int cap);
//
//// ���� ���� Ȯ��
//int IsMember(const Set* s, int data);
//
//// ���� �߰�
//void Add(Set* s, int data);
//
//// ���� ����
//void Remove(Set*, int data);
//
//// ������ ���� ���� �ִ� ������ ����
//int Capacity(const Set* s);
//
//// ������ ����
//int Size(const Set* s);
//
//// ���� s2�� s1���� ����
//void Assgin(Set* s1, const Set* s2);
//
////���� s1, s2 �� ������ Ȯ��
//int Equal(const Set* s1, const Set* s2);
//
//// ���� s2, s3�� �������� s1�� ����
//Set* Union(Set* s1, const Set* s2, const Set* s3);
//
//// ���� s2, s3�� �������� s1�� ����
//Set* Intersection(Set* s1, const Set* s2, const Set* s3);
//
////���� s2, s3�� ������ s1�� ����
//Set* Diffrence(Set* s1, const Set* s2, const Set* s3);
//
////���� s�� ��� ���Ҹ� ���
//void Print(const Set* s);
//
//// ������ �޸𸮿��� ����
//void Terminate(Set* s);
//
////////////////////////////////
//
//int Initialize(Set* s, int cap) {
//	s->capacity = cap;
//	s->size = 0;
//	s->buf = (int*)malloc(sizeof(int) * cap);
//
//	return 0; // ���� -1; ���� 1; �� ���� ��ȯ�Ѵ�
//}
//
//void Terminate(Set* s) {
//	free(s->buf); // free�� �ؼ� malloc()����
//	s->capacity = s->size = 0;
//}
//
//
//void Add(Set* s, int data) {
//	/////�̹� data ����?
//	if (IsMember(s, data) != -1)
//		return;
//
//	if(s->size < s->capacity)
//		s->buf[s->size++] = data;
//};
//
//void Print(const Set* s) {
//	printf("size: %d", s->size);
//	printf("   { ");
//	for (int i = 0; i < s->size; i++)
//	{
//		printf("%d", s->buf[i]);
//		printf(", ");
//
//	}
//	printf(" } ");
//	printf("\n");
//};
//
//int IsMember(const Set* s, int data) {
//	for (int i = 0; i < s->size; i++)
//	{
//		if (data == s->buf[i])
//			return 1;
//	}
//	return -1; // ��� X
//};
//
//int main() {
//	Set A;
//	Initialize(&A, 10);
//	Add(&A, 1);
//	Add(&A, 3);
//	Add(&A, 5);
//	Add(&A, 3);
//	Print(&A);
//	Terminate(&A);
//	return 0;
//
//}



//typedef struct {
//	int capacity; // ������ �ִ� ũ��
//	int size; // ������ ����
//	int* buf; // ���� �迭�� �ּ�
//} Set;
//
//// ���� �ʱ�ȭ
//int Initialize(Set* s, int cap);
//
//// ���� ���� Ȯ��
//int IsMember(const Set* s, int data);
//
//// ���� �߰�
//void Add(Set* s, int data);
//
//// ���� ����
//void Remove(Set*, int data);
//
//// ������ ���� ���� �ִ� ������ ����
//int Capacity(const Set* s);
//
//// ������ ����
//int Size(const Set* s);
//
//// ���� s2�� s1���� ����
//void Assgin(Set * s1, const Set* s2);
//
////���� s1, s2 �� ������ Ȯ��
//int Equal(const Set* s1, const Set* s2);
//
//// ���� s2, s3�� �������� s1�� ����
//Set* Union(Set* s1, const Set* s2, const Set* s3);
//
//// ���� s2, s3�� �������� s1�� ����
//Set* Intersection(Set* s1, const Set* s2, const Set* s3);
//
////���� s2, s3�� ������ s1�� ����
//Set* Diffrence(Set* s1, const Set* s2, const Set* s3);
//
////���� s�� ��� ���Ҹ� ���
//void Print(const Set* s);
//
//// ������ �޸𸮿��� ����
//void Terminate(Set* s);
//
////////////////////////////////
//
//int Initialize(Set* s, int cap) {
//	s->capacity = cap;
//	s->size = 0;
//	s->buf = (int*)malloc(sizeof(int) * cap);
//
//	return 0; // ���� -1; ���� 1; �� ���� ��ȯ�Ѵ�
//}
//
//void Terminate(Set* s) {
//	free(s->buf); // free�� �ؼ� malloc()����
//	s->capacity = s->size = 0;
//}
//
//int main() {
//	Set A;
//	Initialize(&A, 10);
//	Terminate(&A);
//	return 0;
//
//}