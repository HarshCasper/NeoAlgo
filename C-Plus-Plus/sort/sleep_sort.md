[Sleeping](https://media.tenor.com/images/d5f82742a3331e777fc302db2fc80c7d/tenor.gif)
## Sleep Sort in C++ 
In this algorithm we create different threads for each of the elements in the input array and each thread sleeps for an *amount of time* which is **proportional** to the *value of corresponding array element*. This sorting algorithm is a perfect demonstration of multi-threading and scheduling done by OS.

Hence, the thread having the least amount of sleeping time wakes up first and the number gets printed and then the second least element and so on. The largest element wakes up after a long time and then the element gets printed at the last. Thus the output is a sorted one.

All this multithreading process happens in background and at the core of the OS.

## Complexities
1. **Time Complexity:** O(NlogN + max(input))
2. **Space Complexity:** All things are done by internal priority queue in OS. Therefore, auxillary space can be ignored.

## Limitations
* This algorithm won’t work for negative numbers as a thread cannot sleep for a negative amount of time.
    
* Since this algorithm depends on the input elements, so a huge number in the input array causes this algorithm to slow down drastically (as the thread associated with that number has to sleep for a long time). So even if the input array element contains only 2 elements, like- {2, 100000000}, then also we have to wait for a much longer duration to sort.
