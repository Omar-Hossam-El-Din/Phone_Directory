#ifndef QUITE_H_INCLUDED
#define QUITE_H_INCLUDED
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



#endif // QUITE_H_INCLUDED
