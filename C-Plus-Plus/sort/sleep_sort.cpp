#include<iostream>
#include<thread>
#include<chrono>
#include<vector>

std::vector <int> Sorted;

void CountDown(int Sec)
{
	std::this_thread::sleep_for(std::chrono::seconds(Sec));
	Sorted.push_back(Sec);
}

void Multithread(int NumList[], int n){
    std::vector <std::thread> Threads;
    for (int i = 0; i <= n; i++)
	{
		Threads.push_back(std::thread(CountDown, NumList[i]));
	}
	for (auto& thread : Threads)
	{
		thread.join();
	}
}

int main()
 {
    	int n,i;
	std::cin >> n;
	int NumList[n];
	for(i = 0; i < n; i++)
	{
           std::cin >> NumList[i];
	}
	Multithread(NumList, n);
	for (auto& Num : Sorted)
	{
		std::cout << Num<<std::endl;
	}
    return 0;
}

/*
Sample Input : n = 3
	       89
	       12
               26
Sample Output: 12
	       26
               89
Time Complexity : O(NlogN + max(input)) where input is maximum of input array elements.
Space Complexity : All the things are done by the internal priority queue of the OS. Hence auxiliary space is ignored
*/
