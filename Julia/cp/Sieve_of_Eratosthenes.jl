#=Given a posititve number n find all the numbers from 2 to n which 
are prime and print them. Sieve of Eratosthenes is an optimal approach
to find the prime numbers.We get an array of length n and if the value
of array at index i is zero the number i is prime.=#

## Function 

function primeSieve(n)
    a = zeros(Int64, n + 5)
    for i = 2:n
        if (a[i] == 0)
            for j = (i*i):i:n
                a[j] = 1
            end
        end
    end
    for i = 2:n
        if (a[i] == 0)
            print("$(i) ")
        end
    end
end

##Input

n = readline()
n = parse(Int64, n)

#Calling the function

primeSieve(n)

#=
Sample test case:
Input:
    n = 20
Output:
    2 3 5 7 11 13 17 19 
    
Time complexity: O( N * log(log(N)) )
=#