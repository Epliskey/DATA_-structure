#include <iostream>

typedef struct LNode {            //LNode��㣬���嵥����ڵ�����
    int data;                     //������ÿ���ڵ���һ������Ԫ��
    struct LNode* next;           //ָ��ָ����һ���ڵ�
}LNode, * LinkList;

//struct �ṹ��
//struct LNode��һ���ṹ�����ͣ�������һ������������data��һ��ָ����һ��LNode�ṹ���ָ��next��
//* LinkList��һ��ָ��LNode�ṹ���ָ�����͡������*��ʾ����һ��ָ�����ͣ���LinkList�����ָ�����͵������֡�
//LNode   * L    //����һ��ָ�������һ���ڵ��ָ��
//LinkList  L    //�����湦����ͬ

//��λ���ң����ص�i��Ԫ�أ���ͷ��㣩
LNode* GetElem(LinkList& L, int i) {
    if (i < 0)
        return nullptr;
    LinkList p;   //ָ��pָ��ǰɨ�赽�Ľ��
    int j = 0;  //��ǰpָ����ǵڼ������ 
    p = L;      //Lָ��ͷ���,ͷ����ǵ�0�����(��������)
    while (p != nullptr && j < i - 1) { //ѭ���ҵ��� i-1 �����
        p = p->next;
        j++;
    }
    return p;
}

//��ֵ����,�ҵ������� == e �Ľ��

LNode* LocateElem(LinkList L, ElemType e) {
    LNode* p = L->next;
    //�ӵ�1����㿪ʼ����������Ϊe�Ľ��
    while (p != NULL && p->data != e)
        p = p->next;
    return p;//�ҵ��󷵻ظý��ָ��,���򷵻�NULL
}

//���ĳ���
int Length(LinkList L) {
    int len = 0;//ͳ�Ʊ�
    LNode* p = L;
    while (p->next != NULL) {
        p = p->next;
        len++;
    }
    return len;
}