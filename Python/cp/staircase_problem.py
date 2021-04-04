"""This program finds the total number of possible combinations that can be used to
 climb statirs . EG : for 3 stairs ,combination and output will be 1,1,1 , 1,2 , 2,1 i.e 3 . """

def counting_stairs(stair_number):
    result = stair_number
    # This function uses Recursion.
    if(stair_number <=1):
        result = 1
    else:
        result = (counting_stairs(stair_number-1) + counting_stairs(stair_number-2))
    return result

if __name__ == '__main__':
    count_stair = int(input("Enter total number of stairs: "))
    print(f"Total Number of possible Combinations = {counting_stairs(count_stair)}")


"""Output 
Total Number of possible Combinations = 8
Enter total number of stairs: 5

Time Complexity : O(2^n)
Space Complexity :O(1)
Created by Shubham Patel on 16-12-2020 on WoC
"""
