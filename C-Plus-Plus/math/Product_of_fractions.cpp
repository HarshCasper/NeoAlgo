#include <bits/stdc++.h> 
using namespace std; 
  

int gcd(int a, int b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 
  
void prodRed(int n, int num[], int den[]) 
{ 
    int new_num = 1, new_den = 1; 
    for (int i = 0; i < n; i++) { 
        new_num *= num[i]; 
        new_den *= den[i]; 
    } 
  
    int GCD = gcd(new_num, new_den); 
    new_num /= GCD; 
    new_den /= GCD; 
    cout<<"The product is\n";
    cout<<new_num<<"/"<<new_den<<endl; 
} 
  
int main() 
{ 
    int n;
    cin>>n;
    int num[n],den[n],i;
    cout<<"Enter the numerators\n";
    for(i=0;i<n;i++)
    {
        cin>>num[i];   
    }
    cout<<"Enter the denominators\n";
    for(i=0;i<n;i++)
    {
        cin>>den[i];
    }
    prodRed(n, num, den); 
    return 0; 
} 
