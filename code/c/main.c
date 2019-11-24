#include<stdio.h>
#include <dirent.h>
#include<string.h>
#include "sortByAlphabet.h"
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
           // if(mkdir(get_filename_ext(de->d_name))){
            //   printf("Creted Succesfully\n");
            // }
            // else{
            //   printf("Sorry\n");
            // }
        if(isFileExists(get_filename_ext(de->d_name))==1){
           // printf("File Exists\n");
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
            
            // printf("hi Nilesh\n");
                //printf("File Doesn't Exists\n");
            }
}


     closedir(dr);
    

}

int main(int argc, char const *argv[]) {


printf("How you want to sort your files\n");
printf("1.Extensions\n");
printf("2.Alphabetically\n");
printf("3.Date");
printf("4.Size");
int a;
scanf("%d",&a);

switch (a)
{
case 1:{
folderSort();
break;
}
    

default:
printf("Sorry Wrong execution");
    break;
}



}
