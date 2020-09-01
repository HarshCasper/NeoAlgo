#include <iostream>
#define max 20
using namespace std;

class heap{
    int arr[max+1];
    int n;
    public:
    heap(){
        cout<<"Enter the total no. of elements in a heap u want ?"<<endl;
        cin>>n;
        arr[n+1];
        for(int i =0;i< n+1;i++){
            arr[i] = 0;
        }
        
    }
    void max_heap(){
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
    void insert_max(int i){
        int elem = arr[i];
        while(i>1 && arr[i/2]<elem){
            arr[i] = arr[i/2];
            i = i/2;
        }
        arr[i] = elem;
    }
    void min_heap(){
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
        while(i>1 && arr[i/2]>elem){
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
            break;
            case 2:
            h.min_heap();
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
Enter element 1 :3
Enter element 2 :4
Enter element 3 :5
Enter element 4 :6
Enter element 5 :1
6	5	4	3	1	
Enter the choice below :
1.MAX heap 
2.MIN heap 
3.EXIT
2
Enter element 1 :4
Enter element 2 :3
Enter element 3 :1
Enter element 4 :2
Enter element 5 :6
1	2	3	4	6	
Enter the choice below :
1.MAX heap 
2.MIN heap 
3.EXIT
3
*/
