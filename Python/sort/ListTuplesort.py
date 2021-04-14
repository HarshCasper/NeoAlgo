'''
It is a python program to get a list having tuples contained,
to be sorted in ascending order on the basis of the last element 
in each tuple of a list
'''

#This is a function which is used to reverse the elements of tuples 
#It returns a list of reversed tuples
def lys(ls):
    return [tuple(reversed(tup)) for tup in ls]
#Driver's code
def main():
    #It is used to take input a list from user which will contain tuples
    #It makes use of map function as it simplifies the process
    ls=list(tuple(map(int,input().split()))for r in range(int(input('enter number of elements')))) 
    #Here li will store the list of reversed tuples
    li=lys(ls) 
    #It will sort the list in ascending order
    li.sort() 
    #Again we call the function lys so that after sorting the elements get arranged back
    print(lys(li))
if __name__== "__main__":
    main()


'''
Time Complexity-O(nlogn)
Space Complexity-O(n)
Input/Output-
Enter number of elements 5
5 6 
7 8
6 7
1 2
3 4 
[(1, 2), (3, 4), (5, 6), (6, 7), (7, 8)]
'''
