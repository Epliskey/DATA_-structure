#include <iostream>
using namespace std;

//int &e: ���ô���һ�����ͱ��������ڷ��ر�ɾ���ڵ������ֵ��
//LinkList & L: ���ô�������ͷָ�룬�������޸�����
//ͷָ����������λ��

typedef struct LNode {       //LNode��㣬���嵥����ڵ�����
	int data;                //������ÿ���ڵ���һ������Ԫ��
	struct LNode* next;      //ָ��ָ����һ���ڵ�
}LNode, * LinkList;		     //LNodeΪ�ڵ���������LinkListΪ�ṹ��ָ��������

//�ڵ� i ��λ�ò����Ԫ��e (��ͷ���)
bool ListInsert(LinkList& L, int i, int e) {
	if (i < 1)
		return false;
	LNode* p;   //ָ��pָ��ǰɨ�赽�Ľ��
	int j = 0;  //��ǰpָ����ǵڼ������
	p = L;      //Lָ��ͷ���,ͷ����ǵ�0�����(��������)
	while (p != nullptr && j < i - 1) { //ѭ���ҵ��� i-1 �����
		p = p->next;
		j++;
	}
	//return InsertNextNode(p, e);
	if (p == NULL)
		return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL)     //�ڴ����ʧ��
		return false;
	s->data = e;       //�ý��s��������Ԫ��e
	s->next = p->next;
	p->next = s;       //�����s����p֮��
	return true;
}

//������:��p���֮�����Ԫ��e
bool InsertNextNode(LNode* p, int e) {
	if (p == NULL)
		return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL)     //�ڴ����ʧ��
		return false;
	s->data = e;       //�ý��s��������Ԫ��e
	s->next = p->next;
	p->next = s;       //�����s����p֮��
	return true;
}

//��Ϊ����루����ͷ��㣩
//��Ҫ��ͷ���������⴦��
bool ListInsert(LinkList& L, int i, int e) {
	if (i < 1)
		return false;
	if (i == 1) { //�����1�����Ĳ�����������������ͬ
		LNode* s = (LNode*)malloc(sizeof(LNode));
		s->data = e;
		s->next = L;
		L = s;      //ͷָ��ָ���½��
		return true;
	}
	LNode* p;  //ָ��pָ��ǰɨ�赽�Ľ��
	int j = 1; //��ǰpָ����ǵڼ������
	p = L;     //pָ���1�����(ע��:����ͷ���)

	while (p != NULL && j < i - 1) {//ѭ���ҵ��� i-1 �����
		p = p->next;
		j++;
	}
	if (p == NULL)   //iֵ���Ϸ�
		return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;     //����ɹ�
}

//ǰ���������p���֮ǰ����Ԫ��e
bool InsertPriorNode(LNode* p, int e) {
	if (p == NULL)
		return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL)     //�ڴ����ʧ��
		return false;
	s->next = p->next;
	p->next = s;       //�½�� s ���� p ֮��
	s->data = p->data; //��p��Ԫ�ظ��Ƶ�s��
	p->data = e;       //p ��Ԫ�ظ���Ϊ e
	return true;
}

//��Ϊ��ɾ������ͷ��㣩
bool ListDelete(LinkList& L, int i, int& e) {  //ͬʱ����e��ֵ����&e
	if (i < 1)
		return false;
	LNode* p;//ָ��pָ��ǰɨ�赽�Ľ��
	int j = 0;//��ǰpָ����ǵڼ������
	p = L;//Lָ��ͷ���,ͷ����ǵ�0�����(��������)

	while (p != NULL && j < i - 1) { //ѭ���ҵ��� i-1 �����
		p = p->next;
		j++;
	}
	if (p == NULL)//iֵ���Ϸ�
		return false;
	if (p->next == NULL) //��i-1�����֮�������������
		return false;
	LNode* q = p->next;  //��qָ��ɾ�����
	e = q->data;         //��e����Ԫ�ص�ֵ
	p->next = q->next;   //��*q�������С��Ͽ���
	free(q);             //�ͷŽ��Ĵ洢�ռ�
	return true;         //ɾ���ɹ�
}

//ɾ��ָ����� p
bool DeleteNode(LNode* p) {
	if (p == NULL)
		return false;
	LNode* q = p->next;      //��qָ��*p�ĺ�̽��
	p->data = p->next->data; //�ͺ�̽�㽻��������
	p->next = q->next;       //��*q�������С��Ͽ���
	free(q);                 //�ͷź�̽��Ĵ洢�ռ�
	return true;