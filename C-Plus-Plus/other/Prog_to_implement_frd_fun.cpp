#include<iostream>
using namespace std;
class addition
{
	private:
		int a,b,c;
	public:
		void get();
		friend void put(addition A);
};
void addition::get()
{
	cout<<"Enter two number:";
	cin>>a>>b;
}
void put(addition A)
{
	A.c=A.a+A.b;
	cout<<"Addition of a And B is:"<<A.c;
}
int main()
{
	addition Ad;
	Ad.get();
	put(Ad);
}
