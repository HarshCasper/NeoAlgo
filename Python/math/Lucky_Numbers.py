'''
Write a program to print all the Lucky Numbers upto the input number.
Description:
How to know if a number is lucky ?
Start with a list of numbers beginning with 1:
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
Consistently number (every much number) in the list is dispensed with, leaving just the odd numbers:
1 3 5 7 9 11 13 15 17 19 21 23 25
The main number excess in the list after 1 is 3, so every third number which stays in the list (only one out of every odd various of 3) is dispensed with. The first of 
these is 5:
1 3 7 9 13 15 19 21 25
The following enduring number is presently 7, so every seventh leftover number is disposed of. The first of these is 19:
1 3 7 9 13 15 21 25
Keep eliminating the nth leftover numbers, where n is the following number in the list after the last surviving number. Next in this model is 9. Keep repeating until the sieve
of elimination becomes larger than the index of the number[ which is to be checked if lucky ] , then the number is called Lucky Number. If a number is eliminated by any seieve 
then the number is not a lucky number.

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
        n=int(input())
        #Function Call
        LuckyNos=lucky(n)               
        print(LuckyNos)
        
'''
EX1:
input=100
output=[1, 3, 7, 9, 13, 15, 21, 25, 31, 33, 37, 43, 49, 51, 63, 67, 69, 73, 75, 79, 87, 93, 99]
EX2:
input=150
output=[1, 3, 7, 9, 13, 15, 21, 25, 31, 33, 37, 43, 49, 51, 63, 67, 69, 73, 75, 79, 87, 93, 99, 105, 111, 115, 127, 129, 133, 135, 141]

Time Complexity : O(n^2)
Space Complexity : O(n)
'''
