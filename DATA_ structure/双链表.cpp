#include <iostream>
using namespace std;
	
//˫����������
typedef struct DNode {
	int data;                        
	struct DNode * prior , * next; //ָ��ǰ�����ͺ�̽��
}DNode, * DLinkList;               //DNodeΪ�����������DLinkListΪ���ָ��������

bool InitDLinkList (DLinkList &L) {
	L = (DNode*)malloc(sizeof(DNode)); //����һ��ͷ���
	if (L == NULL) //�ڴ����ʧ��
		return false;
	L->prior = NULL; //ͷ����priorָ��ͷ���
	L->next = NULL;  //ͷ����nextָ��ͷ���
	return true;
}