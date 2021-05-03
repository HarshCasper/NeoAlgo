/*
-SRTF(Shortest Remaining Time First) is the preemptive version of SJF scheduling. 
-In SRTF, the execution of the process can be stopped after certain amount of time. 
-At the arrival of every process, the short term scheduler schedules the process 
with the least remaining burst time among the list of available processes and the 
running process.
*/

import java.util.Scanner;

class process {
    int arrivalTime, burstTime, completionTime, turnaroundTime, waitingTime, remainingTime;
    int id;
    String name;

    process() {
        arrivalTime = 0;
        burstTime = 0;
        completionTime = 0;
        turnaroundTime = 0;
        waitingTime = 0;
        name = " ";
    }
}

public class CPU_Scheduling_SRTF {
    public static void main(String[] args) {
        Scanner SC = new Scanner(System.in);
        int num;
        int total_time = 0;
        float average_waiting_time = 0;
        float average_turnaround_time = 0;
        int min, select;

        System.out.println("Enter no of processes: ");
        num = SC.nextInt();

        process process[] = new process[20];

        for (int i = 0; i < num; i++) {
            process[i] = new process();
            System.out.println("Enter burst time: ");
            process[i].burstTime = SC.nextInt();
            process[i].remainingTime = process[i].burstTime;
            System.out.println("Enter arrival time: ");
            process[i].arrivalTime = SC.nextInt();
            System.out.println("Enter name of process: ");
            process[i].name = SC.next();
        }

        for (int i = 0; i < num; i++) {
            total_time = total_time + process[i].burstTime; // Calculation of total time
        }

        System.out.println("Total time: " + total_time);

        String gantt[] = new String[total_time]; // Array of gantt chart

        for (int i = 0; i < total_time; i++) {
            min = total_time;
            select = 0;
            for (int j = 0; j < num; j++) {
                if (process[j].arrivalTime <= i) {
                    if (process[j].remainingTime < min && process[j].remainingTime != 0) // check if min time is less than min
                    {
                        min = process[j].remainingTime;
                        select = j; // store min address in variable
                    }
                }
            }
            gantt[i] = process[select].name;

            process[select].remainingTime--;
        }

        System.out.println("Gantt chart is: ");
        for (int i = 0; i < total_time; i++) {
            System.out.print(gantt[i] + "\t");
        }

        System.out.println();

        for (int i = 0; i < num; i++) {
            int k = total_time - 1;
            while (process[i].name.compareTo(gantt[k]) != 0) {
                k--;
            }
            if (process[i].name.compareTo(gantt[k]) == 0) {
                process[i].completionTime = k + 1;
            }
        }
        for (int i = 0; i < num; i++) {
            process[i].turnaroundTime = process[i].completionTime - process[i].arrivalTime;
            process[i].waitingTime = process[i].turnaroundTime - process[i].burstTime;
            average_waiting_time = average_waiting_time + process[i].waitingTime;
            average_turnaround_time = average_turnaround_time + process[i].turnaroundTime;

        }
        average_waiting_time = average_waiting_time / num;
        average_turnaround_time = average_turnaround_time / num;

        System.out.println("Name\tAT\tBT\tFT\tTT\tWT");

        for (int i = 0; i < num; i++) {
            System.out.println(
                    process[i].name + " " + process[i].arrivalTime + "\t" + process[i].burstTime + "\t" + process[i].completionTime + "\t" + process[i].turnaroundTime + "\t" + process[i].waitingTime);
        }
        System.out.println("\nAverage Waiting Time : " + average_waiting_time);
        System.out.println("\nAverage Turnaround Time : " + average_turnaround_time);
        System.out.println();

    }

}

/*
 * Enter no of processes: 4 
 * Enter burst time: 6 
 * Enter arrival time: 0
 * Enter name of process: p1 
 * Enter burst time: 2 
 * Enter arrival time: 2 
 * Enter name of process: p2 
 * Enter burst time: 5 
 * Enter arrival time: 4 
 * Enter name of process: p3 
 * Enter burst time: 3 
 * Enter arrival time: 6 
 * Enter name of process: p4
 * 
 * Total time: 16
 * 
 * Gantt chart is: p1 p1 p2 p2 p1 p1 p1 p1 p4 p4 p4 p3 p3 p3 p3 p3
 * 
 * Name AT BT FT TT WT p1 0 6 8 8 2 p2 2 2 4 2 0 p3 4 5 16 12 7 p4 6 3 11 5 2
 * 
 * Average Waiting Time : 2.75 ms
 * 
 * Average Turnaround Time : 6.75 ms
 * 
 */