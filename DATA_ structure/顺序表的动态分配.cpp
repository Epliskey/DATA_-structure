#include <stdlib.h>
#include <iostream>
using namespace std;

#define InitSize 10  //Ĭ�ϵ���󳤶�
typedef struct {
    int* data;     //ָʾ��̬���������ָ��
    int MaxSize;   //˳�����������
    int length;    //˳���ĵ�ǰ����
}SeqList;

void InitList(SeqList& L) {
    //�� malloc ��������һƬ�����Ĵ洢�ռ�
    L.data = (int*)malloc(InitSize * sizeof(int));
    L.length = 0;
    L.MaxSize = InitSize;
}

void IncreaseSize(SeqList& L, int len) { //��̬����˳��������
    int* p = L.data;
    L.data = (int*)malloc((L.MaxSize + len) * sizeof(int));
    for (int i = 0; i < L.length; i++) {
        L.data[i] = p[i];
    }
    L.MaxSize = L.MaxSize + len;
    free(p);
}

void Insert(SeqList& L, int element) {  //���뺯������֤˳������������
    if (L.length >= L.MaxSize) {
        IncreaseSize(L, 5);  // ����5������
    }
    L.data[L.length] = element;
    L.length++;
}

int main() {
    SeqList L;
    InitList(L); //��ʼ��һ��˳���

    int mydata[12] = { 5, 1, 4, 9, 6, 5, 7, 8, 2, 1, 3, 7 };
    for (int i = 0; i < 12; i++) {
        Insert(L, mydata[i]); // �ò��뺯������������
    }

    for (int i = 0; i < L.length; i++) {
        cout << "data[" << i + 1 << "]=" << L.data[i] << endl;
    }

    free(L.data); // �ڽ���ǰ�ͷ��ڴ�
    return 0;