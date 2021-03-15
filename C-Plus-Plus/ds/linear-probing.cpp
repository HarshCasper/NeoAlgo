#include <iostream>
using namespace std;

int Hash(int x,int s)
{
    return x%s;
}


void LinearProbe(int L[],int s,int x)
{
    int index=Hash(x,s);
    int i=0;
    while(L[index]!=0 && L[index]!=-1)
    {
        i++;
        index=(Hash(x,s)+i)%s;

    }
    L[index]=x;
}



void LPSearch(int L[],int s,int x)
{
    int index= Hash(x,s);
    int i=0;
    while(L[index]!=0)
    {
        if(L[index]==x)
        {
            cout<<"Element found at index "<<index <<endl;
            return;
        }
        i++;
        index=(Hash(x,s)+i)%s;

    }
    cout<<"Element not found "<<endl;
}


void LPDelete(int L[],int s,int x)
{
    int index= Hash(x,s);
    int i=0;
    while(L[index]!=0)
    {
        if(L[index]==x)
        {
            cout<<"Element deleted "<<endl;
            L[index]=-1;
            return;
        }
        i++;
        index=(Hash(x,s)+i)%s;

    }
    cout<<"Element not found hence cant be deleted "<<endl;

}

int main()
{
    int n,x;
    cout << "Hello world!" << endl;
    cout<<"Enter number of elements "<<endl;
    cin>>n;
    int s=2*n;
    int p=s;
    while(p>0)
    {
        if( ( ((p-1)%6==0) && ((p+1)%6!=0) )  || ( ((p+1)%6==0) && ((p-1)%6!=0) ))
            break;
        p--;
    }
    int L[s]={0},Q[s]={0},D[s]={0};
    cout<<"Enter elements for Linear probing "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        LinearProbe(L,s,x);
    }
    for(int i=0;i<s;i++)
    {
        cout<<L[i]<<endl;
    }
    cout<<"Enter element to be searched in LP : ";
    cin>>x;
    LPSearch(L,s,x);
    cout<<"Enter element to be deleted in LP : ";
    cin>>x;
    LPDelete(L,s,x);
    cout<<"The hash table is"<<endl;
    for(int i=0;i<s;i++)
    {
        cout<<L[i]<<endl;
    }
    cout<<"Enter element to be added : ";
    cin>>x;
    LinearProbe(L,s,x);
    cout<<"The hash table is"<<endl;
    for(int i=0;i<s;i++)
    {
        cout<<L[i]<<endl;
    }



    return 0;
}
