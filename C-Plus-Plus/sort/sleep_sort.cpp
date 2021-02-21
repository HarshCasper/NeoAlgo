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

void Multithread(int NumList[]){
    std::vector <std::thread> Threads;
    for (int i = 0; i <= 10; i++)
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
	int NumList[] = {0,4,2,3,5,6,7,9,8,1};
	Multithread(NumList);
	for (auto& Num : Sorted)
	{
		std::cout << Num<<std::endl;
	}
    return 0;
}
