# Bulb Swither problem
# link to problem: https://leetcode.com/problems/bulb-switcher/


def bulbSwitcher(n):
    bulb = 0
    while bulb * bulb <= n:
        bulb += 1
    return bulb - 1


N = int(input())
print(bulbSwitcher(N))

'''
Input: 5
output: 2
Time complexity: O(N)
'''
