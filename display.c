#include "inverted.h"

void display(mnode *arr[], Slist *head)
{
    printf("\n");
    printf("+-------+----------------------+-----------+----------------------+-------------------+\n");
    printf("| Index | Word                 | Filecount | Filename             | Wordcount in File |\n");
    printf("+-------+----------------------+-----------+----------------------+-------------------+\n");

    for (int i = 0; i < 27; i++)
    {
        if (arr[i] != NULL)
        {
            mnode *m_temp = arr[i];

            while (m_temp != NULL)
            {
                // to print the main node contents

                if (m_temp->slink != NULL) // means sublink exists
                {
                    snode *s_temp = m_temp->slink;

                    // Print main node details only once
                    printf("| %-5d | %-20s | %-9d |",
                           i, m_temp->word, m_temp->filecount);

                    while (s_temp != NULL)
                    {
                        // pritf the filename first
                        // then print the word count in the files

                        printf(" %-20s | %-17d |\n",
                               s_temp->filename, s_temp->wordcount);

                        s_temp = s_temp->slink;

                        if (s_temp != NULL)
                        {
                            printf("| %-5s | %-20s | %-9s |", "", "", "");
                        }
                    }
                }

                m_temp = m_temp->mlink;
            }
        }
    }

    // Bottom border to  close the table
    printf("+-------+----------------------+-----------+----------------------+-------------------+\n");
}
