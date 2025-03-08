#include "STD.h"
#include "SDB.h"
#include <stdio.h>

#define MAX_STUDENTS 10

student students[MAX_STUDENTS];
u8 num_students = 0;


bool SDB_IsFull() {  //func. that compare between num. of students and max. num. of students i created in the prog.
    if (num_students == MAX_STUDENTS) {
        return true;
    }
    else{
        return false;
    }
}


u8 SDB_GetUsedSize() //function that return num. of students i entered
{
    return num_students;
}

/*function at first it check if my data base is full or not if its full the program display a mess. say the data base if full 
if not the user able to insert the data he wants
and after the user entered the data the number of student increase by one until it reach the max. value then he cant enter any other data

*/
bool SDB_AddEntry() 

{
    if (SDB_IsFull())
    {
        printf("Error: database is full.\n");
        return false;
    }

    printf("Enter student ID: ");
    scanf("%u", &students[num_students].Student_ID);

    printf("Enter student year: ");
    scanf("%u", &students[num_students].Student_year);

    printf("Enter Course 1 ID: ");
    scanf("%u", &students[num_students].Course1_ID);

    printf("Enter Course 1 grade: ");
    scanf("%u", &students[num_students].Course1_grade);

    printf("Enter Course 2 ID: ");
    scanf("%u", &students[num_students].Course2_ID);

    printf("Enter Course 2 grade: ");
    scanf("%u", &students[num_students].Course2_grade);

    printf("Enter Course 3 ID: ");
    scanf("%u", &students[num_students].Course3_ID);

    printf("Enter Course 3 grade: ");
    scanf("%u", &students[num_students].Course3_grade);

    num_students++;

    return true;
}
/*
when user enter a ID this loop function search for the ID in data base 
until it find it and then delete it and decrease the number of data base by one
*/
void SDB_DeleteEntry(u32 id)
{
    for (int i = 0; i < num_students; i++)
    {
        if (students[i].Student_ID == id)
        {
            for (int j = i; j < num_students - 1; j++)
            {
                students[j] = students[j + 1];
            }
            num_students--;
            break;
        }
    }
}
/*
the loop in this function search for the ID and then display the data of this ID 
*/
bool SDB_ReadEntry(u32 id)
{
    for (int i = 0; i < num_students; i++)
    {
        if (students[i].Student_ID == id)
        {
            printf("Student ID: %u\n", students[i].Student_ID);
            printf("Student year: %u\n", students[i].Student_year);
            printf("Course 1 ID: %u\n", students[i].Course1_ID);
            printf("Course 1 grade: %u\n", students[i].Course1_grade);
            printf("Course 2 ID: %u\n", students[i].Course2_ID);
            printf("Course 2 grade: %u\n", students[i].Course2_grade);
            printf("Course 3 ID: %u\n", students[i].Course3_ID);
            printf("Course 3 grade: %u\n", students[i].Course3_grade);
            return true;
        }
    }
    return false;
}

/*
 this function pointer point to the adrress of the first element of num of students

*/
void SDB_GetList(u8 *count, u32 *list)
{
    *count = num_students;
    for (int i = 0; i < num_students; i++)
    {
        list[i] = students[i].Student_ID;
    }
}
/*
the loop in this function search for the ID if the ID has been found it return true else return false
*/
bool SDB_IsIdExist(u32 id)
{
    for (int i = 0; i < num_students; i++)
    {
        if (students[i].Student_ID == id)
        {
            return true;
        }
    }
    return false;
}