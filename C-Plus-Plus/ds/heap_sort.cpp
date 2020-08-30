#include<iostream>
using namespace std;

void adjust(int a[] , int n ,int i){
    while(2*i+1<=n){
        int j = 2*i+1;
        if(j+1<=n && a[j+1]>a[j])
            j = j+1;
        if(a[i] >= a[j])
            break;
        else{
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i = j;
        }
    }
}
void heapsort(int a[] , int n){
    for(int i = n/2 - 1;i>=0 ;i--){  //using this for loop for converting it into max heap
        adjust(a,n-1,i);
    }
    cout<<"the max heap is "<<endl;
    for(int i = 0;i<n;i++){    //printing the max heap elements
        cout<<a[i]<<" ";
    }
    cout<<endl;

    while(n>0){           //using this while for given no of elements
        int t = 0;
        t = a[0];            //first swapping of first and last element and then again converting to heap 
        a[0] = a[n-1];
        a[n-1]=t;
        n--;
        adjust(a,n-1,0);
    }


}


int main(){
    int n;
    cin>>n;
    int a[n];
    cout<<"Enter the elements in heap"<<endl;        //accepting the elements in heap
    for(int i=0;i<n;i++){         //heap with index starting from 0
        cin>>a[i];
    }
    heapsort(a,n);            //calling heapsort to sort and convert it into max heap too 
    cout<<"Sorted array is using heapsort is"<<endl;
    for(int i = 0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

}


/*
OUTPUT :- 
10                                                                                                                
Enter the elements in heap                                                                                        
13                                                                                                                
1                                                                                                                 
2                                                                                                                 
3
4                                                                                                                 
4                                                                                                                 
5
6                                                                                                                 
7
8                                                                                                                 
the max heap is                                                                                                   
13 8 5 7 4 4 2 6 3 1                                                                                              
Sorted array is using heapsort is                                                                                 
1 2 3 4 4 5 6 7 8 13    
*/
