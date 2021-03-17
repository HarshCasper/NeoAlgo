/* 
Given n processes with their burst times, the task is to find average waiting time and average turn around time using FCFS scheduling algorithm.
First in, first out (FIFO), also known as first come, first served (FCFS), is the simplest scheduling algorithm. 
FIFO simply queues processes in the order that they arrive in the ready queue.
In this, the process that comes first will be executed first and next process starts only after the previous gets fully executed.
Here we are considering that arrival time for all processes is 0.
*/
#include<bits/stdc++.h> 
using namespace std; 
//this function computes the waiting time for all the processes
void findWaitingTime(int process[], int numOfProcess, int burst_time[], int wait_time[]) 
{ 
    //As first process that comes need not to wait so 
    //waiting time for process 1 will be 0 i.e. wt[0] = 0.
	wait_time[0] = 0; 
	//Find waiting time for all other processes i.e. for
    // process i -> 
	for (int i = 1; i < numOfProcess ; i++ ){
		wait_time[i] = burst_time[i-1] + wait_time[i-1] ; 
	}	
} 

//this function computes the turn around time for all the processes
void findTurnAroundTime( int process[], int numOfProcess, int burst_time[], int wait_time[], int turn_around_time[]) 
{ 
    //turnaround time = waiting_time + burst_time 
	for (int i = 0; i < numOfProcess ; i++) {
			turn_around_time[i] = burst_time[i] + wait_time[i]; 
	}
} 

void findavgTime( int process[], int numOfProcess, int burst_time[]) 
{ 
	int wait_time[numOfProcess], turn_around_time[numOfProcess], total_wt = 0, total_tat = 0; 
    
    //waiting time is calculated by passing the required data as a parameter to this function
	findWaitingTime(process, numOfProcess, burst_time, wait_time); 
	
    //waiting time is calculated by passing the required data as a parameter to this function
	findTurnAroundTime(process, numOfProcess, burst_time, wait_time, turn_around_time); 

	cout << "Processes "<< " Burst time "
		<< " Waiting time " << " Turn around time\n"; 
    
    //displaying the data table of the processes in table format
	for (int i=0; i<numOfProcess; i++) 
	{ 
		total_wt = total_wt + wait_time[i]; 
		total_tat = total_tat + turn_around_time[i]; 
		cout << " " << i+1 << "\t\t" << burst_time[i] <<"\t "
			<< wait_time[i] <<"\t\t " << turn_around_time[i] <<endl; 
	} 

	cout << "Average waiting time = "
		<< (float)total_wt / (float)numOfProcess;   //waiting time = total_waiting_time / no_of_processes.
	cout << "\nAverage turn around time = "
		<< (float)total_tat / (float)numOfProcess;  //average turnaround time = total_turn_around_time / no_of_processes.
} 

//driver code
int main() 
{ 
    //The number of processes that enters fcfs algorithm
    int numOfProcess;
    cout<<"Enter the Total no. of processes: ";
    cin>>numOfProcess;
    
    //the processes are numbered from 1 to N in the order they enter
	int process[numOfProcess]; 
	for(int i =0; i<numOfProcess; i++){
		process[i]=i;
	}
    
    //burst time of the processes are required
	int burst_time[numOfProcess]; 
	cout<<"Enter the burst time of the processes: ";
	for(int i =0; i<numOfProcess; i++){
		cin>>burst_time[i];
	}
    
	findavgTime(process, numOfProcess, burst_time); //the function then calculates the average waiting and average burst time
	return 0; 
} 

/*
Input:
Enter the Total no. of processes: 5
Enter the burst time of the processes 4 5 3 6 3

Output:
Processes  Burst time  Waiting time  Turn around time
 1              4        0               4
 2              5        4               9
 3              3        9               12
 4              6        12              18
 5              3        18              21
Average waiting time = 8.6
Average turn around time = 12.8
*/
