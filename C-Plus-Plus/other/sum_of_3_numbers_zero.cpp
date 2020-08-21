/*
Author : Jeet Patel.

Problem Statement : 
An array is given to you which consists of numbers (integers).
You have to design an algorithm to find different combinations of 3 numbers from the given array whose sum is zero.(distinct pairs)
time complexity : O(n^2)

Input : 1.nummber of testcases(t).
        2.size of array
        3.an array of integers. (step 2 and 3 repeats t times.)
output : t nX3 matrix (where n is number of possible pairs whose sum is zero.) (where t is no of testcases.)


sample case :
 Input :1 
        7
        1 -1 2 -2 0 1 3
Output : [[-1,0,1],
          [-2,0,2],
          [-2,-1,3],
          [-2,1,1]] 

      Approach : Fixing one pointer and moving other two pinters using two pointers theory.    

*/

// code:

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    ll testcases,caseno=1; // counting case 
    cin>>testcases; // taking input of testcases
    while(testcases--)
    {
        ll size;
        cin>>size;    // taking input of size of array for a testcase
        vector<ll> array(size);
        for(ll iterator=0;iterator<size;iterator++)
        {
            cin>>array[iterator];    // taking input for array.
        }

        vector<vector<ll>>ans; // for storing answer for particular test case.
        sort(array.begin(),array.end());  // sorting array as time optmization required is O(n^2) .so it will pass through it easily.
            
        for(ll fixed=0;fixed<size-2;fixed++)  // here fixed is a pointer to the number which is fixed at a time while we find combinations by changing other two numbers.
        {
            ll front=fixed+1,back=size-1; // here front is a pointer to the number which is just after fixed and back starts from the end of the array.
           
            while(front<back)
            {
                if(array[fixed]+ array[front]+ array[back] < 0) front++; // as sum is lesser than zero,also array is sorted,so we will move front forward.
                else if(array[fixed]+ array[front]+ array[back] > 0) back--; // as sum is greater than zero,also array is sorted,so we will move back backwards.
                else
                {
                    vector<ll>temp(3,0); // as we have to find 3 numbers whose sum is zero and store them in ans,so we are using temporary array.
                    temp[0]=array[fixed];
                    temp[1]=array[front];
                    temp[2]=array[back];  // storing 3 numbers in temp.
                    sort(temp.begin(),temp.end()); // to avoid repeat due to position change.
                    ans.push_back(temp); // pushing the i-th combination in the ans matrix.

                    while(front<back && temp[fixed]==array[front]) front++; // to avoid duplicates of value of front pointer. it will activate rarely .so it is still O(n^2)
                    
                    front++;
                    
                }
                
            }

            while(fixed < size-2 && array[fixed+1]==array[fixed]) fixed++; // to avoid duplication of value of fixed pointer.
        }
        
        // printing method.
        cout<<"Test Case# "<<caseno<<endl;
        cout<<"["<<endl;
        for(ll rows=0;rows<ans.size();rows++)
        {
            cout<<"[";
            for (ll cols=0;cols<3;cols++)  // as cols are 3 
            {
                cout<<ans[rows][cols]<<" ";
            }
            cout<<"],"<<endl;
        }
            cout<<"]";
        cout<<endl;
        caseno++;
    }
    
}