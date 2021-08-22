#ifndef PRINT_H_INCLUDED
#define PRINT_H_INCLUDED

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


#endif // PRINT_H_INCLUDED
