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
    - Two Traversal Approach

-------------------------------------------------------
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
    int res=0;// Store result
    int high;// To Store top element of Stack.
    int curr;
    
    for(int i=0;i<n;i++){
        //Find Previous Smaller Element
        while(area.empty()==false && arr[area.top()]>=arr[i]){
            high=area.top();
            area.pop();
            curr=arr[high]* (area.empty() ? i : (i - area.top() - 1));
            res=max(res,curr);
        }
        area.push(i);
    }
    // Remove Element from Stack
    // No Smaller Element on right side
    while(!area.empty()){
        high=area.top();area.pop();
        // If stack is empty, then return (n * arr[high])
        curr=arr[high]* (area.empty() ? n : n - area.top() - 1);
        res=max(res,curr);
    }  
    return res;
} 
// Driver's Code
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Maximum Histogram : "<<getHistogram(arr,n);
    return 0;
}

/* Input : 6 2 5 4 5 1 6
   Output : Maximum Histogram : 12 
   Note : In this One Traversal Approach, Every Element is Pushed once and Poped Once,
   Hence, Time Complexity = O(n)
*/
