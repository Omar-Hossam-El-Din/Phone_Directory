#ifndef QUERY_H_INCLUDED
#define QUERY_H_INCLUDED

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


#endif // QUERY_H_INCLUDED
