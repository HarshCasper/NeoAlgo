#include<bits/stdc++.h>
using namespace std;
class heap{
    int n;
    int arr[1000];
    public:
    heap(){
        cout<<"Enter the total no. of elements in a heap u want ?"<<endl;
        cin>>n;
        memset(arr,0,n+1);       //initialising the value 0 
    }
    void max_heap(){            //max heap function accepting values and calling insert_max to insert element to acc to max heap condition
        char ch;
        int j = n;
        int m ,i=1;
        do{
            cout<<"Enter element "<<i<<" :";
            cin>>m;
            arr[i] = m;
            insert_max(i);
            i++;
            j--;
        }while(j>=1);
        disp();
    }
    void insert_max(int i){ //always checking from its parent element if smaller then swapping is to be done
        int elem = arr[i];
        while(i>1 && arr[i/2]<elem){
            arr[i] = arr[i/2];
            i = i/2;
        }
        arr[i] = elem;
    }
    void min_heap(){ //min heap function accepting values and calling insert_min to insert element to acc to min heap condition 
        char ch;
        int j = n;
        int m ,i=1;
        do{
            cout<<"Enter element "<<i<<" :";
            cin>>m;
            arr[i] = m;
            insert_min(i);
            i++;
            j--;
        }while(j>=1);
        disp();
    }
    void insert_min(int i){
        int elem = arr[i];
        while(i>1 && arr[i/2]>elem){      //always checking from its parent element if greater then swapping is to be done
            arr[i] = arr[i/2];
            i = i/2;
        }
        arr[i] = elem;
    }
    void disp(){
        for(int i=1;i<n+1;i++){
            cout<<arr[i]<<"\t";
        }
        cout<<"\n";
    }
};
int main()
{
    heap h;
    int ch;
    do{
        cout<<"Enter the choice below :\n1.MAX heap \n2.MIN heap \n3.EXIT\n";
        cin>>ch;
        switch(ch)
        {
            case 1:
            h.max_heap();
            cout<<"Max heap created"<<endl;
            break;
            case 2:
            h.min_heap();
            cout<<"Min heap created"<<endl;
            break;
            case 3:
            exit(0);
        }
    }while(ch!=3);
    return 0;
}
/*
Enter the total no. of elements in a heap u want ?
5
Enter the choice below :
1.MAX heap 
2.MIN heap 
3.EXIT
1
Enter element 1 :8
Enter element 2 :4
Enter element 3 :12
Enter element 4 :4
Enter element 5 :2
12	4	8	4	2	
Max heap created
Enter the choice below :
1.MAX heap 
2.MIN heap 
3.EXIT
2
Enter element 1 :5
Enter element 2 :2
Enter element 3 :7
Enter element 4 :5
Enter element 5 :1
1	2	7	5	5	
Min heap created
Enter the choice below :
1.MAX heap 
2.MIN heap 
3.EXIT

*/
