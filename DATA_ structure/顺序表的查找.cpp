#include <iostream>
using namespace std;
#define InitSize 10 // ˳���ĳ�ʼ����

typedef struct {
    int* data;  // ָʾ��̬���������ָ��
    int MaxSize;
    int length;
} SeqList;

// ��ʼ��˳���
void InitList(SeqList& L) {
    L.data = new int[InitSize]; // ��̬��������
    L.MaxSize = InitSize;
    L.length = 0; // ��ʼ����Ϊ0
}

// ��λ����
int GetElem(const SeqList& L, int i) {
    if (i < 1 || i > L.length) {
        cout << "Error: Index out of bounds!" << endl;
        exit(1); // ���߷���һ������ֵ��ʾ����
    }
    return L.data[i - 1];
}

// ��ֵ����
int LocateElem(const SeqList& L, int e) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == e) {
            return i + 1; // �����±�Ϊi��Ԫ��ֵ����e��������λ��i+1
        }
    }
    return 0; // û���ҵ�Ԫ��
}

int main() {
    SeqList L;
    InitList(L); // ��ʼ��˳���

    // ������ݣ�����ֻ��ʾ����ʵ��Ӧ����Ӧ���и��õ�������䷽ʽ��
    for (int i = 0; i < 5; i++) {
        L.data[i] = i + 1; // �������Ǵ洢1��5
        L.length++; // ���ӳ���
    }

    // ���԰�λ����
    std::cout << "Element at position 3: " << GetElem(L, 3) << std::endl;

    // ���԰�ֵ����
    int position = LocateElem(L, 4);
    if (position != 0) {
        std::cout << "Element 4 found at position: " << position << std::endl;
    }
    else {
        std::cout << "Element 4 not found!" << std::endl;
    }

    // ������Դ
    delete[] L.data;

    return 0;