#include <iostream>
using namespace std;

// This is a function template
template <class X> void swap(X *a, X *b)
{
	X temp;
	
	temp = *a;
	*a = *b;
	*b = temp;
}

int main(){
	
	int n,m;
	cout<<"\n Enter two Integer :";
	cin>>n>>m;
	
	char a,b;
	cout<<"\n Enter two Charcter :";
	cin>>a>>b;
	
	swap(&n,&m);  // swap integer
	swap(&a,&b); // swap char
	
	cout<<"\n Swapped n,m :"<<n<<" "<<m<<endl;
    cout<<"\n Swapped a,b :"<<a<<" "<<b<<endl;	
    
    return 0;
}
