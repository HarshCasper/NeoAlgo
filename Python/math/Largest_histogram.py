'''
Problem :- Given n non-negative integers representing the histogram's bar height where
the width of each bar is 1, find the area of largest rectangle in the histogram.

Purpose :- To find the largest rectangular area in histogram.

Time Complexity :- O(n)
Space Complexity:- O(n)
'''


def Largest_Rectangle(histogram):
    heights = []
    area = 0
    i = 0
    histogram.append(0)
    while i < len(histogram):
        # if stack is empty or rectangle with greater height is found
        # then push the index into stack
        if len(heights) == 0 or histogram[heights[-1]] < histogram[i]:
            heights.append(i)
            i += 1
        # if rectangle of smaller height is found pop the top element
        # from the stack and calculate area
        else:
            top = heights.pop()
            area = max(area, histogram[top] * (i - heights[-1] - 1 if heights else i))
    return area


def main():
    # Getting the input from user
    heights = []
    n = int(input("Enter the no.of Rectangles :"))
    for i in range(n):
        height = int(input("Enter the heights of Rectangles : "))
        heights.append(height)

    # Printing the area of largest rectangle
    print('Largest Rectangular area in the Histogram is :', Largest_Rectangle(heights))


if __name__ == "__main__":
    main()


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
