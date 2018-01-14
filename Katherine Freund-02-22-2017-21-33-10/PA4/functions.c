#include "Header.h"

QueueNode *makeNode(int num, int t, int tt)
{
	QueueNode *pTemp;

	QueueNode *pNew = (QueueNode *)malloc(sizeof(QueueNode));
	pNew->customerNumber = num;
	pNew->serviceTime = t;
	pNew->totalTime = tt;

	return pNew;
}


Queue *makeTracker( QueueNode **pFirst, QueueNode **pLast)
{
	Queue *pTemp;

	Queue *pNew = (Queue *)malloc(sizeof(Queue));
	pNew->pHead = pFirst;
	pNew->pTail = pLast;
	return pNew;
}


void printQueue(QueueNode **pList) //maybe adjust this to print out both lists?
{
	QueueNode *pTemp;
	pTemp = pList;

	while (pTemp != NULL)
	{
		printf(" O    Customer Number: %d\n", pTemp->customerNumber);
		printf("/|\\   Service Time: %d\n", pTemp->serviceTime);
		printf("/ \\   Total Time: %d\n\n\n", pTemp->totalTime);
		pTemp = pTemp->pNext;
	}
}



int isEmpty(QueueNode **pList)
{
	if (pList == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}



QueueNode *enqueue(QueueNode **pList, QueueNode **pB)
{
	QueueNode *pPrev;
	pPrev = pB;
	pPrev->pNext = pList;
	return pPrev;
}


void *dequeue(QueueNode **pList)
{
	QueueNode *pTemp, *pAfter;
	pTemp = pList;
	while (pTemp != NULL)
	{
		pAfter = pTemp->pNext;
		free(pTemp);
		pTemp = pAfter;
	}
}




void print_current(QueueNode **pList, int t)
{
	QueueNode *pCur;
	pCur = pList;

	printf("Customer %d arrived at %d minutes. \n", pCur->customerNumber, t);
	printf("Customer service time: %d minutes.\n\n", pCur->serviceTime);
}