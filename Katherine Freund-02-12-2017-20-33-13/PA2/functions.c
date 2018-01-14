#include "Header.h"




FILE* open_file()
{
	FILE *infile;
	infile = fopen("musicPlaylist.csv", "r");
	return infile;
}



FILE* open_filew()
{
	FILE *infile;
	infile = fopen("musicPlaylist.csv", "w+");
	return infile;
}








//makes space for the node(playlist)
Node * makeNode(Record newData)
{
	Node *n = (Node *)malloc(sizeof(Node)); //this is the playlist

	if (n != NULL) // how does this determine that malloc was successfull?
	{
		n->pNext = NULL;
		n->pPrev = NULL;

		n->data.artist = (char*)malloc(sizeof(char)*(strlen(newData.artist) + 1));
		strcpy(n->data.artist, newData.artist);

		n->data.album = (char*)malloc(sizeof(char)*(strlen(newData.album) + 1));
		strcpy(n->data.album, newData.album);

		n->data.song = (char*)malloc(sizeof(char)*(strlen(newData.song) + 1));
		strcpy(n->data.song, newData.song);

		n->data.genre = (char*)malloc(sizeof(char)*(strlen(newData.genre) + 1));
		strcpy(n->data.genre, newData.genre);

		n->data.length.minutes = newData.length.minutes;
		n->data.length.seconds = newData.length.seconds;	
		n->data.repeat = newData.repeat;
		n->data.rating = newData.rating;

	}

	return n;
}











//stores current records in file onto top of list
Node *load_music(FILE *infile)
{

	char line[1000] = { 0 }, *token;
	int *tokeni, count = 0;
	Record temp;
	Duration temp1;
	Node *pOld, *pMem;


	while (!feof(infile)) //while end of file is not reached
	{
	
		fgets(line, 1000, infile);
	
		token = strtok(line, ","); 
		temp.artist = token;
		if (line[0] == '\"')  //HOW THE HELL DO I DEAL WITH THE GODDAMN COMMAS
		{
			token = strtok(NULL, ",");
			strcat(temp.artist, token);
		}

		token = strtok(NULL, ",");
		temp.album = token;

		token = strtok(NULL, ",");
		temp.song = token;

		token = strtok(NULL, ",");
		temp.genre = token;

		token = strtok(NULL, ":");//This is where the duration struct comes into play
		temp1.minutes = atoi(token);
		token = strtok(NULL, ",");
		temp1.seconds = atoi(token);
		temp.length = temp1;

		token = strtok(NULL, ",");
		temp.repeat = atoi(token);

		token = strtok(NULL, "/n");
		temp.rating = atoi(token);

		//Once everything in line is stored in temporary struct, move everything into new node
		pMem = makeNode(temp);

		if (count == 0)
		{
			pMem->pNext = NULL;
			pMem->pPrev = NULL;
		}
		else
		{
			pMem->pNext = pOld;
			pOld->pPrev = pMem;
		}
		pOld = pMem;

		count++;
		
	}
	return pMem; //last thing added will be the top of the list
}

















//overwrites file with records from the list
void store_music(FILE *infile, Node **pList)
{
	Node *pcur;

	pcur = pList;

	while (pcur != NULL)
	{
		fprintf(infile, "%s, %s, %s, %s, ", pcur->data.artist, pcur->data.album, pcur->data.song, pcur->data.genre);
		fprintf(infile, "%d:%d, %d, %d\n", pcur->data.length.minutes, pcur->data.length.seconds, pcur->data.repeat, pcur->data.rating);
		pcur = pcur->pNext;
	}
}











//prints out current records in list
void display_music(Node **pList)
{
	system("cls");
	
	int choice = 0, found = 0, count = 0;
	char name[50];
	Node *pcur = NULL;
	Record temp;
	Duration temp1;

	printf("Do you want to: \n\n1.Print all records.\n2.Print all records that match an artist.\n");
	scanf("%d", &choice);

	if (choice == 1)
	{
		pcur = pList;
		while (pcur != NULL)
		{
			temp = pcur->data;
			temp1 = temp.length;
			printf("%s, %s, %s, %s, %d:%d, %d, %d\n", temp.artist, temp.album, temp.song, temp.genre, temp1.minutes,temp1.seconds, temp.repeat, temp.rating);
			pcur = pcur->pNext;
		}
	}
	else if (choice == 2)
	{
		pcur = pList;
		printf("Please type in the name of an artist:\n");
		scanf("%s", &name);

		while (pcur != NULL) //need to print out all records that match
		{

			temp = pcur->data;
			temp1 = temp.length;
			found = strcmp(temp.artist, name);
			if (found == 0)
			{
				printf("%s, %s, %s, %s, %d:%d, %d, %d\n\n", temp.album, temp.artist, temp.song, temp.genre, temp1.minutes, temp1.seconds, temp.repeat, temp.rating);
				count++;
			}

			pcur = pcur->pNext;

		}
		if (count == 0)
		{
			printf("No records were found that match the artist.\n");
		}
	}
}












//edits any attribute for any album based on artist name
Node *edit_music(Node **pList)
{

	char name[50] = { 0 };
	int choice = 0, edit = 0, found = 0, count = 0, yn = 0;
	Node *pcur, *pTop;
	Record temp;
	Duration temp1;
	Record found_records[10];

	printf("Please type in name of artist of the record you wish to edit:\n");
	scanf("%s", &name);

	pcur = pList;

	while (pcur != NULL)
	{
		temp = pcur->data; //set temporary record equal to current data in node for comparison
		temp1 = temp.length; //set temporary duration equal to current data in temporary record
		
		found = strcmp(temp.artist, name); //should return 1 if equal

		if (found == 0)
		{
			printf("Is this the record you wish to edit? Press 1 for yes, 0 for no. \n");
			printf("%s, %s, %s, %s, %d:%d, %d, %d\n", temp.album, temp.artist, temp.song, temp.genre, temp1.minutes, temp1.seconds, temp.repeat, temp.rating);
			scanf("%d", &yn);
			if (yn == 1) //need to ask for y/n in case of multiple records that match
			{

				printf("What would you like to edit\n\n? 1.Artist\n2.Album\n3.Song\n4.Genre\n5.Length\n6.Repeat\n7.Rating\n");
				scanf("%d", &choice); //prompts user which attribute to edit
				if ((choice > 0) && (choice < 8)) //makes sure user put in an accepted value
				{
					switch (choice)
					{
					case 1:
						printf("Current artist is %s. Please type in new artist name:\n", temp.artist);
						scanf("%s", &temp.artist);
						//printf("Artist name has been changed to %s", temp.artist);
						break;
					case 2:
						printf("Current album is %s. Please type in new album name:\n", temp.album);
						scanf("%s", &temp.album);
						//printf("Album name has been changed to %s", temp.album);
						break;
					case 3:
						printf("Current song is %s. Please type in new song name:\n", temp.song);
						scanf("%s", &temp.song);
						//printf("Song name has been changed to %s", temp.song);
						break;
					case 4:
						printf("Current genre is %s. Please type in new genre:\n", temp.genre);
						scanf("%s", &temp.genre);
						//printf("Genre has been changed to %s", temp.genre);
						break;
					case 5:
						temp1 = temp.length;
						printf("Current song length is %d minutes and %d seconds. Please type in new song length (minutes then seconds):\n", temp1.minutes, temp1.seconds);
						scanf("%d", &temp1.minutes);
						scanf("%d", &temp1.seconds);
						temp.length = temp1;
						break;
					case 6:
						printf("Current number of repeats is %d. Please type in new number of repeats:\n", temp.repeat);
						scanf("%d", &temp.repeat);
						//printf("Number of repeats has been changed to %s", temp.repeat);
						break;
					case 7:
						printf("Current rating is %d. Please type in new rating:\n", temp.rating);
						scanf("%d", &temp.rating);
						//printf("Rating has been changed to %d", temp.rating);
						break;
					}
				}
				pcur->data = temp; //put in edited temp into current node
				//printf("New edited record: %s, %s, %s, %s, %d:%d, %d, %d\n", temp.album, temp.artist, temp.song, temp.genre, temp1.minutes, temp1.seconds, temp.repeat, temp.rating);
				//printf("New edited record: %s, %s, %s, %s, %d:%d, %d, %d\n", pcur->data.album, pcur->data.artist, pcur->data.song, pcur->data.genre, pcur->data.length.minutes, pcur->data.length.seconds, pcur->data.repeat, pcur->data.rating);
				//for some reason the program breaks if I try to print out the newly edited album

				break; 

			}
		}
		if (count == 0)
		{
			pTop = pcur; //keeps track of the top of the list
		}
		pcur = pcur->pNext; //move on to next node.

		count++;

	}
	if (found != 0)
	{
		printf("No records matched artist name.");
	}
	return pTop; //returns top of edited list
}














//changes or edits song ratings based on artist name
Node *rate(Node **pList)
{
	Node *pcur, *pTop;
	Record temp;
	int found = 0, yn = 0, count = 0;
	char name[50] = { 0 };
	
	pcur = pList;
	printf("Please enter artist name of record you wish to rate:\n\n");
	scanf("%s", &name);
	
	while (pcur != NULL)
	{

		temp = pcur->data; 
		found = strcmp(temp.artist, name); 
		if (found == 0)
		{
			printf("Is this the record you wish to edit? Press 1 for yes, 0 for no. \n");
			printf("%s, %s.\n", temp.album, temp.artist);
			scanf("%d", &yn);
			if (yn == 1)
			{
				printf("Current rating is %d. Please type in new rating:\n", temp.rating);
				scanf("%d", &temp.rating);
				pcur->data = temp;
				break;
			}
		}
		if (count == 0) //first in the list
		{
			pTop = pcur;
			count++;
		}
		pcur = pcur->pNext;
	}
	if (found != 0)
	{
		printf("No records matched artist name.\n");
	}


	return pTop;
}







//used sleep, got help from this website: http://stackoverflow.com/questions/3379139/sleep-function-in-windows-using-c
void play_music(Node **plist)
{
	Node *pcur;
	int play = 0;

	pcur = plist;

	while (play != 1); //it just stops. program doesnt even crash, it just stops and doesnt let me do anything. never seen anything like this
	{
		printf("Please press 0 to skip to next song or 1 to play current song: \n\n");
		printf("Current song: %s. Skip (0) or Play(1)?\n", pcur->data.song);
		scanf("%d", &play);
		if (play == 1)
 		{
			while (pcur->pNext != NULL)
			{
				printf("Now playing: %s", pcur->data.song);
				Sleep(2000);
				system("cls");
				pcur = pcur->pNext;
			}
		}
		system("cls");
	}
	
	if (play != 1)
	{
		printf("All of the available songs have been skipped.");
	}
}










Node *new_record(Node **pList)
{
	//plist is the top of the original list

	Node *pNew;
	Record temp;


	//temp.artist = NULL;
	//temp.album = NULL;
	//temp.song = NULL;
	//temp.genre = NULL;
	//temp.length.minutes = 0;
	//temp.length.seconds = 0;
	//temp.repeat = 0;
	//temp.rating = 0; //no other way to initialize this? :(

	printf("Please type in the corresponding fields for the new record:\n\n");

	printf("Artist:\n");
	scanf("%s", &temp.artist);

	printf("Album:\n");
	scanf("%s", &temp.album);

	printf("Song:\n");
	scanf("%s", &temp.song);

	printf("Genre:\n");
	scanf("%s", &temp.genre);

	printf("Song Length (minutes then seconds):\n");
	scanf("%d%d", &temp.length.minutes, &temp.length.seconds);

	printf("Repeat:\n");
	scanf("%d", &temp.repeat);

	printf("Rating:\n");
	scanf("%d", &temp.rating);

	//BREAK AROUND HERE-------------------------------- 


	pNew = makeNode(temp); //actually make the new node with the user's input

	pNew->pNext = pList; //make pnew the top of the list
	pNew->pPrev = NULL;

	return pNew;

}












Node *delete_record(Node **pList)
{
	char song[50] = { 0 };
	Node *pcur, *pTop, *pPrev;
	int found = 0, yn = 0;
	Record temp;

	printf("Please type in name of the song you wish to edit:\n");
	scanf(" %[^\n]s", song); // used this link for help: http://stackoverflow.com/questions/6282198/reading-string-from-input-with-space-character

	pTop = pList;
	pcur = *pList;

	while (pcur != NULL)
	{
		found = strcmp(pcur->data.song, song);

		if (found == 0)
		{
			printf("\nIs this the Record you wish to delete? Press 1 for yes, 0 for no.\n\n");
			printf("%s, %s, %s, %s, %d:%d, %d, %d\n", pcur->data.album, pcur->data.artist, pcur->data.song, pcur->data.genre, pcur->data.length.minutes, pcur->data.length.seconds, pcur->data.repeat, pcur->data.rating);
			scanf("%d", &yn);
			if (yn == 1)
			{
				
				if (pPrev != NULL) //if the found node is the first node
				{
					pPrev->pNext = pcur->pNext;
				}
				
				else
				{
					*pList = (*pList)->pNext;
				}


				//before = pcur->pPrev;
				//after = pcur->pNext;
				//pcur->pNext = NULL;
				//pcur->pPrev = NULL;
				//before->pNext = after; //the node "deleted still exists", i just rearranged the pointers to the other nodes
				//after->pPrev = before;
				//pcur = after;

				free(pcur->data.album); 
				free(pcur);

				printf("\nRecord Deleted.\n\n");
				break;
			}
		}
		
		pPrev = pcur;
		pcur = pcur->pNext;
	}

	return pTop;
}









Node *sort_record(Node **pList)
{

	int choice = 0, num = 0, i = 0, run = 0;
	Node *pNew, *pTop, *pTemp, *pCur, *pAfter;

	printf("How do you want to sort your playlist?\n\n");
	printf("1.Sort based on Artist.\n");
	printf("2.Sort based on Album.\n");
	printf("3.Sort based on Rating.\n");
	printf("4.Sort based on times played.\n");
	
	scanf("%d", &choice);



	num = count_nodes(pList);

	pTop = pList;
	

	if (choice == 1)
	{
		while (num > 0)
		{
			pTemp = pTop;
			pAfter = pTop->pNext;
			while (pAfter != NULL) //should spew out highest string alphabetically - pTop
			{
				i = strcmp(pAfter->data.artist, pTemp->data.artist);
				if (i > 0) //pTemp is above pAfter
				{
					//do nothing
				}
				else if (i < 0)
				{
					pTemp = pAfter;
				} 
				pAfter = pAfter->pNext; 
			}

			if (pTemp->pPrev == NULL)
			{
				pTop = pTemp->pNext;
			}
			if (pTemp->pPrev != NULL) //rip out of list
			{
				pTemp->pPrev->pNext = pTemp->pNext;
				if (pTemp->pNext != NULL)
				{
					pTemp->pNext->pPrev = pTemp->pPrev;
				}
			}
			else
			{
				if (pTemp->pNext != NULL)
				{
					pTemp->pNext->pPrev = NULL;
				}
				else
				{
					//end of the line
					pTemp->pNext = NULL;
				}
			}
			if (run == 0)
			{
				pNew = pTemp;
				pNew->pPrev = NULL;
			}
			else if (run == 1)
			{
				pTemp->pPrev = pNew;
				pNew->pNext = pTemp;
				pCur = pTemp;
			}
			else
			{
				pTemp->pPrev = pCur;
				pCur->pNext = pTemp;
				pCur = pTemp;
			}
			run++;
			num--;
		}			
	}



	else if (choice == 2)
	{
		
	}


	else if (choice == 3) //sort by rating
	{
		
	}

	else if (choice == 4) //sort by times played
	{
		
	}


	return pNew; //returns top of list
}





Node *shuffle_music(Node **pList)
{
	int num = 0, random = 0, run = 0;
	srand(time(NULL));
	Node *pNew, *pTemp, *pCur, *pTop;

	num = count_nodes(pList); //9
	num -= 2; //7
	pTop = pList;
	
	while (num > 0)
	{
		random = rand() % (num);
		pTemp = pTop;
		while (random > 0) //spews out random node selected ; also, if random == 0, ptop is pTemp
		{
			pTemp = pTemp->pNext;
			random--;
		}
		if (pTemp->pPrev == NULL)
		{
			pTop = pTemp->pNext;
		}

		if (pTemp->pPrev != NULL) //rip out of list
		{
			pTemp->pPrev->pNext = pTemp->pNext;
			if (pTemp->pNext != NULL)
			{
				pTemp->pNext->pPrev = pTemp->pPrev;
			}
		}
		else
		{
			if (pTemp->pNext != NULL)
			{
				pTemp->pNext->pPrev = NULL;
			}
			else
			{
				//end of the line
				pTemp->pNext = NULL;
			}
		}

		if (run == 0)
		{
			pNew = pTemp;
			pNew->pPrev = NULL;
		}
		else if (run == 1)
		{
			pTemp->pPrev = pNew;
			pNew->pNext = pTemp;
			pCur = pTemp;
		}
		else
		{
			pTemp->pPrev = pCur;
			pCur->pNext = pTemp;
			pCur = pTemp;
		}

	
		num--;
		run++;
	}

	return pNew;
}








int count_nodes(Node **pList)
{
	Node *pCur;
	pCur = pList;
	int count = 0;

	while (pCur != NULL)
	{
		pCur = pCur->pNext;
		count++;
	}

	return count;
}