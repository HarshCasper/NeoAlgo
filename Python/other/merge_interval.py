'''
Given an array of intervals, merge all overlapping intervals, 
and return an array of the non-overlapping intervals that cover all the intervals in the input.

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

'''
def merge(intervals):
  #sort the array 
  intervals.sort()
  #take another empty list
  intervals_stack = []
  for pair in intervals:
    if len(intervals_stack) == 0:  
      intervals_stack.append(pair) #adding all the number in intervals elements in empty list 
    #check number is equal or greater and less than pop elements 
    else:
      current_pair = intervals_stack[-1]
      if current_pair[1]>=pair[0]:
        intervals_stack.pop()
        if current_pair[1]<pair[1]:
          new_pair = [current_pair[0],pair[1]]
          intervals_stack.append(new_pair)
        else:
          new_pair = [current_pair[0],current_pair[1]]
          intervals_stack.append(new_pair)

      else:
        intervals_stack.append(pair)
   # result             
  return intervals_stack

if __name__ == '__main__':
    R = int(input("Enter the number of rows:"))
    C = int(input("Enter the number of columns:"))
    interval = [[int(input("Enter the elements: ")) for x in range (C)] for y in range(R)] 
    print("Overlapping interval: ",interval)
    print("Non-overlapping intervals: ",merge(interval))

"""
Time complexity : O(n^2) 
Space complexity : O(n^2) 

INPUT:-
Enter the number of rows:4
Enter the number of columns:2
Enter the elements: 1
Enter the elements: 3
Enter the elements: 2
Enter the elements: 6
Enter the elements: 8
Enter the elements: 10
Enter the elements: 15
Enter the elements: 18

OUTPUT:-
Overlapping interval:  [[1, 3], [2, 6], [8, 10], [15, 18]]
Non-overlapping intervals:  [[1, 6], [8, 10], [15, 18]]

"""
