/*
Single Threaded CPU
=========================

Problem Statement:

You are given n​​​​​​ tasks labeled from 0 to n - 1 represented by a 2D integer array tasks.
tasks[i] = [enqueueTime, processingTime] means that the i​​​​​​th​​​​ task will be available to process at enqueueTime and will take processingTime to finish processing.

You have a single-threaded CPU that can process at most one task at a time and will act in the following way:

If the CPU is idle and there are no available tasks to process, the CPU remains idle.
If the CPU is idle and there are available tasks, the CPU will choose the one with the shortest processing time. 
If multiple tasks have the same shortest processing time, it will choose the task with the smallest index.
Once a task is started, the CPU will process the entire task without stopping.
The CPU can finish a task then start a new one instantly.

Output:

Return the order in which the CPU will process the tasks.

Concept:
- We sort the tasks according to enqueueTime
- We have a time variable which is initialized to the enqueueTime of the task with minimum enqueueTime
- We add the tasks with enqueueTime <= time to the Min Heap
- We remove the tasks from the min heap and add the processingTime to the time variable 
- we do this same process till all the tasks are processed by the CPU

We start time with the time of the task with minimum 
*/

#include <iostream>
#include <vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<int> get_order_of_tasks(vector<vector<int>> tasks) 
{
    vector<int> ans;
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> min_heap;

    int size = tasks.size();

    // adding the index of every task in the tasks array
    for (int index = 0; index < size; index++) {
        tasks[index].push_back(index);
    }

    // sorting all tasks based on the enqueue time
    sort(tasks.begin(), tasks.end());

    int index = 0;
    // initialize time with the enqueue time of the first task
    int time = tasks[0][0];

    while (!min_heap.empty() || index < size) {
        // add all the tasks with enqueue time <= time in the min heap
        while (index < size && time >= tasks[index][0]) {
            vector<int> task(2);
            task[0] = tasks[index][1];
            task[1] = tasks[index][2];
            min_heap.push(task);
            ++index;
        }

        //if min heap is empty i.e CPU is idle then make time equal to time of the next nearest task
        if (min_heap.empty()) {
            time = tasks[index][0];
        } else {
            auto task = min_heap.top();
            min_heap.pop();
            // if CPU is not idle add processing time of current task in time
            time += task[0];
            ans.push_back(task[1]);
        }
    }
    return ans;
}

int main() 
{
    vector<vector<int>> tasks;
    int rows;
    int processing_time;
    int enqueue_time;

    cin >> rows;
    
    for (int i = 0; i < rows; i++) {
        vector<int> task;
        cin >> enqueue_time;
        cin >> processing_time;
        task.push_back(enqueue_time);
        task.push_back(processing_time);
        tasks.push_back(task);
    }

    vector<int> ans;
    ans = get_order_of_tasks(tasks);
    
    for (auto element: ans) cout << element << " ";
    cout << endl;
}

/*
Time Complexity: O(NlogN)
Space Complexity: O(N)

Input:
points = [[1,2],[2,4],[3,2],[4,1]]

Output:
[0,2,3,1]

Explanation:
- At time = 1, task 0 is available to process. Available tasks = {0}.
- Also at time = 1, the idle CPU starts processing task 0. Available tasks = {}.
- At time = 2, task 1 is available to process. Available tasks = {1}.
- At time = 3, task 2 is available to process. Available tasks = {1, 2}.
- Also at time = 3, the CPU finishes task 0 and starts processing task 2 as it is the shortest. Available tasks = {1}.
- At time = 4, task 3 is available to process. Available tasks = {1, 3}.
- At time = 5, the CPU finishes task 2 and starts processing task 3 as it is the shortest. Available tasks = {1}.
- At time = 6, the CPU finishes task 3 and starts processing task 1. Available tasks = {}.
- At time = 10, the CPU finishes task 1 and becomes idle.

Input 2: 
points = [[7,10],[7,12],[7,5],[7,4],[7,2]]

Output:
[4,3,2,0,1]
*/

