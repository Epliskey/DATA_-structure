//��ʼ��һ��������
//ÿ�β���һ������Ԫ��

#include <iostream>

//β�巨
typedef int ElemType;

typedef struct LNode {
    ElemType data;
    struct LNode* next;
}LNode, * LinkList;

//����Ԫ�ص���β
bool ListInsert(LinkList& L, int i, ElemType e) {
    if (i < 1)
        return false;
    LNode* p;
    int j = 0;
    p = L;
    while (p != nullptr && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p == nullptr)
        return false;
    LNode* s = new LNode(); //�����ڴ�
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

LinkList List_Taillnsert(LinkList& L) {  //������������
    int x;                               //��ElemTypeΪ����
    L = (LinkList)malloc(sizeof(LNode)); //����ͷ���
    LNode* s, * r = L;                   //rΪ��βָ��

    cin("%d", &x);                     //�������ֵ
    while (x != 9999) {                  //����9999��ʾ����
        //s = (LNode*)malloc(sizeof(LNode));
        s = new LNode;
        s->data = x;
        r->next = s;
        r = s;                           //rָ���µı�β���
        scanf("%d", &x);

        r->next = NULL;                  //β���ָ���ÿ�
        return L;
    }