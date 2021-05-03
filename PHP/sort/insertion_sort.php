<?php$arr = [67, 44, 8, 21, 1, 36, 3, 58, 18];function insertSort($arr)
{
   $count = count($arr); if ($count <2) {
       return $arr;
   } for ($i = 1; $i <$count; $i++) {
      //The current value
       $temp = $arr[$i];
       for ($k = $i-1; $k >= 0; $k--) {
          //The condition is true, move one digit after the comparison value, and replace the current value with the comparison value
          //Reverse order $temp> $arr[$k]
           if ($temp <$arr[$k]) {
               $arr[$k + 1] = $arr[$k];
               $arr[$k] = $temp;
           }
       }
   }
   return $arr;
}print_r(insertSort($arr));
//Array ([0] => 1 [1] => 3 [2] => 8 [3] => 18 [4] => 21 [5] => 36 [6] => 44 [7] = > 58 [8] => 67)