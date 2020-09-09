
class Queue {

        int front, rear;
	int arr[] = new int[100005];

    Queue()
        {
		front=0;
		rear=0;
	}
	
	void push(int x)
	{
	   arr[rear]=x;
	   rear++;
	} 

	int pop()
	{
	    if(front==rear){
	        return -1;
	    }
	    int curr=arr[front];
	    front++;
	    return curr;
	}

	int pop()
	{
	    if(front==rear){
	        return -1;
	    }
	    int curr=arr[front];
	    front++;
	    return curr;
	} 
        
        int peek()
	{
	    if(front==rear){
	        return arr[front];
	    }
	    int curr=arr[rear];
	    return arr[rear];
	} 
}
