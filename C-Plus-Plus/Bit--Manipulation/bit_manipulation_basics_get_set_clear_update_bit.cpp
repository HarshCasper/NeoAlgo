#include <iostream>
#include <string.h>
#include <ctype.h>

using namespace std;

int getbit(int , int);
int setbit(int , int);
int clearbit(int , int);
int updatebit(int , int, int);

int main()
{
	int n,pos;
	cout<<"\nEnter the no. --> ";
	cin>>n;
	cout<<"\nEnter the bit position at which you want to know the bit = ";
	cin>>pos;
	cout<<"\nThe bit at "<<pos<<" is = "<<getbit(n,pos-1)<<endl;
	cout<<"\nEnter the postion where you want to set the bit = ";
	cin>>pos;
	cout<<"\nThe no. after setting the bit is = "<<setbit(n,pos-1)<<endl;
	cout<<"\nEnter the postion where you want to clear the bit = ";
	cin>>pos;
	cout<<"\nThe no. after setting the bit is = "<<clearbit(n,pos-1)<<endl;
	cout<<"\nEnter the postion where you want to update the bit adn the value to be inserted = ";
	int value;
	cin>>pos>>value;
	cout<<"\nThe no. after updating the bit is = "<<updatebit(n,pos-1,value)<<endl;
	
	return 0;
}

int getbit(int n,int i){return ((n & (1<<i))!=0);}
int setbit(int n,int i){return (n | (1<<i));}
int clearbit(int n,int i)
	{
		int mask = ~(1<<i);
		return n & mask;
	}
int updatebit(int n,int i,int value)
	{
		int clear = clearbit(n,i);
		return (clear | (value<<i));
	}
