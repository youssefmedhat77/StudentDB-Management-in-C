#ifndef SDB_H
#define SDB_H


typedef struct SimpleDb
{
    u32 Student_ID;
    u32 Student_year;
    u32 Course1_ID;
    u32 Course1_grade;
    u32 Course2_ID;
    u32 Course2_grade;
    u32 Course3_ID;
    u32 Course3_grade;
} student;

bool SDB_IsFull();
u8 SDB_GetUsedSize();
bool SDB_AddEntry();
void SDB_DeleteEntry(u32 id);
bool SDB_ReadEntry(u32 id);
void SDB_GetList(u8 *count, u32 *list);
bool SDB_IsIdExist(u32 id);
void SDB_choose(u8 choice);
void SDB_APP();




#endif