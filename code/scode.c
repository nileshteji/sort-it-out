#include <stdio.h>
#include <stdlib.h>
void size()
{
    FILE *fptr;
    char ch;
    system("du -ah |sort -h > b1.txt");

    /*  open the file for reading */

    fptr = fopen("b1.txt", "r");
    if (fptr == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }
    ch = fgetc(fptr);
    while (ch != EOF)
    {
        printf ("%c", ch);
        ch = fgetc(fptr);
    }
    fclose(fptr);
}

void time()
{
    FILE *fptr;
    char ch;
    system("ls -t > c1.csv");

    /*  open the file for reading */

    fptr = fopen("c1.csv", "r");
    if (fptr == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }
    ch = fgetc(fptr);
    while (ch != EOF)
    {
        printf ("%c", ch);
        ch = fgetc(fptr);
    }
    fclose(fptr);
}

void main()
{
	int c;
	printf("Select for which you want to sort the files for  \n1) Size\n2)Time\n====================\n");
	scanf("%d",&c);
	switch(c)
	{
		case 1: size();
		break;
		case 2: time();
		break;
	}
}
