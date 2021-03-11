'''
Reversing individual words of a string using stack data structure
'''

def reverseWords(string: str):
    stack = []
    for letter in string:
        if letter.isalnum():
            stack.append(letter) #equivalent to stack.push()
        else:
            while (stack != []):
                print(stack.pop(), end = "")
            print(letter, end = "")
    while (stack):
        print(stack.pop(), end = "")
    print()

sentence = input("Enter a sentence:\n")
print("The sentence after reversing individual words is:")
reverseWords(sentence)