#include <iostream>
using namespace std;

#define MAXSIZE 100

typedef struct StackNode {
	int data;
	struct StackNode * next;
} StackNode, * LinkStack;

void InitStack(LinkStack& S) {  // ��ʼ��ջ
	S = NULL;
}

void testStack() {
	LinkStack S;
	InitStack(S);
}

bool Push(LinkStack& S, int x) {  //��ջ
	StackNode* p = new StackNode; //����ָ��
	p->data = x;
	p->next = S;
	S = p;
	return true;
}

bool Pop(LinkStack& S, int& x) {  //��ջ
	if (S == NULL) {
		return false;
	}
	StackNode* p = S;
	x = p->data;
	S = S->next;
	delete p;
	return true;
}

bool GetTop(LinkStack S, int& x) {  //ȡջ��Ԫ��
	if (S == NULL) {
		return false;
	}
	x = S->data;
	return true;
}

