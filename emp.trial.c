// C program for the above approach
#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#include<dos.h>
#include<time.h>

// Password

void Password(void)
{

    char username[20]={"BOSS"};
    char password[10]={"1234"};
    system("cls");

    char d[26]="  Encrypted Program  ";
    char ch,pass[10];
    int i=0,j;
 /*
    for(j=0;j<20;j++)
    {
        Sleep(50);
        printf("*");
    }
    for(j=1;j<20;j++)
    {
        Sleep(50);
        printf("%c", d[j]);
    }
    for(j=0;j<20;j++)
    {
        Sleep(50);
        printf("*");
    }
*/
    printf("\n\nEnter Username :");
    scanf("%s",username);
    printf("\n\nEnter Password :");

    while(ch!=13)
    {
        ch=getch();

        if(ch!=13 && ch!=8)
            {
                putch('*');
                pass[i] = ch;
                i++;
            }
    }
    pass[i] = '\0';
    if(strcmp(pass,password)==0)
    {
        printf("\n\nverifying...");
        for (i=0; i < 1; i++)
        {
            delay(3);
            printf("\n\nLOGIN SUCCESSFUL");
        }
        for(i=0;i<1;i++)
        {
            delay(2);
            printf("\n\nPress any key to continue...");
        }
        getch();
    }
    else
    {
        printf("\nverifying...");
        for(i=0; i<1;i++)
        {
            delay(3);
            printf("\n\n[!]LOGIN FAILED");
        }
        for(i=0;i<1;i++)
        {
            delay(2);
            printf("\n\nPress any key to try again...");
        }
        getch();
        Password();
    }
}


void delay(int number_of_seconds)
{


    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Stroing start time
    clock_t start_time = clock();

    // looping till required time is not acheived
    while (clock() < start_time + milli_seconds)
        ;
}

//TIME
void t()
{
    time_t orig_format;
    time(&orig_format);

    printf ("%s",asctime(gmtime(&orig_format)));
}


//WELCOME

void welcome()
{
    char y[28]="  EMPLOYEE MANAGEMENT  ";
    char z[26]="  SYSTEM PROTOTYPE  ";
    char ch,pass[10];
    int i=0,j;
    for(j=0;j<20;j++)
    {
        Sleep(50);
        printf("*");
    }
    for(j=1;j<20;j++)
    {
        Sleep(50);
        printf("%c", y[j]);
    }

    for(j=0;j<20;j++)
    {
        Sleep(50);
        printf("*");
    }
    printf("\n\n");

    for(j=0;j<20;j++)
    {
        Sleep(50);
        printf("*");
    }
    for(j=1;j<20;j++)
    {
        Sleep(50);
        printf("%c", z[j]);
    }

    for(j=0;j<20;j++)
    {
        Sleep(50);
        printf("*");
    }
    printf("\n\n");

}


// Structure of the employee
struct emp
{
    char name[50];
    char gender[10];
    float salary;
    int age;
    int id;
};
struct emp e;

// size of the structure
long int size = sizeof(e);

// In the start coordinates
// w    ill be 0, 0
COORD cord = { 0, 0 };

// function to set the
// coordinates
void gotoxy(int x, int y)
{
    cord.X = x;
    cord.Y = y;
    SetConsoleCursorPosition(
    GetStdHandle(STD_OUTPUT_HANDLE),
    cord);
}



FILE *fp, *ft;

// Function to add the records
void addrecord()
{
    system("cls");
    fseek(fp, 0, SEEK_END);

    char another='y';

    while (another == 'y')
        {
           printf("\nEnter EMP-ID : ");
           scanf("%d", &e.id);

           printf("\nEnter Name : ");
            scanf("%s",&e.name);

            printf("\nEnter Gender : ");
            scanf("%s", &e.gender);

            printf("\nEnter Age : ");
            scanf("%d", &e.age);

            printf("\nEnter Salary : ");
            scanf("%f", &e.salary);


            fwrite(&e, size, 1, fp);

            printf("\nWant to add another record (Y/N) : ");
            fflush(stdin);

            scanf("%c", &another);
        }
}


/*// Function to delete the records
void deleterecord()
{
    system("cls");
    int empid;
    char another = 'y';
    char opt='y';

    while (another == 'y')
        {
            printf("\nEnter employee ID to delete : ");
            scanf("%d", &empid);

            ft = fopen("temp.txt", "wb");
            rewind(fp);

            while (fread(&e, size, 1, fp)== 1)
            {
                if(empid==e.id)
                {
                        fwrite(&e, size, 1, ft);
                }

            }

            fclose(fp);
            fclose(ft);
            remove("data.txt");
            rename("temp.txt", "data.txt");
            fp = fopen("data.txt", "rb+");
            printf("\nRecord deleted successfully");
            break;
            }


            printf("\nWant to delete another record (Y/N) :");
            fflush(stdin);
            scanf("%c", &another);
          }
*/

// Function to delete the records
void deleterecord()
{
    system("cls");
    char empname[50];
    char another = 'y';

do
        {
        printf("\nEnter employee name to delete : ");
        scanf("%s", empname);

        ft = fopen("temp.txt", "wb");
        rewind(fp);

        while (fread(&e, size,1, fp)== 1)
       {
            if (strcmp(e.name,empname) != 0)
            {
                  fwrite(&e, size, 1, ft);
            }
        }

        fclose(fp);
        fclose(ft);
        remove("data.txt");
        rename("temp.txt", "data.txt");
        fp = fopen("data.txt", "rb+");

        printf("\nWant to delete another record (Y/N) :");
        fflush(stdin);
        another = getche();
    }while (another == 'y');
}
// Function to display the record
void displayrecord()
{
    system("cls");

    // sets pointer to start
    // of the file
    rewind(fp);

    printf("\n===============================================================================");
    printf("\nID\tNAME\t\tGENDER\t\tAGE\t\tSALARY\t\t\n",e.id,e.name,e.gender,e.age,e.salary );
    printf("===============================================================================\n");

    while (fread(&e, size, 1, fp) == 1)
        printf("\n%2d    \t%s   \t %s\t\t%d\t\t%.2f\n",e.id,e.name,e.gender,e.age,e.salary );

    printf("\n\n\n\t");
    system("pause");
    system("cls");
}


// Function to search th record
void searchrecord()
{
    system("cls");
    char empname[50];
    char another = 'y';

    while (another == 'y')
        {
        printf("\nEnter employee name to search : ");
        scanf("%s", empname);

        fp = fopen("data.txt", "rb+");
        rewind(fp);

        while (fread(&e, size,1, fp)== 1)
       {
           if (strcmp(e.name,empname) != 0)
           {
               printf("\nRecord Found");
               break;
           }

        }

        printf("\nWant to search another record (Y/N) :");
        fflush(stdin);
        another = getche();
        }
}
//Function to search a record
/*
void searchrecord()
{
system("cls");
int empID;

char another= 'y';


while (another== 'y')
    {

        if(fp==NULL)
            {
                printf("File could not open");
                exit(0);
            }


        printf("\nEnter Employee ID to search : ");
        scanf("%d", &empID);

        rewind(fp);

        while (fread(&e, size, 1, fp) == 1)
        {
                 if(e.id==empID)
                 {
                     printf("\nRecord found");
                     break;
                 }

        }

        fclose(fp);

}

*/
// Function to modify the record
void modifyrecord()
{
system("cls");
int empID;
char another = 'y',op;
int options;

while (another == 'y')
    {
        printf("\nEnter Employee ID to modify : ");
        scanf("%d", &empID);

        rewind(fp);

        // While File is open
        while (fread(&e, size, 1, fp) == 1)
        {

            if(e.id==empID)
            {

do
                {
                system("cls");
                 gotoxy(30, 8);
                 printf("\nChoose :\n");
                 gotoxy(30, 10);
                 printf("\n1. ID No \n");
                 gotoxy(30, 12);
                 printf("\n2. Name \n");
                 gotoxy(30, 14);
                 printf("\n3. Gender  \n");
                 gotoxy(30, 16);
                 printf("\n4. Age \n");
                 gotoxy(30, 18);
                 printf("\n5. Salary \n");
                 gotoxy(30, 22);
                 printf("\nENTER YOUR CHOICE...\n");
                 fflush(stdin);
                scanf("%d", &options);


                 switch(options)
                {
                case 1:
                    printf("\nEnter new EMP-ID :");
                    scanf("%d", &e.id);
                    break;

                case 2:
                    printf("\nEnter new name :");
                    scanf("%s",e.name);
                    break;

                case 3:
                    printf("\nEnter Gender :");
                    scanf("%s",e.gender);
                    break;

                case 4:
                     printf("\nEnter new age :");
                      scanf("%d", &e.age);
                      break;

                case 5:
                    printf("\nEnter new salary :");
                    scanf("%f", &e.salary);
                    break;

                default:
                    printf("\nInvalid choice");
                    break;
                }

              printf("\nDo you want to modify?\n");
              scanf("%s",&op);
              fflush(stdin);
            }while(op=='y');

                fseek(fp, -size, SEEK_CUR);
                fwrite(&e, size, 1, fp);
                break;
            }
        }

      // Ask for modifying another record
        printf("\nWant to modify another record (Y/N) :");
        fflush(stdin);
        scanf("%c", &another);
    }
}

// Driver code
int main()
{

    system("cls");
    system("Color 0A");


    gotoxy(100,0);
    t();

    //welcome();

    system("pause");
/*
    Password();
    getch();
*/
    int choice;

    // opening the file
    fp = fopen("data.txt", "rb+");

    // showing error if file is
    // unable to open.
    if (fp == NULL)
    {
        fp = fopen("data.txt", "wb+");
        if (fp == NULL)
        {
            printf("\nCannot open file...");
            exit(1);
        }
    }

 gotoxy(100,0);
    t();

    while (1) {
    // Clearing console and asking the
    // user for input
    system("cls");

    gotoxy(20, 10);
    printf("\n1. ADD RECORD\n");
    gotoxy(30, 12);
    printf("\n2. DELETE RECORD\n");
    gotoxy(30, 14);
    printf("\n3. DISPLAY RECORDS\n");
    gotoxy(30, 16);
    printf("\n4. SEARCH RECORD\n");
    gotoxy(30, 18);
    printf("\n5. MODIFY RECORD\n");
    gotoxy(30, 20);
    printf("\n6. EXIT\n");
    gotoxy(30, 22);
    printf("\nENTER YOUR CHOICE...\n");
    fflush(stdin);
    scanf("%d", &choice);


    // Switch Case
    switch (choice)
    {
    case 1:

    // Add the records
    addrecord();
    break;

    case 2:

    // Delete the records
    deleterecord();
    break;

    case 3:

    // Display the records
    displayrecord();
    break;

    case 4:

    //Search the records
    searchrecord();
    break;

    case 5:

    // Modify the records
    modifyrecord();
    break;

    case 6:
    fclose(fp);
    system("cls");
    gotoxy(30,20);
    printf("\n==============================");
    printf("\nTHANK YOU. SEE YOU NEXT TIME");
    printf("\n==============================\n");
    system("pause");
    exit(0);
    break;

    default:
    printf("\nINVALID CHOICE...\n");
    system("pause");
    }
    }

return 0;

}
