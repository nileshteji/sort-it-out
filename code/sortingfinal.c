#include <dirent.h>
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

char name[256][256];

int main(void)
{
  DIR   *d;
  struct dirent *dir;
  int count = 0;
  int index = 0;
  d = opendir(".");
  if (d)
  {
    while ((dir = readdir(d)) != NULL)
    {
      printf("%s\n", dir->d_name);
      strcpy(name[count],dir->d_name);
      count++;
    }

    closedir(d);
  }


  while( count > 0 )
  {
      printf("%s\r\n",name[index]);
      index++;
      count--;
  }
printf("\n ------- NOW WE WILL MOVE THE FILES ---------- \n");

        char str1[50]="cp *.c /home/codingtitan/Desktop/cFiles";
        char str1a[50]="mkdir /home/codingtitan/Desktop/cFiles";
        system(str1a);
        system(str1);

        char str2[50]="cp *.cpp /home/codingtitan/Desktop/MinorTesting/cppFiles";
         char str2a[50]="mkdir /home/codingtitan/Desktop/MinorTesting/cppFiles";
         system(str2a);
         system(str2);

          char str3[50]="cp *.txt /home/codingtitan/Desktop/MinorTesting/textFiles";
         char str3a[50]="mkdir /home/codingtitan/Desktop/MinorTesting/textFiles";
         system(str3a);
         system(str3);

         char str4[50]="cp *.py /home/codingtitan/Desktop/MinorTesting/pythonFiles";
         char str4a[50]="mkdir /home/codingtitan/Desktop/MinorTesting/pythonFiles";
         system(str4a);
         system(str4);

    printf("\n FILES COPIED \n ");

  return(0);
}
