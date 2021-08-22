#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<windows.h>
#include<conio.h>



typedef struct
{
    char fName[100];
    char lName[100];
    char number[1000];
    char add[1000];
    char email[1000];
}info;
typedef struct
{
    int day;
    int month;
    int year;
}DOB;
    info contact[500];
    DOB cont[500];
    int holder;
void add_Cont();
void save();
void load_Cont();
void del_cont();
void quite();
void modify ();
void sort();
void query();
void sort_DOB();
void print();
int main()
{
    printf("\t\t----PhoneBook----\n");
    printf("1-Add Contact\n");
    printf("2-Load Contact\n");
    printf("3-Query Contact\n");
    printf("4-Delete Contact\n");
    printf("5-Print contacts\n");
    printf("6-Modify contact\n");
    printf("7-Save\n");
    printf("8-Quit\n\n");
    int choise;
    printf("Enter YOUR choise:- ");
    scanf("%d",&choise);
    system("cls");
    if(choise==1)
        add_Cont();
    if(choise==2)
        load_Cont();
    if(choise==3)
        query();
    if(choise==4)
        del_cont();
    if(choise==5)
        print();
    if(choise==6)
        modify();
    if(choise==7)
        save();
    if(choise==8)
        quite();
    if(choise==9)
        sort_DOB();
    return 0;
}
int j=0;
void add_Cont()
{
    int l=0;    int i;
    FILE *fp;
    fp = fopen("Phone_rec.txt","a");
    if(fp != EOF)
    {
        fseek(stdin,0, SEEK_END);
        printf("Enter the first name: ");
        gets((contact)->fName);
        printf("Enter the last name: ");
        gets((contact)->lName);
        printf("Enter the number: ");
        gets((contact)->number);
        char *x=contact->number;
        while(l!=1)
        {
            for(int i=0;i<strlen(x);i++)
           {
               if(isdigit (x[i]))
                {
                    l=1;
                }
                else
                {

                    printf("INVALID PHONE NUMBER\n");
                    printf("Enter the number: ");
                    gets((contact)->number);
                }
           }
        }
        l =0;
        printf("Enter the address: ");
        gets((contact)->add);
        printf("Enter the email: ");
        gets((contact)->email);
        while(l != 1)
        {
            if(strchr(contact->email,'.') && strchr(contact->email,'@'))
            {
                l = 1;
            }
            else
            {
                printf("INVAlID EMAIL ADDRESS\n");
                printf("Enter the email: ");
                gets((contact)->email);
            }
        }

        printf("Enter the birthdate: ");
        scanf("%d",&cont->day);
        scanf("%d",&cont->month);
        scanf("%d",&cont->year);
        fprintf(fp,"%s ",(contact)->fName);
        fprintf(fp,",%s",(contact)->lName);
        fprintf(fp,",%s",(contact)->number);
        fprintf(fp,",%s",(contact)->add);
        fprintf(fp,",%s",(contact)->email);
        fprintf(fp,",%d-%d-%d\n",(cont)->day,(cont)->month,(cont)->year);
        fclose(fp);
    }
    else
            printf("FILE NOT EXIST\n");
    fseek(stdin,0, SEEK_END);
    int r;
    printf("0-return menu to save cahnges\n");
    scanf("%d",&r);
    if(r==0)
    { system("cls");
        main(1);
    }

}
void save()
{

    FILE *fp;
    FILE *fp1;
    char ch;
    fp = fopen("PhoneBook.txt","w");
    fp1 = fopen("Phone_rec.txt","r");
    if(fp1 != EOF)
    {ch = fgetc(fp1);
    while (ch != EOF)
    {
        fputc(ch, fp);
        ch = fgetc(fp1);
    }
    printf("Changing saved...\n");
    }
    else
        {
            printf("ERROR SAvING CHANGES...\n");
        }
    fclose(fp);
    fclose(fp1);
    printf("0-return menu to save cahnges\n");
    int r;
    scanf("%d",&r);
    system("cls");
    main(1);
}
void load_Cont()
{
    FILE *fp;
    int counter=0;
    char c;

    int i=0;
     fp=fopen("PhoneBook.txt","r");
      for (c = getc(fp); c != EOF; c = getc(fp))
         {
             if (c == '\n')
                counter = counter + 1;
         }
         fclose(fp);
         fp=fopen("PhoneBook.txt","r");
     if(counter==0)
        printf("NO CONTACTS....\n");
     else
        {while(i<counter)
        {
            if(!feof(fp))
            {
                fscanf(fp,"%[^,],",(contact+i)->fName);
                fscanf(fp,"%[^,],",(contact+i)->lName);
                fscanf(fp,"%[^,],",(contact+i)->number);
                fscanf(fp,"%[^,],",(contact+i)->add);
                fscanf(fp,"%[^,],",(contact+i)->email);
                fscanf(fp,"%d-",&(cont+i)->day);
                fscanf(fp,"%d-",&(cont+i)->month);
                fscanf(fp,"%d\n",&(cont+i)->year);
            }
            printf("NAME:%s",(contact+i)->fName);
            printf("%s\n",(contact+i)->lName);
            printf("NUMBER:%s\n",(contact+i)->number);
            printf("ADDRESS:%s\n",(contact+i)->add);
            printf("E-MAIL:%s\n",(contact+i)->email);
            printf("BIRTHDAY:%d/%d/%d\n\n",(cont+i)->day,(cont+i)->month,(cont+i)->year);
            i++;
        }
        }
        fclose(fp);
        int r;
        printf("0-return menu to save cahnges\n");
        scanf("%d",&r);
        if(r==0)
        {
            system("cls");
            main(1);
        }
}
 // typedef struct
   // {
     //   char fname[20];
       // char lname[20];
    //}name2;
void del_cont()
{
    //name2 B[20];
    char name[20];  char c;
    int i=0;
    int counter=0;
    FILE *fp;
    fp=fopen("Phone_rec.txt","r");
    for (c = getc(fp); c != EOF; c = getc(fp))
        {
            if (c == '\n')
            counter = counter + 1;
        }
    fclose(fp);
    fp = fopen("Phone_rec.txt","r");
    if(fp != EOF)
    {
        while(i<counter)
        {
                fscanf(fp,"%[^,],",(contact+i)->fName);
                fscanf(fp,"%[^,],",(contact+i)->lName);
                fscanf(fp,"%[^,],",(contact+i)->number);
                fscanf(fp,"%[^,],",(contact+i)->add);
                fscanf(fp,"%[^,],",(contact+i)->email);
                fscanf(fp,"%d-",&(cont+i)->day);
                fscanf(fp,"%d-",&(cont+i)->month);
                fscanf(fp,"%d\n",&(cont+i)->year);
                i++;
        }
        fclose(fp);
    printf("Enter the name of the contact\n");
    fseek(stdin,0, SEEK_END);
    gets(name);
    system("cls");
    int l;
        for(i=0;i<counter;i++)
            {
                strcat((contact+i)->fName,(contact+i)->lName);
                if(strcmp(name,contact[i].fName)==0)
                {
                    printf("\033[1;34m");
                    printf("CONTACT FOUND...\n");
                    printf("\033[0m");
                    printf("%d-\nname:%s\n",(i+1),(contact+i)->fName);
                    printf("number:%s\n",(contact+i)->number);
                    printf("address:%s\n",(contact+i)->add);
                    printf("email:%s\n",(contact+i)->email);
                    printf("DOB:%d/%d/%d\n",(cont+i)->day,(cont+i)->month,(cont+i)->year);
                    *(contact+i)->fName = '\0';
                    l=1;

                }
                else
                {
                    char *token;        char del[2]=" ";
                    token = strtok((contact+i)->fName,del);
                }
            }
            if(l!=1)
            {
                printf("\033[1;34m");
                printf("CONTACT NOT FOUNED\n");
                 printf("\033[0m");
            }
            fp = fopen("Phone_rec.txt","w");
            for(i=0;i<counter;i++)
            {
                if(*(contact+i)->fName != '\0')
                {
                    fprintf(fp,"%s ,",(contact+i)->fName);
                    fprintf(fp,"%s,",(contact+i)->lName);
                    fprintf(fp,"%s,",(contact+i)->number);
                    fprintf(fp,"%s,",(contact+i)->add);
                    fprintf(fp,"%s,",(contact+i)->email);
                    fprintf(fp,"%d-%d-%d\n",(cont+i)->day,(cont+i)->month,(cont+i)->year);
                }
            }
            fclose(fp);
    }
    int r;
    printf("\033[1;35m");
    printf("0-return menu to save cahnges\n");
    printf("\033[0m");    scanf("%d",&r);
    system("cls");
    main(1);
}
void quite()
{

    FILE *fp;
    FILE *fp1;
    char ch;
    fp = fopen("PhoneBook.txt","r");
    fp1 = fopen("Phone_rec.txt","w");
    if(fp != EOF)
    {ch = fgetc(fp);
    while (ch != EOF)
    {
        fputc(ch, fp1);
        ch = fgetc(fp);
    }
    }
    exit(1);
}
void sort()
{
    int i=0;
    char c;
    int counter=0;
    FILE *fp;
    fp=fopen("Phone_rec.txt","r");
    for (c = getc(fp); c != EOF; c = getc(fp))
        {
            if (c == '\n')
            counter = counter + 1;
        }
        fclose(fp);
    info temp[100];//name of structure
    fp=fopen("Phone_rec.txt","r");
            while(i<counter)
        {
                fscanf(fp,"%[^,],",(contact+i)->fName);
                fscanf(fp,"%[^,],",(contact+i)->lName);
                fscanf(fp,"%[^,],",(contact+i)->number);
                fscanf(fp,"%[^,],",(contact+i)->add);
                fscanf(fp,"%[^,],",(contact+i)->email);
                fscanf(fp,"%d-",&(cont+i)->day);
                fscanf(fp,"%d-",&(cont+i)->month);
                fscanf(fp,"%d\n",&(cont+i)->year);
                i++;
        }
    for (int j=0; j<counter-1; j++)
    {
        for (i=j+1; i<counter; i++)
        {
            if (strcasecmp(contact[j].lName, contact[i].lName) > 0)
            {
                temp[0]= contact[j];
                contact[j]= contact[i];
                contact[i]=temp[0];

            }
            else if(strcasecmp(contact[j].lName,contact[i].lName) == 0)
            {
                if(strcasecmp(contact[j].fName, contact[i].fName) > 0)
                {
                    temp[0]= contact[j];
                    contact[j]= contact[i];
                    contact[i]=temp[0];
                }
            }
        }
    }
    for (i=0; i<counter; i++)
    {
        printf("first name is: %s\n",contact[i].fName);
        printf("last name is: %s\n",contact[i].lName);
        printf("date is: %d/%d/%d\n",cont[i].day,cont[i].month,cont[i].year); //hn8ayr ya abo 7meed 3la asas elly asamy el structure elly 3ndna
        printf("address is: %s\n",contact[i].add);
        printf("email is: %s\n",contact[i].email);
        printf("phone number is: %d\n",contact[i].number);
        printf("...............................\n");
           }
    int v;

    printf("0-TO RETURN TO MAIN MENU\n");
    scanf("%d",&v);
    system("cls");
    main(1);
}




int u,nf;
char searchname[50] ;
int b[100];
void query()
{
    char c;     int a=0;
    int counter=0;
    FILE *fp;
    fp=fopen("Phone_rec.txt","r");
    for (c = getc(fp); c != EOF; c = getc(fp))
        {
            if (c == '\n')
            counter = counter + 1;
        }
    fclose(fp);
    fp=fopen("Phone_rec.txt","r");
    while(a<counter)
    {
        fscanf(fp,"%[^,],",(contact+a)->fName);
        fscanf(fp,"%[^,],",(contact+a)->lName);
        fscanf(fp,"%[^,],",(contact+a)->number);
        fscanf(fp,"%[^,],",(contact+a)->add);
        fscanf(fp,"%[^,],",(contact+a)->email);
        fscanf(fp,"%d-",&(cont+a)->day);
        fscanf(fp,"%d-",&(cont+a)->month);
        fscanf(fp,"%d\n",&(cont+a)->year);
        a++;
    }
    fclose(fp);
    u=0;
    nf=1;
    int cb=0;
    printf("Enter the last name: ");
    fseek(stdin,0,SEEK_END);
    gets(searchname);
    for (a=0; a<counter; a++)
    {
        if(strcasecmp(searchname,contact[a].lName)==0)
        {
            printf("---------------------\n");
            printf("\nlast name is: %s\n",contact[a].lName);
            printf("first name is: %s\n",contact[a].fName);
            printf("date is: %d/%d/%d\n",cont[a].day,cont[a].month,cont[a].year);
            printf("address is: %s\n",contact[a].add);
            printf("email is: %s\n",contact[a].email);
            printf("phone number is: %d\n",contact[a].number);
            b[cb]=a;
            cb++;
            u++;
        }
    }

    if(u==0)
    {

        nf=0;
        printf("this person does not exist\n\n") ;

    }
    int v;
    printf("0-return menu to save cahnges\n");
    scanf("%d",&v);
    if(v==0)
    {
        system("cls");
        main(1);
    }


}

void modify ()
{
    char c;     int a=0;
    int counter=0;
    FILE *fp;
    fp=fopen("Phone_rec.txt","r");
    for (c = getc(fp); c != EOF; c = getc(fp))
        {
            if (c == '\n')
            counter = counter + 1;
        }
    fclose(fp);
    fp=fopen("Phone_rec.txt","r");
    while(a<counter)
    {
        fscanf(fp,"%[^,],",(contact+a)->fName);
        fscanf(fp,"%[^,],",(contact+a)->lName);
        fscanf(fp,"%[^,],",(contact+a)->number);
        fscanf(fp,"%[^,],",(contact+a)->add);
        fscanf(fp,"%[^,],",(contact+a)->email);
        fscanf(fp,"%d-",&(cont+a)->day);
        fscanf(fp,"%d-",&(cont+a)->month);
        fscanf(fp,"%d\n",&(cont+a)->year);
        a++;
    }
    fclose(fp);
    char name[200];
    printf("Enter the last name:\t");
    fseek(stdin,0,SEEK_END);
    gets(name);
    int i;      int flag=0;
    for(i=0;i<counter;i++)
    {
        if(strcmp(name,(contact+i)->lName)==0)
        {
            printf("Contact found...\n");
            printf("NAME:%s",(contact+i)->fName);
            printf("%s\n",(contact+i)->lName);
            printf("NUMBER:%s\n",(contact+i)->number);
            printf("ADDRESS:%s\n",(contact+i)->add);
            printf("E-MAIL:%s\n",(contact+i)->email);
            printf("BIRTHDAY:%d/%d/%d\n\n",(cont+i)->day,(cont+i)->month,(cont+i)->year);
            break;
        }
        flag++;
    }
    if(flag==0)
        {
            printf("No contact found\n");
        }
    int change;
    int b=0;
    while(b!=7)
    {
        printf("For change last name -->>>(1)\n");
        printf("For change first name -->>>(2)\n");
        printf("For change phone number -->>>(3)\n");
        printf("For change address -->>>(4)\n");
        printf("For change email -->>>(5)\n");
        printf("For change date of birth -->>>(6)\n");
        printf("Exit and save -->>>(7)\n");
        scanf("%d",&change);
        if(change==1)
        {
            flag;
            fseek(stdin,0,SEEK_END);
            printf("Enter the last name:\t");
            gets((contact[flag].lName));
            b = change;
        }
        if(change==2)
        {
            flag;
            fseek(stdin,0,SEEK_END);
            printf("Enter the first name:\t");
            gets((contact[flag].fName));
            strcat(contact[flag].fName," ");
        }
        if(change==3)
        {
            flag;
            fseek(stdin,0,SEEK_END);
            printf("Enter the number:\t");
            gets((contact[flag].number));
            b = change;
        }
        if(change==4)
        {
            flag;
            printf("Enter the address:\t");
            fseek(stdin,0,SEEK_END);
            gets((contact[flag].add));
            b = change;
        }

        if(change==5)
        {
            flag;
            printf("Enter the email:\t");
            fseek(stdin,0,SEEK_END);
            gets((contact[flag].email));
            b = change;
        }
        if(change==6)
        {
            flag;
            printf("Enter the date:\t");
            fseek(stdin,0,SEEK_END);
            printf("DAY:\t");
            scanf("%d",&cont[flag].day);
            printf("MONTH:\t");
            fseek(stdin,0,SEEK_END);
            scanf("%d",&cont[flag].month);
            printf("YEAR:\t");
            fseek(stdin,0,SEEK_END);
            scanf("%d",&cont[flag].year);
            b = change;
        }
        if(change==7)
        {
            fopen("Phone_rec.txt","w");
                  for(i=0;i<counter;i++)
            {
                    fprintf(fp,"%s,",(contact+i)->fName);
                    fprintf(fp,"%s,",(contact+i)->lName);
                    fprintf(fp,"%s,",(contact+i)->number);
                    fprintf(fp,"%s,",(contact+i)->add);
                    fprintf(fp,"%s,",(contact+i)->email);
                    fprintf(fp,"%d-%d-%d\n",(cont+i)->day,(cont+i)->month,(cont+i)->year);
            }
            fclose(fp);
            system("cls");
            main(1);
        }

    }
}
void sort_DOB()
{
    char c;     int a=0;
    int counter=0;
    FILE *fp;
    fp=fopen("Phone_rec.txt","r");
    for (c = getc(fp); c != EOF; c = getc(fp))
        {
            if (c == '\n')
            counter = counter + 1;
        }
    fclose(fp);
    fp=fopen("Phone_rec.txt","r");
    while(a<counter)
    {
        fscanf(fp,"%[^,],",(contact+a)->fName);
        fscanf(fp,"%[^,],",(contact+a)->lName);
        fscanf(fp,"%[^,],",(contact+a)->number);
        fscanf(fp,"%[^,],",(contact+a)->add);
        fscanf(fp,"%[^,],",(contact+a)->email);
        fscanf(fp,"%d-",&(cont+a)->day);
        fscanf(fp,"%d-",&(cont+a)->month);
        fscanf(fp,"%d\n",&(cont+a)->year);
        a++;
    }
    fclose(fp);
    int i,j;        info temp[500];
    DOB temp2[500];
    for (int j=0; j<counter-1; j++)
    {
        for (i=j+1; i<counter; i++)
            {
                if(cont[j].year < cont[i].year)
                    {
                        printf("%d",cont[i].year);
                        printf("%d",cont[i+1].year);
                        temp[0]= contact[j];
                        contact[j]=contact[i];
                        contact[i]=temp[0];
                        temp2[0]=cont[j];
                        cont[j]=cont[i];
                        cont[i]=temp2[0];
                    }

                else if(cont[i].year == cont[i+1].year)
                {
                    if(cont[i].month < cont[i+1].month)
                    {
                         temp[0]= contact[j];
                        contact[j]=contact[i];
                        contact[i]=temp[0];
                        temp2[0]=cont[j];
                        cont[j]=cont[i];
                        cont[i]=temp2[0];
                    }
                }
                else if(cont[i].month == cont[i+1].month)
                {
                    if(cont[i].day < cont[i+1].day)
                    {
                         temp[0]= contact[j];
                        contact[j]=contact[i];
                        contact[i]=temp[0];
                        temp2[0]=cont[j];
                        cont[j]=cont[i];
                        cont[i]=temp2[0];
                    }
                }
        }
    }
        for (i=0; i<counter; i++)

        {
            printf("first name is: %s\n",contact[i].fName);
            printf("last name is: %s\n",contact[i].lName);
            printf("date is: %d/%d/%d\n",cont[i].day,cont[i].month,cont[i].year);
            printf("address is: %s\n",contact[i].add);
            printf("email is: %s\n",contact[i].email);
            printf("phone number is: %d\n",contact[i].number);
            printf("..........................................\n");

        }
        printf("0-TO RETURN TO MAIN MENU\n");
        int v;
        scanf("%d",&v);
        if(v==0)
        {
            system("cls");
            main(1);
        }
}
void print()
{
    printf("SORT BY LAST NAME-->>>(1)\n");
    printf("SORTB BY DATE OF BIRTH-->>>(2)\n\n");
    int k;
    fseek(stdin,0,SEEK_END);
    printf("ENTER YOUR CHOISE:-  ");
    scanf("%d",&k);
    if(k==1)
        sort();
    if(k==2)
        sort_DOB();
}
