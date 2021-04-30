# Python program to check collinearity of three given points

# We can calculate the area formed by the three points, and if the area is zero then they lie on a same line.
def check_collinear(ax, ay, bx, by, cx, cy):
    """ The Area of a Triangle formed by three points (x1, y1), (x2, y2), (x3, y3)
    is determined by the following formula

    Area = (1/2) * {x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)} """
    area = ax * (by - cy) + bx * (cy - ay) + cx * (ay - by)
    if(area == 0):
        return True
    else:
        return False


if __name__ == '__main__':
    print("Enter the first co-ordinates:  ", end="")
    ax, ay = [int(x) for x in input().split(' ')]
    print("Enter the second co-ordinates: ", end="")
    bx, by = [int(x) for x in input().split(' ')]
    print("Enter the third co-ordinates:  ", end="")
    cx, cy = [int(x) for x in input().split(' ')]
    res = check_collinear(ax, ay, bx, by, cx, cy)
    if res:
        print("The given points are collinear")
    else:
        print("The given points are not collinear")


"""
Time Complexity: O(1)
Space Complexity: O(1)

SAMPLE INPUT AND OUTPUT

Enter the first co-ordinates:  1 1
Enter the second co-ordinates: 2 2
Enter the third co-ordinates:  3 3
The given points are collinear
"""
