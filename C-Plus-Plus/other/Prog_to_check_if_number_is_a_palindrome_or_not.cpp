
#include <iostream>  
using namespace std;  
int main()  
{  
  int num,rem,sum=0,temp;    
  cout<<"Please Enter Your  Number :";    
  cin>>num;    
 temp=num;    
 while(num>0)    
{    
 rem=num%10;    
 sum=(sum*10)+rem;    
 num=num/10;    
}    
if(temp==sum)
{    
cout<"Given Number is Palindrome number";    
}
else    
{
cout<"Given Number is not Palindrome number";   
} 
 return 0;  
}  
