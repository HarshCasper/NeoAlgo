## This program finds the total number of possible combinations that can be used to
## climb statirs . EG : for 3 stairs ,combination and output will be 1,1,1 , 1,2 , 2,1 i.e 3 . 

def counting_stairs(stair_number):
    result = stair_number
    ##Using Recursion to find the total number of stairs as f(a) = f(a-1) + a(a-2) 
    ## where f(a) is the final result
    if(stair_number <=1):
        result = 1
    else:
        result = (counting_stairs(stair_number-1) + counting_stairs(stair_number-2))
    return result

##Asking for number of steps to find combination.
count_stair = int(input("Enter total number of stairs: "))
##passing stair number to  the function.
##Printing the number of combination which is given by the function.
print(f"Total Number of possible Combinations = {counting_stairs(count_stair)}")


## Output 
## Enter total number of stairs: 5
## Total Number of possible Combinations = 8

## Time Complexity : O(2^n)
## Space Complexity :O(1)
## Created by Shubham Patel on 16-12-2020 on WoC
