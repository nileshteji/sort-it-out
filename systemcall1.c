//#include <bits/stdc++.h> 
#include<stdlib.h>
//#include<cstdlib.h>

using namespace std; 
int main () 
{ 
    char filename[100]; 
    cout << "Enter file name to compile "; 
    cin.getline(filename, 100); 
  
    // Build command to execute.  For example if the input 
    // file name is a.cpp, then str holds "gcc -o a.out a.cpp"  
    // Here -o is used to specify executable file name 
    string str = "gcc "; 
    str = str + " -o a.out " + filename; 
  
    // Convert string to const char * as system requires 
    // parameter of type const char * 
    const char *command = str.c_str(); 
  
    cout << "Compiling file using " << command << endl; 
    system(command); 
  
    cout << "\nRunning file "; 
    system("./a.out"); 
   




    return 0; 
} 