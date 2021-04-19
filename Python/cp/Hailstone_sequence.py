"""
Problem Statement : To find the Hailstone Sequence for the number given.

Problem Link:- https://wiki.formulae.org/Hailstone_sequence

Intution: Print the value of n.
          If n is odd, calculate the next number as n*3+1.
          If n is even, calculate the next number as n/2.
          Append the last element of the sequence 1.

Return  : Array of the hailstone sequence.

Repl.it Link : https://replit.com/@batul02/hailstonesequence#main.py

"""

def hailstone_sequence(n):

    #array to store the sequence
    sequence = []

    #loop will continue until the number > 1
    while n > 1:

        #appending the number
        sequence.append(n)

        #checking if the number is odd or even
        if n % 2 == 1:
            n = n * 3 + 1
        else:
            n = int(n / 2)

    #append 1 because every hailstone sequence ends with 1
    sequence.append(1)

    #return the array
    return sequence
 
def main():
    #User input for a number to get its hailstone sequence
    n = int(input("Enter a number: "))

    #function call for getting hailstone sequence for the number
    print("Hailstone Sequence: ", hailstone_sequence(n))
    

main()

"""
Sample Input / Output:

Enter a number: 20
Hailstone Sequence:  [20, 10, 5, 16, 8, 4, 2, 1]

Enter a number: 31
Hailstone Sequence:  [31, 94, 47, 142, 71, 214, 107, 322, 161, 484, 242, 121, 364, 182, 91, 274, 137, 412, 206, 103, 310, 155, 466, 233, 700, 350, 175, 526, 263, 790, 395, 1186, 593, 1780, 890, 445, 1336, 668, 334, 167, 502, 251, 754, 377, 1132, 566, 283, 850, 425, 
1276, 638, 319, 958, 479, 1438, 719, 2158, 1079, 3238, 1619, 4858, 2429, 7288, 3644, 1822, 911, 2734, 1367, 4102, 2051, 6154, 3077, 9232, 4616, 2308, 1154, 577, 1732, 866, 433, 1300, 650, 325, 976, 488, 244, 122, 61, 184, 92, 46, 23, 70, 35, 106, 53, 160, 80, 40, 20, 10, 5, 16, 8, 4, 2, 1]

Enter a number: 50
Hailstone Sequence:  [50, 25, 76, 38, 19, 58, 29, 88, 44, 22, 11, 34, 17, 52, 26, 13, 40, 20, 10, 5, 16, 8, 4, 2, 1]

"""

