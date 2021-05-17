//Naive algorithm for string searching is used to search for a substring in a given string. It returns
 all the occurences of the substring.

#include <stdio.h>

#include <string.h>

int main()

{
   
 char str[100],new[100];
    
int i,j,m,n;
   
 printf("Enter string: ");
   
 scanf("%s",str);
    
printf("Enter string to be searched: ");
   
 scanf("%s",new);
   
 m=strlen(str);
   
 n=strlen(new);
    
    
for(i=0;i<m-n;i++){
        
for(j=0;j<n;j++)
            
if(str[i+j]!=new[j])
           
 break;
        
       
 if(j==n)
           
 printf("The given substring is found at position %d\n",i);
  
  }
   
 return 0;

}