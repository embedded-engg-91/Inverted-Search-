#ifndef INVERTED_H
#define INVERTED_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define size 50

/* Main node structure definiton*/
typedef struct mainnode
{
    char word[20]; //the word 
    int filecount; //in how many files the word has appeared
    struct mainnode *mlink; //link to next mainnnode
    struct subnode *slink; //link to next sublink
}mnode;

/* subnode structure defintion*/
typedef struct subnode
{
    int wordcount;    //how many times the word appeared in the current file
    char filename[20]; //the current file name 
    struct subnode *slink; ///next file link
}snode;

typedef struct node
{
    char *filename; //name of the file 
    struct node *link; //link to next file name 
}Slist;

typedef enum
{
    SUCCESS, FAILURE, DUPLICATE, INVALID_FNAME, FILE_NOT_FOUND
}Status;


extern int db_created;
extern int restored;

FILE* exist_and_non_empty(char *argv);
Status read_validate( char **argv, Slist **head);
Status insert_at_last(Slist **head, char *argv); 
void print_list(Slist *head);
Status create_database(mnode *arr[], Slist *head);
mnode *create_mnode(char word[], char *filename);
snode* create_snode(char *filename);
snode *match_filename(char *filename, mnode *head); 
mnode *match_word(char *word, mnode *head);
void display(mnode *arr[],Slist *head);
void search(mnode *arr[],Slist *head,char *);
Status save(mnode *arr[], Slist *head);
Status update(mnode *arr[], Slist **head);
Status find_node(Slist *head, char *filename); 
Status restore(mnode *arr[]);






#endif