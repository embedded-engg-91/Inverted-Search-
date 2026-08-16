#include "inverted.h"

Status insert_at_last(Slist **head, char *argv)
{
    Slist *new_node=malloc(sizeof(Slist));
    if(new_node==NULL)
    {
        return FAILURE; 
    }
    new_node->filename=argv;
    new_node->link=NULL;
    if((*head)==NULL)
    {
        *head=new_node; 
        return SUCCESS; 
    }
    Slist *temp= (*head); 
    while(temp->link!=NULL)
    {
        temp=temp->link;
    }
    temp->link=new_node;
    return SUCCESS;
}

Status find_node(Slist *head, char *filename) 
{
	int count=1;
	while(head!=NULL) 
	{                   
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

mnode *match_word(char *word, mnode *head) 
{
    
   
   mnode *temp=head;
   while(head!=NULL)
   {
    if(strcmp(head->word,word) == 0)
    {
        
        return head;  
    }
    temp=head;
    head=head->mlink; 
   }
   return NULL;
}


snode *match_filename(char *filename, mnode *head) 
{
    
    snode *temp=head->slink;
    snode *prev=temp;
    while (temp!=NULL)
    {
       if(strcmp(temp->filename,filename) == 0)
        {
            
            return temp; 
        }
        prev=temp;
        temp=temp->slink; 
        
    }
    return NULL; 
    

}
