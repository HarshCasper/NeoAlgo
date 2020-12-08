"""
Find the area of various geometric shapes
"""

import math


def area_rectangle(base, height):
    """
    Calculate the area of a rectangle
    >> area_rectangle(10,20)
    200
    """
    return base * height


def area_square(side_length):
    """
    Calculate the area of a square
    >>> area_square(10)
    100
    """
    return side_length * side_length


def area_triangle(length, breadth):
    """
    Calculate the area of a triangle
    >>> area_triangle(10,10)
    50.0
    """
    return 1 / 2 * length * breadth


def area_parallelogram(base, height):
    """
    Calculate the area of a parallelogram
    >> area_parallelogram(10,20)
    200
    """
    return base * height


def area_trapezium(base1, base2, height):
    """
    Calculate the area of a trapezium
    >> area_trapezium(10,20,30)
    450
    """
    return 1 / 2 * (base1 + base2) * height


def area_circle(radius):
    """
    Calculate the area of a circle
    >> area_circle(20)
    1256.6370614359173
    """
    return math.pi * radius * radius


def main():
    print("Areas of various geometric shapes: \n")
    print("enter the shape of your choice:")
    again = True

    while(again):
        print("menu:")
        print("1. Rectangle")
        print("2. Square")
        print("3. Triangle")
        print("4. Parallelogram")
        print("5. Trapezium")
        print("6. Circle")
        choice = int(input())
        if(choice == 1):
            print("Enter sides of rectangle:", end=" ")
            l, b = input().split()
            l = int(l)
            b = int(b)
            print("Rectangle with sides "+str(l)+" and "+str(b)+" is:", end="")
            print(str(area_rectangle(l, b)))
            print("you wnat to continue (1/0)", end=" ")
            again_choice = int(input())
            if(again_choice):
                again = True
            else:
                again = False
        elif(choice == 2):
            print("Enter side of square:", end=" ")
            l = int(input())
            print("Square with side "+str(l)+" is: "+str(area_square(l)))
            print("you wnat to continue (1/0)", end=" ")
            again_choice = int(input())
            if(again_choice):
                again = True
            else:
                again = False
        elif(choice == 3):
            print("Enter base and height of triangle:", end=" ")
            b, h = input().split()
            h = int(h)
            b = int(b)
            print("Triangle of height "+str(h)+",base "+str(b)+" is:", end="")
            print(str(area_triangle(h, b)))
            print("you wnat to continue (1/0)", end=" ")
            again_choice = int(input())
            if(again_choice):
                again = True
            else:
                again = False
        elif(choice == 4):
            print("Enter base and height of parallelogram:", end=" ")
            b, h = input().split()
            h = int(h)
            b = int(b)
            print("Parallelogram of height "+str(h)+",base "+str(b)":", end="")
            print(str(area_parallelogram(h, b)))
            print("you wnat to continue (1/0)", end=" ")
            again_choice = int(input())
            if(again_choice):
                again = True
            else:
                again = False
        elif(choice == 5):
            print("Enter bases and height of trapezium:", end="")
            b1, b2, h = input().split()
            b1 = int(b1)
            b2 = int(b2)
            h = int(h)
            print("Trapezium with bases "+str(b1)+" and "+str(b2), end=" ")
            print("and height "+str(h)+" is: "+str(area_trapezium(b1, b2, h)))
            print("you wnat to continue (1/0)", end=" ")
            again_choice = int(input())
            if(again_choice):
                again = True
            else:
                again = False
        elif(choice == 6):
            print("Enter radius of circle:", end=" ")
            r = int(input())
            print("Circle with radius "+str(r)+" is: "+str(area_circle(r)))
            print("you wnat to continue (1/0)", end=" ")
            again_choice = int(input())
            if(again_choice):
                again = True
            else:
                again = False
        else:
            print("please enter valid choice")
            again = True
if __name__ == "__main__":
    main()
