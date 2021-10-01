/*Problem Statement: 
You are given a max heap, 
your task is to delete the peak elements from the max heap until the last element is left. */

#include<bits/stdc++.h>
using namespace std;

void upward_heapify(vector<int> &max_heap, int index)
{
    if(index==0)
        return;
    
    if(max_heap[(index-1)/2] < max_heap[index])
    {
        int temp = max_heap[index];
        max_heap[index] = max_heap[(index-1)/2];
        max_heap[(index-1)/2] = temp;
        upward_heapify(max_heap, (index-1)/2);
    }
    else
    {
        return;
    }
}

void insert(vector<int> &max_heap, int key)
{
    max_heap.push_back(key);
    upward_heapify(max_heap, max_heap.size()-1);
}

void downward_heapify(vector<int> &max_heap, int index)
{

    int size = max_heap.size();
    if(index>=max_heap.size()/2)
    {
        return;
    }
    if(index*2 + 1 >= size) 
    {
        return;
    }
    if(index*2 + 2 >= size) 
    {
        //If only left child exists
        if(max_heap[index*2 + 1] > max_heap[index]) 
        {
            swap(max_heap[index*2 + 1], max_heap[index]);
            downward_heapify(max_heap, index*2 + 1);
        }
    } 
    else 
    {
        // If both child exists
        int maxIndex = max_heap[index*2 + 1] > max_heap[index*2 + 2] ? index*2 + 1 : index*2 + 2;
        if(max_heap[index] < max_heap[maxIndex]) 
        {
            swap(max_heap[index], max_heap[maxIndex]);
            downward_heapify(max_heap, maxIndex);
        }
    }
}

void delete_peak(vector<int> &max_heap)
{
    swap(max_heap[0],max_heap[max_heap.size()-1]);
    max_heap.pop_back();
    downward_heapify(max_heap, 0);
}

void display(vector<int> &max_heap)
{
    for(int i=0;i<max_heap.size();i++)
        cout<<max_heap[i]<<" ";
    cout<<endl;
}

int main()
{
    vector<int> max_heap;
    int n,temp;
    cout<<"Enter total elements: "<<endl;
    cin>>n;
    cout<<"Enter all elements of max heap: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        insert(max_heap,temp);
    }
    cout<<"Max heap looks like: "<<endl;
    display(max_heap);
    for(int i =0;i<n-1;i++)
    {
        delete_peak(max_heap);
        cout<<"After deleting peak element: "<<endl;
        display(max_heap);
    }
    return 0;
}
/*Example:-

Input:-
Enter total elements: 
5
Enter all elements of max heap: 
1 4 3 2 5

Output:-
Max heap looks like: 
5 4 3 1 2 
After deleting peak element: 
4 2 3 1 
After deleting peak element: 
3 2 1 
After deleting peak element: 
2 1 
After deleting peak element: 
1 

Time Complexity: O(nlogn)
Space Complexity: O(nlogn)
*/

