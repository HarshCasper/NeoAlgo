'''
Author : @anushkrishnav
Problem : https://www.hackerrank.com/challenges/find-angle/problem
'''

import math


def AngleMBC(AB, BC):
    '''Finds the angle of MBC'''
    AC = math.sqrt(AB**2 + BC**2)
    MC = AC / 2.0
    adjacent = BC / 2.0
    print (str(int(round(math.degrees(math.acos(adjacent/MC))))) + "°")

if __name__ == "__main__":
    AB = int(input('Ab = '))
    BC = int(input('BC = '))
    AngleMBC(AB, BC)