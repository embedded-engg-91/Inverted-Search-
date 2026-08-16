#include "inverted.h"

int db_created = 0;

Status create_database(mnode *arr[], Slist *head)
{
   char buffer[size];
   while(head) 
   {
        FILE *fp=fopen(head->filename,"r");
        if(fp==NULL) return FAILURE; 
        while(fscanf(fp, "%s", buffer) == 1) 
        {
            int ind=tolower(buffer[0])-'a';
            if(arr[ind]==NULL) 
            {
                mnode *new=create_mnode(buffer, head->filename);
                arr[ind]=new; 
            }
            else
            {
                
                
                mnode *addrs=match_word(buffer, arr[ind]); 

                if(addrs==NULL) 
                {
                    mnode *temp = arr[ind];

                    while(temp->mlink != NULL)
                    temp = temp->mlink;

                    temp->mlink = create_mnode(buffer, head->filename);
                }
                else
                {
                    
                    snode *filename=match_filename(head->filename, addrs); 
                    if( filename!=NULL)
                    {
                        
                        filename->wordcount+=1;

                    }
                    else 
                    {
                        
                         snode *new = create_snode(head->filename);

                        
                        snode *temp = addrs->slink;

                        while(temp->slink != NULL)
                        {
                            temp = temp->slink;
                        }

                        
                        temp->slink = new;

                        
                        addrs->filecount++;
                        


                    }
                }
            }
            
        }
        fclose(fp);
        head=head->link;
   }
   db_created=1;
   return SUCCESS;
}
