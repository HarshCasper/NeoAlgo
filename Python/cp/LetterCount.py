"""
The program uses dictionary in python
to count the number of occurence a letter 
makes in a word

"""
word=input("enter a word ").lower() #Converting to lowercase for the ASCII code to be same
  

dict={}

for c in word:
    co = dict.get(c,0) #get checks wether the dictionary has the letter at index c
    if co == 0:
        dict[c]=1
    else:
	    dict[c]=co+1
print(dict)	

"""
Sample Input-output

LetterCount.py
enter a word All i well
{'a': 1, 'l': 4, ' ': 2, 'i': 1, 'w': 1, 'e': 1}

"""
"""
Complexity- O(n)

"""