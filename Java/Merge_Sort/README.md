# Merge_sort

 Merge Sort is a Divide and Conquer algorithm.

 It divides input array in two halves, calls itself for the two halves and then merges the two sorted halves.

 The merge_sort() is used to divide the array into two halves.

 The merge() function is used for merging two halves.

 I used a recursive approach.

 To better understand the algorithm lets trace the program with example we took.

a[]= {8, 1,10,5,4,2,7,3}

## merge_sort(a,0,7) is called

In merge_sort() (0<7) is checked then
  
mid=0+7/2=3
  
* merge_sort(a,0,3)
  
  - (0<3) is checked then
   
  - mid=0+3/2=1
  
  - merge_sort(a,0,1)
   
   - (0<1) is checked then
    
   - mid=0+1/2=0
    
   - merge_sort(a,0,0)
    
    - 0!<0
     
    - call terminates so it goes back to previous call
     
    - till now merge_sort(a,l,mid) was being called now merge_sort(a,mid+1,h) will be called.
     
   - merge_sort(a,1,1)
    
    - single element so call terminates it goes back to previous call.
     
    - now merging has to be done ie calling of merge(a,l,mid,h)
     
  - merge(a,0,0,1)
  
   - comparision takes place and new result becomes {1,8} which is stored in b.
     
   - it goes to previous call
     
  - merge_sort(a,2,3)

   - (2<3) is checked then
    
   - mid=2+3/2=2
    
   - merge_sort(a,2,2)
    
    - single element so call terminates it goes back to previous call.
     
    - call terminates so it goes back to previous call
     
    - merge_sort(a,3,3)

     - single element so call terminates it goes back to previous call.

     - now merging has to be done ie calling of merge(a,l,mid,h)
     
   - merge(a,2,2,3)
   
    - comparision takes place and new result becomes {5,10} which is stored in b.
    
    - it goes to previous call.
    
* now merging has to be done ie calling of merge(a,0,1,3) and new result is {1,5,8,10}
  
Similarly for second part

* now merging has to be done ie calling of merge(a,4,5,7) and new result is {2,3,4,7}

* now merging has to be done ie calling of merge(a,0,3,7) and new result is {1,2,3,4,5,7,8,10}


## merge(a,0,3,7) can be seen as example to see how the function works
i=k=0  j=4

while loop (i<=4 && j<=7)

* comparing 1st element and 5th element the i & k or j& k is incremented
* comparing 2nd element and 6th element the i & k or j& k is incremented
* comparing 3rd element and 7th element the i & k or j& k is incremented
* comparing 4th element and 8th element the i & k or j& k is incremented

the other 2 for loops are if the list has been divided into uneven parts ie 4  & 5 when we try to merge we compare upto 4 th 
element and 5th element is inserted without comparision as there is nothing to compare.

last loop is to copy b to a.

