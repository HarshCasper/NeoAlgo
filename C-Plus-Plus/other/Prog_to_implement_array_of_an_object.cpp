#include<iostream>
using namespace std;
class vehicle
{
	public:
		int vcode;
		char vname[20];
		void getinfo()
		{
			cout<<"Enter code of Vehicle: ";
			cin>>vcode;
			cout<<"Enter name of vehicle: ";
			cin>>vname;
		}
		void putinfo()
		{
			cout<<"Code of vehicle is: "<<vcode<<"\n";
			cout<<"Name of  vehicle is: "<<vname<<"\n";
		}
};
int main()
{
	vehicle v[3];
	for(int i=1;i<=3;i++)
	{
		cout<<"Enter Information for "<<i<<" vehicle is\n";
		v[i].getinfo();
	}
	for(int i=1;i<=3;i++)
	{
		cout<<"Information of "<<i<<" vehicle is\n";
		v[i].putinfo();
	}
	return 0;

}

