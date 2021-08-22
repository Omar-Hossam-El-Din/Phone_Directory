#ifndef ADD_H_INCLUDED
#define ADD_H_INCLUDED

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

#endif // ADD_H_INCLUDED
