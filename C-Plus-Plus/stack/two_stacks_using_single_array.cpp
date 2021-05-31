/*Problem Statement- Cpp program to implement Two stacks using a single array. The operations push and pop is to be performed on two stacks and this should be done in one array. 

Approach- Top of first stack will start from index 0 of the array and move towards right of the array as more elements are pushed into stack 1. Top of second stack will start from the end of the array(size-1) and stack 2 will grow in left direction when elements are pushed into it.
when both the stacks meet each other(top of first stack = top of second stack-1) we cannot push any element in both stacks.
*/

#include <iostream>
#define size 20

using namespace std;

int array[size];
int top1 = -1;
int top2 = size;

/*Function to push element in stack 1*/
void push_in_stack1(int data){
	if(top1 < top2-1){
		array[++top1] = data;
		cout<<data<<" pushed onto stack 1"<<endl;
	}
	/*when the value of top1 = top2-1, the array is completely used up and we cannot push more elements in it.*/
	else{
		cout<<"Stack Overflow!"<<endl;
	}
}

/*Function to push element in stack 2*/
void push_in_stack2(int data){
	if(top1 < top2-1){
  		array[--top2] = data;
  		cout<<data<<" pushed onto stack 2"<<endl;
	}
	else{
		cout<<"Stack Overflow!"<<endl;
	}
}

/*Function to pop an element in stack 1*/
void pop_from_stack1(){
	if(top1 > -1){
		int popped_data = array[top1];
		top1--;
		cout<<popped_data<<" popped from stack 1"<<endl;
	}
	/*when the value of top is -1, there is no element present in the stack, hence pop operation cannot be performed.*/
	else{
		cout<<"Stack 1 is Empty!"<<endl;
	}
}

/*Function to pop an element in stack 2*/
void pop_from_stack2(){
	if(top2 < size){
		int popped_data = array[top2];
		top2++;
		cout<<popped_data<<" popped from stack 2"<<endl;
	}
	else{
		cout<<"Stack 2 is Empty!"<<endl;
	}
}

/*Function to display all the elements in stack 1*/
void display_stack1(){
	cout<<"Displaying elements in Stack 1"<<endl;
	for(int i = top1;i>-1;--i){
		cout<<array[i]<<" "<<endl;
	}
}

/*Function to display all the elements in stack 2*/
void display_stack2(){
	cout<<"Displaying elements in Stack 2"<<endl;
	for(int i = top2;i<size;++i){
		cout<<array[i]<<" "<<endl;
	}
}

/*Driver program */
int main(){
	int ch;
	do{
		cout<<"\n---------MENU---------"<<endl;
		cout<<"1. Push in stack 1\n2. Push in stack 2\n3. Pop from stack 1\n4. Pop from stack 2\n5. Display stack 1\n6. Display stack 2\n7. Exit"<<endl;
		cout<<"Enter your choice: "<<endl;
        cin>>ch;

        switch(ch) {
        	case 1: {
        	int val;
            cout<<"Enter value to be pushed:"<<endl;
            cin>>val;
            push_in_stack1(val);
            break;
        	}
        	case 2:{
        	int val;
        	cout<<"Enter value to be pushed:"<<endl;
            cin>>val;
            push_in_stack2(val);
            break;
        	}
        	case 3: {
            pop_from_stack1();
            break;
        	}
        	case 4: {
            pop_from_stack2();
            break;
        	}
         	case 5: {
            display_stack1();
            break;
        	}
        	case 6: {
            display_stack2();
            break;
         	}
         	case 7: {
            cout<<"Exit"<<endl;
            break;
        	}
         	default: {
            cout<<"Invalid Choice"<<endl;
         	}
      	}
    }while(ch!=7);

    return 0;
}

/*Time Complexity
push - O(1) as we directly push the value at the end of stack.
pop - O(1) as we directly remove the last value at the top of stack.

Space Complexity
O(size)

Sample Output

---------MENU---------
1. Push in stack 1
2. Push in stack 2
3. Pop from stack 1
4. Pop from stack 2
5. Display stack 1
6. Display stack 2
7. Exit
Enter your choice:
1
Enter value to be pushed:
10
10 pushed onto stack 1

---------MENU---------
1. Push in stack 1
2. Push in stack 2
3. Pop from stack 1
4. Pop from stack 2
5. Display stack 1
6. Display stack 2
7. Exit
Enter your choice:
1
Enter value to be pushed:
20
20 pushed onto stack 1

---------MENU---------
1. Push in stack 1
2. Push in stack 2
3. Pop from stack 1
4. Pop from stack 2
5. Display stack 1
6. Display stack 2
7. Exit
Enter your choice:
1
Enter value to be pushed:
30
30 pushed onto stack 1

---------MENU---------
1. Push in stack 1
2. Push in stack 2
3. Pop from stack 1
4. Pop from stack 2
5. Display stack 1
6. Display stack 2
7. Exit
Enter your choice:
3
30 popped from stack 1

---------MENU---------
1. Push in stack 1
2. Push in stack 2
3. Pop from stack 1
4. Pop from stack 2
5. Display stack 1
6. Display stack 2
7. Exit
Enter your choice:
5
Displaying elements in Stack 1
20
10

---------MENU---------
1. Push in stack 1
2. Push in stack 2
3. Pop from stack 1
4. Pop from stack 2
5. Display stack 1
6. Display stack 2
7. Exit
Enter your choice:
2
Enter value to be pushed:
5
5 pushed onto stack 2

---------MENU---------
1. Push in stack 1
2. Push in stack 2
3. Pop from stack 1
4. Pop from stack 2
5. Display stack 1
6. Display stack 2
7. Exit
Enter your choice:
2
Enter value to be pushed:
8
8 pushed onto stack 2

---------MENU---------
1. Push in stack 1
2. Push in stack 2
3. Pop from stack 1
4. Pop from stack 2
5. Display stack 1
6. Display stack 2
7. Exit
Enter your choice:
4
8 popped from stack 2

---------MENU---------
1. Push in stack 1
2. Push in stack 2
3. Pop from stack 1
4. Pop from stack 2
5. Display stack 1
6. Display stack 2
7. Exit
Enter your choice:
6
Displaying elements in Stack 2
5

---------MENU---------
1. Push in stack 1
2. Push in stack 2
3. Pop from stack 1
4. Pop from stack 2
5. Display stack 1
6. Display stack 2
7. Exit
Enter your choice:
7
Exit
*/
