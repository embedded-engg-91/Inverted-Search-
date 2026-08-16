#include "inverted.h"

FILE *exist_and_non_empty(char *argv)
{
    FILE *fptr = fopen(argv, "r");
    if (fptr == NULL)
        return NULL;
    char c;
    if ((c = fgetc(fptr)) == EOF)
        return NULL;
    fclose(fptr);
        return fptr;
}

Status read_validate(char **argv, Slist **head)
{
    
    int count = 0;
    for (int i = 0; argv[i] != NULL; i++)
    {
        
        char *temp = NULL;
        if ((temp = strrchr(argv[i], '.')) != NULL) 
        {
            if ((strcmp(temp, ".txt")) == 0) 
            {
                
                FILE *fp;
                if ((fp = exist_and_non_empty(argv[i])) != NULL &&
                    find_node(*head, argv[i]) == SUCCESS)

                {
                    insert_at_last(head, argv[i]);
                    count++;
                }
            }
        }
    }
    
    return SUCCESS; 
}
