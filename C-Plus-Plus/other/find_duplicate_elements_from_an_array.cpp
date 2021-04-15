/*
Given an array of N elements, each element's occurrence in the array can be more than once. Find all elements whose occurrence is more than 1.
Formally find all duplicate elements of the array. This can be done with the help of map and set data structure.
*/

using namespace std;

vector<int>removeDuplicates(int*a,int size){
	vector<int>output;
	unordered_map<int,bool>seen;
	for(int i=0;i<size;i++){
		if(seen.count(a[i])>0){
			 continue;
		}
		seen[a[i]]=true;
		output.push_back(a[i]);
	}
	return output;
}

int main()
{
    cout << "Enter the size of the array : ";
    int N; 
    cin >> N;
    int ar[N + 1];
    cout << "Enter array elements :\n";
    for(int i = 0; i < N; i++)
    {
        cin >> ar[i];
    }
    vector<int>output=removeDuplicates(ar,ar.size());
	for(int i=0;i<output.size();i++){
		cout<<output[i]<<endl;
	}

/*
Standard Input:

Enter the size of the array : 11
Enter array elements :
1 2 3 3 2 1 4 6 3 5 5

Output:
1
2
3
4
6
5

------------------------------------------------------------------------
Time Complexity : O(logN)
Space Complexity : O(N)

*/
