class Stack{
    //Initializing stack with an empty array
    constructor(){
        this.arr=[];
        var top=0;
        
    }
    //push_back is used to push the elements in the stack
    push_back(num){
        arr[top]=num;
        top++;
        
    }
    //peek is used to return the element which is on the top of stack
    peek(){
        return arr[top];
    }

    //pop returns the element which is at the top and also removes it from the stack
    pop(){
        if(this.isEmpty()){
            console.log("UnderFlow"); 
            return 0;
        }else{
            var temp=arr[top];
            top--;
            console.log("One element has been removed from the stack");
            return temp;
        }
    }
    //isEmpty is used to check whether the stack is empty or not
    isEmpty(){
        if(top==0){
            return true;
        }else{
            return false;
        }
    }
    // print is used to print all the elements of the stack 
    print(){
        var output="";
        for(var i=0;i<top;i++){
            output+=arr[i]+" ";
        }
        return output;
    }
    //size is used to return the size of the stack
    count(){
        return top;
    }

    
}
//Implementation

const another_arr=[56,75,24,69,47];

//Making an object of the stack class
var mystack=new Stack();

//Checking whether the stack is empty or not by isEmpty() 
if(mystack.isEmpty()==true){
    console.log("The stack is empty right now");
}else{
    console.log("The stack has elements in it");
}

//We can check it by count() also but it will not return true or false
console.log("The size of the current stack is",mystack.count());

//pushing elements in the stack
mystack.push_back(another_arr[0]);

mystack.push_back(another_arr[1]); 

mystack.push_back(another_arr[2]);

//Printing the new size of the array using count()
console.log("The new size of stack is ",count());

//Printing the stack with print()
console.log("The elements present in stack are ",mystack.print());

//Removing the topmost element from the stack by pop()
var removed_element=mystack.pop();

console.log("The element which is popped from the stack is ",removed_element);

//Printing the stack after removing the element using print()
console.log("The elements present after removing one element in stack are ",mystack.print());


