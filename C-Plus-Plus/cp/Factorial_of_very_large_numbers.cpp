/* C++ program to compute factorial of big numbers
   We will we finding factorial of quite big numbers,
   which can't be solved with the general approach of recursion */
   
#include<bits/stdc++.h>
using namespace std;

/* This function calculates product and carry,
   `rsize` is size of vector `res`*/
int multiply(int x, vector<int> &res, int rsize){

    int carry = 0;
	for (int i=0; i<rsize; i++)
	{
		int product = res[i] * x + carry;

		/* Storing the last digit of `prod` in res */
		res[i] = product % 10;
		carry = product/10;
	}

	/* Put carry in res and increment the result size */
	while (carry)
	{
		res.push_back(carry%10);
		carry = carry/10;
		rsize++;
	}
	return rsize;
}

/* Function finds factorial of large numbers
   and prints them */
void largeFactorial(int num)
{
	vector<int> res; 
	res.push_back(1);
	int rsize = 1;

	/* Applying general factorial formula */
	for (int x=2; x<=num; x++)
		rsize = multiply(x, res, rsize);

	cout << "Factorial of "<< num << " is : ";
	for (int i=rsize-1; i>=0; i--)
		cout << res[i];
}

/* Driver Function */
int main()
{
	int num;
	/*Taking input of the number*/
	cout << "Enter the number : ";
	cin >> num;
    largeFactorial(num);
    return 0;
}

/*
SAMPLE I/O =>
1.
Enter the number : 51
Factorial of 51 is : 1551118753287382280224243016469303211063259720016986112000000000000
2.
Enter the number : 69
Factorial of 69 is : 171122452428141311372468338881272839092270544893520369393648040923257279754140647424000000000000000
Time complexity : O(n^2)
Space complexity : O(log(n!))
*/
