#include<iostream>
using namespace std;
int main()
{
    float A[10],B[10];
    int i,j,key,m,n,temp,k;
    cout<<"\nenter no of elements in array:";
    cin>>n;
    cout<<"\nenter elements of array:";
    for(i=0;i<n;i++)
    {
        cin>>B[i];
    }
    cout<<"\nthe array elements are:";
    for(i=0;i<n;i++)
    {
        cout<<B[i]<<"\t";
    }
    for(i=n/2;i>0;i=i/2)
    {
        for(j=1;j<n;j++)
        {
            for(k=j-i;k>=0;k=k-i)
            {
                if(B[k+i]>=B[k])
                {
                    break;
                }
                else
                {
                    key=B[k];
                    B[k]=B[k+i];
                    B[k+i]=key;
                }
            }
        }
    }
    cout<<"\nthe shell sorted array is:";
    for(i=0;i<n;i++)
    {
        cout<<B[i]<<"\t";
    }


    return 0;
}
				
