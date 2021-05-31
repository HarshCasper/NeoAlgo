# Sleep Sort:
In this sort, we create different threads for every element within the input array, then each thread sleeps for an amount of the duration which is proportional to the value of corresponding array element.<br>
Hence, the thread having the smallest amount of sleeping time wakes up first and therefore the number gets printed and then the second least element and so on. The largest element wakes up after an extended time, after which the element gets printed at the last. Thus, the output is a sorted one.<br>
All this multithreading process takes place in the background at the core level of the operating system. We don't get to understand anything about what’s happening within the background; hence this is often referred to as a “mysterious” algorithm .

### Analysis:
•	1) Sleep : This thread will be in sleep mode till arr[i] milliseconds (where arr[i] is the array element with which the thread is associated to). This is done using Sleep() function. The Sleep(n) function suspends all the activities associated with this thread till the timer reaches ‘n’ milliseconds. Hence if we write Sleep(1000), so it means that the thread will sleep for 1000 milliseconds which is equivalent to 1 second.<br>
•	2) Print : When the thread ‘wakes’ after the sleep of certain time, then this function prints the array element that is the arr[i] which this thread is associated to.<br>
•	After the creation of threads, we process these threads. This is done using WaitForMultipleObjects().


### Limitations:
•	This sorting cannot be used for the negative numbers.<br>
•	A large input array may gradually slow down the processing.<br>
•	Accuracy is not good always.

### Complexities:
•	Time complexity:  O(nlog n + max(input)).<br>
•	There is no space complexity as everything is performed by the internal priority queue of operating system.
