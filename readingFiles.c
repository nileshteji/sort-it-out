  #include <stdio.h> 
#include <dirent.h> 
#include<string.h>

int main(void) 
{ 
    char *fileName[100];
    
	struct dirent *de;  
	DIR *dr = opendir("."); 

	if (dr == NULL)  
	{ 
		printf("Could not open current directory" ); 
		return 0; 
	} 
    int index=0;

	while ((de = readdir(dr)) != NULL) 
			{
strcpy(fileName[index],de->d_name);
index++;
            } 

            for(int i=0;i<sizeof(fileName)/sizeof(char);i++){
                printf("%s",fileName[i]);
            }

	closedir(dr);	 
	return 0; 
} 

