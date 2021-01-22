"""
It is implementsation of the Geometric Series algorithm in python language.

"""


def geometric_series(nth_term: int, start_term_a: int, common_ratio_r: int) -> list:
    """Implementation of Geometric Series algorithm includes
    -nth_term: The last term (nth term of Geometric Series)
    -start_term_a : The first term of Geometric Series
    -common_ratio_r : The common ratio between all the terms

    Some Examples:
    >>> geometric_series(6, 3, 3)
    ['3', '9.0', '27.0', '81.0', '243.0', '729.0']
    >>> geometric_series(8, 1, 1)
    ['1', '1.0', '1.0', '1.0', '1.0', '1.0', '1.0', '1.0']
    >>> geometric_series(0, 0, 0)
    []
    """
    if "" in (nth_term, start_term_a, common_ratio_r):
        return ""
    gseries = []
    multiple = common_ratio_r
    power = 1
    for _ in range(int(nth_term)):
        if gseries == []:
            gseries.append(start_term_a)
        else:
            power += 1
            gseries.append(str(float(start_term_a) * float(multiple)))
            multiple = pow(float(common_ratio_r), power)
    return gseries


if __name__ == "__main__":
    nth_term = input("Enter the nth term of the Geometric Series:: ")
    start_term_a = input("Enter the first term (a) of the Geometric Series:: ")
    common_ratio_r = input("Enter the common ratio between both terms (r) of the Geometric Series:: ")
    print("Formula of the Geometric Series => a + ar + ar^2 ... +ar^n")
    print(geometric_series(nth_term, start_term_a, common_ratio_r))