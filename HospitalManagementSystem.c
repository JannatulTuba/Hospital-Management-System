#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
#include<time.h>
 void module1(void);//function prototype for entering patient detail
 void module2(void);//function prototype for viewing patient detail
 void module3(void);//function prototype for doctors enquiry
 void module4(void);//function prototype for getting details about software
 void module5(void);//function prototype for taking feedback
 void module6(void);//function prototype for quitting the programme
 void module7();//function prototype for log in as administrator
 void exit();//exit prototype for exit function
 void userchk(void);//function prototype for giving privilages between user and administrator
 char privilage='\0';
 void menu(void);//function prototype for calling the main menu
struct patient
{
char p_id[10];
char name[20];
char gender[10];
char age[4];
char address[50];
char diagnosis[200];
char bloodgroup[10];
char test[200];
};
void main()
{
 printf("Welcome To MEDINOVA MEDICAL SERVICES");
 printf("\n ***** Medinova Hospital Management Simulation ***** ");
 userchk();//module checks the user and administrator
}
void userchk()//module that differentiates user & administrator
 {
char passuser[]={"NITIKA"};// password for user
char passadmin[]={"TUBA"};//password for administrator
char s1[15];//entered password of administrator
int i=0;
char ch='\0';
char s2[15];//entered password of user
int us_choice;// choice between user and administrator
int us_check; // varible that compare integers
printf("\nenter choice\n 1 - administrator \n 2 - user \n");
scanf("%d",&us_choice);
if(us_choice==1)
{
printf(" enter password\n");
while(ch!=13)
{
ch=getch();
s1[i++]=ch;
printf("*");
}
s1[i-1]='\0';
us_check = stricmp(passadmin,s1); // printf("us_check=%d",us_check);
if(us_check==0)
{
printf("\nWelcome to Medinova Administrator");
privilage = 'a';
menu();
//return;
}
else
{
printf("\nentered password is wrong\n");
printf("\nPlease Choose the correct User Mode \nEnter correct password");
userchk();
}
}
if(us_choice==2)
{
printf("enter password\n");
while(ch!=13)
{
ch=getch();
s2[i++]=ch;
printf("*");
}
s2[i-1]='\0';
us_check = stricmp(passuser,s2);
 // printf("%d",us_check);
if(us_check==0)
{
printf("welcome to  user");
privilage = 'u';
menu();
}
else
{
printf("entered password is wrong");
}
}
}
void menu()
 {
 int choice;//choice for main menu
 int mm;// choice for the goto tag

 printf("welcome to");
 printf("\n ***** Medinova Hospital Management Simulation ***** ");
 //main menu starts from here
 printf("\n ***********Medinova Hospital Management Software***********");
 printf(" \n1 - Entering patient detail 2 - View patient detail ");
 printf(" \n3 - Doctors enquiry 4 - Details about software ");
 printf(" \n5 - Feedback 6 - Exit ");
 printf(" \n7- Change current User Mode");
 printf(" \n");
 n1:
 printf("\n enter choice");
 scanf("%d",&choice);
 switch(choice)
 {
case 1 :
 printf("enter patient detail");
 module1();//module for enterting patient detail
 printf(" \nwould you like to goto the main menu");
 printf(" \n 1 - yes \t\t 0 - no\n\t");
 scanf("%d",&mm);
 if(mm==1)
 {
menu();
}
else
{
 break;
 }
case 2 :
 printf(" view patient detail");
 module2();//module for veiwing existing patient detail
 printf(" \nwould you like to goto the main menu");
 printf(" \n 1 - yes \t\t 0 - no\n\t");
 scanf("%d",&mm);
 if(mm==1)
 {
menu();
}
else
{
 break;
 }case 3 :
 printf("Welcome to doctor's enquiry section");
 module3();//module for doctors enquiry section
 printf(" \nwould you like to goto the main menu");
 printf(" \n 1 - yes \t\t 0 - no\n\t");
 scanf("%d%d",&mm);
 if(mm==1)
 {
menu();
}
else
{
 break;
 }
case 4:
 printf("details about software");
 module4();// module for details about s/w n programmer
 printf(" \nwould you like to goto the main menu");
 printf(" \n 1 - yes \t\t 0 - no\n\t");
 scanf("%d",&mm);
 if(mm==1)
 {
menu();
}
else
{
 break;
 }
case 5 :
 printf(" welcome to feedback section:");
 module5();// module for feedback
 printf(" \nwould you like to goto the main menu");
 printf(" \n 1 - yes \t\t 0 - no\n\t");
 scanf("%d",&mm);
 if(mm==1)
 {
menu();
}
else
{
 break;
 }
case 6 :
 printf("you are about to exit");
 module6(); // module for exit
  printf(" \nwould you like to goto the main menu");
 printf(" \n 1 - yes \t\t 0 - no\n\t");
 scanf("%d",&mm);
 if(mm==1)
 {
menu();
}
else
{
exit();
// break;
}
case 7 :
printf("case 7");
module7();
printf(" \nwould you like to goto the main menu");
printf(" \n 1 - yes \t\t 0 - no\n\t");
scanf("%d",&mm);
if(mm==1)
 {
 menu();
}
 else
 {
exit();
// break;
}
default :
 printf("not valid");
 printf(" \nwould you like to goto the main menu");
 printf(" \n 1 - yes \t\t 0 - no\n\t");
 scanf("%d",&mm);
 if(mm==1)
 {
menu();
}
else
{
break;
}
}
}
void module1()//module for enterting patient detail
{
FILE *source;
char another='y';
struct patient detail;
source=fopen("pat_det.data","ab");
while(another=='y' || another=='Y')
{
printf("\n Enter Details of a patient --\n");
printf("\n Patient ID : ");
fflush(stdin);
gets(detail.p_id);
printf("\n Name : ");
fflush(stdin);
gets(detail.name);
printf("\n gender : ");
fflush(stdin);
gets(detail.gender);
printf("\n Age : ");
gets(detail.age);
printf("\n Bloodgroup : ");
fflush(stdin);
gets(detail.bloodgroup);
printf("\n Address : ");
fflush(stdin);
gets(detail.address);
printf("\n Diagnosis : ");
fflush(stdin);
gets(detail.diagnosis);
printf("\n Test : ");
fflush(stdin);
gets(detail.test);
if(source==NULL)
{
printf("\n Can not open file.");
}
else
{
// fprintf(source,"%s%s%s%s",detail->name,detail->p_id,detail->age,detail->gender);
fwrite(&detail,sizeof(detail),1,source);
fclose(source);
}
printf("\n Add another record (y/n) :");
another=getch();
}
}
void module2() //module for veiwing existing patient detail
{
FILE *target;
struct patient detail;
char ch;
//detail=(struct patient *)malloc(sizeof(struct patient));
target=fopen("pat_det.dat","rb");
if(target==NULL)
{
printf("\n Can not open file");
}
else
{
while(fread(&detail,sizeof(struct patient),1,target)==1)
{
printf("\n%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",detail.p_id,detail.name,detail.address,detail.bloodgroup,detail.diagnosis,detail.gender,detail.test,detail.age);
fseek(target,sizeof(struct patient),SEEK_CUR);
}
  ch=fgetc(target);
while(ch!=EOF)
{
printf("%c",ch);
ch=fgetc(target);
}
fclose(target);
}
}
void module3()//module for doctors enquiry section
 {
 int choice1;
 printf("\n choose Infectious Diseases and NoN infectious Diseases");
 printf("\n 1 - HIV AIDS reactive \t 2 - Tuberculosis");
 printf("\n 2 - Pulmonary TB by chest \t4 - eye specialist ");
 printf("\n 5 - Known Leptosy Patient  \t 6 - Hepatitis B Surface Antigen Positive And HCV positive ");
 printf("\n 7- Chronic Renal Failure\t8-Choronic Hepatic Failure");
printf("\n 11- Congestive Heart Failure\t12 - Uncontrolled Hypertension");
printf("\n 13 -Known Case Cancer");
 printf("\n enter field for which you want to see consultation time ");
 scanf("%d",&choice1);
if(choice1==1)

 {
 printf("the timing are 8:00 am");
 }
 else if(choice1==2)
 {
 printf("the timings are 10:00 am");
 }
else if(choice1==3)
 {
 printf("the timings are 11:00");
 }
 else if(choice1==4)
 {
 printf("the timings are 11:00");
 }
 else if(choice1==5)
 {
 printf("the timings are 12:00");
  }
 else if(choice1==6)
 {
 printf("the timings are 12:00");
 }
else if(choice1==7)
{
    printf("the timing are 2:30 pm");

}else if(choice1==8)
{
printf("the timing are 3:00 pm");
}else if(choice1==9)
{
    printf("the timing are 4:00 pm");

}else if(choice1==10)
{
    printf("the timing are 5:00 pm");

}else if(choice1==11)
{
    printf("the timing are 6:00 pm");

}else if(choice1==12)
{
printf("the timing are 7:00 pm");
}else if(choice1==13)
{
    printf("the timing are 9:00 pm");
}


 else{
 printf("invalid choice please retype again");
 }
 }
void module4()// module for details about s/w n programmer
 {
 printf("\n*****this section contains Medinova Medical Services Company contact details*****");
 printf("\n hospital simulation software");
 printf("\n Company :-MEDINOVA \t\t \t Programmer :- AFIA FARIHA && JANATUL TUBA");
 printf("\n Front End :- 'c' \t\t \t Back End :- MS word,files");
 printf("\n Contact Address:-Medinova Medical Services Ltd\n \t\tDhanmondi \n\t\t 1209");
 printf("\n Contact No.:-\t 01796222222,01750557744");
 printf("\n Email : info @medinovamedicalbd.com");
 printf("\n HOPE YOU LIKE IT");
 }
 void module5()// module for feedback
 {
char feed_check;
FILE *feedback;
char feed[2000];//limit for feedback
printf(" \n You are welcomed for Feedback Section ");
printf(" \n Let us describe you the Requisites for giving Feedback ");
printf(" \n while the System is preparing itself for feedback ");
printf(" \n You are required to write your feedback regarding in not more than ");
printf(" \n 2000 characters,alphanumeic allowed and an space has its own value.");
 // printf("\n\n\n\n\n\n Now give your Feedback ");

 if(privilage=='u')
{ printf("\n\n\n\n\n\n\n\n Now give your feedback");
feedback =fopen("feed.txt","g+");
 if(feedback==NULL)
{
puts("cannot open file");
return;
}
fflush(stdin);
gets(feed);
fprintf(feedback,"%s",feed);
fclose(feedback);
}
 if(privilage=='a')
{
 printf("\n welcome Administrator");
 printf("\n Please select a task to do");
printf("\n a - to read feedback file \t b - append feedback for futurevisit\n\n\n\n\n\t");
 fflush(stdin);
 feed_check = getchar();
 if(feed_check=='a')
{
FILE *fopen(), *fp;
int c , linecount;
char filename[40], reply[40];

printf("Enter file name: ");
fflush(stdin);
gets( filename );
fp = fopen( filename, "r" ); /* open for reading */
if ( fp == NULL ) /* check does file exist etc */
{
printf("Cannot open %s for reading \n",
filename );
exit(); /* terminate program */
 }
linecount = 1 ;
reply[0] ='\0' ;
c = getc( fp ) ; /* Read 1st character if any */
while ( c != EOF && reply[0] != 'Q' && reply[0] !=
'q')
{
putchar( c ) ; /*
Display character */
if ( c == '\n' )linecount = linecount+ 1 ;
if ( linecount == 20 )
{
linecount = 1 ;
printf("[PressReturn to continue, Q to quit]");
gets( reply ) ;
}
c = getc ( fp );
}
fclose( fp );
 }
 if(feed_check=='b')
 {
feedback =fopen("feed.txt","a+");
 if(feedback==NULL)
{
puts("cannot open file");
return;
}
 fflush(stdin);
gets(feed);
fprintf(feedback,"%s",feed);
fclose(feedback);
 }
}
}
 void module6() // module for exit
 {
 printf("\nPlease wait the program ends");

 exit();
 }
 void module7()// module for log in as administrator
{
 userchk();
 }

