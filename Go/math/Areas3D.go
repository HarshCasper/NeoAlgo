package main

import (
	"fmt"
	"math"
)

// Surface area of a Cone

func cone(r, l float64) float64 {
	return (math.Pi * r * r) + (math.Pi * r * l)
}

// Surface area of a Cube

func cube(a float64) float64 {
	return 6.0 * a * a
}

// Surface area of a Cuboid

func cuboid(a, b, c float64) float64 {
	return 2.0 * ((a * b) + (b * c) + (c * a))
}

// Surface area of a Cylinder

func cylinder(r, h float64) float64 {
	return (2.0 * (math.Pi * r * r)) + (r * h)
}

// Surface area of a Pyramid

func pyramid(l, b, h float64) float64 {
	return (l * b) + (l * math.Sqrt((b/2.0*b/2.0)+(h*h))) + (b * math.Sqrt((l/2.0*l/2.0)+(h*h)))
}

// Surface area of a Rectangular Prism

func rectangular_prism(l, b, h float64) float64 {
	return 2.0 * (l*b + l*h + b*h)
}

// Surface area of a Sphere

func sphere(r float64) float64 {
	return 4.0 * math.Pi * r * r
}

// Surface area of a Hemisphere

func hemisphere(r float64) float64 {
	return (2.0 * math.Pi * r * r) + (math.Pi * r * r)
}

func main() {
	fmt.Println(cone(3.0, 5.0))
	fmt.Println(cube(4.0))
	fmt.Println(cuboid(4.0, 6.0, 2.5))
	fmt.Println(cylinder(3.5, 5.0))
	fmt.Println(pyramid(4.0, 7.0, 5.5))
	fmt.Println(rectangular_prism(4.0, 3.5, 6.5))
	fmt.Println(sphere(4.0))
	fmt.Println(hemisphere(4.5))
}

// Time Complexity - O(1)
// Space Complexity - O(1)
