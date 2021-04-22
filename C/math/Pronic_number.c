/*
A pronic number is a number which is the product of two consecutive integers.
Such as 2=2*1 (2 and 1 are consecutive numbers)
        12=4*3
        
This program will print the pronic numbers in the given range.        
*/


#include <stdio.h>
#include<math.h>

/* Function to check whether number is pronic or not
A number is pronic if the root of equation i^2+i-num=0 is real and integer.*/
int is_pronic(int num){
    int dis=1+4*num,root;
    if(dis<=0)
      return 0;
    else{
    	 root=floor(sqrt(dis));
         if(root*root==dis && dis%2==1)
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

Sample Input/Output:

Input:
Enter the range for which you want to print PRONIC NUMBERS:
Enter lower limit:1
Enter higher limit:1000

Output:
PRONIC NUMBERS from 1 to 1000 are:
2 6 12 20 30 42 56 72 90 110 132 156 182 210 240 272 306 342 380 420 462 506 552 600 650 702 756 812 870 930 992

Time Complexity:O(n) where n is total numbers in range.
Time Complexity of is_pronic()=O(1) 
Space Complexity:O(1)

*/

