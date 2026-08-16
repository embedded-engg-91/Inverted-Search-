#include "inverted.h"

Status insert_at_last(Slist **head, char *argv)//changes should be reflected in main 
{
    Slist *new_node=malloc(sizeof(Slist));
    if(new_node==NULL)
    {
        return FAILURE; //memory allocation failure 
    }
    new_node->filename=argv;
    new_node->link=NULL;
    if((*head)==NULL)//means list is empty 
    {
        *head=new_node; 
        return SUCCESS; 
    }
    Slist *temp= (*head); //to not lose the head ptr
    while(temp->link!=NULL)
    {
        temp=temp->link;
    }
    temp->link=new_node;
    return SUCCESS;
}

Status find_node(Slist *head, char *filename) //we just nned to identily whther the filename is repeated or not 
{
	int count=1;
	
	while(head!=NULL) //no need of temp here cuz head that we have here is pass by val(*head not **head check) so 
	{                   //changes we do to head here wont be reflected in main
	    if(strcmp(head->filename, filename) == 0)
	    {
	        return DUPLICATE;
	    }
	    head=head->link;
	    count++;
	}
	return SUCCESS;
}


void print_list(Slist *head)
{
	if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
    else
    {
        printf("All the valid files are: \n");
	    while (head)		
	    {
		    printf("%s\n", head -> filename);
		    head = head -> link;
	    }

    }
}

mnode *match_word(char *word, mnode *head) //only one index we have na so pass by value
{
    /*
    Case 1. Word is matched return the addrs 
    Case 2. Word is not matched return the NULL
    */
   /* for this we traverse the mainlinks nodes */
   mnode *temp=head;
   while(head!=NULL)
   {
    if(strcmp(head->word,word) == 0)
    {
        //means the word found 
        return head;  
    }
    temp=head;
    head=head->mlink; //note  word is stored inside the mainlink 
   }
   return NULL;
}


snode *match_filename(char *filename, mnode *head) //here inside head i have collected mainnode 
{
    /* noe we need to traverse till the sublinks is not null*/
    snode *temp=head->slink;
    snode *prev=temp;
    while (temp!=NULL)
    {
       if(strcmp(temp->filename,filename) == 0)
        {
            //means the filename is  found 
            return temp; 
        }
        prev=temp;
        temp=temp->slink; //note  word is stored inside the mainlink 
        //so we must go there 
    }
    return NULL; 
    

}
