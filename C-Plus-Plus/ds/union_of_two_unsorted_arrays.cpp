/* A C++ PROGRAM TO FIND UNION OF TWO UNSORTED ARRAYS */
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    int a1[20],a2[20],u[40],i,j,k,n,m,flag;
    cout<<"Enter size of first array :: ";
    cin>>n;
    cout<<"\nEnter elements to the array :: \n";
    for(i=0;i<n;++i)
    {
        cout<<"Enter "<<i+1<<" element :: ";
        cin>>a1[i];
    }
    cout<<"\nEnter size of second array :: ";
    cin>>m;
    cout<<"\nEnter elements to the array :: \n";
    for(i=0;i<m;++i)
    {
        cout<<"Enter "<<i+1<<" element :: ";
        cin>>a2[i];
    }
        k=0;
    for(i=0;i<n;++i)
	{
        u[k]=a1[i];
        k++;
    }

    for(i=0;i<m;++i)
	{
        flag=1;
        for(j=0;j<n;++j)
		{
            if(a2[i]==a1[j])
			{
                flag=0;
                break;
            }
        }

        if(flag)
		{
            u[k]=a2[i];
            k++;
        }
    }
    cout<<"\nUnion of two arrays is :: \n\n";
    for(i=0;i<k;++i)
    {
        cout<<u[i]<<"  ";
    }
    cout<<"\n";
    return 0;
}
/*
TIME COMPLEXITY OF UNION OF TWO UNSORTED ARRAY IS: O(m+n)
SPACE COMPLEITY OF UNION OF TWO ARRAYS IS : O(min(m, n))
Enter size of first array :: 4
Enter elements to the array ::
Enter 1 element :: 4
Enter 2 element :: 2
Enter 3 element :: 5
Enter 4 element :: 1
Enter size of second array :: 3
Enter elements to the array ::
Enter 1 element :: 3
Enter 2 element :: 0
Enter 3 element :: 8
Union of two arrays is ::
4  2  5  1  3  0  8
*/
