/*  

Arrange the elements of array such that to form the  
biggest possible number, by rearranging them.  

For a given array arr[] having numbers,  
your task is to arrange the elements of the array arr[],  
such that the new arrangement forms the biggest number.  
The output is given in a single number form  
i.e. the elements should be printed without spaces, 
forming a single number.
*/  

#include <bits/stdc++.h>  

using namespace std;  

//function to compare between elements  
int formBiggest(string str1, string str2)  
{  

    string appnd1 = str1.append(str2);  

    string appnd2 = str2.append(str1);  

    //comparing between appnd1 and appnd2  
    //and returning bigger one 
    return appnd1.compare(appnd2) > 0 ? 1 : 0;  

}  

//main function  
int main()  
{  

    int n;  

    cout<<"Enter the size of array: ";  
    cin>>n;  

    vector<string> arr(n);  

    cout<<"Enter the elements for the array: ";  

    for(int pass = 0; pass < n; pass++)  
    {  
        arr.push_back(arr[pass]);  
    }  
    cout<<"The biggest number so formed is: ";  

    sort(arr.begin(), arr.end(), formBiggest);   

    for(int pass = 0; pass < n; pass++){  
        cout<<arr[pass];  
    }  

    return 0;  

}  

/*  

EXAMPLES:-  

Example 1:  
Input--  
Enter the size of array: 5  
Enter the elements for the array: 44 66 88 01 56  
Output--  
The biggest number so formed is: 8866564401  

Example 2:  
Input--  
Enter the size of array: 3  
Enter the elements for the array: 200 545 76  
Output--  
The biggest number so formed is: 76545200   

Example 3:  
Input--  
Enter the size of array: 1  
Enter the elements for the array: 220  
Output--  
The biggest number so formed is: 220  

TIME COMPLEXITY -> O(Nlog(N))  
SPACE COMPLEXITY -> O(1)  

*/  
