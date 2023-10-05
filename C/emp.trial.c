
#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#include<dos.h>
#include<time.h>


FILE *fp, *ft;

//Welcome function

void welcome(void)

{
    char d[]={"EMPLOYEE RECORD MANAGEMENT SYSTEM"};
    int j;

    gotoxy(0,0);
    printf("\n\n\n\n\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                                                   =");
    printf("\n\t\t\t        =          EMPLOYEE RECORD  MANAGEMENT  SYSTEM      =");
    printf("\n\t\t\t        =                                                   =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
}



//Main program

void program(void)

{
      int choice;
       // opening the file

       fp = fopen("data.txt", "rb+");

       // showing error if file is unable to open.
        if (fp == NULL)
            {
                 printf("\nCannot open file...");
                 exit(1);
            }


    while (1)

        {
    // Clearing console and asking the user for input

    system("cls");

    welcome();

    gotoxy(35,10);
    printf("\n CHOOSE THE OPTIONS");

    gotoxy(35, 12);
    printf("\n 1. ADD RECORD\n");

    gotoxy(35, 14);
    printf("\n 2. DELETE RECORD\n");

    gotoxy(35, 16);
    printf("\n 3. DISPLAY RECORDS\n");

    gotoxy(35, 18);
    printf("\n 4. SEARCH RECORD\n");

    gotoxy(35, 20);
    printf("\n 5. MODIFY RECORD\n");

    gotoxy(35, 22);
    printf("\n 6. EXIT\n");

    gotoxy(35, 24);
    printf("\n ENTER THE OPTIONS : \n");
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

        welcome();

        gotoxy(35,20);
        printf("\n==============================");
        printf("\nTHANK YOU");
        printf("\n==============================\n");
        system("pause");
        exit(0);
        break;

        default:
            printf("\nINVALID CHOICE...\n");
            system("pause");
        }
    }

}


// Password

void Password(void)
{

    char username[20];
    char password[10]={"1234"};
    system("cls");

    char ch,pass[10];
    int i=0,j;

    welcome();
    sleep(1);

    printf("\n\n Enter Username :");
    scanf("%s",username);

    printf("\n\n Enter Password :");

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
        printf("\n\n verifying...");
        for (i=0; i < 1; i++)
        {
            delay(3);
            printf("\n\n LOGIN SUCCESSFUL..");
        }
        for(i=0;i<1;i++)
        {
            delay(2);
            printf("\n\n Press any key to continue...");
        }
        getch();
    }

    else
    {
        printf("\n verifying...");
        for(i=0; i<1;i++)
        {
            delay(3);
            printf("\n\n LOGIN FAILED");
        }
        for(i=0;i<1;i++)
        {
            delay(2);
            printf("\n\nPress any key to try again...");
        }
        Password();
    }
}


void delay(int number_of_seconds)
{


    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    clock_t start_time = clock();

    // looping till required time is not acheived
    while (clock() < start_time + milli_seconds)
        ;
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

// In the start coordinates will be 0, 0
COORD cord = { 0, 0 };

// function to set the coordinates

void gotoxy(int x, int y)
{
    cord.X = x;
    cord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cord);
}



// Function to add the records

void addrecord()
{

    system("cls");
    fseek(fp, 0, SEEK_END);

    char another='y';

    while (another == 'y')
        {
            system("cls");
           printf("\nEnter EMP-ID : ");
           scanf("%d", &e.id);

           printf("\nEnter Name : ");
           fflush(stdin);
           gets(e.name);

            printf("\nEnter Gender : ");
            scanf("%s", &e.gender);

            printf("\nEnter Age : ");
            scanf("%d", &e.age);

            printf("\nEnter Salary : ");
            scanf("%f", &e.salary);


            fwrite(&e, size, 1, fp);
            displayrecord();



            printf("\nWant to add another record (Y/N) : ");
            fflush(stdin);

            scanf("%c", &another);
        }
}


//Function to delete records

void deleterecord()

{
    system("cls");
    int empid,flag=1;
    char another = 'y';

    do

        {
        flag=1;
        system("cls");
        printf("\nEnter employee ID to delete : ");
         fflush(stdin);
        scanf("%d",&empid);

        ft = fopen("temp.txt", "wb");
        rewind(fp);

        while (fread(&e, size,1, fp)== 1)
        {

            if (e.id!=empid)
            {
                  fflush(stdin);
                  fwrite(&e, size, 1, ft);
                  flag=0;
            }

        }


        if(flag==1)
        {
            printf("\nRecord Not Deleted");
        }

        fclose(fp);
        fclose(ft);
        remove("data.txt");
        rename("temp.txt", "data.txt");
        fp = fopen("data.txt", "rb+");

        displayrecord();

        printf("\nWant to delete another record (Y/N) :");
        fflush(stdin);
        another = getche();

    }while (another == 'y');
}



// Function to display the record

void displayrecord()

{
    system("cls");

    welcome();

    // sets pointer to start of the file
    rewind(fp);

    gotoxy(35,12);

    printf("\n==============================================================================================");
    printf("\n ID\t\tNAME\t\t\tGENDER\t\tAGE\t\tSALARY\t\t\n",e.id,e.name,e.gender,e.age,e.salary );
    printf("==============================================================================================\n");

    while (fread(&e, size, 1, fp) == 1)

        printf("\n%2d\t%s\t\t\t%s\t\t%d\t\t%.2f\n",e.id,e.name,e.gender,e.age,e.salary );
        printf("\n\n\n\t");

        system("pause");
        system("cls");
}


// Function to search the records

void searchrecord()

{

system("cls");
int empID,flag=0;
char another = 'y';


do

    {
        flag=0;
        system("cls");

        printf("\nEnter Employee ID to search : ");
        scanf("%d", &empID);

        rewind(fp);

    while (fread(&e, size, 1, fp) == 1)

        {

            if(e.id==empID)
            {
            printf("\nRecord Found");

            flag=1;

            printf("\n==============================================================================================");
            printf("\n ID\t\tNAME\t\t\tGENDER\t\tAGE\t\tSALARY\t\t\n",e.id,e.name,e.gender,e.age,e.salary );
            printf("==============================================================================================\n");
            printf("\n%2d\t%s\t\t\t%s\t\t%d\t\t%.2f\n",e.id,e.name,e.gender,e.age,e.salary );
            fflush(stdin);
            }
        }

        if(flag==0)
        {
            printf("\nRecord not found");
            fflush(stdin);

        }

        printf("\nWant to search another record (Y/N) :");
        fflush(stdin);
        scanf("%c", &another);

    }while (another == 'y');

}

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
                 printf("\nOptions :\n");
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
                 printf("\nChoose the option : ");
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
                    fflush(stdin);
                    gets(e.name);
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

        printf("\nWant to modify another record (Y/N) :");
        fflush(stdin);
        scanf("%c", &another);
    }
}


//Main function

int main()

{

system("Color 0A");

Password();

program();

return 0;

}
