#include "inverted.h"

Status save(mnode *arr[], Slist *head)
{
    
    char filename[100]; 
    printf("Enter the filename you want backup in: \n");
    getchar(); 
    scanf("%[^\n]",filename);
    char *str=strrchr(filename, '.'); 
    if(str==NULL)
    {
        printf("Invalid filename. The file extension must end in .txt\nPlease try again\n");
        return FAILURE;
    }
    if((strcmp(str, ".txt")) != 0) 
    {
        printf("Invalid filename. The file extension must end in .txt\nPlease try again\n");
        return FAILURE;

    }
    
    FILE *fp = fopen(filename, "w"); 
    
    if(fp!=NULL)
    {
    for (int i = 0; i < 27; i++)
    {
        if (arr[i] != NULL) 
        {
            mnode *m_temp = arr[i];
            fprintf(fp, "#%d;", i); 

            while (m_temp != NULL)
            {
                
                fprintf(fp, "%s;", m_temp->word); 
                fprintf(fp, "%d;", m_temp->filecount); 
                
                snode *s_temp = m_temp->slink;
                while (s_temp != NULL)
                {
                    

                    fprintf(fp, "%s;", s_temp->filename);  
                    fprintf(fp, "%d;", s_temp->wordcount); 
                    s_temp = s_temp->slink;
                    
                }
                m_temp=m_temp->mlink; 
            }
            fprintf(fp,"#"); 
            fprintf(fp,"\n"); 
        }
    }
}

    fclose(fp);
    return SUCCESS;
}
