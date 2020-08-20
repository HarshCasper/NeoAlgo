/* Prime Factorization using Sieve */
using System; 
using System.Collections; 
  
class PFS
{ 
    static int MAX = 100001; 
    static int[] small_pf = new int[MAX]; 
      
    static void prime_sieve() 
    { 
        small_pf[1] = 1; 
        for (int i = 2; i < MAX; i++) 
            small_pf[i] = i; 
      
        for (int i = 4; i < MAX; i += 2) 
            small_pf[i] = 2; 
      
        for (int i = 3; i * i < MAX; i++) 
        { 
            if (small_pf[i] == i) 
            { 
                for (int j = i * i; j < MAX; j += i) 
                    if (small_pf[j] == j) 
                        small_pf[j] = i; 
            } 
        } 
    } 

    static ArrayList get_Factor(int x) 
    { 
        ArrayList r = new ArrayList(); 
        while (x != 1) 
        { 
            r.Add(small_pf[x]); 
            x = x / small_pf[x]; 
        } 
        return r; 
    } 
      
    public static void Main() 
    { 
        prime_sieve(); 
        Console.WriteLine("Enter a value:");
        int val = Convert.ToInt32(Console.ReadLine());
        
        Console.WriteLine("Prime factors are:"); 
        ArrayList p = get_Factor(val); 
      
        for (int i = 0; i < p.Count; i++) 
            Console.Write(p[i] + " "); 
        Console.WriteLine(""); 
    } 
} 
  
/* SAMPLE OUTPUT
Enter a value:                                                                                                                                
25                                                                                                                                            
Prime factors are:                                                                                                                            
5 5 

*/