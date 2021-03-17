#include<iostream>
using namespace std;

/**/

void uniqnum(int [],int);
int checkbit(int , int); /*This function checks and returns 0 or 1 depending if the bit is a set bit or not.*/

int main()
{
    int n;
    cout<<"\nEnter the no. of elements in your array = ";
    cin>>n;
    int a[n];
    cout<<"\nEnter the values into the array --> ";
    for(int i=0;i<n;i++)
    {cin>>a[i];}
    uniqnum(a,n);
    return 0;
}

void uniqnum(int a[], int n)
{
	int xorsum =0;
	for(int i=0;i<n;i++)
		{
			xorsum = xorsum^a[i];/* This will store the XOR of those 2 unique elements. */
		}
		
	int txor = xorsum;
	int setbit=0;
	int pos=0;
	while(setbit!=1)
		{
			/* This loop checks the occurance of setbit at a particular position 
			 * in binary representation of the number.
			 * */
			setbit = xorsum & 1;
			pos++;
			xorsum = xorsum>>1;
		}
		
	int newxor =0;
	for(int i=0;i<n;i++)
		{
			if(checkbit(a[i],pos-1)){newxor = xorsum^a[i];}
		}
	txor  = txor ^ newxor;
	cout<<"\nThe 2 unique numbers are "<<newxor<<" "<<txor<<endl;
	
}

int checkbit(int n, int pos)
{
	return (n&(1<<pos)!=0);
}

/*
 * This method is ineffective compared to the other 
void uniqnum(int a[], int n)
{
	int k,pos=0;
    for(int i=0;i<n;i++)
		{
			k=0;
			for(int j=0;j<n;j++)
				{
					if(i==j)
						{continue;}
						
					if((a[i]^a[j]) == 0)
						{
							k=1;
							break;
						}
				}
			if(k==0)
			 {
				pos = i;
				cout<<a[pos]<<" is the unique element."<<endl;
			 }
		}
}
*/
