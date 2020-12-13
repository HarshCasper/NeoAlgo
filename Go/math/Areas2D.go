// Area of a rectangle

package main

import "fmt"

var area float64

func main() {
	var l float64 = 6
	var b float64 = 4
	area = l*b
	fmt.Print(area)
  }


// Area of a Square

package main

import "fmt"

var area float64

func main() {
	var a float64 = 5
	area = a*a
	fmt.Print(area)
  }



// Area of a Triangle

package main

import "fmt"

var area float64

func main() {
	var b float64 = 5
	var h float64 = 4.3
	area = b*h/2
	fmt.Print(area)
	}


// Area of a Circle

package main

import "fmt"
import "math"

var area float64

func main() {
	var r float64 = 5
	area = math.Pi * math.Pow(r,2)
	fmt.Print(area)
	}
  
  
  // Area of a Parallelogram
  
package main

import "fmt"

var area float64

func main() {
	var b float64 = 5
  var h float64 = 7
	area = b * h
	fmt.Print(area)
	}
  
  
  // Area of a Trapezium
  
package main

import "fmt"

var area float64

func main() {
	var a float64 = 5
  var b float64 = 6.5
	var h float64 = 4
  area = (a+b)*h/2
	fmt.Print(area)
	}

// Time Complexity - O(n)
// Space Complexity - O(n)
