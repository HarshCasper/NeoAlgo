// Randomized sort

#include <iostream>
using namespace std;

//GENERATES RANDOM NUMBER IN THE GIVEN RANGE
int random(int min, int max) 
{
    int range = max - min + 1;
    int num = min + (rand() % range);
    return num;
}
//CONVENTIONAL PARTITION
int partition(int arr[], int p, int r) 
{
    int x = arr[r];
    int i = p - 1;
    for (int j = p; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            ++i;
             //Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // Swap arr[i+1] and arr[r]
    int temp = arr[i + 1]; 
    arr[i + 1] = arr[r];
    arr[r] = temp;
    return i + 1;
}
//RANDOMIZED PARTITION
int randomizedPartition(int arr[], int p, int r) 
{
    int i = random(p, r);
    int temp = arr[r];
    arr[r] = arr[i];
    arr[i] = temp;
    return partition(arr, p, r);
}

//     RANDOMIZED SELECTION ALGORITHM TO FIND i_th ORDER STATISTIC IN EXPECTED LINEAR TIME.
 //RANDOMIZED SELECT
int randomizedSelect(int arr[], int p, int r, int i)
{
    // Checks for base case, when array has just 1 element
    if (p == r) 
        return arr[p];
    int q = randomizedPartition(arr, p, r);
    int k = q - p + 1;
    // The pivot value is the answer
    if (i == k) 
        return arr[q];
        // If this case, the desired value lies on the lower side of partition
    else if (i < k) 
        return randomizedSelect(arr, p, q - 1, i);
    else
        return randomizedSelect(arr, q + 1, r, i - k);
}

int main()
{
    int n, i;
    cout << "Enter number of elements: ";
    cin >> n;
    int A[n];
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    cout << "Enter i: ";
    cin >> i;
    cout << randomizedSelect(A, 0, n - 1, i) << endl;
    return 0;
}

/*
Time complexity :O(N)
Space complexity : O(1)
*/

/*
SAMPLE INPUT/OUTPUT
 INPUT--------------------------
 7
 5 9 4 12 7 1 10
 3
 OUTPUT-------------------------
 5
*/

