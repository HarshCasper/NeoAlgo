# Binary Search
Binary search is a fast search algorithm with run-time complexity of Ο(log n). 

This search algorithm works on the principle of divide and conquer. 

For this algorithm to work properly, the data collection should be in the sorted form.

let the array be 

a[] ={2,5,6,7,11,13,15};

k=11;//key to find in the array

## binsearch(a,0,6,k)

* while loop 0<=6 so we enter  

> mid= 0+6/2=3

> k!=a[mid]

> k!<a[mid]

> as k> a[mid] so l=mid+1= 3+1 =4

* while loop 4<=6 so we enter

> mid=4+6/2=5

> k!=a[mid]

> k<a[mid] so h=mid-1=5-1=4

*while loop 4<=4 so we enter

> mid=4+4/2=4

> k==a[mid]

> return 4+1(position of key element)

> index starts from zero


Basically a sorted array helps us to guess in which half of the array the element lies and then we take that half and find new mid and further divides
into halves until element found or -1 is returned if not found.

lets see 2 examples when k=11,10.


                                when         k=11
                                 2  ,  5   ,6  ,7  ,11  ,13  ,15      l=0 h=6 mid=3 l<=h   
                                         a[mid]=a[3]=7<k           so l=mid+1=4 h=6
                                      11    ,13    ,15                l=4 h=6 mid=5 l<=h
                                         a[mid]=a[5]=13>k          so h=mid-1=4 l=4
                                             11                       l=4 h=4 mid=4 l<=h
                                         a[mid]=a[4]=11=k             return 4+1=5
                                         
                                         
                                         
                                         
                                when         k=10
                                 2  ,  5   ,6  ,7  ,11  ,13  ,15      l=0 h=6 mid=3 l<=h
                                         a[mid]=a[3]=7<k           so l=mid+1=4 h=6
                                      11    ,13    ,15                l=4 h=6 mid=5 l<=h
                                         a[mid]=a[5]=13>k          so h=mid-1=4 l=4
                                             11                       l=4 h=4 mid=4 l<=h
                                         a[mid]=a[4]=11>k          so h=mid-1=3 l=4 
                                         cant enter loop              l=4 h=3       l!<=h
                                         return -1                 ie element not found
                                
