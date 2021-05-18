/* TASK : Given two, one digit positive integers 'A' , 'B' and a number 'N' consisting of these two integers only,
 the task is to find the greatest number that can can be formed by altering atmost one digit.

APPROACH : The simplest approach is to store the digits of a given number N in an array 
           and then iterate over the array and find the first occurence of minimum of two given integers A and B and 
           break out of the loop.
           Below is the implementation for the same.
*/ 

#include <bits/stdc++.h>
using namespace std;

//Function to calculate the maximum number
int maximum(int A, int B, int N)
{
    //Calculate maximum and minimum among the given integers
    int maxi=max(A,B);
    int mini=min(A,B);
    vector<int> v;
    //Create array of digits of given number
    while(N>0) 
    {
        v.push_back(N%10);
        N/=10;
    }
    int size=v.size()-1;
    //Alter the first occurence of minimum of A and B and break out
    for (int i=size; i>= 0; i--)
    {
        if (v[i]==mini) 
        {
            v[i]=maxi;
            break;
        }
    }
    //Store the number after altering
    int ans=0,temp=size;
    while (temp>=0)
    {
        ans=ans*10+v[temp];
        temp--;
    }
    return ans;
}

int main()
{
    int a, b, n;
    cin>>a>>b>>n;
    int max_num=maximum(a, b, n);
    cout<<max_num;
    return 0;
}

/*
Sample TestCase :

INPUT : a = 4, b = 5, n = 544545
OUTPUT : 554545
EXPLANATION : Altering first digit will give 444545
              Altering second digit will give 554545
              Altering third digit will give 545545
              Altering fourth digit will give 544445
              Altering fifth digit will give 544555
              Altering sixth digit will give 544544
              We get the maximum digit by altering the second digit, 554545

TIME COMPLEXITY : O(N), N = no. of digits
AUXILIARY SPACE : O(N), N = no. of digits

*/ 