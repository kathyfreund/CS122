#include <stdio.h>
#include <Windows.h>
#include <dos.h>
#include <time.h>
#include <stdlib.h>

//void sleep(unsigned milliseconds)
//{
//	Sleep(milliseconds);
//}



typedef struct duration
{
	int minutes;
	int seconds;
}Duration;

typedef struct record
{
	char *artist;
	char *album;
	char *song;
	char *genre;
	Duration length;
	int repeat;
	int rating;
}Record;


typedef struct node
{
	Record data;
	struct node *pNext;
	struct node *pPrev;
}Node;


Node *makeNode(Record playlist); //DONE

Node* load_music(FILE *infile); // DONE

void store_music(FILE *infile, Node **pList); //DONE

void display_music(Node **pList); //DONE

Node *edit_music(Node **pList); //DONE

Node *rate(Node **pList); //DONE

void play_music(Node **plist); //Sort of done, fix bugs

Node* new_record(Node **pList); //Sort of done, fix bugs

Node *delete_record(Node **pList); //DONE

Node *sort_record(Node **pList); //Sort of done, fix bugs

Node *shuffle_music(Node **pList); //GET STARTED ON THIS ASAP




int count_nodes(Node **pList);


FILE* open_file(void); //DONE, opens file for reading
FILE* open_filew(void); //DONE, opens file for overwriting