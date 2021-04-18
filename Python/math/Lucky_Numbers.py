'''
Write a program to print all the Lucky Numbers upto the input number.

Approach:
Lets understand with input of 25 for example.
Start with a list of numbers beginning with 1:
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25

Every second number (all even numbers) in the list is eliminated, leaving only the odd integers:
1 3 5 7 9 11 13 15 17 19 21 23 25

The first number remaining in the list after 1 is 3, so every third number which remains in the list 
(not every multiple of 3) is eliminated. The first of these is 5:
1 3 7 9 13 15 19 21 25

The next surviving number is now 7, so every seventh remaining number is eliminated. The first of these is 19:
1 3 7 9 13 15 21 25

The next surviving number after 7 is 9, so every 9th element was meant to be deleted, but as we see 9 is greater
than size of list , So we got our list of surviving numbers from seive of elimination i.e. LUCKY NUMBERS upto 
input number.

'''
def lucky(nos):
        #list of odd numbers
        odds = list(range(1, nos + 1, 2))
        #iterator variable
        j = 1                             
        while j <= len(odds) - 1 and odds[j] <= len(odds):
                #counting and adding the lucky numbers in the list
                odds = [Li for i, Li in enumerate(odds) if (i + 1) % odds[j]] 
                #incrementing the variable
                j += 1
        #returning list of all the lucky numbers upto 'nos'
        return odds
#Driver code
if __name__ == "__main__":
        #User input
        number=int(input("Enter a number :"))
        #Function Call
        LuckyNos=lucky(number)               
        print("The list of all the lucky numbers upto",number," is :",LuckyNos)
        
'''
SAMPLE INPUT AND OUTPUT

SAMPLE 1:-

Enter a number :25
The list of all the lucky numbers upto 25  is : [1, 3, 7, 9, 13, 15, 21, 25]

Time Complexity : O(n^2)
Space Complexity : O(n)
'''
