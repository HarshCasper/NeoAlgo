'''

What is Pancake Sorting??
Given an array of integers, sort the array using a given Flip operation.
This is called Pancake sorting because this uses Flip operation which is analogous to flipping pancakes.
For example, if there are 5 pancakes stacked one of top of the other, then Flip operation is when a spatula is inserted at any point in the stack and then turned upside down flipping all pancakes above it.

'''


'''
Pancake sorting uses only one operations i.e. flip operation 
flip(arr,i): Reverse array from 0 to i
'''

'''
Algorithm for Pancake Sorting
1.) Start form the length of the array and reduce it by one while its greater than one
1 Let current length be length. do following for len 
--- Find index of maximum element in arr[0..length-1].Let the index of maximum element be i.
--- Call flip(arr,i)
--- Call flip(arr,length-1)
'''


#Python Program for sorting the array

#Reverse the array[0..i]
def flip(arr,i):
    st = 0
    while st < i:
        temp = arr[st]
        arr[st]  = arr[i]
        arr[i] = temp
        st+=1
        i-=1


#Return index of maximum element in
def maxx(arr,n):
    maxx=0
    for i in range(0,n):
        if arr[i]>arr[maxx]:
            maxx=i
    return maxx



#Writing the function for Pancake Sorting using array arr and length of arr n as parameters
def PancakeSoritng(arr,n):

    #Taking the cuurent length of array as length
    # and reducing it by 1
    length = n
    while length > 1:
        #finding index of maximum element
        # in arr[0..length-1]
        i = maxx(arr,length)

        #Moving maximum elelemnt to end
        #if not present already
        if i!=length-1:
            #first moving maximum element to beginning
            flip(arr,i)

            #now moving maximum element to end
            flip(arr,length-1)
        length-=1


#Testing our function on a user array
user_input = input("Enter input numbers separated by a comma\n").strip()

#Storing value of input element in the variable arr
arr= [int(elem) for elem in user_input.split(',')]

#Storing length of array in n
n=len(arr)
print('Length of array is {}'.format(n))

#Applying the fuction on the input array
PancakeSoritng(arr,n)

#Printing the sorted array
print("The Sorted array is \n{}".format(arr))

"""
#Sample Input 
[2,6,5,1,8,6,9]

#Sample Output
Length of the array is 7
The Sorted array is [1,2,5,6,6,8,9]

"""

