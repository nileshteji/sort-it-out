
#include <stdio.h> 
#include<stdlib.h>
int main() 
{ 
   char str[20]; 

   scanf("%[^\n]%*c", str); 
   printf("%s", str); 
   system(str); 
   //char command1[40];
   //scan


  
   return 0; 
} 
