def calculate_gcd(a, b):
    while b:
        a, b = b, a % b
    return a

if __name__ == '__main__':
    print(calculate_gcd(36, 20))  # Should print 4
    print(calculate_gcd(16, 24))  # Should print 8
