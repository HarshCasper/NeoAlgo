// Surface Area of a Cone

package main

import ("fmt" ; "math")

var Surface_Area float64

func main(){
            var r float64 = 3
            var l float64 = 7
            Surface_Area = (math.Pi * r * r) + (math.Pi * r * l)
            fmt.Print(Surface_Area)
           }


// Surface Area of a Cube

package main

import "fmt"

var Surface_Area float64

func main(){
            var a float64 = 3
            Surface_Area = 6 * a * a
            fmt.Print(Surface_Area)
           }


// Surface Area of a Cuboid

package main

import "fmt"

var Surface_Area float64

func main(){
            var a float64 = 3
            var b float64 = 5
            var c float64 = 7
            Surface_Area = 2 * ((a*b)+(b*c)+(c*a)) 
            fmt.Print(Surface_Area)
           }


// Surface Area of a Cylinder

package main

import ("fmt" ; "math")

var Surface_Area float64

func main(){
            var r float64 = 3
            var h float64 = 5
            Surface_Area = (2 * (math.Pi * r * r)) + (r*h)
            fmt.Print(Surface_Area)
           }


// Surface Area of a Pyramid

package main

import ("fmt" ; "math")

var Surface_Area float64

func main(){
            var l float64 = 3
            var b float64 = 4
            var h float64 = 5
            Surface_Area = (l*b) + (l*math.Sqrt((b/2*b/2)+(h*h))) + (b*math.Sqrt((l/2*l/2)+(h*h)))
            fmt.Print(Surface_Area)
           }
           
           
// Surface Area of a Rectangle Prism

package main

import "fmt"

var Surface_Area float64

func main(){
            var l float64 = 3
            var b float64 = 4
            var h float64 = 5
            Surface_Area = 2 * (l*b + l*h + b*h)
            fmt.Print(Surface_Area)
           }


// Time Complexity - O(n)
// Space Complexity - O(n)
           
           
// Surface Area of a Sphere
 
package main

import ("fmt" ; "math")

var Surface_Area float64

func main(){
            var r float64 = 3.5
            Surface_Area = 4 * math.Pi * r * r
            fmt.Print(Surface_Area)
           }
           
           
// Surface Area of Hemisphere

package main

import ("fmt" ; "math")

var Surface_Area float64

func main(){
            var r float64 = 3.5
            Surface_Area = (2 * math.Pi * r * r) + (math.Pi * r * r)
            fmt.Print(Surface_Area)
           }
