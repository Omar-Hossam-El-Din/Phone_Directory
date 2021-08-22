#ifndef DELETE_H_INCLUDED
#define DELETE_H_INCLUDED

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

#endif // DELETE_H_INCLUDED
