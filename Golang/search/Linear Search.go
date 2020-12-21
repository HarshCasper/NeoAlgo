package main
 
//Importing the module
import "fmt"
//Creating a function for linear search with arguments as key which is the element to be seached and an array
func linearsearch(datalist []int, key int) bool {
	for _, item := range datalist {
		//Checking if the search element is found
		if item == key {
			//If element being searched is found , return True else False
			return true
		}
	}
	return false
} 
 //Driver Code
func main() {
    items := []int{1,10,99,98,95,94,94,89,100}
    fmt.Println(linearsearch(items,98))
}