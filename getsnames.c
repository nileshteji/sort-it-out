#include <stdio.h> 
#include <dirent.h> 
#include<stdlib.h>
  
int main(void) 
{ 
    struct dirent *de;  // Pointer for directory entry 
  
    // opendir() returns a pointer of DIR type.  
    DIR *dr = opendir("."); 
  
    if (dr == NULL)  // opendir returns NULL if couldn't open directory 
    { 
        printf("Could not open current directory" ); 
        return 0; 
    } 
  
    // Refer http://pubs.opengroup.org/onlinepubs/7990989775/xsh/readdir.html 
    // for readdir() 
    while ((de = readdir(dr)) != NULL) 
            printf("%s\n", de->d_name); 

    printf("\n ------- NOW WE WILL MOVE THE FILES ---------- \n");

        char str[50]="cp *.c /home/shivam/Desktop/Rahul3";
        //scanf("%[^\n]%*c", str); 
        //str=
        //printf("%s", str); 
         system(str);
        if(system(str)){
            printf("\n Files copied \n");
        }

        
        else 
            printf("\n Files copied \n");

  
     char arr[1000]="ls";
     system(arr);
      // to read the array
      int i;
      for(i=0;i<1000;i++){
        printf("%s",arr);
      } 
    


    closedir(dr);     
    return 0; 
} 