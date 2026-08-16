#include "inverted.h"

int restored=0;
Status restore(mnode *arr[])
{
    printf("Enter the file you want to restore the data from:\n");
    getchar();
    char filename[100];
    scanf("%[^\n]", filename);
    getchar();
    char *str = strrchr(filename, '.'); // find the dot char from the last
    if (str == NULL)
    {
        printf("Invalid filename. The file extension must end in .txt\nPlease try again\n");
        return FAILURE;
    }
    if ((strcmp(str, ".txt")) != 0) // not zero means need to ask to enter the valid filename
    {
        printf("Invalid filename. The file extension must end in .txt\nPlease try again\n");
        return FAILURE;
    }
    FILE *fp = fopen(filename, "r"); // always open in read mode
    if (fp == NULL)
    {
        return FILE_NOT_FOUND;
    }
    else
    {
        char line[100];
        while (fgets(line, sizeof(line), fp)) /* until we can read a line adn eof is not reached*/
        {
            /*get index*/
            char *tok = strtok(line, "#;");
            int ind = atoi(tok); // the very first element in the line stored was th eindex na

            /*get word */
            char *fword = strtok(NULL, "#;");

            /*create m node */
            mnode *new_node = malloc(sizeof(mnode));
            new_node->mlink = NULL;
            new_node->slink = NULL;
            strcpy(new_node->word, fword);

            /*put mnode in hashtable or append it to existing mnode list */
            if (arr[ind] == NULL) /*if the index in array  turns out to be null then*/
            {
                /* only mnode no subnode attached to it */

                arr[ind] = new_node; // putting mnode in hashtable
            }
            else
            {
                mnode *temp = arr[ind]; // arr if ind is pointing towards on mnode only na
                mnode *prev = NULL;
                while (temp != NULL)
                {
                    prev = temp;
                    temp = temp->mlink;
                }
                prev->mlink = new_node; /* last mnode line with new node*/
            }

            /*get filecount */
            tok = strtok(NULL, "#;");
            ind = atoi(tok);
            // also need to store the filecount into the mainlink
            new_node->filecount = ind;
            for (int i = 0; i < ind; i++)
            {
                char *file = strtok(NULL, "#;");
                snode *new_s = create_snode(file); // create a subnode for that file
                int wc = atoi(strtok(NULL, "#;"));
                strcpy(new_s->filename, file);
                new_s->wordcount = wc;
                // the next slink is null by default

                if (new_node->slink == NULL) /*need to update the sublinks in mainlink na */
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
    restored=1; //so that we can create again after restoring
    db_created=1; //to set it here as well 
    return SUCCESS;
}
