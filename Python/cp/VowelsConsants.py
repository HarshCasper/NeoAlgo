"""
The program helps to count the number of
vowels and consants in a string.

"""

def Count(word):
    vc, cc = 0, 0

    for s in word:
        if (s.isalpha()):
            if (s == 'a' or s == 'e' or s == 'i' or s == 'o' or s == 'u'):
                vc = vc + 1
            else:
                cc = cc + 1
    return vc, cc

TheWord = input("Enter a string: ").lower()

vc, cc = Count(TheWord)

print("Vowel count = ", vc, " Consonant count = ", cc)


"""
Time Complexity: O(n)

Sample Input:
Enter a string: Hello World

Sample Output:
Vowel count =  3  Consonant count =  7
"""
