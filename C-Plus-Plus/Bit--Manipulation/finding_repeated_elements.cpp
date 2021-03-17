#include <iostream>
using namespace std;


int main(){  
    int arr[] = {601,602,603,604,605,605,606,607,607,608};  
     
    int n= sizeof(arr)/sizeof(arr[0]);  

    for (int i = 0; i < n; i++)  
    {  
        for (int j = i+1; j < n; j++)  
        {  
            int res = arr[i] ^ arr[j];  

            if (res == 0)  
            {  
                cout<< "Repeated Element in array = "<<arr[i]<<endl;  
            }  
        }  
    }  
    return 0;  
}  