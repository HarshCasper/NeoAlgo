# Logarithm Algorithm (ln)

"""
An algorithm that demonstrates how to approximately calculate the \
natural algorithm of a value and show how this logarithm is \
dependent on Inverse hyperbolic functions.
"""

def conv_if_neg(x):
    """Returns abs of x if it's negative"""
    if x < 0:
        return abs(x), True
    return x, False

# Inverse Hyperbolic Functions return angles in radian form
def artanh(val):
    """Returns Inverse Hyperbolic Tan of x"""
    # artanh(-x) = -1 * artanh(x)
    val, neg_flag = conv_if_neg(val)
    if val > 1:  # Domain: [-1,1]
        return "Domain error" 
    # Taylor series
    res = 0
    for i in range(1, 92, 2):
        res += val**i/i
    if neg_flag:  # Check negative flag
        res *= -1
    return res  # Radian angle

def ln(x):
    """Returns the natural algorithm of x"""
    # Use fact: ln(x) = 2 * artanh((x-1) / (x+1))
    x = (x-1) / (x+1)
    return 2 * artanh(x)

# Start Checkpoint
if __name__ == "__main__":
    x = float(input("ln(x), x? > "))
    # ln(x) domain: ]0,inf[
    if x <= 0:
        print("Domain error, x must be bigger than 0")
    else:
        print(ln(x))

"""
Steps:
=======
It all depends on some expansion facts which are:
    1) ln(x) = 2 * artanh((x-1) / (x+1))
    2) artanh(x) = val + val**3/3 + val**5/5 + ...
    3) artanh(-x) = -1 * artanh(x)

The approach to calculate the natural algorithm is using artanh Taylor's series.
Here the accuracy of the results decreases as x increases, but deviation can be \
overcome by increasing the number of terms of artanh Taylor series. Using 46 terms we can \
assure that correct values can be obtained up to x=300, if x was bigger than this, decimal \
deviations can be noticed. but by increasing the number of terms of artanh Taylor's series \
accuracy will increase.

The most efficient way to calculate such function is using the CORDIC algorithms, but these \
cannot be implemented without the help of the C language.
Refer to function: "ln_values" in the following link:
https://people.math.sc.edu/Burkardt/c_src/cordic/cordic.c

I/O example:
=============
Input:
ln(x), x? > 5

Output:
1.6094379124341003
=============

Time Complexity: O(1)
Explain: Accuracy here is controlled by the developer so if the program was built on using \
         using 300 Taylor terms, then the program will have a fixed time complexity of the \
         time needed to calculate these 300 terms.

Space Complexity: O(1)
Explain: Because space required won''t increase whatever the input was.
"""
