#include <iostream>
using namespace std;

#define MaxSize 15  // ����˳������󳤶�

// ����˳���ṹ��
typedef struct {
    int data[MaxSize]; // ��̬����洢˳���Ԫ��
    int length;        // ˳���ǰ����
} SqList;

// ��ʼ��˳���
void InitList(SqList& L) {
    for (int i = 0; i < MaxSize; i++) {
        L.data[i] = 0; // ������Ԫ�س�ʼ��Ϊ0
    }
    L.length = 0; // ˳����ʼ����Ϊ0
}

int main() {
    SqList L; // ����˳������
    InitList(L); // ��ʼ��˳���
    int myData[15] = { 4, 8, 8, 2, 9, 1, 7, 6, 4, 3, 2, 9, 11, 7, 9 }; // ��ʼ������

    // ��������䵽˳�����
    for (int i = 0; i < 15; i++) {
        L.data[i] = myData[i];
        L.length++;  // ͬʱ����˳���ĳ���
    }

    // ��ӡ˳����е�Ԫ��
    for (int i = 0; i < L.length; i++) {
        cout << "data[" << i + 1 << "]=" << L.data[i] << endl;
    }
    return 0;
}