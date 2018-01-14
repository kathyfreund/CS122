#ifndef FITBIT_H
#define FITBIT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum sleep
{
	NONE, ASLEEP, AWAKE, REALLYAWAKE
	//0 = none, 1 = asleep, 2 = awake, 3 = reallyawake
} Sleep;

typedef struct fitbit //7 total categories
{
	char minute[9];
	double calories;
	double distance;
	unsigned int floors;
	unsigned int heartRate;
	unsigned int steps;
	Sleep sleeplevel;
} Fitbit;

////////////////////////////////FUNCTIONS///////////////////////////

void manual_parse(int i, char line, Fitbit data[]);


int tot_cal(Fitbit data[]);
int tot_dist(Fitbit data[]);
int tot_floors(Fitbit data[]);
int tot_steps(Fitbit data[]);

int ave_heart(Fitbit data[]);

int max_steps(Fitbit data[]);

//function for longest consecutive range of poor sleep (sleep level > 1)
	//the max sum of the ranges is considered the poorest sleep
void poor_sleep(Fitbit data[], char start[], char end[]);



#endif
