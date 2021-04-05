'''
Function to calculate Lucky numbers.
EX:
n=100
output=[1, 3, 7, 9, 13, 15, 21, 25, 31, 33, 37, 43, 49, 51, 63, 67, 69, 73, 75, 79, 87, 93, 99]
EX2:
n=300
output=[1, 3, 7, 9, 13, 15, 21, 25, 31, 33, 37, 43, 49, 51, 63, 67, 69, 73, 75, 79, 87, 93, 99, 105, 111, 115, 127, 129, 133, 135, 141, 151, 159, 163, 169, 171, 189, 193, 195, 201, 205, 211, 219, 223, 231, 235, 237, 241, 259, 261, 267, 273, 283, 285, 289, 297]
'''
def lucky(nos):
        odds = list(range(1, nos + 1, 2))#list of odd numbers
        j = 1
        while j <= len(odds) - 1 and odds[j] <= len(odds):
                odds = [Li for i, Li in enumerate(odds) if (i + 1) % odds[j]]#counting and adding the lucky numbers in the list
                j += 1
        return odds

#Driver code
if __name__ == "__main__":
        n=int(input())#User input
        LuckyNos=lucky(n)#Function Call
        print(LuckyNos)
