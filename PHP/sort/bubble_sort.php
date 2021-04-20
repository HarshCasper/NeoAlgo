<!-- Bubble Sort is a simplealgorithm in which each element is compared to its adjacent element 
and if first elememt is greater than second element,then the swapping occurs.
This process continues till the array is sorted. -->

<?php
function bubbleSort($arr)
{
	do
	{
	/*$isSwap checks if swapping has occured or not*/
		$isSwap = false;
		for( $i = 0; $i < count($arr) - 1; $i++ )
		{
		    /*if the next element is smaller than the current element,
		    swapping will occur*/
			if( $arr[$i] > $arr[$i + 1] )
			{
				$temp = $arr[$i];
				$arr[$i] = $arr[$i + 1];
				$arr[$i + 1] = $temp;
				/*updating the value to true as swapping occured*/
				$isSwap = true; 
			}
		}
	}
	while( $isSwap ); 
	/*returning sorted array*/
	return $arr;
}

/*declaration and initialization of $arr*/
$arr = array(4, 0, 3, 1, -1, 6);
echo 'Original array is:    ';
$i=0;
for(;$i<count($arr)-1;$i++)
	echo $arr[$i].',';
echo $arr[$i]."\n";

/*call of sort function*/
$arr = bubbleSort($arr);

/*printing the finally sorted array*/
echo 'Sorted array is:  ';
$i=0;
for(;$i<count($arr)-1;$i++)
	echo $arr[$i].',';
echo $arr[$i];

?>

<!-- Output Screen =>

Original array is:    4,0,3,1,-1,6
Sorted array is:  -1,0,1,3,4,6

Time complexity : O(n^2)
Space complexity : O(1) -->
