#include <stdio.h>
#include <time.h>


typedef struct queueNode
{
	int customerNumber;
	int serviceTime;
	int totalTime;
	struct queueNode *pNext;
} QueueNode;


typedef struct queue
{
	QueueNode *pHead;
	QueueNode *pTail;
} Queue;



QueueNode *makeNode(int num, int t, int tt);
Queue *makeTracker(QueueNode **pFirst, QueueNode **pLast);
void printQueue(QueueNode **pList);
int isEmpty(QueueNode **pList);
QueueNode *enqueue(QueueNode **pList, QueueNode **pB);
void *dequeue(QueueNode **pList);


void print_current(QueueNode **pList, int t);