''' Huffman coding in python issue-3306
Huffman coding works on data stream that makes up the file to be compressed'''
from collections import defaultdict
#importing defaultdict is valuable option for handling missing keys in dictionaries.
from heapq import heappop, heapify,heappush
''' 
A heap queue is created by using python's inbuilt library named heapq
heappop - This function is used to remove and return the smallest element from heap
heapify -This function converts a regular list to a heap
heappush-This function is used to insert the element mentioned in its arguments
'''
def Huffman(huff):
    getheap = [[ab, [xyz,"\t "]] for xyz, ab in huff.items()]
#getting a loop to access all elements
    while (1 < len(getheap)) :
        heapify(getheap)
        least = heappop(getheap)
        heighest = heappop(getheap)
        for allelements in heighest[1:]:
            allelements[1] = '1'+ allelements[1] 
#need to add 1 for heighest and 0 for lower ones to the all elements
        for allelements in least[1:]:
            allelements[1] = '0' + allelements[1]
        heappush(getheap,[least[0] + heighest[0]] +least[1:] + heighest[1:] )
#need to push additon of least and heighest in an order itself to ger correct results
    return sorted(heappop(getheap)[1:], key =lambda text: (len(text[-1]), text))
#getting a lambda function for length of inputs directed into keyword key
print("huffcode first printed in row")
print("element printed in second row")
print("weights are printed last of row")
huff = defaultdict(int)
inputs = "testing code with inputs "
#give the inputs in string format
for element in inputs:
    huff[element] = huff[element] + 1
huffman =Huffman(huff)
#for  loop to print the result for text input
for text in huffman:
    print(text[1], text[0], huff[text[0]])
'''output for input "testing code with inputs"  is:
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
output for input "added the code for issue huffman" is:
huffcode first printed in row                                                                                                                                               
element printed in second row                                                                                                                                               
weights are printed last of row                                                                                                                                             
111         6                                                                                                                                                               
010       d 4                                                                                                                                                               
011       e 4                                                                                                                                                               
000       f 3                                                                                                                                                               
0010      a 2                                                                                                                                                               
1000      h 2                                                                                                                                                               
1010      o 2                                                                                                                                                               
1100      s 2                                                                                                                                                               
1101      u 2                                                                                                                                                               
00110     c 1                                                                                                                                                               
00111     i 1                                                                                                                                                               
10010     m 1                                                                                                                                                               
10011     n 1                                                                                                                                                               
10110     r 1                                                                                                                                                               
10111     t 1  
output for input "done with all the inputs" is :
huffcode first printed in row                                                                                                                                               
element printed in second row                                                                                                                                               
weights are printed last of row                                                                                                                                             
00          5                                                                                                                                                               
011       t 3                                                                                                                                                               
1010      e 2                                                                                                                                                               
1011      h 2                                                                                                                                                               
1100      i 2                                                                                                                                                               
1101      l 2                                                                                                                                                               
1110      n 2                                                                                                                                                               
0100      s 1                                                                                                                                                               
0101      u 1                                                                                                                                                               
1000      w 1                                                                                                                                                               
10010     a 1                                                                                                                                                               
10011     d 1                                                                                                                                                               
11110     o 1                                                                                                                                                               
11111     p 1 

time complexity is O(logn) 
space complexity is  O(n log k)

'''