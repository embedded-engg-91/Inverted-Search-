#include "inverted.h"

Status save(mnode *arr[], Slist *head)
{
    /*take the filename fromt the user and store in that file only*/
    char filename[100]; //the user file will be store here 
    printf("Enter the filename you want backup in: \n");
    getchar(); //skip the newline 
    scanf("%[^\n]",filename);
    char *str=strrchr(filename, '.'); //find the dot char from the last
    if(str==NULL)
    {
        printf("Invalid filename. The file extension must end in .txt\nPlease try again\n");
        return FAILURE;
    }
    if((strcmp(str, ".txt")) != 0) //not zero means need to ask to enter the valid filename
    {
        printf("Invalid filename. The file extension must end in .txt\nPlease try again\n");
        return FAILURE;

    }
    /*
    Format to save is #index;word;filecount;filename;worcount_in_that_file;#
    */
    FILE *fp = fopen(filename, "w"); 
    //printf("File openeed Suceessfully\n");
    if(fp!=NULL)
    {
    for (int i = 0; i < 27; i++)
    {
        if (arr[i] != NULL) // if it's null no need to write that
        {
            mnode *m_temp = arr[i];
            fprintf(fp, "#%d;", i); //index will be printed only first time // with  this sotred the #index;

            while (m_temp != NULL)
            {
                //printf("Writing mainnode deatials onto the file\n");
                fprintf(fp, "%s;", m_temp->word); //store the word
                fprintf(fp, "%d;", m_temp->filecount); // store the filecount;
                // each mainnode has atleast one subnode
                snode *s_temp = m_temp->slink;
                while (s_temp != NULL)
                {
                    //printf("Writing subnode deatials onto the file\n");

                    fprintf(fp, "%s;", s_temp->filename);  // prints the filename
                    fprintf(fp, "%d;", s_temp->wordcount); // printd the wordcount inside that file
                    s_temp = s_temp->slink;
                    
                }
                m_temp=m_temp->mlink; //shift the main node until reaches null
            }
            fprintf(fp,"#"); //again at the end we need to print the # na 
            fprintf(fp,"\n"); //the newline aalso want
        }
    }
}

    fclose(fp);
    return SUCCESS;
}
