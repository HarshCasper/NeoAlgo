#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    vector<int>v;
    int n;

    cout<<"Enter the number of elements:";
    cin>>n;

    cout<<"Enter the elements:\n";
    for(int i=0;i<n;i++)
    {
        int num;
        cin >> num;

        //Inserts new element at the end of vector and size increases by 1
        v.push_back(num);
    }

    cout<<"\nElements before sorting:"<<endl;
    for(auto i = v.begin(); i != v.end(); i++)
    {
        cout<< *i <<" ";
    }

    //Sorting by swapping the elements
    int position;
	for (int i = 0; i < v.size(); i++)
	{
		position = i;
		for (int j = i + 1; j < v.size(); j++)
		{
			if (v[j] < v[position])
			{
				position = j;
			}
		}

		int temp = v[position];
		v[position] = v[i];
		v[i] = temp;
	}

	//sort(v.begin(), v.end()) function can also be used for sorting

    cout<<"\nElements after sorting:"<<endl;
    for(auto i = v.begin(); i != v.end(); i++)
    {
        cout<< *i << " ";
    }
    return 0;
}

/*
Example:

Enter the number of elements: 9
Enter the elements:
-6 86 -44 -100 23 54 22 10 1 3

Elements before sorting:
-6 86 -44 -100 23 54 22 10 1

Elements after sorting:
-100 -44 -6 1 10 22 23 54 86

*/