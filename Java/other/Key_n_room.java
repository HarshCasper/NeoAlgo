/*
Keys and rooms for entry

You are given n rooms and you are asked to start from room 0.
Each room is given a distinct number in 0, 1, 2, ..., N-1,
and each room may have some keys to access the next room. 
Formally, each room i has a list of keys room[i], 
and each key room[i][j] is an integer in [0, 1, ..., N-1],
where n is room length. Any key rooms[i][j] = v opens only for number v.
Initially, all the rooms starts locked except for room 0. 
It is given that you can walk back and forth between rooms freely.
Your task is to return true if and only if you can enter every room.
*/

import java.util.*;
import java.io.*;

class Key_n_room
{
    //function to check if rooms is visited and return true accordingly
    public boolean didVisitRooms(List<List<Integer>> room)
    {
        //visited reperesents true if at some time the room has been visited
        boolean[] visited = new boolean[room.size()];
        //it is given that we start we room 0 so it is automatically visited
        visited[0] = true;
        //keeping track of all the keys
        //keys represent the index of the next room that we can visit
        Stack<Integer> keys = new Stack();
        //since we are starting from room 0 it is also added in the keys stack 
        keys.add(0);

        while(!keys.isEmpty())
        {
            int current_key = keys.pop();
            //now we are going to access each key and check if 
            //any room unlocks with that key it means 
            //we haven't visited it yet so we unlock that room
            for (int new_key: room.get(current_key)) 
            {
                if (!visited[new_key])
                { 
                    //checking ..which hasn't been used for unlock yet
                    visited[new_key] = true; 
                    //if any key has not been used to unlocked then we add it to keys stack
                    keys.add(new_key); 
                }
            }    
        }

        for(boolean explored : visited)
        {
            //if room not visited return false
            if(!explored)
            {
                return false;
            }
        }
        return true;
    }

    //driver code
    public static void main(String []args)
    {
        Scanner scanner = new Scanner(System.in);
        //taking input
        int n;
        System.out.println("Enter the number of rooms : ");
        int n = scanner.nextInt();
        List<List<Integer>> room = new ArrayList<List<Integer>>();
        System.out.println("Enter the keys for rooms : ");
        for(int i = 0; i < n; i++)
        {
            room.add(scanner.nextInt());
        }
        //for output
        boolean result = didVisitRooms(room);
        System.out.println("The rooms are visited : "+result);
        System.out.println(" ");
    }
}

/*
EXAMPLE:-
Input--
Enter the number of rooms : 4
Enter the keys for rooms : [[1],[2],[3],[]]
Output--
The rooms are visited : true

TIME COMPLEXITY --> O(n+k), where n is the number of rooms, and r is the total number of keys.
SPACE COMPLEXITY --> O(n)
*/
