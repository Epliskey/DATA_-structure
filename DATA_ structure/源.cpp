#include <iostream>  
using namespace std;

#define MAXSIZE 100  

typedef struct {
    int data[MAXSIZE];
    int top;  // ջ��ָ��  
} SqStack;  // Sq: sequence ˳��  

void InitStack(SqStack& S) {
    S.top = -1;  // ��ʼ��ջ��ָ��  
}

bool Push(SqStack& S, int x) {
    if (S.top == MAXSIZE - 1) {
        return false;  // ջ��  
    }
    S.data[++S.top] = x;  // �ȼӺ���  
    return true;
}

bool Pop(SqStack& S, int& x) {
    if (S.top == -1) {
        return false;  // ջ��  
    }
    x = S.data[S.top--];  // ���ú��  
    return true;
}

bool GetTop(SqStack S, int& x) {
    if (S.top == -1) {
        return false;  // ջ��  
    }
    x = S.data[S.top];
    return true;
}

void DisplayMenu() {
    cout << "��ѡ�����:" << endl;
    cout << "1. ��ջ" << endl;
    cout << "2. ��ջ" << endl;
    cout << "3. ��ȡջ��Ԫ��" << endl;
    cout << "4. ��ʾջ��Ԫ��" << endl;
    cout << "5. �˳�" << endl;
}

void DisplayStack(SqStack S) {
    if (S.top == -1) {
        cout << "ջΪ�ա�" << endl;
        return;
    }
    cout << "ջ��Ԫ��: ";
    for (int i = 0; i <= S.top; i++) {
        cout << S.data[i] << " ";
    }
    cout << endl;
}

int main() {
    SqStack S;
    InitStack(S);
    int option, element;

    // Ԥ�Ƚ�һЩ������ջ  
    int sampleData[] = { 10, 20, 30, 40, 50 };
    for (int i = 0; i < 5; i++) {
        Push(S, sampleData[i]);
    }

    while (true) {
        DisplayMenu();
        cin >> option;

        switch (option) {
        case 1: // ��ջ  
            cout << "������Ҫ��ջ��Ԫ��: ";
            cin >> element;
            if (Push(S, element)) {
                cout << element << " ����ջ��" << endl;
            }
            else {
                cout << "ջ����!" << endl;
            }
            break;
        case 2: // ��ջ  
            if (Pop(S, element)) {
                cout << element << " �ѳ�ջ��" << endl;
            }
            else {
                cout << "ջΪ��!" << endl;
            }
            break;
        case 3: // ��ȡջ��Ԫ��  
            if (GetTop(S, element)) {
                cout << "ջ��Ԫ����: " << element << endl;
            }
            else {
                cout << "ջΪ��!" << endl;
            }
            break;
        case 4: // ��ʾջ��Ԫ��  
            DisplayStack(S);
            break;
        case 5: // �˳�  
            cout << "�˳�����..." << endl;
            return 0;
        default:
            cout << "��Чѡ������ԡ�" << endl;
        }
    }
}