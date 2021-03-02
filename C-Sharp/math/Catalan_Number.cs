// Nth Catalan Number 
using System; 
class CatalanNumber 
{ 
    // A recursive function to find 
    // nth catalan number 
    static int catalan(int n) 
    { 
        int res = 0; 
        
        // Base case 
        if (n <= 1) 
        { 
            return 1; 
        } 
        for (int i = 0; i < n; i++) 
        {
            res += catalan(i) * catalan(n - i - 1); 
        } 
        return res; 
    } 
    
    // Main Function
    public static void Main() 
    { 
        int number;
        Console.Write("Enter the Number: ");
        number = int.Parse(Console.ReadLine());
        Console.Write("Nth Catalan numbers are: ");
        // Catalan Numbers
        for (int i = 0; i < number; i++) 
            Console.Write(catalan(i) + " "); 
    } 
} 

/*
Input:
Enter the Number: 4
Output:
Nth Catalan numbers are: 1 1 2 5

Time Complexity: O(2^n)
Space Complexity: O(1)
*/
