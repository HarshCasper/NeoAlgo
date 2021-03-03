/*
Largest Rectangular Area in a Histogram
---------------------------------------
Given a Heights of Bars and Width of Bars is 1 Unit. 
Find out the Largest Rectangular area in a Histogram.
-----------------------------------------------------

Note : We have Three approaches to solve this particular problem.
1. Efficient Approach 
    - Time Complexity : O(n)
    - One Traversal Approach 
2. Naive Approach  
    - Time Complexity : θ(n^2)
3. Better Approach
    - Time Complexity : O(n) 
*/
#include<iostream>
#include<stack>
using namespace std;
/* Efficeient Approach
----------------------------------------------------------------------------------
Algorithm:-
1). Create a Stack "area".
2). int res = 0;
3). Then, we have tp find Previous Smaller instead of Previous Greater Element.
4). for(int i=0;i<n;i++){
    while(area.empty()==false && arr[area.top()]>=arr[i]){
            high=area.top();
            area.pop();
            curr=arr[high]* (area.empty() ? i : i - area.top() - 1);
            res=max(res,curr);
        }
        area.push(i);
        //when we push item i in to stack, we have to ensure that item below it is smaller.
    }
5).Using next smaller and previous smaller we can find out the length of bar,
    which can form rectangle with this being the smallest height bar.
6).After completing the first while loop, we have another While Loop which do not have Next Smaller Element.
   these elements do not have any Smaller element on his Right Side.
7). After Removal of every element and stack become empty, the fall to base case where we multiply value 'n'
    with arr[high] find max(res,curr) and simply Return result.

Time Complexity : O(n)
* ONE TRAVERSAL SOLUTION *
--------------------------------------------------------------------------------------
*/
int getHistogram(int arr[],int n){
    stack <int> area;
    int res=0;
    int high;
    int curr;
    
    for(int i=0;i<n;i++){
        while(area.empty()==false && arr[area.top()]>=arr[i]){
            high=area.top();
            area.pop();
            curr=arr[high]* (area.empty() ? i : i - area.top() - 1);
            res=max(res,curr);
        }
        area.push(i);
    }
    while(area.empty()==false){
        high=area.top();area.pop();
        curr=arr[high]* (area.empty() ? n : n - area.top() - 1);
        res=max(res,curr);
    }
    
    return res;
} 
/* NAIVE APPROACH
-----------------------------------
int getHistogram(int arr[],int n){

    int res = 0; // Initilize result as Zero.

    // We have to traverse every bar,
    // Considering every bar as Smallest Height of Histogram.
    for(int i=0;i<n;i++){
        int curr = arr[i];
        //Traverse Left Part
        for(int j=i-1;j>=0;j--){
        // Here we find out greater values, 
        // as soon as we find Smaller Break out of the Loop.
            if(arr[j] >= arr[i]){
                // We use arr[i] becasue this is the Smallest Bar we are Considering.
                curr += arr[i];
            }
        }
        //Traverse Right Part, Using same Logic as above.
        for(int j=i+1;j<=n;j++){
            if(arr[j] >= arr[i])
                curr += arr[i];
            else
                break;
        }
        //Getting the Maximum, Either result or current value.
        res = max(res,curr);
    }
    return res;
}
*/

/*Better Approach
---------------------------------------------------
Algorithm :-
!). Initialize res = 0;
2). Find Previous Smaller Element for Every Element.
3). Find Next Smaller Element for Every Element.
4). Do following for Every Element arr[i];
    curr = arr[i];
    curr += (i - ps[i] - 1) * arr[i];
    curr += (ns[i] - i - 1) * arr[i];
    res = max(res,curr);
5). return res;

Time Complexity : O(n)
----------------------------------------------------
Implementation:-
----------------------------------------------------
int getHistogram(int arr[],int n){
    int res=0;
    int ps[n],ns[n];
    
    stack <int> s;
    s.push(0);

    //Find Previous Smaller Element
    for(int i=0;i<n;i++){
        while(s.empty()==false && arr[s.top()]>=arr[i])
            s.pop();
        int pse=s.empty()?-1:s.top();
        ps[i]=pse;
        s.push(i);
    }
    
    while(s.empty()==false){
        s.pop();
    }
    s.push(n-1);
    // Find Next 
    for(int i=n-1;i>0;i--){
        while(s.empty()==false && arr[s.top()]>=arr[i])
            s.pop();
        int nse=s.empty()?n:s.top();
        ns[i]=nse;
        s.push(i);
    }
    
    for(int i=0;i<n;i++){
        int curr=arr[i];
        curr+=(i-ps[i]-1)*arr[i];
        curr+=(ns[i]-i-1)*arr[i];
        res=max(res,curr);
    }
    return res;
}
*/
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        cout<<"Maximum Histogram :"<<getHistogram(arr,n);
    }
    return 0;
}