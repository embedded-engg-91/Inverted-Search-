#include "inverted.h"

Status update(mnode *arr[], Slist **head)
{
    int newfc = 0;

    printf("Enter the number of files you wish to add: \n");
    scanf("%d", &newfc);
    getchar();

    if (newfc <= 0)
        return FAILURE;

    char *newfiles[newfc + 1];

    for (int i = 0; i < newfc; i++)
    {
        newfiles[i] = malloc(size);

        if (newfiles[i] == NULL)
        {
            for (int j = 0; j < i; j++)
                free(newfiles[j]);

            return FAILURE;
        }
    }

    printf("Enter your file names one after the other:\n");

    for (int i = 0; i < newfc; i++)
    {
        scanf("%[^\n]", newfiles[i]);
        getchar();
    }

    newfiles[newfc] = NULL;

    
    Slist *old_tail = *head;

    if (old_tail != NULL)
    {
        while (old_tail->link != NULL)
            old_tail = old_tail->link;
    }

    
    if (read_validate(newfiles, head) != SUCCESS)
    {
        for (int i = 0; i < newfc; i++)
            free(newfiles[i]);

        return FAILURE;
    }

    
    Slist *newhead;

    if (old_tail == NULL)
    {
        
        newhead = *head;
    }
    else
    {
        newhead = old_tail->link;
    }

    
    if (old_tail != NULL)
        old_tail->link = NULL;

    
    if (newhead != NULL)
    {
        if (create_database(arr, newhead) != SUCCESS)
        {
            
            if (old_tail != NULL)
                old_tail->link = newhead;

            for (int i = 0; i < newfc; i++)
                free(newfiles[i]);

            return FAILURE;
        }
    }

    
    if (old_tail != NULL)
    {
        old_tail->link = newhead;
    }
    else
    {
        *head = newhead;
    }

    for (int i = 0; i < newfc; i++)
        free(newfiles[i]);

    return SUCCESS;
}
