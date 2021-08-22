#ifndef LOAD_H_INCLUDED
#define LOAD_H_INCLUDED

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



#endif // LOAD_H_INCLUDED
