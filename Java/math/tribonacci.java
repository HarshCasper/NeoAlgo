 //package mypack;
 import java.util.Scanner;
 public class tribonacci 
 {
    public static void main(String [] args)
    {
	/*Approach : A term is the sum of preceding three terms in this series. The sum of three preceding variables will be stored in "sum" variable.
	The first of the three variable terms will be overrided by second variable term which in turn will be overrided by third one and the third term will be 
	overrided by the sum. This process will continue till n terms.*/ 

        Scanner scan = new Scanner(System.in);
        long num;int first=0,second=0,third=1,sum=0,count=0;
        System.out.println("Enter the number upto which the series is to be printed");
        num=scan.nextLong();

        while(num>0)	
        {
            count++;
            if(count==1)
            System.out.print(0);
           else if(count==2)
            System.out.print(", "+0);
           else if(count==3)
            System.out.print(", "+1);
            else
            {
            sum=first+second+third;
            System.out.print(", "+sum);
            first=second;second=third;third=sum;
            }
         num--;
        }
    }
 }

 /*                                              OUTPUT:

 Test Case 1:

 Enter the number upto which the series is to be printed
 23
 0, 0, 1, 1, 2, 4, 7, 13, 24, 44, 81, 149, 274, 504, 927, 1705, 3136, 5768, 10609, 19513, 35890, 66012, 121415

 Test Case 2:

 Enter the number upto which the series is to be printed
 5
 0, 0, 1, 1, 2

 Space Complexity: O(n)
 Time Complexity: O(n)

 */
 
