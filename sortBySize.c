#include <stdio.h> 
#include<dirent.h>
#include<string.h>

long int findSize(char file_name[]) 
{ 
	
	FILE* fp = fopen(file_name, "r"); 

	 
	if (fp == NULL) { 
		printf("File Not Found!\n"); 
		return -1; 
	} 

	fseek(fp, 0L, SEEK_END); 
	long int res = ftell(fp); 
	fclose(fp); 
    return res; 
} 

// Driver code 
int main() 
{ 
	
	 
} 
