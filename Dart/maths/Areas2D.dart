import 'dart:io';

// Area of a Square
double square(double a) {
  return a * a;
}

// Area of a Reactangle
double rectangle(double l, double b) {
    return l * b;
}

// Area of a Circle
double circle(double r, [double PI = 3.14]) {
    return PI * r * r;
}

// Area of a Triangle
double triangle(double b, double h) {
    return b * h/2.0;
}

// Area of a Parallelogram
double parallelogram(double b, double h) {
    return b * h;
}

// Area of a Trapezium

double trapezium(double a, double b, double h) {
    return (a+b)*h/2.0;
}

void main() {
  print("Enter side of square:");
  double squareSide = double.parse(stdin.readLineSync()!);
	print(square(squareSide));

  print("Enter length of rectangle:");
  double rectL = double.parse(stdin.readLineSync()!);
  print("Enter breadth of rectangle:");
  double rectB = double.parse(stdin.readLineSync()!);
  print(rectangle(rectL, rectB));

  print("Enter radius of circle:");
  double rad = double.parse(stdin.readLineSync()!);
  print(circle(rad));

  print("Enter base of triangle:");
  double triB = double.parse(stdin.readLineSync()!);
  print("Enter height of triangle:");
  double triH = double.parse(stdin.readLineSync()!);
  print(triangle(triB, triH));

  print("Enter base of parallelogram:");
  double paraB = double.parse(stdin.readLineSync()!);
  print("Enter height of parallelogram:");
  double paraH = double.parse(stdin.readLineSync()!);
  print(parallelogram(paraB, paraH));

  print("Enter length of 1st parallel side of trapezium:");
  double a = double.parse(stdin.readLineSync()!);
  print("Enter length of 2nd parallel side of trapezium:");
  double b = double.parse(stdin.readLineSync()!);
  print("Enter height of trapezium:");
  double h = double.parse(stdin.readLineSync()!);
  print(trapezium(a, b, h));
}
/**
Time complexity = O(n)
Space complexity = O(n)
Sample input/output:-
Enter side of square:
2.0
4.0
Enter length of rectangle:
4.1
Enter breadth of rectangle:
2.3
9.429999999999998
Enter radius of circle:
3.0
28.259999999999998
Enter base of triangle:
3.0
Enter height of triangle:
2.0
3.0
Enter base of parallelogram:
4.5
Enter height of parallelogram:
2.0
9.0
Enter length of 1st parallel side of trapezium:
1.5
Enter length of 2nd parallel side of trapezium:
4.5
Enter height of trapezium:
6.0
18.0
 */
