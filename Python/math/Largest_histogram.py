'''
Problem :- Given n non-negative integers representing the histogram's bar height where 
the width of each bar is 1, find the area of largest rectangle in the histogram.

Purpose :- To find the largest rectangular area in histogram.

Time Complexity :- O(n)
Space Complexity:- O(n)
'''

#Getting the input from user
a = []
n=int(input("Enter the no.of Rectangles :"))
for i in range(n):
    x=int(input("Enter the heights of Rectangles : "))
    a.append(x)
    
def Largest_Rectangle(histogram):
    a=[]
    area=0
    i=0
    histogram.append(0)
    
    while i<len(histogram):
        #if stack is empty or rectangle with greater height is found then push the index into stack
        if len(a) == 0 or histogram[a[-1]] < histogram[i]:
                          a.append(i)
                          i += 1
        #if rectangle of smaller height is found pop the top element from the stack and calculate area              
        else:
            top = a.pop()
            area = max(area,histogram[top]*(i-a[-1] - 1 if a else i))
    return area

#Printing the area of largest rectangle
print('Largest Rectangular area in the Histogram is :',Largest_Rectangle(a))

'''
Sample Input/Output :-
Input:-
Enter the no.of Rectangles :5
Enter the heights of Rectangles : 5
Enter the heights of Rectangles : 3
Enter the heights of Rectangles : 1
Enter the heights of Rectangles : 2
Enter the heights of Rectangles : 4

Output :-
Largest Rectangular area in the Histogram is : 6
'''