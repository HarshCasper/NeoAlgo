#include<iostream>
using namespace std;
class sample
{
	int a,b;
	public:
	int get();
	int operator +();
	int put();
};
int sample::get()
{
	cout<<"\nEnter Value for a and b:";
	cin>>a>>b;
}
int sample::operator +()
{
	a=-b;
	b=-b;
}
int sample::put()
{
	cout<<"\nValue of a is:"<<a;
	cout<<"\nValue of b is:"<<b;
}
int main()
{
	sample s;
	s.get();
	s.put();
	+s;
	cout<<"\nAfter Overloading";
	s.put();
	return 0;
}

