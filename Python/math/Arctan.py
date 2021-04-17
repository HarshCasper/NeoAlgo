# Arctan Algorithm
# Written by XZANATOL

"""
Algorithm that demonstrates how to calculate Arctan and obtain angle in the \
desired mode. (degrees/radians)
"""
pi = 3.141592653589793238462643383279502884197169399375105  # Constant


def conv_to_deg(angle):
    """Converts radian angles to degrees"""
    return angle*180 / pi


def conv_if_neg(x):
    """Returns abs of an angle if it's negative"""
    if x < 0:
        return abs(x), True
    return x, False


def arctan(val):
    """Arctan power series that obtains the angle in radians"""
    val = val - (val**3)/3 + (val**5)/5 - (val**7)/7 + (val**9/9) - \
        (val**11/11)
    return val


# Start Checkpoint
if __name__ == "__main__":
    # Get Inputs
    val = float(input("Enter value to obtain its angle > "))
    mode = input("Enter display mode (deg/rad) > ")

    val, neg_flag = conv_if_neg(val)  # Step 1 - Check if negative
    comp_flag = False  # Step 2 - Complementary angles
    identity_flag = False  # Step 3 - Identity angle
    if val > 1:
        comp_flag = True
        val = val**-1
    elif val > (2-3**0.5):
        identity_flag = True
        val = ((3**0.5 * val) - 1) / (3 ** 0.5 + val)

    angle = arctan(val)  # Step 4 - Substitute in the power series

    # Validate flags
    if comp_flag:
        angle = pi/2 - angle
    if identity_flag:
        angle = pi/6 + angle
    if neg_flag:
        angle *= -1

    # Validate display mode
    if mode == "deg":
        angle = conv_to_deg(angle)

    print("Angle > {}".format(angle))

"""
The approach to calculate the Arctan is using a power series. \
but the value must be validated before substituting it into the power series.
Steps:
=======
    1) Check if value is negative and use the fact that tan(-x) = -tan(x)
    2) If the value > 1: use complementary angles => arctan(x) = pi/2 - arctan(x**-1)
    3) else if value > 2-3**0.5: use identity equation => arctan(x) = pi/6 + arctan( (3**0.5*x-1)
    4) Finally substitute in the power series x - x**3/3 + x**5/5 - x**7/7 + x**9/9 - x**11/11

I/O example:
=============
Input:
Enter value to obtain its angle > 3.6
Enter display mode (deg/rad) > deg

Output:
Angle > 74.47588924544092
=============

Time Complexity: O(1)
Explain: None of the functions use loops or depend on how large the entered number is.
"""
