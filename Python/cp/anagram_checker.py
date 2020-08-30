"""
This script takes two input strings and compare them to check if they are anagrams or not.
"""

def check_anagrams(first_string, second_string):
    
    #If the length of both these words dont match then they cant be anagrams
    if len(first_string) == len(second_string):
        
        #Sort both the strings and check their equality
        first_string = sorted(first_string.lower())
        second_string = sorted(second_string.lower())
        
        if first_string == second_string:
            print("These two words are anagrams")
        else:
            print("These two words are not anagrams")
        
        
    else:
        print("These two words are not anagrams")
        
def main():
    first_string = input("Enter a word: ")
    second_string = input("Enter another one: ")

    check_anagrams(first_string, second_string)

main()    

#Sample Input-Output:

#Sample 1
#Inputs: "silent" and "listen"

#Output: These two words are anagrams

#Sample 2
#Inputs: "july" and "june"

#Output: These two words are  not anagrams