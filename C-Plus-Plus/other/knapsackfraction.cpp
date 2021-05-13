/*
Given weights and values of n items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
Here We are solving fractional knapsack in which we can take a fraction of item too.
*/

#include <iostream>
using namespace std;
// A function to sort the arrays according to profit/weight
void sort_arr(float ratio[], float profit[], float weight[], int n) 
{
    float temp;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (ratio[j] < ratio[j + 1])
            {
                temp = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = temp;

                temp = weight[j];
                weight[j] = weight[j + 1];
                weight[j + 1] = temp;

                temp = profit[j];
                profit[j] = profit[j + 1];
                profit[j + 1] = temp;
            }
}

//function to calculate max value in knapsack.
int knapsack_fraction(float weight[], float ratio[], float profit[], int n, int capacity) 
{
    int final = 0;
    int i;
    //iterating over all items
    for (i = 0; i < n; i++) 
    {
        //checking if current weight is greater tahn break i.e this weight can't be put into knapsack.
        if (weight[i] > capacity) 
            break;
        //else add profir to final varibale i.e max profit and update capacity accordingly
        else 
        {
            final = final + profit[i];
            capacity = capacity - weight[i];
        }
    }
    //for fraction amount of item
    if (i < n) 
        final = final + (ratio[i] * capacity);
    return final;
}

int main()
{
    float weight[20], profit[20], ratio[20], final, temp, capacity, amount;
    int n, i, j;
    cout << "Enter the number of items :";
    cin >> n;
    //accepting the profit and weight values for given value of n.
    for (i = 0; i < n; i++) 
    {
        cout << "Enter Profit and weight for item" << i + 1;
        cin >> profit[i] >> weight[i];
    }
    cout << "Enter the capacity of knapsack :" << endl;
    cin >> capacity;
    //making the new array and storing ratio (profit/weight)
    for (i = 0; i < n; i++)
        ratio[i] = profit[i] / weight[i];
    //first sort the array acc to Profit/weight
    sort_arr(ratio, profit, weight, n); 
    //call the function to calculate max profit.
    int ans = knapsack_fraction(weight, ratio, profit, n, capacity); 
    cout << "the maximum profit is : " << ans << endl;
    return 0;
}

/*
OUTPUT:-
Enter the number of items :5
Enter Profit and weight for item15 2
Enter Profit and weight for item23 1
Enter Profit and weight for item36 3
Enter Profit and weight for item48 1
Enter Profit and weight for item510 6
Enter the capacity of knapsack :
the maximum profit is : 32
*/
