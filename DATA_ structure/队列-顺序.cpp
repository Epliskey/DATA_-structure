#include <iostream>
using namespace std;
#define MAXSIZE 100


//������ֻ������һ�˽��в��룬����һ�˽���ɾ�������Ա�
//��ͷ������ɾ����һ��
//��β����������һ��
//�Ƚ��ȳ�


typedef struct {
	int data[MAXSIZE];
	int front, rear;  // ��ͷָ��Ͷ�βָ��
} SqQueue;  // Sq: sequence ˳��

