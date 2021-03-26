/* JavaScript program for Implementation of Cocktail Shaker Sort
       Time Complexity: O(n*n)  */


function cocktailShakerSort(array) {

    
    let flag = true;  //  create a variable to keep track of whether or not there was a successful comparison made

    while (flag) {
        flag = false;
        for (let i = 0; i < array.length - 1; i++) {

            if (array[i] > array[i + 1]){

               // if the condition is true, swap i and i+1 elements 
               [array[i], array[i + 1]] = [array[i + 1], array[i]]; 
               flag = true;
            }
   }

   if (!flag)
   {
    break;   /* if the value of flag is still false, no changes were made
                 the array is already sorted, so we exit */
   }
       

   flag = false;

        for (let j = array.length - 1; j > 0; j--) {
            if (array[j-1] > array[j]) {
                // if the condition is true, swap j and j-1 elements 
                [array[j-1], array[j]] = [array[j], array[j-1]]; 
                flag = true;
            }
        }
    }
    return array;
}

console.log(cocktailShakerSort([5, 3, 4, 1, 2]));
// output will be [ 1, 2, 3, 4, 5 ]

console.log(cocktailShakerSort([15, 23, 4, 12, 32]));
// output will be [ 4, 12, 15, 23, 32 ]
