#include <bits/stdc++.h>
using namespace std;

// Function to find maximum number of non-overlapping activities
int activitySelection(vector<int>& start, vector<int>& end) {
    int n = start.size();
    vector<pair<int, int>> activities;
    for (int i = 0; i < n; i++) {
        activities.push_back({end[i], start[i]});
    }

    // Sort by end time
    sort(activities.begin(), activities.end());

    int count = 1; 
    int last_end = activities[0].first;

    for (int i = 1; i < n; i++) {
        if (activities[i].second >= last_end) {
            count++;
            last_end = activities[i].first;
        }
    }
    return count;
}

int main() {
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};

    cout << "Maximum number of activities: " << activitySelection(start, end) << endl;
    return 0;
}
