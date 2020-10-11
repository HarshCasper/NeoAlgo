def calculate_gcd(a, b):
    while b:
        a, b = b, a % b
    return a

if __name__ == '__main__':
    i, j = input().split()
    print(calculate_gcd(i, j))  # 36, 20Should print 4
