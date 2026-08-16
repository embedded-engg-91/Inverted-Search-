#include "inverted.h"

void search(mnode *arr[],Slist *head, char *word)
{
    /*first step is to find the key where it woulf be presnet*/
    int key= tolower(word[0])-'a';//this is where the element would be present
    if(arr[key]==NULL)
    {
        printf("The word is not present\n");
        return;
    }
    else
    {
        //key is ont null means has atleasset one mainnode
        mnode *m_temp=arr[key];
        while(m_temp!=NULL) //tarversing the main node
        {
            /* first check whteher it is art of minnode*/
            if(strcmp(m_temp->word, word) ==0) //word match in currebt main
            {
                printf("The word %s is present in %d files\n", word, m_temp->filecount);
                //now we need to peint in which all files and what is the count in each file
                snode *s_temp=m_temp->slink;
                while(s_temp!=NULL)
                {
                    //just print the details like filename -> wordcount
                    printf("%s -> %d", s_temp->filename, s_temp->wordcount);
                    printf("\n");
                    s_temp=s_temp->slink;
                }
                return; //completed the intended 
            }
            m_temp=m_temp->mlink; //see if it did noot match in cuurent mainnide we shift the main node and search in next main node
        }
        if(m_temp==NULL) //come till here means did not match in any mtemp na 
        {
            printf("Word is not present\n");
            return;
        }


    }
}