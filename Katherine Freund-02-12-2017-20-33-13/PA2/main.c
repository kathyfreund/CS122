#include "Header.h"

int main()
{
	int choice = 0;
	FILE *infile = NULL;
	Node *plist = NULL;
	
	//open files
	infile = open_file();
	
	//user choice menu
	do
	{

		printf("Please select one of the following options:\n\n");
		printf("1.Load \n2.Store \n3.Display \n4.Insert \n5.Delete \n");
		printf("6.Edit\n7.Sort \n8.Rate \n9.Play \n10.Shuffle \n11.Exit\n");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1: //load
			infile = open_file(); //open for reading only
			plist = load_music(infile);
			fclose(infile);
			system("cls");
			if (plist != NULL) //will not be null if load was successfull
			{
				printf("Load successfull!\n");
			}
			break;
		case 2: //store
			if (plist == NULL)
			{
				printf("Error: No records found. Please load some records first!\n");
			}
			else
			{
				infile = open_filew();
				store_music(infile, plist);
				fclose(infile);
			}
			break;
		case 3: //display
			if (plist == NULL) //wont work if there's nothin in the list
			{
				printf("Error: No records found. Please load some records first!\n");
			}
			else
			{
				display_music(plist);
			}
			break;
		case 4: //insert
			system("cls");
			if (plist == NULL)
			{
				system("cls");
				printf("Error: No records found. Please load some records first!\n");
			}
			else
			{
				plist = new_record(plist);
			}
			break;
		case 5: //delete
			system("cls");
			if (plist == NULL)
			{
				system("cls");
				printf("Error: No records found. Please load some records first!\n");
			}
			else
			{
				plist = delete_record(plist);
			}
			break;
		case 6: //edit
			system("cls");
			if (plist == NULL)
			{
				printf("Error: No records found. Please load some records first!\n");
			}
			else
			{
				edit_music(plist);
			}
			break;
		case 7: //sort
			system("cls");
			if (plist == NULL)
			{
				printf("Error: No records found. Please load some records first!\n");
			}
			else
			{
				plist = sort_record(plist);
			}
			break;
		case 8: //rate
			system("cls");
			if (plist == NULL)
			{
				printf("Error: No records found. Please load some records first!\n");
			}
			else
			{
				rate(plist);
			}
			break;
		case 9: //play
			play_music(plist);
			break;
		case 10: //shuffle
			system("cls");
			if (plist == NULL)
			{
				printf("Error: No records found. Please load some records first!\n");
			}
			else
			{
				plist = shuffle_music(plist);
			}
			break;
		case 11: //exit
			system("cls");
			printf("\nThank you, goodbye!\n\n");
			if (plist != NULL)
			{
				infile = open_filew();
				store_music(infile, plist);
				fclose(infile);
			}
			//uses same function as store option
			break;
		}
		system("pause");
		system("cls");
	} while (choice != 11);


	//close files
	fclose(infile);


	return 0;
}

