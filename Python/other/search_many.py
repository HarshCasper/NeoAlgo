'''
A program that returns a boolean value depending upon the occurence of an integer x in the given sequence.
If the number of occurences of x are atmost k,which is another integer,then it return true else false
'''
#search function which returns a boolean value
def search(s,x,k):
    c=0
    for i in s:
		#counts if x is there in sequence s or not
        if (i==x):
            c=c+1
    if(c<=k):
        return True
    else:
        return False
#Driver's code
def main():
    sq=[]
    n=int(input("Enter the number of items in list"))
	#Creating a list by taking input from user
    for i in range(n):
        sq.append(int(input("Enter element")))
    a=int(input("Enter the value to be searched"))
    b=int(input("Enter the total number of occurence"))
	#Calling the search function and printing true or false depending upon the condition
    print(search(sq,a,b))
if __name__=="__main__":
    main()

'''
Time Complexity:O(n)
Space Complexity:O(n)

Input/Output:
Enter the number of items in list 4

Enter element 10

Enter element 17

Enter element 15

Enter element 12

Enter the value to be searched 15

Enter the total number of occurence1
True
'''
