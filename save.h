#ifndef SAVE_H_INCLUDED
#define SAVE_H_INCLUDED

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

#endif // SAVE_H_INCLUDED
