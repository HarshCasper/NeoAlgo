#include<iostream>
using namespace std;
int main() {
	int n;
	cin>>n;
	int flag=1;
	if(n>1){
	for(int i=2;i<n-1;i++)
	{
		if(n%i==0)
		{cout<<"Not Prime"<<endl;
		flag=0;
		break;
	}
	else
	{flag=1;
	
	}}
		if(flag==1)
		cout<<"Prime"<<endl;}
	return 0;
}