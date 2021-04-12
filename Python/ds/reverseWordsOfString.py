'''
Reversing individual words of a string using stack data structure
Algorithm/Approach:
We iterate through the string character-by-character.
If the current character is not a space, or not a newline character or not a null character,
we push it into the stack
Otherwise, we pop the elements from the stack until it's empty. 
(Because a space or newline or null character marks the end of a word.)
'''

def reverseWords(string: str):
    ''' Prints the individual words in a reverse order '''
    stack = []
    for letter in string:
        if letter.isalnum():
            stack.append(letter)  # equivalent to stack.push()
        else:
            while stack != []:
                print(stack.pop(), end="")
            print(letter, end="")
    while stack:
        print(stack.pop(), end="")
    print()


sentence = input("Enter a sentence:\n")
print("The sentence after reversing individual words is:")
reverseWords(sentence)

'''
Sample I/O:
Enter a sentence:
Get me food
The sentence after reversing individual words is:
teG em doof

Time complexity = O(n) [since each pop or push takes O(1) times]
Space Complexity = O(n)
'''
