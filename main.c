#include "inverted.h"
int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("\n");
        printf("============================================================\n");
        printf("              INVERTED SEARCH APPLICATION\n");
        printf("============================================================\n");
        printf("\n");
        printf("  No input files were provided.\n");
        printf("  Please provide valid .txt files as command-line arguments.\n");
        printf("\n");
        printf("  Example:\n");
        printf("  ./a.out file1.txt file2.txt file3.txt\n");
        printf("\n");
        return FAILURE;
    }
    printf("\n");
    printf("============================================================\n");
    printf("                 INVERTED SEARCH SYSTEM\n");
    printf("============================================================\n");

    Slist *head = NULL;
    printf("\n[+] Validating the given input files...\n");

    read_validate(argv, &head);
    printf("\n[+] Files loaded successfully.\n\n");

    // print_list(head);
    mnode *arr[27] = {NULL}; // array of STRUCTRE POINTERS is ur database
    int choice;
    do
    {
        printf("\n");
        printf("============================================================\n");
        printf("                     MAIN MENU\n");
        printf("============================================================\n");
        printf("\n");

        printf("   [1]  Create Database\n");
        printf("   [2]  Display Database\n");
        printf("   [3]  Search Database\n");
        printf("   [4]  Save Database\n");
        printf("   [5]  Update Database\n");
        printf("   [6]  Restore Database\n");
        printf("   [7]  Exit\n");

        printf("\n------------------------------------------------------------\n");
        printf("Enter your choice : ");
        if (scanf("%d", &choice) != 1)
        {
            printf("\n");
            printf("[!] Invalid input.\n");
            printf("[!] Please enter a number between 1 and 7.\n");

            /* clear invalid input */
            while (getchar() != '\n')
                ;

            continue;
        }
        printf("\n");
        switch (choice)
        {
            /*Create Database*/

        case 1:
            if (db_created == 0) /* cuz database shall be create donly once */
            {
                if (create_database(arr, head) == SUCCESS) // head is the list containing file names
                    printf("The Database has been successfully created\n");
            }
            else if (restored == 1 && db_created == 1) /* databse was created by restoring */
            {
                if (update(arr, &head) == SUCCESS)
                    printf("Database Updated Successfully for new and valid files!!!\n");
                else
                {
                    printf("You have entered Invalid Files.\n");
                    printf("Please makesure that all your files have \".txt\" at the end and they are not duplicates of previously stored files.\n");
                }
            }
            else
            {
                printf("Database has already been created.\n");
                printf("Cannot create the database twice!!!\n");
            }

            break;

        case 2: /* Display the Database*/

            if (db_created == 1) /* to display first database shall exist */
                display(arr, head);
            else
                printf("Please either create or restore the database first!!!\n");

            break;

        case 3: /* Search Element */
        {
            if (db_created == 1) /*to search also first databse shall exisst*/
            {
                char word[size];
                printf("Enter the word you want to search\n");
                getchar(); 

                scanf("%[^\n]", word);
                search(arr, head, word);
                printf("\n");
            }
            else
            {
                printf("Please either create or restore the database first!!!\n");
            }
        }
        break;

        case 4:                  /*nSave the database into the backup file */
            if (db_created == 1) /*to save also database shall exist first*/
            {
                if (save(arr, head) == SUCCESS)
                    printf("Data Saved Successfully!!!\n");
            }
            else
                printf("Please either create or restore the database first!!!\n");

            break;

        case 5: /* upadte the lsit*/
            if (update(arr, &head) == SUCCESS)
                printf("Database Updated Successfully!!!\n");
            else
            {
                printf("You have entered Invalid Files.\n");
                printf("Please makesure that all your files have \".txt\" at the end and they are not duplicates of previously stored files.\n");
            }
            break;

        case 6: /*restore from  a backup file */
            if (restore(arr) == SUCCESS)
            {
                printf("The database has been restored with the contents of the file.\n");
                printf("\n");
            }
            break;

        case 7:
            printf("Exiting...\n");
            return 0;

        default:
            printf("Invalid Choice Entered\nPlease Select a Valid Choice\n");
            break;
        }
    } while (choice >= 1 && choice <= 7);
    return 0;
}