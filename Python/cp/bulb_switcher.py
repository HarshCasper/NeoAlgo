'''
Bulb switcher problem: There are n bulbs that are initially off.
You first turn on all the bulbs,then you turn off every second bulb.
On the third round,toggle every third bulb (turn on if it's off or vice-versa)
For the ith round, you toggle every i bulb.
For the nth round, you only toggle the last bulb.
Return the number of bulbs that are on after n rounds.

approach : By observation, A bulb is ON if it is toggled odd times
Only when `i` has perfect square root, its number of divisors is odd.

Time Complexity:  O(N)
Space Complexity: O(1)
'''


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
'''
