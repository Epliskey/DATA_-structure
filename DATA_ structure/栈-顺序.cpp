#include <iostream>
using namespace std;

#define MAXSIZE 100

typedef struct {
	int data[MAXSIZE];
	int top;              //ջ��ָ��
} SqStack;                //Sq:sequence˳��

void InitStack(SqStack & S){  // ��ʼ��ջ
	S.top = -1;
}

void teseStack() {
	SqStack S;
	InitStack(S);
}

bool Push(SqStack& S, int x) {  //��ջ
	if (S.top == MAXSIZE - 1){  //ջ�Ƿ���
		return false;
	}
	S.data[++S.top] = x;        //�ȼӺ���
	return true;
} 

bool Pop(SqStack& S, int& x) {  //��ջ
	if (S.top == -1) {          //ջ�Ƿ��
		return false;
	}
	x = S.data[S.top--];        //���ú��
	return true;
} 

bool GetTop(SqStack S, int& x) {  //ȡջ��Ԫ��
	if (S.top == -1) {            //ջ�Ƿ��
		return false;
	}
	x = S.data[S.top];
	return true;
}

//����ջ������ջ����һ���洢�ռ䣬top1��top2�ֱ�ָ������ջ��ջ��
typedef struct {
	int data[MAXSIZE];
	int top1;
	int top2;
} SqDoubleStack;
