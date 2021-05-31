<!-- Quicksort is a divide-and-conquer algorithm.
    It works by selecting a 'pivot' element from the array
    and partitioning the other elements into two sub-arrays,
    according to whether they are less than or greater than the pivot. 
    The sub-arrays are then sorted recursively. -->

    <?php

function quickSort($arr)
 {
	$low = $great = array(); 
    /* If the array size is less than 2,
    we will return the array as it is */ 
	if(count($arr) < 2)
		return $arr;

    /*returns the key of the $arr element that's currently being pointed */
	$pivotKey = key($arr);
    /*removes the first element from $arr
      and stores the value in $pivot */
	$pivot = array_shift($arr);

	foreach($arr as $val)
        /* if the value is less than pivot update $low array */
		if($val <= $pivot)
			$low[] = $val;
        /*if the value is more than pivot update $great array*/
		elseif ($val > $pivot)
			$great[] = $val;

    /* merging the arrays to obtain the final result */
	return array_merge(quickSort($low),array($pivotKey=>$pivot),quickSort($great));
}

/*declaration and initialization of $arr*/
$arr = array(4, 0, 3, 1, -1, 6);
echo 'Original array is:    ';
$i=0;
for(;$i<count($arr)-1;$i++)
	echo $arr[$i].',';
echo $arr[$i].'<br>';

/*call of sort function*/
$arr = quickSort($arr);

/*printing the finally sorted array*/
echo 'Sorted array is:  ';
$i=0;
for(;$i<count($arr)-1;$i++)
	echo $arr[$i].',';
echo $arr[$i];

?>


<!-- Output Screen =>

Original array is: 4,0,3,1,-1,6
Sorted array is: -1,0,1,3,4,6

Time complexity : O(n^2)
Space complexity : O(log(n)) -->

