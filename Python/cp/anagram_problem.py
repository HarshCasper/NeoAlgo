"""
Problem Statement : To find out if two given string is anagram strings or not.

What is anagram?  The string is anagram if it is formed by changing the positions of the characters.
         
Problem Link:- https://en.wikipedia.org/wiki/Anagram

Intution: Sort the characters in both given strings.
          After sorting, if two strings are similar, they are an anagram of each other.

Return  : A string which tells if the given two strings are Anagram or not.

"""

def checkAnagram(str1, str2):

    #Checking if lenght of the strings are same
    if len(str1) == len(str2):

        #Sorting both the strings
        sorted_str1 = sorted(str1)
        sorted_str2 = sorted(str2)

        #Checking if both sorted strings are same or not
        if sorted_str1 == sorted_str2:
            return "The two given strings are Anagram."
        
        else:
            return "The two given strings are not Anagram."
            
def main():

    #User input for both the strings
    str1 = input("Enter 1st string: ")
    str2 = input("Enter 2nd srring: ")
    
    #function call for checking if strings are anagram
    print(checkAnagram(str1, str2))

main()

"""
Sample Input / Output:

Enter 1st string: lofty
Enter 2nd srring: folty
The two given strings are Anagram.

Enter 1st string: bhuj
Enter 2nd srring: ghuj
The two given strings are not Anagram.

"""
