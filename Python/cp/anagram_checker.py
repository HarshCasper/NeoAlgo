"""
This script takes two input strings and compare them to check if they are anagrams or not.
"""
def mysort(s):    	#function that splits the letters
	d=sorted(s)
	s=''.join(d)
	return s

s1=input("enter first word ")
n1=mysort(s1) #function invocation /calling the function

s2=input("enter second word ")
n2=mysort(s2)

if n1.lower()==n2.lower():
	print(s1," and ",s2," are anagrams")
else:
	print(s1," and ",s2," are not anagrams")


    
