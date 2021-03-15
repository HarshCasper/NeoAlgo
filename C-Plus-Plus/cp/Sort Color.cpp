#include <bits/stdc++.h> 
#define MAX 100
using namespace std;

class Sort_Col {
	int n;
	int a[MAX];
public:
    void sort_colors(int a[]) 
	{ 
	int lo = 0; 
	int hi = n - 1; 
	int mid = 0; 

	// Iterate till all the elements 
	// are sorted 
	while (mid <= hi) { 
		switch (a[mid]) { 

		// If the element is 0 
		case 0: 
			swap(a[lo++], a[mid++]); 
			break; 

		// If the element is 1 . 
		case 1: 
			mid++; 
			break; 

		// If the element is 2 
		case 2: 
			swap(a[mid], a[hi--]); 
			break; 
		} 
	} 
}
    
    void set_data(){
    	cout<<"Enter number of elements: "<<endl;
    	cin>>n;
    	cout << "Input Numbers:" << endl;

		for (int i = 0; i < n; i++) 
			{
				cin >> a[i];
			}
	}
	
	void display(){
		sort_colors(a);
		
		cout<<"[";
		for (int i = 0; i < n; i++) 
		{
			cout << a[i] <<"  ";
		}
		cout<<"]";
	}
        
};

int main(){
	Sort_Col sc;
	sc.set_data();
	sc.display();
	return 0;	
}
