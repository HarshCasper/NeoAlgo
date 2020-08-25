class Stack{
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
    size(){
        return top;
    }

    
}
//Implementation

//Making an object of the stack class
var mystack=new Stack();

//Checking whether the stack is empty or not
console.log(mystack.isEmpty()); 

//We can check it by size() also 
console.log(mystack.size());

//pushing elements in the stack
mystack.push_back(56); 
mystack.push_back(75); 
mystack.push_back(24);

//Printing the new size of the array
console.log("The new size of stack is ",top);

//Printing the stack
console.log("The elements present in stack are ",mystack.print());

//Removing the topmost element from the stack
mystack.pop();

//Printing the stack after removing the element
console.log("The elements present after removing one element in stack are ",mystack.print());