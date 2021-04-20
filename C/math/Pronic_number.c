/*
     A pronic number is a number which is the product of two consecutive integers.
     Such as 2=2*1 (2 and 1 are consecutive numbers)
             12=4*3
             
     This program will print the pronic numbers in the given range.        
*/


#include <stdio.h>
#include<math.h>

//Function to check whether number is pronic or not
//A number is pronic if the root of equation i^2+i-num=0 is real and integer.
int is_pronic(int num){
    int d=1+4*num,root;
    if(d<=0)
      return 0;
    else{
    	 root=floor(sqrt(d));
         if(root*root==d && d%2==1)
            return 1;
         else
		   return 0;   
    }  
}

int main(){
    int ll,hl,i;
    printf("Enter the range for which you want to print PRONIC NUMBERS:\n");
    printf("Enter lower limit:");
    scanf("%d",&ll);
    printf("Enter higher limit:");
    scanf("%d",&hl);
    
    //Printing pronic numbers in given range
    printf("PRONIC NUMBERS from %d to %d are:\n",ll,hl);
    for(i=ll;i<=hl;i++){
        if(is_pronic(i))
           printf("%d ",i);   
    }
}

/*
Enter the range for which you want to print PRONIC NUMBERS:
Enter lower limit:1
Enter higher limit:1000
PRONIC NUMBERS from 1 to 1000 are:
2 6 12 20 30 42 56 72 90 110 132 156 182 210 240 272 306 342 380 420 462 506 552 600 650 702 756 812 870 930 992

Enter the range for which you want to print PRONIC NUMBERS:
Enter lower limit:500
Enter higher limit:5000
PRONIC NUMBERS from 500 to 5000 are:
506 552 600 650 702 756 812 870 930 992 1056 1122 1190 1260 1332 1406 1482 1560 1640 1722 1806 1892 1980 2070 2162 
2256 2352 2450 2550 2652 2756 2862 2970 3080 3192 3306 3422 3540 3660 3782 3906 4032 4160 4290 4422 4556 4692 4830 4970

*/

/*
   Time Complexity:O(n) //where n is total numbers in range.
   Time Complexity of is_pronic()=O(1) 
   Space Complexity:O(1)
*/