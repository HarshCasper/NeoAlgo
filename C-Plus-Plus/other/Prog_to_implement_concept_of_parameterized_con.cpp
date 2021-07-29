#include<iostream>
using namespace std;
class student
{
	int rollno;
	float marks;
	public:
	student(int r , float m);
};
student::student(int r, float m)
{
	rollno=r;
	marks=m;
	cout<<"\nroll no. of student is:"<<rollno;
	cout<<"\nmarks of student is:"<<marks;
}
int main()
{
	student s(1,90.30);
	return 0;
}
