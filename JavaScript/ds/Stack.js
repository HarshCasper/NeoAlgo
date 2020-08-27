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


//Taking input from the user that how many values he/she wants to push into the stack
var input = prompt('Enter the number of values you want to push into the stack');

var another_arr = []; //Declaring the array

input=parseInt(input);

for(var i=0; i<input; i++) {
	
	//Taking array values as an input from the user
	another_arr[i] = prompt('Enter Element ' + (i+1));
}

/*I will be taking the value of input be 3 and array values as 56,75,24 for explanation. */
var input=3;

const another_arr=[56,75,24];

//Making an object of the stack class
var mystack=new Stack();

//Checking whether the stack is empty or not by isEmpty() 
if(mystack.isEmpty()==true){
    console.log("The stack is empty right now");
}else{
    console.log("The stack has elements in it");
}

//We can check it by count() also but it will not return true or false
console.log("The size of the current stack is",mystack.count()); //It will print 0.

//Pushing elements in the stack
for(var i=0; i<input; i++) {
	mystack.push_back(another_arr[i]);
}

//After pushing all the elements then mystack will be [56,75,24]

//Printing the new size of the array using count()
console.log("The new size of stack is ",count()); // It will print 3.

//Printing the stack with print()
console.log("The elements present in stack are ",mystack.print()); //It will print 56 75 24.

//Removing the topmost element from the stack by pop()
var removed_element=mystack.pop(); //This will return 24.

console.log("The element which is popped from the stack is ",removed_element); //It will print 24

//Printing the stack after removing the element using print()
console.log("The elements present after removing one element in stack are ",mystack.print()); //It will print 56 75 


