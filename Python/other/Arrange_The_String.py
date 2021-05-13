"""
Query : Arrange The String
Task:
Input a string S (assume lowercase letters) and arrange the letters of the string in such a way that no two adjacent letters are same.
If multiple answers exist, output anyone of them.
else print "IMPOSSIBLE".
Input is a string S
Output the organized string as per the algorithm.
We will use :
 1) heap data structure thus importing heapq
    In python we dont have max heap thus implementing through min heap by 
    inserting the negation of the value
 2) OrderedDict to store the frequencies of the letters in the input string
"""
import heapq
from collections import OrderedDict

if __name__ == "__main__":
    #Input the string
    input_string = input("Enter a string:")
    len_input = len(input_string)
    
    # Initialising an Output string
    output_string = ""
    
    # Initialising an OrderedDict
    od = OrderedDict()
    
    #Inserting the frequency of the corresponding letter as a key,value pair
    for ch in input_string:
        if ch not in od:
            od[ch] = -1
        else:
            od[ch] -= 1
        
    
    flag = True
    # Initialising a list of value , key pair
    freq_heap=[]
    
    # Heapify the list
    for key,value in od.items():
        heapq.heappush(freq_heap, (value , key))
    
    # Pop two elements and add it to the result.
    # Push the popped elements back into the priority_queue if absolute of their their frequencies are greater than 1 
    # and decrease the frequency of the popped elements by 1 (i.e. +1 as they are negative values)
    while len(freq_heap) > 1:
        char1 = heapq.heappop(freq_heap)
        char2 = heapq.heappop(freq_heap)

        output_string = output_string + char1[1]
        output_string = output_string + char2[1]

        if abs(char1[0]) > 1:
            heapq.heappush(freq_heap, (char1[0] + 1, char1[1]))

        if abs(char2[0]) > 1:
            heapq.heappush(freq_heap, (char2[0] + 1, char2[1]))
   
    #If still our priority_queue has an element left with single occurrence we will add it to our answer
    if len(freq_heap):
        char1 = heapq.heappop(freq_heap)
        
        #If any character with more than 1 occurrence is left, we cannot insert it into answer as that will not suffice our answer
        # hence this is the scenario of impossible case
        if abs(char2[0]) > 1:
            print( "IMPOSSIBLE")
            flag = False

        output_string = output_string + char1[1]

    if flag:
        print(output_string)
        
    
"""
COMPLEXITY:
	
	 Time Complexity -> O(N*log N).
	 Space Complexity -> O(N)
   
Sample Test Cases:
Example #1:
Input : eeeg
Output: IMPOSSIBLE
Explanation: We cannot arrange the letters such that no two of the adjacent letters are different.
Example #2:
Input : eeg
Output: ege
Explanation: No two of the adjacent letters are same in the output string.
    
"""