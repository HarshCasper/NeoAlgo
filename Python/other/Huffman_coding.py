'''Python code to implement HUffman encoding 
and decoding of a string'''
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


'''Time complexity: 0(n*logn)

INPUT
Enter the string:- ABCBAACD

OUTPUT
The decoded code is  ABCBAACD
The encoded code is 0111101110010110'''
