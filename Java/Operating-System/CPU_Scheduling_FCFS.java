/*
-First Come First Serve (FCFS) is an operating system scheduling algorithm that automatically 
executes queued requests and processes in order of their arrival. 
-It is the easiest and simplest CPU scheduling algorithm. 
-In this type of algorithm, processes which requests the CPU first get the CPU allocation first.
-This is managed with a FIFO queue.
*/

import java.util.Scanner;

class fcfs          
{
    int arrival_time;
    int finish_time=0;
    int burst_time;
    int turnaround_time;
    int id;
    int waiting_time;
  
    public fcfs(int at,int bt,int Id)			
    {
        arrival_time=at;
        finish_time=0;
        burst_time=bt;
        id=Id;
    }
}

class first_come_first_serve
{
    fcfs f[]=new fcfs[20];				//Array of objects
  
    Scanner sc=new Scanner(System.in);
    int arrival_time,burst_time,num;
    int id;
 
    public void accept()				//Accepting the details of processes
    {
    
        System.out.println("Enter the number of processes: ");
        num=sc.nextInt();
            for(int i=0;i<num;i++)
            {
                 System.out.println("Enter process id(Integer): ");
                id=sc.nextInt();
              
                System.out.println("Enter arrival time: ");
                arrival_time=sc.nextInt();
              
                System.out.println("Enter burst time: ");
                burst_time=sc.nextInt();
              
                f[i]=new fcfs(arrival_time,burst_time,id);
            }
        }
    
        public void calc() 		
        {
            f[0].finish_time=f[0].burst_time;
          
            System.out.println(f[0].finish_time);
          
            for(int i=1;i<num;i++)           //Finish time calculation
            {
                f[i].finish_time=f[i].burst_time+f[i-1].finish_time;
            }

        for(int i=0;i<num;i++)				//Turnaround time calculation
        {
            f[i].turnaround_time=f[i].finish_time-f[i].arrival_time;
        }
      
        for(int i=0;i<num;i++)				  //Waiting time calculation
        {
            f[i].waiting_time=f[i].turnaround_time-f[i].burst_time;
        }
    }
  
        public void display()						//Display of table
        {
            System.out.println("PROCESS"+"\t\t"+"ARRIVAL TIME"+"\t   "+"BURST TIME"+"\t   "+"FINISH TIME"+"\t\t"+"TURNAROUND TIME"+"\t\t"+"WAITING TIME");
     
        for(int i=0;i<num;i++)
        {
            System.out.println("P"+f[i].id+"\t\t   "+f[i].arrival_time+"\t\t\t"+f[i].burst_time+"\t\t "+f[i].finish_time+"\t\t"+f[i].turnaround_time+"\t\t"+f[i].waiting_time);
        }
      
        int sum=0;
        int avg_tt;
        int avg_wt;

        for(int i=0;i<num;i++)
        {
     
            sum=sum+(f[i].turnaround_time);
        }
      
        avg_tt=sum/num; 		//average turnaround time calculation
      
        System.out.println("\nAverage turn around time is: "+avg_tt+"ms");
      
        sum=0;
        for(int i=0;i<num;i++)
        {
            sum=sum+(f[i].waiting_time);
        }

        avg_wt=sum/num;			//average waiting time calculation
      
        System.out.println("Average waiting time is: "+avg_wt+"ms");
        }
     
 
}
public class CPU_Scheduling_FCFS {

    public static void main(String[] args) {
        first_come_first_serve f=new first_come_first_serve();
        f.accept();
        f.calc();
        f.display();

    }

}



/*
Enter the number of processes: 
4
Enter process id: 
0
Enter arrival time: 
0
Enter burst time: 
6
Enter process id: 
1
Enter arrival time: 
2
Enter burst time: 
5
Enter process id: 
2
Enter arrival time: 
4
Enter burst time: 
8
Enter process id: 
3
Enter arrival time: 
6
Enter burst time: 
4
6
PROCESS		ARRIVAL TIME	   BURST TIME	   FINISH TIME	    TURNAROUND TIME	WAITING TIME
P0		   0			6		6		 6		    0
P1		   2			5		11		 9		    4
P2		   4			8		19		 15		    7
P3		   6			4		23		 17		    13

Average turn around time is: 11ms
Average waiting time is: 6ms
*/
