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
    return round(1 / 2 * length * breadth,2)


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
    return round(1 / 2 * (base1 + base2) * height,2)


def area_circle(radius):
    """
    Calculate the area of a circle
    >> area_circle(20)
    1256.6370614359173
    """
    return round(math.pi * radius * radius,2)


def main():
    print("Areas of various geometric shapes: \n")
    print("Enter the shape of your choice: ")
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
            print(f"Rectangle with sides {l} and {b} is:", end="")
            print(str(area_rectangle(l, b)))
            print("you want to continue (1/0)", end=" ")
            again_choice = int(input())
            if(again_choice):
                again = True
            else:
                again = False
        elif(choice == 2):
            print("Enter side of square:", end=" ")
            l = int(input())
            print(f"Square with side {l} is: {area_square(l)}")
            print("You want to continue (1/0)", end=" ")
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
            print(f"Triangle of height {h},base {b} is:", end="")
            print(str(area_triangle(h, b)))
            print("You want to continue (1/0)", end=" ")
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
            print(f"Parallelogram of height {h},base {b}:", end="")
            print(str(area_parallelogram(h, b)))
            print("You want to continue (1/0)", end=" ")
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
            print(f"Trapezium with bases {b1} and {b2}", end=" ")
            print(f"and height {h} is: {area_trapezium(b1, b2, h)}")
            print("You want to continue (1/0)", end=" ")
            again_choice = int(input())
            if(again_choice):
                again = True
            else:
                again = False
        elif(choice == 6):
            print("Enter radius of circle:", end=" ")
            r = int(input())
            print(f"Circle with radius {r} is: {area_circle(r)}")
            print("You want to continue (1/0)", end=" ")
            again_choice = int(input())
            if(again_choice):
                again = True
            else:
                again = False
        else:
            print("Please enter valid choice")
            again = True
if __name__ == "__main__":
    main()
