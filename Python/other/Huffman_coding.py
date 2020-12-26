'''Huffman Compression and Decompression: Files of high size need much cost
to handle and this can be overcome by huffman compression and decompression
techniques in which the byte size of charactersare given values by their frequency,
more freuent char are given less bytes and vice versa.

Purpose: To encode and decode strings by priority queue and binary trees.
Method: Huffman algorithm
Intution: 1.Push all the freq keys in the priority queue.
          2.To build the tree pop two items as left and right child of tree.
          3.Push the new node formed in the priority queue until it become 1.
          4.Traverse the formed Huffman tree and the code is encoded.
          5.For decoding we traverse according to the bits assigned for left(0)
          and right(1).
Time complexity: 0(n*logn) 
Argument:1.Encoding function:root and the empty string.
         2.Decoding function: root and encoded string.
Return:1.Encoding function:encoded string
       2.Decoding function:printing the decoded string.
'''
import queue as Queue

counter = 0

class Node:
    def __init__(self, freq, data):
        self.freq = freq
        self.data = data
        self.left = None
        self.right = None
        global counter
        self._count = counter
        counter = counter + 1
 
def buildHuffmanTree():#builds the tree and returns root
    queue = Queue.PriorityQueue()

    
    for key in freq:
        queue.put((freq[key], key, Node(freq[key], key) ))
    
    while queue.qsize() != 1:
        a = queue.get()
        b = queue.get()
        item = Node(a[0] + b[0], '\0' )
        item.left = a[2]
        item.right = b[2]
        queue.put((item.freq, item.data, item ))
        
    root = queue.get()
    root = root[2]#contains root itemect
    return root

def dfsHuffmanTree(item, already):
    if(item == None):
        return
    elif(item.data != '\0'):
        code_hidden[item.data] = already
        
    dfsHuffmanTree(item.right, already + "1")
    dfsHuffmanTree(item.left, already +"0")
def decodeHuff(root, s): #decode the code
    str1=""
    current=root     
    for i in range(0,len(s)):
        if s[i]=='0':
            current=current.left
        else:
            current=current.right
        if current.left is None and current.right is None:
            str1+=current.data
            current=root
    print('The decoded code is ',str1)

ip = input('Enter the string:-')
freq = {}#maps each character to its frequency

counter = 0

for ch in ip:
    if(freq.get(ch) == None):
        freq[ch] = 1
    else:
        freq[ch]+=1

root = buildHuffmanTree()#contains root of huffman tree

code_hidden = {}#contains code for each item

dfsHuffmanTree(root, "")

if len(code_hidden) == 1:#if there is only one character in the i/p
    for key in code_hidden:
        code_hidden[key] = "0"

toBeDecoded = ""

for ch in ip:
   toBeDecoded += code_hidden[ch]

decodeHuff(root, toBeDecoded)
print('The encoded code is',toBeDecoded)


'''
INPUT
Enter the string:- ABCBAACD

OUTPUT
The decoded code is  ABCBAACD
The encoded code is 0111101110010110'''
