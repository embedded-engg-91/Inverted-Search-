#include "inverted.h"

int db_created = 0;

Status create_database(mnode *arr[], Slist *head)//head is the list containing file names, here we using pass by value concept
{
   char buffer[size];
   while(head) //untit he list becomes empty 
   {
        FILE *fp=fopen(head->filename,"r");
        if(fp==NULL) return FAILURE; //wont happen cuz inouts are alreaddy validate
        while(fscanf(fp, "%s", buffer) == 1) //fscanf returns the no of cahrs successfully read
        {
            int ind=tolower(buffer[0])-'a';
            if(arr[ind]==NULL) /* case 1 */
            {
                mnode *new=create_mnode(buffer, head->filename);
                arr[ind]=new; //this is important we must update the link here after first insertion 
            }
            else
            {
                /* case 2 the index of the database is not null*/
                //travere main node and check whehter the word exist/not 
                mnode *addrs=match_word(buffer, arr[ind]); //main node only wwe passing 

                if(addrs==NULL) //word does not exist 
                {
                    mnode *temp = arr[ind];

                    while(temp->mlink != NULL)
                    temp = temp->mlink;

                    temp->mlink = create_mnode(buffer, head->filename);
                }
                else
                {
                    //traverse mainnocde and check if the filename in the sublinks matches or not 
                    snode *filename=match_filename(head->filename, addrs); //cuz addrs contains the addrs of the mainnode corresponding to current word 
                    if( filename!=NULL)
                    {
                        /* increment the wordcount in that sublink*/
                        filename->wordcount+=1;

                    }
                    else /* if the file names does not match*/
                    {
                        //ALSO UPDATE THE FILE COUNT IN MAINNODE
                         snode *new = create_snode(head->filename);

                        /* Go to the last subnode */
                        snode *temp = addrs->slink;

                        while(temp->slink != NULL)
                        {
                            temp = temp->slink;
                        }

                        /* Link new subnode */
                        temp->slink = new;

                        /* One more file contains this word */
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
