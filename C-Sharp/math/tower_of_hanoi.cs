// Tower of Hanoi problem a mathematical problem
// The Time complexity of this problem is O(2^n) and Space complexity is O(n).

using System; 
  
class towerOfHanoi
{ 
	// recursive function to move complete disks from starting rod to final rod
	
    static void moveDisks(int n, int start_rod, int final_rod, int aux_rod) 
    { 
        if (n>0) 
        { 
        moveDisks(n-1, start_rod, aux_rod, final_rod); 
        Console.WriteLine("Move disk " + n + " from rod " + start_rod + " to rod " + final_rod); 
        moveDisks(n-1, aux_rod, final_rod, start_rod); 
        }
    } 
      
    public static void Main() 
    { 
        Console.WriteLine("Enter the number of disks: ");
        int num = Convert.ToInt32(Console.ReadLine());
          
        moveDisks(num, 1, 3, 2);  
    } 
}

/* Sample input/output

Enter the number of disks: 
4
Move disk 1 from rod 1 to rod 2
Move disk 2 from rod 1 to rod 3
Move disk 1 from rod 2 to rod 3
Move disk 3 from rod 1 to rod 2
Move disk 1 from rod 3 to rod 1
Move disk 2 from rod 3 to rod 2
Move disk 1 from rod 1 to rod 2
Move disk 4 from rod 1 to rod 3
Move disk 1 from rod 2 to rod 3
Move disk 2 from rod 2 to rod 1
Move disk 1 from rod 3 to rod 1
Move disk 3 from rod 2 to rod 3
Move disk 1 from rod 1 to rod 2
Move disk 2 from rod 1 to rod 3
Move disk 1 from rod 2 to rod 3

*/