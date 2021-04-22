package main

import (
	"fmt"
	"math"
)

// Area of a Rectangle

func rectangle(l, b float64) float64 {
	return l * b
}

// Area of a Square

func square(l float64) float64 {
	return l * l
}

// Area of a Triangle

func triangle(b, h float64) float64 {
	return (b * h) / 2.0
}

// Area of a Circle

func circle(r float64) float64 {
	return math.Pi * math.Pow(r, 2)
}

// Area of a Parallelogram

func parallelogram(b, h float64) float64 {
	return b * h
}

// Area of a Trapezium

func trapezium(a, b, h float64) float64 {
	return (a + b) * h / 2.0
}

func main() {
	fmt.Println(rectangle(3.0, 5.0))
	fmt.Println(square(4.0))
	fmt.Println(triangle(4.0, 6.0))
	fmt.Println(circle(3.5))
	fmt.Println(parallelogram(4.0, 7.0))
	fmt.Println(trapezium(4.0, 3.5, 6.5))
}

// Time Complexity - O(1)
// Space Complexity - O(1)
