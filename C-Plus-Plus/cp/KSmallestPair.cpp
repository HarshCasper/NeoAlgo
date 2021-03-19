//A O(k*n1) TIME COMPLEXITY EFFICIENT SOLUTION WHICH IS BETTER THAN SOLVING BY
//BRUTE FORCE METHOD

#include<bits/stdc++.h>
#include<iostream>

using namespace std;

void kSmallPair(int array1[], int number1, int array2[], int number2, int k)
{
	if (k > number1*number2)
	{
		cout << "k pairs Does not exists";
		return ;
	} 
	
	int index2[number1];
	memset(index2, 0, sizeof(index2));

	while (k > 0)
	{
		int min_sum = INT_MAX;
		int min_index = 0;
		for (int i1 = 0; i1 < number1; i1++)
		{
	
			if (index2[i1] < number2 &&
				array1[i1] + array2[index2[i1]] < min_sum)
	     		{
			    	// Update index that gives minimum
		    		min_index = i1;

				    // update minimum sum
				    min_sum = array1[i1] + array2[index2[i1]];
			    }
		}

		cout << "(" << array1[min_index] << ", "
			<< array2[index2[min_index]] << ") ";

		index2[min_index]++;

		k--;
	}
}

int main()
 { 
    // GIVEN TESTCASE IN THE QUESTION

	int array1[] = {1, 3, 11};
	int number1 = sizeof(array1) / sizeof(array1[0]);

	int array2[] = {2, 4, 8};
	int number2 = sizeof(array2) / sizeof(array2[0]);

	int k = 4;
	kSmallPair( array1, number1, array2, number2, k);

	return 0 ;
    
 }
