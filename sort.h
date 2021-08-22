#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

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


#endif // SORT_H_INCLUDED
