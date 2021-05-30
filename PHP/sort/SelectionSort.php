<?php
/*Selection Sort is a type of sorting algorithm which saves the index of the
first element in every iteration and checks whether there is an element smaller than it,
then it saves the index of that particular element and swap it with the first element
of each iteration*/

    // function to implement Selection Sort in PHP
  
function SelectionSort(&$arr) {
    for ($i = 0; $i < count($arr) - 1; $i++)
    {   
    //the position of the first element is choosen as the minimum index
   //at each iterations of outer loop
        
        $min_index = $i;
        
        //then the below loop will run to check whether there is a
        //element smaller than the element at $min_index
        //if so it will swap the element at index j
        
        //with the element at min_index
    for ($j = $i + 1; $j < count($arr) - 1; $j++)
    {
    if ($arr[$j] < $arr[$min_index])
    {
    $min_index = $j;
    }
    }
        //swapping is done on the basis of the index found
        //which is stored in index min_index
        
        //and then swapped
    $temp = $arr[$min_index];
    $arr[$min_index] = $arr[$i];
    $arr[$i] = $temp;
        }
       }
       
$arr = array(-1, 2, -8, 854, -19, 0, 25000);
echo "Array before sorting:"."\n";
for($i=0;$i<count($arr);$i++)
{
    echo $arr[$i]." ";
}
SelectionSort($arr);
echo "\nArray after sorting:"."\n";
for($i=0;$i<count($arr);$i++)
{
    echo $arr[$i]." ";
}

//time complexity :O(n^2)
//space complexity:O(1)


/* Sample Output
Array before sorting:
-1 2 -8 854 -19 0 25000
Array after sorting:
-19 -8 -1 0 2 854 25000
*/
?>
