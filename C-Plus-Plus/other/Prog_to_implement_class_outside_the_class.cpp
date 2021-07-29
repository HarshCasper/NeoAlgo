#include<iostream>
using namespace std;
class student
{
	public:
		int rno;
		char name[10];
		char address[20];
		void getstudinfo();
		void putstudinfo();
};
void student::getstudinfo()
{
	cout<<"Enter Roll no. of student:";
	cin>>rno;
	cout<<"Enter Name of student:";
	cin>>name;
	cout<<"Enter address of student:";
	cin>>address;
}
void student::putstudinfo()
{
	cout<<"Roll no of student:"<<rno<<"\n";
	cout<<"Name of student:"<<name<<"\n";
	cout<<"Address of student:"<<address<<"\n";
}
int main()
{
	student s;
	s.getstudinfo();
	s.putstudinfo();
}

