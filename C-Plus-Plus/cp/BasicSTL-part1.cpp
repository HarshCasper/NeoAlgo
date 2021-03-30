#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;
int main()
{
    //vector
    vector<int>v1;                               //declaring a vector 
    v1={1,2,3,4,5};                              //initialising the vector as an array
    v1.push_back(6);                             //adding an element at the the last of the vector
    vector<int>v2(5,0);                          //initialising a vector of size 5 with all zeros
    for(int i=0;i<v1.size();i++)                 //traversing the vector using indices
    {
        cout<<v1[i]<<" ";
    }
    cout<<endl;
    for(auto it=v2.begin();it!=v2.end();it++)    //traversing the vector using iterator 
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    for(auto & i : v2) cout<<i<<" ";            //for loop for quick traversal
    cout<<endl;

    //map
    map<int,char>m1;                            //declaring a map
    m1 = { {1,'a'}, {2,'b'} , {3,'c'} };        //initialising the map
    m1.insert(pair<int,char>(4,'d'));           //inserting a pair in the map
    m1[5]='e';                                  //inserting a value at a particular key
    for(auto it=m1.begin();it!=m1.end();it++)   //traversing the map
    {
        cout<<it->first<<" "<<it->second<<" ";
    }
    cout<<endl;
    for(auto & i : m1) cout<<i.first<<" "<<i.second<<" ";   //for-each loop for quick traversal
    cout<<endl;

    //set
    set<int>s1;                                //declaring a set
    s1 = {1,1,2,2,3,3};                        //initialising the set
    s1.insert(5);                              //inserting an element in the set
    for(auto it=s1.begin();it!=s1.end();it++)  //traversing the set
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    for(auto & i : s1) cout<<i<<" ";           //for loop for quick traversal
    return 0;
}

/*
Output:
v1=1,2,3,4,5,6
v2=0,0,0,0,0
m1={{1,a},{2,b},{3,c},{4,d},{5,e}}
s1=1,2,3,5
*/