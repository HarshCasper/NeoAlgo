/*
-In Round-robin scheduling, each ready task runs turn by turn only in a cyclic queue 
for a limited time slice. 
-This algorithm also offers starvation free execution of processes.
-It is preemptive as processes are assigned CPU only for a fixed slice of time at most.
*/

import java.util.*;

class Procces {
    float ArrivalTime, BurstTime, FinishTime, WaitingTime, TurnAroundTime, BT;
    int flag, id;

    public Procces(float BurstTime, int id) {
        this.ArrivalTime = 0;
        this.BurstTime = BurstTime;
        WaitingTime = 0;
        BT = BurstTime;
        this.id = id;
        flag = 0;
    }
}

class ManagingQueue {
    Procces P[] = new Procces[20];
    int SizeOfCircularQueue, TotalProcessesFinished;
    int front, rear;
    float Timer, AWT, ATT;

    ManagingQueue(int SizeOfCircularQueue) {
        front = -1;
        rear = -1;
        this.SizeOfCircularQueue = SizeOfCircularQueue;
        Timer = 0;
        TotalProcessesFinished = 0;
    }

    int IsQueueEmpty() { // Checking whether queue is empty
        if ((front == 0 && rear == -1) || (front == (rear + 1))) {
            return 1;
        } else {
            return 0;
        }
    }

    int IsQueueFull() { // checking queue is full or not
        if ((front == 0 && rear == (SizeOfCircularQueue - 1)) || front == (rear + 1) % SizeOfCircularQueue) {
            return 1;
        } else {
            return 0;
        }
    }

    void ManageProcessQueue() {
        float BurstTime;
        int id, i, QuantumTime;
        Scanner sc = new Scanner(System.in);
        Procces CircularQueue[] = new Procces[SizeOfCircularQueue];
        System.out.println("Enter Quantum time :");
        QuantumTime = sc.nextInt();
        for (i = 0; i < SizeOfCircularQueue; i++) {
            System.out.println("Enter Process ID :");
            id = sc.nextInt();
            System.out.println("Enter Burst time :");
            BurstTime = sc.nextFloat();
            P[i] = new Procces(BurstTime, id);
            if (IsQueueFull() != 1) {
                rear = (rear + 1) % SizeOfCircularQueue;
                CircularQueue[rear] = P[i]; // Enqueuing process

            }
        }
        while (TotalProcessesFinished != SizeOfCircularQueue) {
            for (i = 0; i < SizeOfCircularQueue; i++) {
                if (IsQueueEmpty() != 1) {
                    if (front == -1) {
                        front = 0;
                    }
                    if (P[i].flag != 1) {
                        if (P[i].BurstTime <= QuantumTime) {
                            TotalProcessesFinished++;
                            Timer = Timer + P[i].BurstTime;
                            P[i].BurstTime = 0;
                            P[i].FinishTime = Timer;
                            P[i].flag = 1;

                        } else {
                            P[i].BurstTime = P[i].BurstTime - QuantumTime;
                            Timer = Timer + QuantumTime;
                            if (IsQueueFull() != 1) {
                                rear = (rear + 1) % SizeOfCircularQueue;
                                CircularQueue[rear] = P[i];

                            }
                            front = (front + 1) % SizeOfCircularQueue; // Dequeue process
                        }

                    }
                }
            }
        }
        for (i = 0; i < SizeOfCircularQueue; i++) {
            P[i].TurnAroundTime = P[i].FinishTime;
            P[i].WaitingTime = P[i].TurnAroundTime - P[i].BT;
            AWT += P[i].WaitingTime;
            ATT += P[i].TurnAroundTime;
        }
        System.out.println("ProcessID    BurstTime FinishTime TurnAroundTime WaitingTime");
        for (i = 0; i < SizeOfCircularQueue; i++) {
            System.out.println(P[i].id + "\t\t" + P[i].BT + "\t" + P[i].FinishTime + "\t\t" + P[i].TurnAroundTime
                    + "\t\t" + P[i].WaitingTime);
        }
        System.out.println("Average turn around time is : " + (ATT / SizeOfCircularQueue) + "ms");
        System.out.println("Average waiting time is : " + (AWT / SizeOfCircularQueue) + "ms");
    }

}

public class CPU_Scheduling_RR {

    public static void main(String[] args) {
        int SizeOfCircularQueue;
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter size :");
        SizeOfCircularQueue = sc.nextInt();
        ManagingQueue M = new ManagingQueue(SizeOfCircularQueue);
        M.ManageProcessQueue();

    }

}

/*
 * Enter size :4 
 * Enter Quantum time : 2 
 * Enter Process ID : 1 
 * Enter Burst time : 4 
 * Enter Process ID : 2 
 * Enter Burst time : 3 
 * Enter Process ID : 3 
 * Enter Burst time : 8 
 * Enter Process ID : 4 
 * Enter Burst time : 1 
 * 
 * ProcessID BurstTime FinishTime TurnAroundTime WaitingTime 
 * 1         4.0       9.0        9.0            5.0 
 * 2         3.0       10.0       10.0           7.0 
 * 3         8.0       16.0       16.0           8.0 
 * 4         1.0       7.0        7.0            6.0 
 * 
 * Average turn around time is : 10.5ms
 * Average waiting time is : 6.5ms
 * 
 */
