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

        char str1[50]="cp *.c /home/shivam/Desktop/Rahul_c";
        //scanf("%[^\n]%*c", str); 
        //str=
        //printf("%s", str); 
         system(str1);
       
       char str2[50]="cp *.cpp /home/shivam/Desktop/Rahul_cpp";
        //scanf("%[^\n]%*c", str); 
        //str=
        //printf("%s", str); 
         system(str2);
          char str3[50]="cp *.txt /home/shivam/Desktop/Rahul_txt";
        //scanf("%[^\n]%*c", str); 
        //str=
        //printf("%s", str); 
         system(str3);
          char str4[50]="cp *.py /home/shivam/Desktop/Rahul_py";
        //scanf("%[^\n]%*c", str); 
        //str=
        //printf("%s", str); 
         system(str4);
   
    printf("\n FILES COPIED \n ");

  return(0);
}