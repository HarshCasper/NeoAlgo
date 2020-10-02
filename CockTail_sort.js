<html>  
<head>  
    <title>Cocktail Sort</title>  
    </head>  
        <body>  
            <script>  
                  
function Cocktail( a, n)  
{  
    var temp=0;   
    var is_swapped = 1;  
    var begin = 0;  
    var end = n - 1;  
   
    while (is_swapped) {  
        is_swapped = 0;  
     for (i = begin; i < end; ++i) {  
            if (a[i] > a[i + 1]) {  
            temp = a[i];  
        a[i]=a[i+1];  
        a[i+1]=temp;                  
        is_swapped = 1;  
            }  
        }  
    if (!is_swapped)  
            break;  
    is_swapped = 0;  
    for (i = end - 1; i >= begin; --i) {  
        if (a[i] > a[i + 1])   
    {  
          temp = a[i];  
      a[i]=a[i+1];  
      a[i+1]=temp;  
      is_swapped = 1;  
         }  
      }  
      beginbegin=begin+1;  
    }  
}  
  
    var txt = "<br>";  
    var arr = [0, 10, 2, 8, 23, 1, 3, 45];  
    var n = arr.length;  
    Cocktail(arr, n);  
    document.writeln("printing sorted array :\n"+txt);  
     for (i = 0; i < n; i++)  
     {  
         document.writeln(arr[i]+"/xa0");  
     }  
</script>  
</body>  
</html>  
