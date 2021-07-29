#include<iostream>
using namespace std;
class item
{
	static int count;
	int num;
	public:
	void getdata(int a)
	{
		num=a;
		count++;
	}
	void getcount()
	{
	cout<<"Count is:"<<count<<"\n";
	}
};
int item::count = 0;
int main()
{
	item a,b,c;
	a.getcount();
	b.getcount();
	c.getcount();
	a.getdata(100);
	b.getdata(200);
	c.getdata(300);
	cout<<"After recording data"<<"\n";
	a.getcount();
	b.getcount();
	c.getcount();
}

