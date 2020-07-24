#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
  int n;// length of the array
  cin>>n;
  vector<int> ar;
  int enter;
  for(int x=0;x<=n-1;x++)
  {
    cin>>enter;
    ar.push_back(enter);
  }
  int min=0;
  int max=n-1;
  sort(ar.begin(),ar.end());//We just sorted the vector in ascending order
  int s;//element you want to search for
  cin>>s;
  int flag=0;//if this becomes 1 then the element is found else not found
  //firstly we need to sort the array
  while(min<=max)
  {
    int mid=(min+max)/2;
    if(s==ar[mid])
    {
      cout<<s<<" is found at index "<<mid;
      flag=1;
      break;
    }
    else if(s<ar[mid])
    {
      max=mid-1;
    }
    else if(s>ar[mid])
    {
      min=mid+1;
    }

  }
  if(flag==0)
  {
    cout<<"Searched element is not found"<<endl;
  }
  return 0;
}
