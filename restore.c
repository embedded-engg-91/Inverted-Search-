#include "inverted.h"

int restored=0;
Status restore(mnode *arr[])
{
    printf("Enter the file you want to restore the data from:\n");
    getchar();
    char filename[100];
    scanf("%[^\n]", filename);
    getchar();
    char *str = strrchr(filename, '.'); 
    if (str == NULL)
    {
        printf("Invalid filename. The file extension must end in .txt\nPlease try again\n");
        return FAILURE;
    }
    if ((strcmp(str, ".txt")) != 0) 
    {
        printf("Invalid filename. The file extension must end in .txt\nPlease try again\n");
        return FAILURE;
    }
    FILE *fp = fopen(filename, "r"); 
    if (fp == NULL)
    {
        return FILE_NOT_FOUND;
    }
    else
    {
        char line[100];
        while (fgets(line, sizeof(line), fp)) 
        {
            
            char *tok = strtok(line, "#;");
            int ind = atoi(tok); 

            
            char *fword = strtok(NULL, "#;");

            
            mnode *new_node = malloc(sizeof(mnode));
            new_node->mlink = NULL;
            new_node->slink = NULL;
            strcpy(new_node->word, fword);

            
            if (arr[ind] == NULL) 
            {
                

                arr[ind] = new_node; 
            }
            else
            {
                mnode *temp = arr[ind]; 
                mnode *prev = NULL;
                while (temp != NULL)
                {
                    prev = temp;
                    temp = temp->mlink;
                }
                prev->mlink = new_node; 
            }

            
            tok = strtok(NULL, "#;");
            ind = atoi(tok);
            
            new_node->filecount = ind;
            for (int i = 0; i < ind; i++)
            {
                char *file = strtok(NULL, "#;");
                snode *new_s = create_snode(file); 
                int wc = atoi(strtok(NULL, "#;"));
                strcpy(new_s->filename, file);
                new_s->wordcount = wc;
                

                if (new_node->slink == NULL) 
                {
                    new_node->slink = new_s;
                }
                else
                {
                    snode *temp = new_node->slink;

                    while (temp->slink != NULL)
                    {
                        temp = temp->slink;
                    }

                    temp->slink = new_s;
                }
            }
        }
    }
    restored=1; 
    db_created=1; 
    return SUCCESS;
}
