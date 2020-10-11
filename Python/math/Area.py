#! /usr/bin/env python3
"""
Find the area of various geometric shapes at once
"""

import math


def area_rectangle(length, breadth):
    return length * breadth


def area_square(side_length):
    return side_length ** 2


def area_triangle(base, height):
    return 0.5 * base * height


def area_parallelogram(base, height):
    return base * height


def area_trapezium(base1, base2, height):
    return 0.5 * (base1 + base2) * height


def area_circle(radius):
    return math.pi * (radius **2)


def main():
    i, j, k = [float(x) for x in input("Enter three value: ").split()]
    print("Areas of various geometric shapes: \n")
    print("Rectangle (length= {}, breadth= {}): {}".format(i, j, area_rectangle(i, j)))
    print("Square (side= {}): {}".format(i, area_square(i)))
    print("Triangle (base= {}, height= {}): {}".format(i, j, area_triangle(i, j)))
    print("Parallelogram (base= {}, height= {}): {}".format(i, j, area_parallelogram(i, j)))
    print("Trapezium (base1= {}, base2 = {}, height= {}): {}".format(i, j, k, area_trapezium(i, j, k)))
    print("Circle (radius= {}): {}".format(j, area_circle(j)))
    print(i, j, k)


if __name__ == "__main__":
    main()