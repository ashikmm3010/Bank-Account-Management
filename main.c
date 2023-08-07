#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct {
char name[20];
int acc_no,age;
char address[60];
float amt,phone;
}add,check,rem;
void menu()
{
int ch;
clrscr();
printf("\n\n\n\t\t1.Add Account\n\t\t2.Delete Account\n\t\t3.Search
Account\n\t\t4.Display All Account\n\t\t5.Exit\n\n\t\tEnter the choice:");
scanf("%d",&ch);
clrscr();
switch(ch)
{
case 1:add();
break;
case 2: delete();
break;
case 3: search();
break;
case 4: display();
break;
case 5: printf("\n\n\n\n\n\n\n\n\n\n\t\t\tC PROJECT done by Aswin &

Ashik");

getch();
break;

}
}
void add()
{
FILE *ptr;
ptr=fopen("record.txt","a+");
account_no:
clrscr();
printf("\n\n\t\t\t\tADD ACCOUNT\n\n");
printf("\nEnter the account number:");
scanf("%d",&check.acc_no);
while(fscanf(ptr,"%d %s %d %s %f %f
\n",&add.acc_no,add.name,&add.age,add.address,&add.phone,&add.amt)!=EOF)
{

if (check.acc_no==add.acc_no)
{
printf("Account no. already in use!");
goto account_no;
}

}
add.acc_no=check.acc_no;
printf("\nName:");
scanf("%s",add.name);
printf("\n Age:");
scanf("%d",&add.age);
printf("\n\tAddress:");
scanf("%s",add.address);
printf("\n\tPhone number: ");
scanf("%f",&add.phone);
printf("\n\t Amount to deposit:");
scanf("%f",&add.amt);
fprintf(ptr,"%d %s %d %s %f %f
\n",add.acc_no,add.name,add.age,add.address,add.phone,add.amt);
fclose(ptr);
printf("\n\n\tAccount created successfully!");
getch();
menu();
}
void search()
{
int flag=0;
clrscr();
FILE *ptr;
ptr=fopen("record.txt","r");
printf("\n\n\t\t\tSEARCH ACCOUNT\n");
printf("\n\tEnter Acc.No. to be searched:");
scanf("%d",&check.acc_no);
while(fscanf(ptr,"%d %s %d %s %f %f
\n",&add.acc_no,add.name,&add.age,add.address,&add.phone,&add.amt)!=EOF)
{
if(add.acc_no==check.acc_no)
{
flag++;
printf("\n\n\n\tAccount

No.:%d\n\tName:%s\n\tAge:%d\n\tAddress:%s\n\tPhone number:%.0f\n\tAmount
deposited:%.2f",add.acc_no,add.name,add.age,add.address,add.phone,add.amt);
printf("\n\n\n\n\n\n\n\n\t\tPress any key to continue...");
}
}
if(flag==0)

{
printf("\n\n\n\t\tAccount Not Found!!!");
printf("\n\n\n\n\n\n\n\n\t\tPress any key to continue...");
}
getch();
menu();
}
void delete()
{
char ch;
int flag=0,f=0;
FILE *old,*newrec,*view;
view=fopen("record.txt","r")
old=fopen("record.txt","r");
newrec=fopen("new.txt","w");
printf("Enter the account no. of the customer you want to delete:");
scanf("%d",&rem.acc_no);
while(fscanf(ptr,"%d %s %d %s %f %f
\n",&add.acc_no,add.name,&add.age,add.address,&add.phone,&add.amt)!=EOF)
{
if(add.acc_no==rem.acc_no)
{
flag++;
printf("\n\n\n\tAccount

No.:%d\n\tName:%s\n\tAge:%d\n\tAddress:%s\n\tPhone number:%.0f\n\tAmount
deposited:%.2f",add.acc_no,add.name,add.age,add.address,add.phone,add.amt);

printf("\n\nAre you sure(Y/N)?:");
scanf("%s",ch);
if(ch=='Y'||ch=='y')
{
while(fscanf(old,"%d %s %d %s %f %f

\n",&add.acc_no,add.name,&add.age,add.address,&add.phone,&add.amt)!=EOF)

{
if(add.acc_no!=rem.acc_no)

fprintf(ptr,"%d %s %d %s %f %f

\n",add.acc_no,add.name,add.age,add.address,add.phone,add.amt);

}
f++;
fclose(view);
fclose(old);
fclose(newrec);
remove("record.txt");
rename("new.txt","record.txt");
}
//else

//break;

}
}
if(f==1)
{
printf("\n\tRecord Deleted Successfully");
}
if(flag==0)
{
printf("\n\n\nRecord not Found");
}
getch();
menu();
}
void display()
{
FILE *disp;
disp=fopen("record.txt","r");
int flag=0;
clrscr();
printf("\nACC. NO.\tNAME\tAGE\t\t\tADDRESS\t\t\tPHONE\n");
while(fscanf(disp,"%d %s %d %s %f %f
\n",&add.acc_no,add.name,&add.age,add.address,&add.phone,&add.amt)!=EOF)
{
printf("\n%6d\t

%10s\t%5d\t\t\t%10s\t\t\t%.0f",add.acc_no,add.name,add.age,add.address,add.phone);

test++;
}
fclose(disp);
if (flag==0)
{
clrscr();
printf("\n\n\n\t\t\tNO RECORDS!!\n");
}
getch();
menu();
}
void main()
{
int flag=0,pass;
while(flag==0)
{
printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tPassword: ");
scanf("%d",&pass);

if(pass==1234)
{
clrscr();
printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tAccess

Granted\n\n\t\t\tWELCOME\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tTap any key to continue...");

getch();
flag++;
clrscr();
menu();
}
else
{
clrscr();
printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tIncorrect Password!!!");
getch();
clrscr();
}
}
}
