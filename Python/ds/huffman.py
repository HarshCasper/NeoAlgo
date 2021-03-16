''' Huffman coding in python issue-3306
Huffman coding works on data stream that makes up the file to be compressed'''
from collections import defaultdict
#  importing defaultdict is valuable option for handling missing keys in dictionaries.
from heapq import heappop, heapify, heappush
''' A heap queue is created by using python's inbuilt library named heapq
heappop - This function is used to remove and return the smallest element from heap
heapify -This function converts a regular list to a heap
heappush-This function is used to insert the element mentioned in its arguments'''
def Huffman(code):
    getheap = [[ab, [xyz, "\t "]] for xyz, ab in code.items()]
    
    
#  getting a loop to access all elements
    while len(getheap) > 1 :
        heapify(getheap)
        least = heappop(getheap)
        heighest = heappop(getheap)
        for allelements in heighest[1:]:
            allelements[1] = '1' + allelements[1] 
#  need to add 1 for heighest and 0 for lower ones to the all elements
        for allelements in least[1:]:
            allelements[1] = '0' + allelements[1]
        heappush(getheap, [least[0] + heighest[0]] + least[1:] + heighest[1:])
#  need to push additon of least and heighest in an order itself to ger correct results
    return sorted(heappop(getheap)[1:], key = lambda text:(len(text[-1]), text))
# getting a lambda function for length of inputs directed into keyword key


print("element first printed in row")
print("weights printed in second row")
print("huffcode  are printed last of row")
code = defaultdict(int)
inputs = "testing code with inputs"
#  give the inputs in string format
for element in inputs:
    code[element] = code[element] + 1
huffman = Huffman(code)
#  for  loop to print the result for text input
for text in huffman:
    print(text[1], text[0], code[text[0]])
''' input testing code with inputs.
output:
huffcode first printed in row                                                                                                                                               
element printed in second row                                                                                                                                               
weights are printed last of row                                                                                                                                             
00        t 4                                                                                                                                                               
100         4                                                                                                                                                               
011       i 3                                                                                                                                                               
1011      e 2                                                                                                                                                               
1101      n 2                                                                                                                                                               
1111      s 2                                                                                                                                                               
0100      u 1                                                                                                                                                               
0101      w 1                                                                                                                                                               
10100     c 1                                                                                                                                                               
10101     d 1                                                                                                                                                               
11000     g 1                                                                                                                                                               
11001     h 1                                                                                                                                                               
11100     o 1                                                                                                                                                               
11101     p 1
time complexity is O(logn). 
space complexity is  O(n log k).'''
