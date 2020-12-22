
package main
  //Importing libraries and files
import (
    "fmt"
)
  //Function of Siral Matrix with arguments containg matrix
func spiral(n int) []int {
	//Traversing 
    left, top, right, bottom := 0, 0, n-1, n-1
    sz := n * n
    s := make([]int, sz)
    i := 0
    for left < right {
		
		//Traversing towards right top
        for c := left; c <= right; c++ {
            s[top*n+c] = i
            i++
        }
        top++
		
		//Traversing towards rright downward edge
        for r := top; r <= bottom; r++ {
            s[r*n+right] = i
            i++
        }
        right--
        if top == bottom {
            break
        }
		
		//Traversing towards left bottom
        for c := right; c >= left; c-- {
            s[bottom*n+c] = i
            i++
        }
        bottom--
		
		//Traversing towards left side of the matrix
        for r := bottom; r >= top; r-- {
            s[r*n+left] = i
            i++
        }
        left++
    }

    s[top*n+left] = i
  
    return s
}
  
func main() {
    num := 10
    len := 4
    for i, draw := range spiral(num) {
        fmt.Printf("%*d ", len, draw)
        if i%num == num-1 {
            fmt.Println("")
        }
    }
}