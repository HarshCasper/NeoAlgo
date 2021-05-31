<?php
function InsertionSort(&$arr)
{
    $n=count($arr);
    $next=null;
    for($i=1; $i<$n; $i++)//outer loop
    {
        $next=$arr[$i];
        for($j=$i-1; $j>=0; $j--)//inner loop
        {
            if( $arr[$j]>$next )//change > to < for descending order
            {
                $arr[$j+1]=$arr[$j];
            }
            else
            {
                break;
            }
        }
        $arr[$j+1]=$next; // insert the next value to the correct postion of the already sorted elements
 
    }
 
    return $arr;
}


$arr = array(-1, 2, -8, 854, -1900, 0, 250);
echo "Array before sorting:"."\n";
for($i=0;$i<count($arr);$i++)
{
    echo $arr[$i]." ";
}
InsertionSort($arr);
echo "\nArray after sorting:"."\n";
for($i=0;$i<count($arr);$i++)
{
    echo $arr[$i]." ";
}
/*
Sample Output
Array before sorting:
-1 2 -8 854 -1900 0 250 
Array after sorting:
-1900 -8 -1 0 2 250 854 

Time Complexity

    Best complexity: n
    Average complexity: n^2
    Worst complexity: n^2

*/


?>
