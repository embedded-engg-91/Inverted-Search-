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

    /* to the old last node */
    Slist *old_tail = *head;

    if (old_tail != NULL)
    {
        while (old_tail->link != NULL)
            old_tail = old_tail->link;
    }

    /* read_validate adds valid new files to head */
    if (read_validate(newfiles, head) != SUCCESS)
    {
        for (int i = 0; i < newfc; i++)
            free(newfiles[i]);

        return FAILURE;
    }

    /* Find the beginning of the newly added portion*/
    Slist *newhead;

    if (old_tail == NULL)
    {
        /*  no old files means*/
        newhead = *head;
    }
    else
    {
        newhead = old_tail->link;
    }

    /* Temporarily detach the new files from the old list */
    if (old_tail != NULL)
        old_tail->link = NULL;

    /* to process only the newly added files*/
    if (newhead != NULL)
    {
        if (create_database(arr, newhead) != SUCCESS)
        {
            /* reconnect before returning */
            if (old_tail != NULL)
                old_tail->link = newhead;

            for (int i = 0; i < newfc; i++)
                free(newfiles[i]);

            return FAILURE;
        }
    }

    /* Reconnect the new files to the original list*/
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
