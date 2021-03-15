#Sine Algorithm
#Written by XZANATOL

"""
Algorithm that explains how to calculate the Sine of an angle
"""

import math
pi = 3.141592653589793238462643383279502884197169399375105 #Constant

def conv_to_rad(angle):
    """Converts degree angles to radians"""
    return angle/180 * pi


def factorial(n):
    """Factorial function. This will be used in the power series"""
    if n==1:
        return 1
    return n * factorial(n-1)


def conv_if_neg(x):
    """returns abs of an angle if it's negative"""
    #sin(-x) = -sin(x)
    if x<0:
        return abs(x), True
    return x,False


def reduce_angle(angle):
    """Reduces the angle if it is bigger than pi/2"""
    """
    sin(pi - X) = sin(x)
    We do know that every quadrant has the same range of sines results which is from [0-1] \
    but every quadrant has it's own sign according to the ASTC rule.
    So by reducing the angle to it's equivalent in the first quadrant \
    we will get the same result, all what's left is to determine in which quadrant the angle \
    lies. This can be determined using a counter where if it is divisble by 2 then it is in \
    second/fourth quadrant, and it increases with every reduction loop.
    """
    count = 1 #used to determine the angles quadrant
    while(angle>=pi/2):
        angle -= pi
        count += 1
    return angle, count


def sin(x):
    res = x - x**3/factorial(3) + x**5/factorial(5) - x**7/factorial(7) + \
          x**9/factorial(9) - x**11/factorial(11)

    return res


#Start checkpoint
if __name__ == "__main__":
    #Get inputs
    angle = float(input("Enter angle > "))
    mode  = input("Enter angle mode [deg\\rad] > ")

    #convert to rad if the input is deg
    if mode == "deg":
        angle = conv_to_rad(angle)

    angle, neg_flag = conv_if_neg(angle) #check if negative
    angle, count = reduce_angle(angle) #reduces the angle value if it's bigger than pi/2
    res = sin(angle) #calculate the sin

    #check for signs of the result
    if count%2 == 0:
        res *= -1
    if neg_flag:
        res *= -1

    #Print Results
    print("Result: {}".format(res))
    print("Math library for comparison: {}".format(math.sin(angle)))
    #Note: math.sin doesn't support detection of quadrants
    #so compare only the magnitude
    
"""
The approach to calculate the Sine of an angle is using A power series. \
It is an infinite series like polynomails of unbounded degree.
The power series for Sine is:
    sin(x) = x - x^3/3! + x^5/5! - x^7/7! + x^9/9!
where:
    x! = factorial(x)
    x is an angle measured in radians
    The series gives the correct results for [0,pi/2] values
The challenge here is to deal with angles that are bigger than pi/2.
This is explained in the reduce_angle function.

I/O example:
=============
Input:
30
deg

Output:
Result: 0.4999999999999643
Math library for comparison: 0.49999999999999994
=============


General Time Complexity: O(n)
Explain: The larger the angle, the more loops it will take to be reduced in the \
while loop in reduce_angle function

Detailed Time Complexity for each function:
conv_to_rad: O(1)

factorial: O(n)
Need to note that it won't be used by a user, just for a max of 11 recursions, \
so It won't affect the performance of the script

conv_if_neg: O(1)

reduce_angle: O(1)

sin: O(1)
"""
