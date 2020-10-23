/* There is an array of n integers. There are also 2 disjoint sets, A and B, each containing m integers.
You like all the integers in set A and dislike all the integers in set B. Your initial happiness is 0. 
For each i integer in the array, if i e A , you add 1 to your happiness. If i e B, you add -1 to your happiness.
Otherwise, your happiness does not change. Output your final happiness at the end.

	Input Format
	
	The first line contains integers n and m separated by a space.
	The second line contains n integers, the elements of the array.
	The third and fourth lines contain m integers, A and B, respectively.
	
	Output Format
	
	Output a single integer, your total happiness.
	
Problem Link: https://www.hackerrank.com/challenges/no-idea/problem
*/

#include<stdio.h>

int countHappiness(int arr[], int n, int m, int A[], int B[]) {
  int happiness = 0, i, j;

  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {

      if (A[j] == arr[i]) {
        happiness += 1;
        break;
      }

      if (B[j] == arr[i]) {
        happiness -= 1;
        break;
      }
    }
  }
  return happiness;
}

int main() {
  int i, n, m, arr[100000], A[100000], B[100000], totalHappy;

  printf("Enter the value of n and m: ");
  scanf("%d%d", & n, & m);

  printf("Enter the elements of array: ");
  for (i = 0; i < n; i++)
    scanf("%d", & arr[i]);

  printf("Enter the elements of set A: ");
  for (i = 0; i < m; i++)
    scanf("%d", & A[i]);

  printf("Enter the elements of set B: ");
  for (i = 0; i < m; i++)
    scanf("%d", & B[i]);

  totalHappy = countHappiness(arr, n, m, A, B);
  printf("Total happiness= %d", totalHappy);

  return 0;
}

/*
	Sample input/output
	Enter the value of n and m: 3 2
	Enter the elements of array: 1 5 3
	Enter the elements of set A: 3 1
	Enter the elements of set B: 5 7
	Total happiness= 1
	
	Time Complexity= O(n^2) 
	Space Complexity= O(1)
*/
