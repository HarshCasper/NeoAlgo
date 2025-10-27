#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value, weight;
};

bool cmp(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, vector<Item>& arr) {
    sort(arr.begin(), arr.end(), cmp);

    double totalValue = 0.0;
    for (auto& item : arr) {
        if (W >= item.weight) {
            totalValue += item.value;
            W -= item.weight;
        } else {
            totalValue += item.value * ((double)W / item.weight);
            break;
        }
    }
    return totalValue;
}

int main() {
    int W = 50;
    vector<Item> arr = {{60, 10}, {100, 20}, {120, 30}};
    cout << "Maximum value in Knapsack = " << fractionalKnapsack(W, arr) << endl;
    return 0;
}
