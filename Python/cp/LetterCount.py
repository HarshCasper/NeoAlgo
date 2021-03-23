"""
The program uses dictionary in python
to count the number of occurence a letter
makes in a word
"""


def LetterCount(word):
    dict = {}

    for c in word:
        co = dict.get(c, 0)
        if co == 0:
            dict[c] = 1
        else:
            dict[c] = co + 1

    return(dict)

if __name__ == '__main__':
    word = input("enter a word ").lower()
    LetterCount = LetterCount(word)
    print(LetterCount)


"""
Sample Input-output
enter a word aayuhsi
{'a': 2, 'y': 1, 'u': 1, 'h': 1, 's': 1, 'i': 1}
"""

"""
Time complexity- O(n)

"""
