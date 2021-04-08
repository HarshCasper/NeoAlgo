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

interval = [[1, 3], [2, 6], [8, 10], [15, 18]]  
print("Overlapping interval: ",interval)
print("Non-overlapping intervals: ",merge(interval))

"""
Time complexity : O(n^2) 
Space complexity : O(n^2) 

INPUT:-
Overlapping interval:  [[1, 3], [2, 6], [8, 10], [15, 18]]

OUTPUT:-
Non-overlapping intervals:  [[1, 6], [8, 10], [15, 18]]
 
"""