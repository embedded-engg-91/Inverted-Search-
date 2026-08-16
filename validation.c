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
    /*Validations
    1. The File is ".txt"
    2. The File is Existing
    3. The File isnt Empty
    4. The File isnt repaeted in the List of file(SLL)
    */
    int count = 0;
    for (int i = 0; argv[i] != NULL; i++)
    {
        // toknow the file is txt we do strrchr then strcmp
        char *temp = NULL;
        if ((temp = strrchr(argv[i], '.')) != NULL) // means dot i s presernt
        {
            if ((strcmp(temp, ".txt")) == 0) // means .txt is at the end
            {
                // now the file name has .txt means the file is valid
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
