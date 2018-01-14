#include "header.h"


void manual_parse(int i, char line, Fitbit data[])
{

}






int tot_cal(Fitbit data[])
{
	int i = 0, temp = 0;
	for (i = 0; i < 1440; i++)
	{
		data[i].calories += temp;
	}
	return temp;
}


int tot_dist(Fitbit data[])
{
	int i = 0, temp = 0;
	for (i = 0; i < 1440; i++)
	{
		data[i].distance += temp;
	}
	return temp;
}


int tot_floors(Fitbit data[])
{
	int i = 0, temp = 0;
	for (i = 0; i < 1440; i++)
	{
		data[i].floors += temp;
	}
	return temp;
}


int tot_steps(Fitbit data[])
{
	int i = 0, temp = 0;
	for (i = 0; i < 1440; i++)
	{
		data[i].steps += temp;
	}
	return temp;
}


int ave_heart(Fitbit data[])
{
	int i = 0, temp = 0, average = 0;
	for (i = 0; i < 1440; i++)
	{
		data[i].heartRate += temp;
	}

	average = temp / 1440;

	return temp;
}





int max_steps(Fitbit data[])
{
	int i = 0, max = 0;

	for (i = 0; i < (1440-1); i++)
	{
		if (data[i + 1].steps > data[i].steps)
		{
			max = data[i + 1].steps;
		}
		else if (data[i + 1].steps < data[i].steps)
		{
			max = data[i].steps;
		}
		else if (data[i + 1].steps == data[i].steps)
		{
			max = data[i + 1].steps;
		}
	}
	return max;
}




void poor_sleep(Fitbit data[], char start[], char end[])
{
	int i = 0, temp = 0, count = 0;
	char temp_s[50] = { 0 }, temp_e[50] = { 0 };
	for (i = 0; i < (1440 - 1); i++)
	{
		if ((data[i].sleeplevel > 1) && (data[i + 1].sleeplevel > 1)) //only works if it's consecutive
		{
			strcpy(temp_s, data[i].minute); //temporary start
			while (data[i].sleeplevel > 1)
			{
				temp++; //temporary counter
				i++;
			}
			strcpy(temp_e, data[i].minute); //temporary end
			if (temp > count) 
			{
				count = temp;
				strcpy(start, temp_s);
				strcpy(end, temp_e);
			}
		}
	}
}

