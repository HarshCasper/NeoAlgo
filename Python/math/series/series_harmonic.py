"""
It is implementsation of the Harmonic Series algorithm in python language.

"""


def harmonic_series(n_term: str) -> list:
    """Implementation of Harmonic Series algorithm includes
    -n_term: The last (nth) term of Harmonic Series 
    -The Harmonic Series starting from 1 to last (nth) term

    Some examples:
    >>> harmonic_series(1)
    ['1']
    >>> harmonic_series(9)
    ['1', '1/2', '1/3', '1/4', '1/5', '1/6', '1/7', '1/8', '1/9']
    >>> harmonic_series(5.1)
    ['1', '1/2', '1/3', '1/4', '1/5']
    >>> harmonic_series(-2)
    []
    >>> harmonic_series(0)
    []
    """
    if n_term == "":
        return n_term
    series = []
    for temp in range(int(n_term)):
        series.append(f"1/{temp + 1}" if series else "1")
    return series


if __name__ == "__main__":
    nth_term = input("Enter the nth term of the Harmonic Series:: ")
    print("Formula of the Harmonic Series => 1+1/2+1/3 ..... 1/n")
    print(harmonic_series(nth_term))