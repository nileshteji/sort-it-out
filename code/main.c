#include<stdio.h>
#include <dirent.h>
#include<string.h>



//This function tell us about the extension of the file
const char *get_filename_ext(char *filename) {
   const char *dot = strrchr(filename, '.');
   if(!dot || dot == filename) return "";
   return dot + 1;
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
            if(mkdir(get_filename_ext(de->d_name))){
              printf("Creted Succesfully\n");
            }
            else{
              printf("Sorry\n");
            }
}


     closedir(dr);
     return 0;




  return 0;
}
