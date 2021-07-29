#include<iostream>
using namespace std;
class student
{
	int rollno;
	float marks;
	public:
	student();
	student(int a, float b);
	student(student &t);
};
student::student()
{
	rollno=12;
	marks=78.40;
	cout<<"\n rollno of student is:"<<rollno;
	cout<<"\n marks of student is:"<<marks;
}
student::student(int a, float b)
{
	rollno=a;
	marks=b;
	cout<<"\n rollno of student is:"<<rollno;
	cout<<"\n marks of student is:"<<marks;	
}

student::student(student & t)
{
	rollno=t.rollno;
	marks=t.marks;
	cout<<"\n rollno of student is:"<<rollno;
	cout<<"\n marks of student is:"<<marks;	
}
int main()
{
 
	student s1();
	student s2(4 , 80.00);
	student s3(s2);
}
