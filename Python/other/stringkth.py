'''
A program to remove the kth index from a string and print the remaining string.In case the value of k
is greater than length of string then return the complete string as it is.
'''
#main function
def main():
    s=input("enter a string")
    k=int(input("enter the index"))
    l=len(s)
	#Check whether the value of k is greater than length
    if(k>l):
        print(s)
    #If k is less than length of string then remove the kth index value
    else:
         s1=''
         for i in range(0,l):
             if(i!=k):
                 s1=s1+s[i]
         print(s1)
if __name__== "__main__":
    main()

'''
Time Complexity:O(n),n is length of string
Space Complexity:O(1)

Input/Output:
enter a string python
enter the index 2
pyhon
'''
