#include "STD.h"
#include "SDB.h"
#include <stdio.h>
#define MAX_STUDENTS 10

void SDB_choose(u8 choice) //switch case function
{
    switch (choice)
    {
        case 1:
            if (SDB_AddEntry())
            {
                printf("Student added successfully.\n");
            }
            else
            {
                printf("Error: unable to add student.\n");
            }
            break;
        case 2:
            printf("Used size in database: %hhu\n", SDB_GetUsedSize());
            break;
        case 3:
            printf("Enter student ID to read data: ");
            u32 id;
            scanf("%u", &id);
            if (SDB_ReadEntry(id))
            {
                printf("Student data: \n");
            }
            else
            {
                printf("Error: student not found.\n");
            }
            break;
        case 4:
            printf("List of student IDs: \n");
            u8 count;
            u32 list[MAX_STUDENTS];
            SDB_GetList(&count, list);
            for (int i = 0; i < count; i++)
            {
                printf("%u\n", list[i]);
            }
            break;
        case 5:
            printf("Enter student ID to check if it exists: ");
            scanf("%u", &id);
            if (SDB_IsIdExist(id))
            {
                printf("ID exists in database.\n");
            }
            else
            {
                printf("ID does not exist in database.\n");
            }
            break;
        case 6:
            printf("Enter student ID to delete data: ");
            scanf("%u", &id);
            SDB_DeleteEntry(id);
            break;
        case 7:
            if (SDB_IsFull())
            {
                printf("Database is full.\n");
            }
            else
            {
                printf("Database is not full.\n");
            }
            break;
        default:
            printf("Error: invalid choice.\n");
            break;
    }
}
void SDB_APP()
{
    while (true)
    {
        printf("\nEnter 1 to add entry\n");
        printf("Enter 2 to get used size in database\n");
        printf("Enter 3 to read student data\n");
        printf("Enter 4 to get the list of all student IDs\n");
        printf("Enter 5 to check if ID is existed\n");
        printf("Enter 6 to delete student data\n");
        printf("Enter 7 to check if database is full\n");
        printf("Enter 0 to exit\n");

        u8 choice;
        scanf("%hhu", &choice);

        if (choice == 0)
        {
            break;
        }

        SDB_choose(choice);
    }
}
