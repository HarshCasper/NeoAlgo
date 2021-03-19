/*A priority queue is a data structure for maintaining a set S of elements, each
with an associated value called a key. The set is so created so that the highest priority 
element is always at the head of the set..
Here, It is implemented using the Max-heap data structure. Operations it perform are return Maximum element,
remove maximum element, insert element etc*/

#include<iostream>
#include<conio.h>
#include<math.h>
#include"HEAP_18.cpp" //max-heap file included to implement Max-Priority Queues.
using namespace std;

//class for handling the exceptions
class RuntimeException{
	public:
		RuntimeException(const string&err){
			cout<<err;
		}
};
class HeapEmpty: public RuntimeException{
	public:
		HeapEmpty(const string&err):RuntimeException(err){
		}
};


template<class H>
class PriorityClass{
	HeapClass<H> h1;// HeapClass object
	public:
	 void max_heap_insert_priority(H Key);
	  H	heap_extract_max_priority();
      H heap_maximum_priority();
      void display_priority();
      int size();
      bool empty_priority();
		
};

// function which checks whether the priority queue is empty or not
template<class H>
bool PriorityClass<H>::empty_priority(){
 h1.empty();
}

// function which counts and returns the total number of elements present in the priority queue
template<class H>
int PriorityClass<H>::size(){
	if(empty_priority())
	   throw HeapEmpty("PRIORITY QUEUE IS EMPTY!!");
	cout<<"TOTAL NUMBER OF ELEMENT : ";
  return h1.count();
}

// function which diplays the priority queue
template<class H>
void PriorityClass<H>::display_priority(){
	if(empty_priority())
	   throw HeapEmpty("PRIORITY QUEUE IS EMPTY!!");
 cout<<"PRIROITY QUEUE : [ ";
 h1.display();
 cout<<"]"<<endl;
}

//function which removes the maximum element from the priority queue
template<class H>
H PriorityClass<H>::heap_extract_max_priority(){
	if(empty_priority())
	   throw HeapEmpty("PRIORITY QUEUE IS EMPTY!!");
	cout<<"DELETED ELEMENT : ";
    return h1.heap_extract_max();
}

//function which inserts an element in the priority queue
template<class H>
void PriorityClass<H>::max_heap_insert_priority(H Key){
 h1.heap_insert(Key);
}

//function which returns the maximum value element from the priority queue
template<class H>
H PriorityClass<H>::heap_maximum_priority(){
	if(empty_priority())
	   throw HeapEmpty("PRIORITY QUEUE IS EMPTY!!");
	cout<<"MAXIMUM OF PRIORITY QUEUE : ";
    return h1.heap_max();
}

int main(){
	int choice;
	char ans;
	cout<<"\n\t  PRIORITY QUEUE";
	cout<<"\n\t******************\n\n";
	cout<<"ENTER TYPE : 1. INTEGER   2.DOUBLE"<<endl;
	cin>>choice;
	switch(choice){
		case 1:
			{
			PriorityClass<int>ob;
			int opt,element;
			do{
				cout<<"\n\nENTER YOUR CHOICE\n"
				"1.INSERT ELEMENTS\n"
				"2.DELETE MAXIMUM ELEMENT\n"
				"3.SHOW MAXIMUM ELEMENT\n"
				"4.SIZE OF PRIORITY QUEUE\n"
				"5.DISPLAY\n";
				cin>>opt;
				
				if(opt==1){
					char ch;
					cout<<"ENTER ELEMENT : ";
					cin>>element;
					ob.max_heap_insert_priority(element);
					cout<<"INSERT MORE ELEMENTS : [Y/N] ";
					cin>>ch;
					while(ch=='y'||ch=='Y'){
					    cout<<"ENTER ELEMENT : ";
					    cin>>element;
					    ob.max_heap_insert_priority(element);
					    cout<<"INSERT MORE ELEMENTS : [Y/N] ";
					    cin>>ch;
					}
				}
				else if(opt==2){
					try{
					cout<<ob.heap_extract_max_priority()<<endl;	
					}catch(HeapEmpty &e){}
				}
				else if(opt==3){
					try{
					cout<<ob.heap_maximum_priority()<<endl;	
					}catch(HeapEmpty &e){}
				}
				else if(opt==4){
					try{
					cout<<ob.size()<<endl;	
					}catch(HeapEmpty &e){}
				}
				else if(opt==5){
					try{
					ob.display_priority();	
					}catch(HeapEmpty &e){}
				}
				else cout<<"INVALID OPTION\n";
				cout<<"\nDO YOU WANT TO CONTINUE [Y/N] : ";
				cin>>ans;	
			}while(ans=='y'||ans=='Y');
			}
			
		break;
		
		case 2:
			{
				PriorityClass<double>ob1;
			    int opt;
			    double element;
			do{
				cout<<"\n\nENTER YOUR CHOICE\n"
				"1.INSERT ELEMENTS\n"
				"2.DELETE MAXIMUM ELEMENT\n"
				"3.SHOW MAXIMUM ELEMENT\n"
				"4.SIZE OF PRIORITY QUEUE\n"
				"5.DISPLAY\n";
				cin>>opt;
				
				if(opt==1){
					char ch;
					cout<<"ENTER ELEMENT : ";
					cin>>element;
					ob1.max_heap_insert_priority(element);
					cout<<"INSERT MORE ELEMENTS : [Y/N] ";
					cin>>ch;
					while(ch=='y'||ch=='Y'){
					    cout<<"ENTER ELEMENT : ";
					    cin>>element;
					    ob1.max_heap_insert_priority(element);
					    cout<<"INSERT MORE ELEMENTS : [Y/N] ";
					    cin>>ch;
					}
				}
				else if(opt==2){
					try{
					cout<<ob1.heap_extract_max_priority()<<endl;	
					}catch(HeapEmpty &e){}
				}
				else if(opt==3){
					try{
					cout<<ob1.heap_maximum_priority()<<endl;	
					}catch(HeapEmpty &e){}
				}
				else if(opt==4){
					try{
					cout<<ob1.size()<<endl;	
					}catch(HeapEmpty &e){}
				}
				else if(opt==5){
					try{
					ob1.display_priority();	
					}catch(HeapEmpty &e){}
				}
				else cout<<"INVALID OPTION\n";
				cout<<"\nDO YOU WANT TO CONTINUE [Y/N] : ";
				cin>>ans;	
			}while(ans=='y'||ans=='Y');
			}
		break;
		
		default :
			cout<<"INVALID OPTION\n";
	}
	getch();
	return 0;
}
/* 
 Input - 15,13,9,12,6,8
 Output-[ 15,13,9,12,6,8,]
 
 Time Complexity -O(nlogn)
*/
