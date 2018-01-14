#include "header.h"
/*
SOURCES:
https://www.tutorialspoint.com/c_standard_library/c_function_atoi.htm
http://www.wellho.net/resources/ex.php4?item=c209/lunches.c
*/


int main(void)
{
	FILE *pinput = NULL, *poutput = NULL;
	char line[1000], categories[1000], sleep_start[50] = { 0 }, sleep_end[50] = { 0 };
	int calories = 0, distance = 0, floors = 0, steps = 0, average = 0, max_s = 0, i = 0;
	Fitbit data[1440]; //in place of malloc --> Fitbit*fbdata = malloc(1440 * sizeof(Fitbit));
	


	int length = 0;


	//open files
	pinput = fopen("FitbitData.csv", "r");
	//poutput = fopen("Results.csv", "w");


	//get line first, then get tokens

	if (pinput != NULL)
	{
		printf("File opened successfully.\n\n");
		fgets(categories, 1000, pinput); // stores categories
		
		char *token;
		while (fgets(line, 1000, pinput) != NULL)
		{
			length = strlen(line);

			if (length == 31)
			{
				token = strtok(line, ","); //start of line
				strcpy(data[i].minute, token); //had to use strcpy because minute is an array

				token = strtok(NULL, ",");
				data[i].calories = atof(token);

				token = strtok(NULL, ",");
				data[i].distance = atof(token);

				token = strtok(NULL, ",");
				data[i].floors = atoi(token);

				token = strtok(NULL, ",");
				data[i].heartRate = atoi(token);

				token = strtok(NULL, ",");
				data[i].steps = atoi(token);

				token = strtok(NULL, "\n"); //last of the categories, delimeter is "\n"
				if (atoi(token) == 0)
				{
					data[i].sleeplevel = NONE;
				}
				else if (atoi(token) == 1)
				{
					data[i].sleeplevel = ASLEEP;
				}
				else if (atoi(token) == 2)
				{
					data[i].sleeplevel = AWAKE;
				}
				else if (atoi(token) == 3)
				{
					data[i].sleeplevel = REALLYAWAKE;
				}
			}
			else
			{
				manual_parse(i, line, data);
			}


			i++;
		}

		//calculating totals
		calories = tot_cal(data);
		distance = tot_dist(data);
		floors = tot_floors(data);
		steps = tot_steps(data);

		//average
		average = ave_heart(data);

		//max and consecutive
		max_s = max_steps(data);
		poor_sleep(data, sleep_start, sleep_end);

	}

	else
	{
		//printf("Failed to open file.\n");
		perror("Error");
	}


	//ONCE EVERYTHING IS STORED:
	fprintf(poutput, "%s", line); //prints out categories











	//close files
	fclose(pinput);
	//fclose(poutput);


	return 0;
}