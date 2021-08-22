#ifndef MODIFY_H_INCLUDED
#define MODIFY_H_INCLUDED
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


#endif // MODIFY_H_INCLUDED
