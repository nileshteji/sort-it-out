#include<stdio.h>
#include <dirent.h>
#include<string.h>
int isFileExists(const char *path);

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

int main(int argc, char const *argv[]) {
   struct dirent *de;  
    DIR *dr = opendir(".");

     if (dr == NULL)  
     {
         printf("Could not open current directory" );
         return 0;
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
           if(de->d_name=="main.c"){
               break;
           }
           else{

           
            char move[10]="mv";
            strcat(strcat(move," "),de->d_name);
            strcat(strcat(move," "),get_filename_ext(de->d_name));
            system(move);
            
           }
           
            
            }

            else{
            mkdir(get_filename_ext(de->d_name),0070);
            // printf("hi Nilesh\n");
                //printf("File Doesn't Exists\n");
            }
}


     closedir(dr);
     return 0;




  return 0;
}
