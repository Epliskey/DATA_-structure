#include <iostream>
using namespace std;
#define MAXSIZE 100


//队列是只允许在一端进行插入，在另一端进行删除的线性表
//队头：允许删除的一端
//队尾：允许插入的一端
//先进先出


typedef struct {
	int data[MAXSIZE];
	int front, rear;  // 队头指针和队尾指针
} SqQueue;  // Sq: sequence 顺序

