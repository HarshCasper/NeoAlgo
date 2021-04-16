/* Reverse a number using stack */

#include<bits/stdc++.h>
using namespace std;

/* Function for Reversing a number using stack */
int solve()
{
    int no;
    cin >> no;

    /* Craete an empty stack */     
    stack<int> s;

    /* Push number into the stack */
    while (no != 0)  
    { 
        s.push(no % 10); 
        no = no / 10; 
    }

    int reverse = 0;
    int r = 1;

    /* Pop the number and form reverse number*/
    while (s.empty() == 0) 
    {
        reverse = reverse + (s.top() * r);
        s.pop();
        r = r * 10;
    }

    /* Return the reverse number*/
    return reverse;
}

int main()
{
    int k = solve();

    cout << "Reverse Number is : " << k << endl;
    return 0;
}

/*
Test cases :
    
    Input 1 :
        
        365

    Output 1 :

        Reverse Number is : 563   

    Input 2 :

        6899
    
    Output 2 :
    
        Reverse Number is : 9986
    
    Time complexity: O(logn)
    Space Complexity: O(1)
*/
