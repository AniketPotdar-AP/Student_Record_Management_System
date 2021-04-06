/*                       This Program will help to Add student Data 
----------------------------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

void menu();
void add();
void view();
void search();
void modify();
void deleterec();

struct student
{
    char name[25];
    char mobile[10];
    int rollno;
    char course[20];
    char branch[20];
};

int main()
{
    printf("\n\n\t\t\t\t   <--:Student Record Management System:--> \n");
    printf("\n\t\t\t\t\t Press any key to continue. ");
    getch();
    menu();
    return 0;
}

/*------------------- It will create a Menu which will show function to do -------------*/

void menu()
{
    int choice;
    system("cls");
    printf("\n<--:MENU:--> \n\n");
    printf("Enter appropriate number to perform following task.\n\n");
    printf("1 : Add Record.\n");
    printf("2 : View Record.\n");
    printf("3 : Search Record.\n");
    printf("4 : Modify Record.\n");
    printf("5 : Delete.\n");
    printf("6 : Exit.\n\n");
    printf("Enter your choice :-  ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        add();
        break;

    case 2:
        view();
        break;
    case 3:
        search();
        break;
    case 4:
        modify();
        break;
    case 5:
        deleterec();
        break;
    case 6:
        exit(1);
        break;
    default:
        printf("\nInvalid Choice.");
    }
}

/*--------------------------------- It will add the student data -------------------------------*/

void add()
{
    FILE *fp;
    struct student std;
    char another = 'y';
    system("cls");
    fp = fopen("record.txt", "ab");
    if (fp == NULL)
    {
        printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
    while (another == 'y')
    {
        printf("<--:ADD RECORD:-->");
        printf("Enter details of student.\n\n");
        printf("Enter Name : ");
        gets(std.name);
        printf("Enter Mobile Number : ");
        gets(std.mobile);
        printf("Enter Roll No : ");
        scanf("%d", &std.rollno);
        fflush(stdin);
        printf("Enter Course : ");
        gets(std.course);
        printf("Enter Branch : ");
        gets(std.branch);
        fwrite(&std, sizeof(std), 1, fp);
        printf("Want to add of another record? Then press 'y' else 'n'.");
        fflush(stdin);
        another = getch();
        system("cls");
        fflush(stdin);
    }
    fclose(fp);
    printf("Press any key to continue.");
    getch();
    menu();
}

/*---------------------- We can see all student data here which we have added ------------------*/

void view()
{
    FILE *fp;
    int i = 1, j;
    struct student std;
    system("cls");
    printf("<--:VIEW RECORD:--> \n\n");
    printf("S.No \tName of Student         \tMobile No \tRoll No \tCourse \t\tBranch \t\n");
    printf("--------------------------------------------------------------------------------------------------- \n");
    fp = fopen("record.txt", "rb+");
    if (fp == NULL)
    {
        printf("Error opening file.");
        exit(1);
    }
    j = 8;
    while (fread(&std, sizeof(std), 1, fp) == 1)
    {

        printf("%-8d%-31s%-19s%-16d%-17s%-12s \n", i, std.name, std.mobile, std.rollno, std.course, std.branch);
        i++;
        j++;
    }
    fclose(fp);
    printf("\n Press any key to continue.");
    getch();
    menu();
}

/*------------------------------- It will search the Student data --------------------------------*/

void search()
{
    FILE *fp;
    struct student std;
    char stname[25];
    char stcourse[20];
    char stbranch[20];
    system("cls");
    printf("<--:SEARCH RECORD:-->");
    printf("\n\nEnter name of student : ");
    fflush(stdin);
    gets(stname);
    printf("Enter Course of student : ");
    fflush(stdin);
    gets(stcourse);
    printf("Enter Branch of student : ");
    fflush(stdin);
    gets(stbranch);
    fp = fopen("record.txt", "rb+");
    if (fp == NULL)
    {
        printf("Error opening file");
        exit(1);
    }
    while (fread(&std, sizeof(std), 1, fp) == 1)
    {
        if (strcmp(stname, std.name) == 0)
        {
            if (strcmp(stcourse, std.course) == 0)
            {
                if (strcmp(stbranch, std.branch) == 0)
                {
                    printf("\nName : %s\n", std.name);
                    printf("Mobile Number : %s\n", std.mobile);
                    printf("Roll No : %d\n", std.rollno);
                    printf("Course : %s\n", std.course);
                    printf("Branch : %s\n", std.branch);
                }
            }
        }
    }
    fclose(fp);
    printf("Press any key to continue.");
    getch();
    menu();
}

/*---------------------------------- It will Modify the sudent data ----------------------------*/

void modify()
{
    char stname[25];
    FILE *fp;
    struct student std;
    system("cls");
    printf("<--:MODIFY RECORD:-->");
    printf("\nEnter name of student to modify: ");
    fflush(stdin);
    gets(stname);
    fp = fopen("record.txt", "rb+");
    if (fp == NULL)
    {
        printf("Error opening file");
        exit(1);
    }
    rewind(fp);
    fflush(stdin);
    while (fread(&std, sizeof(std), 1, fp) == 1)
    {
        if (strcmp(stname, std.name) == 0)
        {
            printf("\nEnter name: ");
            gets(std.name);
            printf("Enter mobile number : ");
            gets(std.mobile);
            printf("Enter roll no : ");
            scanf("%d", &std.rollno);
            printf("Enter Course : ");
            fflush(stdin);
            gets(std.course);
            printf("Enter Branch : ");
            fflush(stdin);
            gets(std.branch);
            fseek(fp, -sizeof(std), SEEK_CUR);
            fwrite(&std, sizeof(std), 1, fp);
            break;
        }
    }
    fclose(fp);
    printf("Press any key to continue.");
    getch();
    menu();
}

/*---------------------------------- It will Delete the sudent data ----------------------------*/

void deleterec()
{
    char stname[20];
    char stcourse[20];
    char stbranch[20];
    FILE *fp, *ft;
    struct student std;
    system("cls");
    printf("<--:DELETE RECORD:-->\n\n");
    printf("Enter name of student to delete record : ");
    fflush(stdin);
    gets(stname);
    // printf("Enter Course of student to delete record : ");
    // fflush(stdin);
    // gets(stcourse);
    // printf("Enter Branch of student to delete record : ");
    // fflush(stdin);
    // gets(stbranch);
    fp = fopen("record.txt", "rb+");
    if (fp == NULL)
    {
        printf("Error opening file");
        exit(1);
    }
    ft = fopen("temp.txt", "wb+");
    if (ft == NULL)
    {
        printf("Error opening file");
        exit(1);
    }
    while (fread(&std, sizeof(std), 1, fp) == 1)
    {
        if (strcmp(stname, std.name) != 0)
        {
            // if (strcmp(stcourse, std.course) != 0)
            // {
            //     if (strcmp(stbranch, std.branch) != 0)
            //     {
                    fwrite(&std, sizeof(std), 1, ft);
                // }
            // }
        }
    }
    fclose(fp);
    fclose(ft);
    remove("record.txt");
    rename("temp.txt", "record.txt");
    printf("Press any key to continue.");
    getch();
    menu();
}