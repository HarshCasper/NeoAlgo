/*
-Shortest Job First (SJF) is an algorithm in which the process having the smallest execution time is chosen for the next execution. 
-This scheduling method can be preemptive or non-preemptive. It significantly reduces the average waiting time for other processes 
awaiting execution. 
-It can improve process throughput by making sure that shorter jobs are executed first, hence possibly have a short turnaround time.
*/

import java.util.Scanner;

class sjf
{
    int arrival_time;
    int finish_time=0;
    int turnaround_time;
    int waiting_time;
    int burst_time;
    int id;
    public sjf(int B_T,int id)			//Parameterized constructor
    {
        arrival_time=0;
        burst_time=B_T;
    }
}

class process_sjf
{
    sjf process[]=new sjf[30];				//Array of objects
    Scanner sc=new Scanner(System.in);
   
    int burst_time;
    int id;
    int num;

    public void create()			
    {
    System.out.println("Enter number of processes: ");
    num=sc.nextInt();
    for(int i=0;i<num;i++)
    {

        System.out.println("Enter the process id: ");
        id=sc.nextInt();
        System.out.println("Enter the burst time: ");
        burst_time=sc.nextInt();
        process[i]=new sjf(burst_time,id);
    }
    }
   
    public void sorting()					//Bubble sort
    {
        int i,j;
        sjf temp;
        for(i=0;i<num-1;i++)
        {
            for(j=0;j<num-i-1;j++)
            {
                if(process[j].burst_time > process[j+1].burst_time)
                {
                    temp=process[j];
                    process[j]=process[j+1];
                    process[j+1]=temp;
                }
   
            }
        }
       
    }
   
    public void calc()			
    {
        int i;   
        sorting();
        process[0].finish_time=process[0].burst_time;
        System.out.println(process[0].finish_time);
        for(i=1;i<num;i++)          //Completion time
        {
            process[i].finish_time=process[i-1].finish_time+process[i].burst_time;		//Finish time calculation
        }
       
        for(i=1;i<num;i++)         //Turnaround time
        {
            process[i].turnaround_time=process[i].finish_time-0;					//Turnaround time calculation
        }
        for(i=1;i<num;i++)        //Wating time
        {
            process[i].waiting_time=process[i].turnaround_time-process[i].burst_time;		//Waiting time calculation
        }
       
 
    }

    public void display()			
    {
    	int i=0;
    	int j=0;
    	int k=0;
    	sjf temp;
    	float avg_tt=0;
        float avg_wt=0;
           calc();
           for(i=0;i<num-1;i++)
           {
                k=i;
               for(j=i+1;j<num;j++)
               {
                   if(process[j].id<process[k].id)
                   {
                       k=j;
                   }
               }
              
                  if(k!=i)
                   {
                       temp=process[i];
                       process[i]=process[k];
                       process[k]=temp;
                   }
           }
       System.out.println("Process"+"\t\t"+"Arrival time"+"\t\t"+"Burst time"+"\t\t"+"Finish time"+"\t\t"+"Turnaround time"+"\t\t"+"Waiting time");
 
           for( i=0 ; i<num ; i++)
           {
               System.out.println("P"+process[i].id+"\t\t\t"+"0"+"\t\t\t"+process[i].burst_time+"\t\t\t"+process[i].finish_time+"\t\t\t"+process[i].turnaround_time+"\t\t\t"+process[i].waiting_time);
               avg_tt=avg_tt+process[i].turnaround_time;
               avg_wt=avg_wt+process[i].waiting_time;
           }
          
           avg_tt=avg_tt/num;				//Average turnaround time
           avg_wt=avg_wt/num;				//Average waiting time
          
           System.out.println("\nAverage Turn Around time="+avg_tt+"ms");
           System.out.println("Average Waiting time="+avg_wt+"ms");
    }
}

public class CPU_Scheduling_SJF{
    public static void main(String[] args)
    {
        process_sjf p=new process_sjf();
        p.create();
        p.display();
       
    }

}

/*
Enter number of processes: 
5
Enter the process id: 
1
Enter the burst time: 
22
Enter the process id: 
2
Enter the burst time: 
8
Enter the process id: 
3
Enter the burst time: 
20
Enter the process id: 
4
Enter the burst time: 
10
Enter the process id: 
5
Enter the burst time: 
4

Gantt chart:
P5		P2		P4		P3		P1

Process		Arrival time		Burst time		Finish time		Turnaround time		Waiting time
P1			0			22			64			64			42
P2			0			8			12			12			4
P3			0			20			42			42			22
P4			0			10			22			22			12
P5			0			4			4			0			0

Average Turn Around time=28.0ms
Average Waiting time=16.0ms
*/