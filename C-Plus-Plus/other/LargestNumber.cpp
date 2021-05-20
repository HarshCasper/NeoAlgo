/* Given a list of non-negative integers nums (The numbers not need necessarily to be single digit), arrange them such that they form the largest number. 
   Intuition
   To construct the largest number, we want to ensure that the most significant digits are occupied by the largest digits. */ 
   
/* Code / Solution */

#include<bits/stdc++.h>
using namespace std;

/* Comparator function for custom sorting  */
static bool comparator(int first ,int second){
	//to_string is inbuilt function which converts int to string
	string a=to_string(first);
	string b=to_string(second);
	
	return (a + b > b + a); // Returns true/false based on the condition
	
}

/* Largest number function return maximum number as a string as the number can be very large   */
string largestNumber(int n,int arr[]){
	
/* A simple solution is to sort the numbers in descending order but simply sorting doesn't works.
   This would definately work if only single digit numbers are present .
   For this we first convert each integer into string and then create a custom sort function.
   We assume that for some pair of integer a and b our comparator a + b > b + a. Here a ,b represents
   strings so + gives concatenation of strings. In other words our custom comparator preserves transitivity,
   so this sort is correct.        */
   sort(arr,arr+n,comparator); //using custom sort 
   string res="";//Initialising result string 
   
/* Iterating over the numns array after sorting and storing in a string   */
   for(int i=0;i<n;i++)
   res+=to_string(arr[i]);
   
/* Edge case if the array consist of only zeroes
   So if the most significant number is 0, we can simply
   return 0  */
   if(res[0]=='0')
   return "0";
   
   return res;	  
}

//Driver Code
int main(){
	int n;
	cout<<"Enter the size of the Array : ";
	cin>>n;
	int arr[n];//Initialising array of size n
	cout<<"Enter the elements of the Array arr :";
	for(int i=0;i<n;i++)
	cin>>arr[i];
	string res=largestNumber(n,arr);
	cout<<"The largest Number formed from given array is : ";
	cout<<res<<endl;
	return 0;
}

/*

    Sample Input1:
    Enter the size of the Array : 5
    Enter the elements of the Array arr : 3 30 34 5 9
  
    Output:The largest Number formed from given arrar is : 9534330
  
    Sample Input2:
    Enter the size of the Array : 2
    Enter the elements of the Array arr : 10 2
  
    Output:The largest Number formed from given arrar is : 210
  
  
  
  
    Time Complexity :  O(nlogn)
       Although we are doing extra work in our comparator, it is only by a constant factor.
	   Therefore, the overall runtime is dominated by the complexity of sort, which is O(nlogn).
	 
    Space Complexity :  O(n)
	   Since there is allocation of extra space to store copy of the original array.
	  
*/
  
  
  
   
   

