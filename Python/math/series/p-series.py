"""
It is implementsation of the P-Series Series algorithm in python language.

"""


def p_series(nth_term: int, power: int) -> list:
    """Implementation of  P-Series Series algorithm includes
    -The P-Series starting from 1 to last (nth) term

    Some examples:
    >>> p_series(6, 3)
    [1, '1/8', '1/27', '1/64', '1/125', '1/216']
    >>> p_series(-5, 2)
    []
    >>> p_series(1, 1)
    [1]
    >>> p_series(4, -2)
    [1, '1/0.25', '1/0.1111111111111111', '1/0.0625']
    >>> p_series("", 100)
    ''
    """
    if nth_term == "":
        return nth_term
    nth_term = int(nth_term)
    power = int(power)
    series = []
    for temp in range(int(nth_term)):
        series.append(f"1/{pow(temp + 1, int(power))}" if series else 1)
    return series


if __name__ == "__main__":
    nth_term = input("Enter the nth term of the P-Series:: ")
    power = input("Enter the power for the P-Series:: ")
    print("Formula of the P-Series => 1+1/2^p+1/3^p ..... 1/n^p")
    print(p_series(nth_term, power))