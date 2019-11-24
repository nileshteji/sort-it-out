#include<stdio.h>
#include <dirent.h>
#include<string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>


int isFileExists(const char *path);
void folderSort();

//This function tell us about the extension of the file
const char *get_filename_ext(char *filename) {
   const char *dot = strrchr(filename, '.');
   if(!dot || dot == filename) return "";
   return dot + 1;
}

int isFileExists(const char *path)
{
    // Try to open file
    FILE *fptr = fopen(path, "r");

    // If file does not exists 
    if (fptr == NULL)
        return 0;
        
  
  fclose(fptr);

    return 1;
}

void folderSort(){
struct dirent *de;  
    DIR *dr = opendir(".");
    

     if (dr == NULL)  
     {
         printf("Could not open current directory" );
        
     }
        while ((de = readdir(dr)) != NULL){
           
        if(isFileExists(get_filename_ext(de->d_name))==1){
          
            char move[10]="mv";
            strcat(strcat(move," "),de->d_name);
            strcat(strcat(move," "),get_filename_ext(de->d_name));
            system(move);
             }

            else{
            mkdir(get_filename_ext(de->d_name),0070);
            char command[100]="chmod 777";
            strcat(command," ");
            strcat(command,get_filename_ext(de->d_name));
            
            system(command);

            char move[10]="mv";
            strcat(strcat(move," "),de->d_name);
            strcat(strcat(move," "),get_filename_ext(de->d_name));

            system(move);
            
           
            }
}


     closedir(dr);
    

}

void sortBySize(){
   FILE *fptr;
    char ch;
    system("ls -S > b1.txt");
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

void sortByDate(){
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





int main(int argc, char const *argv[]) {



printf("How you want to sort your files\n");
printf("1.Extensions\n");
printf("2.Size\n");
printf("3.Date created \n");
printf("4.Alphabetically\n");
printf("5.Details of all Files\n");
int a;
scanf("%d",&a);

switch (a)
{
case 1:{
folderSort();
break;
}

case 2:{
 sortBySize();
 break;
}

case 3:{
    sortByDate();
    break;
} 
    

default:
printf("Sorry Wrong execution");
    break;
}



}
