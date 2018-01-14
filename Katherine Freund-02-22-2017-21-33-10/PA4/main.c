#include "Header.h"


int main(void)
{
	//Express lane:
		//Customer Arrivals: Every 1-5 minutes
		//Service time: 1-5 min
	//Normal lane:
		//Customer Arrivals: Every 3-8 minutes
		//Service time: 3-8 min

	int min_n = 0, min_e = 0, min = 0, run = 0, run1 = 0, r_n = 0, r_e = 0, normal = 0, express = 0, tot_time = 0;
	int print_run = 0, print_trackN = 0, print_trackE = 0;
	int numc_n = 0, numc_e = 0, total_n = 0, total_e = 0, t = 0;
	QueueNode *pCur_n, *pCur_e, *pN_last, *pE_last, *p0n, *p1n, *p0e, *p1e;
	Queue *pTrackN, *pTrackE;
	srand(time(NULL));

	printf("Please type in how many minutes allowed for simulation to run: ");
	scanf("%d", &min);
	min_n = min;
	min_e = min;
	system("cls");

	print_run = min / 10; //have to print out queue every 10 min
	if ((print_run % 10) > 0)
	{
		print_run++;
	}

	while ((min_n > 0))
	{
		run++; 

		r_n = 3 + (rand() % 6); //random arrival time
		normal = 3 + (rand() % 6); //random service time 
		numc_n++;

		total_n += normal; //keeps track of total service time up to current customer
		
		//pCur_n->customerNumber = numc_n;
		//pCur_n->serviceTime = normal;			   
		//pCur_n->totalTime = total_n; 
		pCur_n = makeNode(numc_n, normal, total_n);

		print_trackN = print_trackN + normal + r_n;
		t = t + normal + r_n;
		if (run == 1)
		{
			min_n = min - (r_n + normal);
			p0n = pCur_n;
			print_current(pCur_n, r_n);
		}
		else
		{
			min_n = min_n - (r_n + normal);	
			pN_last = enqueue(pCur_n, pN_last);
			print_current(pCur_n, (t - normal));

			//pN_last->pNext = pCur_n; //person before points to person next in line
			//pE_last->pNext = pCur_e;
		}

		if (print_trackN >= 10)
		{
			print_trackN -= 10;
			printf("10 minutes have passed. List will clear and reprint for the next 10 min.\n");
			system("pause");
			system("cls");
		}
		pN_last = pCur_n; //keeps track of person before for next round
	}

	if ((min_n <= 0)) //once loop breaks and error checking
	{
		pCur_n->pNext = NULL;
		p1n = pCur_n;
	}

	pTrackN = makeTracker(p0n, p1n);
	printQueue(pTrackN->pHead);







	system("pause");
	system("cls");
	printf("And now for the express line.\n\n");
	system("pause");
	system("cls");







	t = 0;

	while ((min_e > 0))
	{
		run1++;

		r_e = 1 + (rand() % 5); //random arrival time
		express = 1 + (rand() % 5);	//random service time
		numc_e++;

		total_e += express;

		pCur_e = makeNode(numc_e, normal, total_e);


		print_trackE = print_trackE + express + r_e;
		t = t + express + r_e;

		if (run1 == 1)
		{
			min_e = min - (r_e + express);
			p0e = pCur_e;
			print_current(pCur_e, r_e);
		}
		else
		{
			min_e = min_e - (r_e + express);
			pE_last = enqueue(pCur_e, pE_last);
			print_current(pCur_e, (t - express));
		}

		if (print_trackE >= 10)
		{
			print_trackE -= 10;
			printf("10 minutes have passed. List will clear and reprint for the next 10 min.\n");
			system("pause");
			system("cls");
		}
		pE_last = pCur_e;
	}

	if ((min_e <= 0)) //once loop breaks and error checking
	{
		pCur_e->pNext = NULL;
		p1e = pCur_e;
		//printQueue(pTrackE->pHead);
	}

	pTrackE = makeTracker(p0e, p1e);
	printQueue(pTrackE->pHead);
	system("pause");
	system("cls");

	////print both lists at the same time?
	//printf("Here are the two queues: \n\n");
	////print both queues
	//system("pause");
	//system("cls");

	if (run > run1)
	{
		printf("It seems the normal line was faster.\n\n");
	}
	else if (run1 > run)
	{
		printf("It seems the express line was faster.\n\n");
	}
	else if (run1 == run)
	{
		printf("I guess it doesn't matter which line you go to since both lines hosted the same amount of people.\n\n");
	}

	printf("People Hosted:\n");
	printf("Normal: %d\n", run);
	printf("Express: %d\n\n", run1);

	system("pause");

	//free data
	dequeue(pTrackN->pHead);
	dequeue(pTrackE->pHead);

	return 0;
}