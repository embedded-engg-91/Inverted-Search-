#include "inverted.h"

void search(mnode *arr[],Slist *head, char *word)
{
    
    int key= tolower(word[0])-'a';
    if(arr[key]==NULL)
    {
        printf("The word is not present\n");
        return;
    }
    else
    {
        
        mnode *m_temp=arr[key];
        while(m_temp!=NULL) 
        {
            
            if(strcmp(m_temp->word, word) ==0) 
            {
                printf("The word %s is present in %d files\n", word, m_temp->filecount);
                
                snode *s_temp=m_temp->slink;
                while(s_temp!=NULL)
                {
                    
                    printf("%s -> %d", s_temp->filename, s_temp->wordcount);
                    printf("\n");
                    s_temp=s_temp->slink;
                }
                return; 
            }
            m_temp=m_temp->mlink; 
        }
        if(m_temp==NULL) 
        {
            printf("Word is not present\n");
            return;
        }


    }
}
