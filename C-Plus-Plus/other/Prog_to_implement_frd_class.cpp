#include<iostream>
using namespace std;
class XYZ
{
	private:
		int a,b;
	public :
		void get()
		{
			cout<<"Enter value of A and B:";
			cin>>a>>b;
		}
		friend class adi;
};
class adi
{
	private:
		float c;
		
	public:
			void show(XYZ  d)
			{
				c=d.a+d.b;
				cout<<"Addition of A and B is:"<<c;
			}
};
int main()
{
	XYZ t;
	t.get();
	adi t2;
	t2.show(t);
}
