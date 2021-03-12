'''
Reversing individual words of a string using stack data structure
'''


def reverseWords(string: str):
    ''' Prints the individual words in a reverse order '''
    stack = []
    for letter in string:
        if letter.isalnum():
            stack.append(letter)     # equivalent to stack.push()
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

Sample Input1: Get me food
Sample Output1: teG em doof

Sample Input2: happy birthday
Sample Output2: yppah yadhtrib

'''
