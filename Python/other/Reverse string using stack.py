#class of stack 
class stack:   
    def __init__(self):
        self.items=[]
    def push(self,item):
        self.items.append(item)
    def pop(self):
        return self.items.pop()
    def is_empty(self):
        return self.items==[]


#function to reverse a function
def reverse(string):

   """ 
    >>Input:ziuQ
    >>Output:Quiz
    
  """
    x=len(string)
    l=0
    while l<x:
        s.push(string[l])
        l+=1
    rev=''
    while not s.is_empty():
        rev+=s.pop()
    return rev
s=stack()

#  Driver Code Starts
if __name__=='__main__':
    t=int(input())
    for i in range(t):
        str1=input()
        print(reverse(str1))
