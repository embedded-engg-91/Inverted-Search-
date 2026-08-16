#include "inverted.h"

mnode *create_mnode(char word[], char *filename)
{
    mnode *new_mnode=malloc(sizeof(mnode));
    if(new_mnode==NULL)
    {
        return NULL;
    }
    strcpy(new_mnode->word, word);
    new_mnode->filecount=1;
    new_mnode->mlink=NULL;
    new_mnode->slink=create_snode(filename);
    return new_mnode;
}

snode* create_snode(char *filename)
{
    snode *new_snode=malloc(sizeof(snode));
    if(new_snode==NULL) return NULL;
    new_snode->wordcount=1;
    strcpy(new_snode->filename, filename);
    new_snode->slink=NULL;
    return new_snode;
}