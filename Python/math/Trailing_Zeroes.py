def trailingZeroes(number):
    rem = 0
    while number > 0:
        number //= 5
        rem += number
    return rem
    
    
    
number = int(input('Enter Number for calculating trailing Zeroes : '))
    
solution = trailingZeroes(number)

print(solution)