#include <bits/stdc++.h>
using namespace std;

struct Job {
    int id;
    int deadline;
    int profit;
};

bool cmp(Job a, Job b) {
    return a.profit > b.profit;
}

pair<int, int> jobScheduling(vector<Job>& jobs) {
    sort(jobs.begin(), jobs.end(), cmp);

    int maxDeadline = 0;
    for (auto& job : jobs) maxDeadline = max(maxDeadline, job.deadline);

    vector<int> slot(maxDeadline + 1, -1);
    int countJobs = 0, totalProfit = 0;

    for (auto& job : jobs) {
        for (int j = job.deadline; j > 0; j--) {
            if (slot[j] == -1) {
                slot[j] = job.id;
                countJobs++;
                totalProfit += job.profit;
                break;
            }
        }
    }

    return {countJobs, totalProfit};
}

int main() {
    vector<Job> jobs = {{1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 3, 15}};
    auto result = jobScheduling(jobs);
    cout << "Number of jobs done: " << result.first << endl;
    cout << "Total profit: " << result.second << endl;
    return 0;
}
