#= Given a number n, print its prime factorization. We could do it 
normal way which will be having time complexity of O (sqrt(N)) 
but we will be using Sieve to lessen the time complexity
We will make a sieve to get all the prime numbers and then get the 
prime factorization of the number using that.=#

## Function

function PrimeFactor(n)
    a = zeros(Int64, n)
    for i = 2:n
        a[i] = i
    end
    for i = 2:n
        if (a[i] == i)
            for j = (i*i):i:n
                if (a[j] == j)
                    a[j] = i
                end
            end
        end
    end
    while (n != 1)
        println(a[n])
        n = div(n, a[n])
    end
end

## Input

n = readline()
n = parse(Int64, n)

#Calling the function

PrimeFactor(n)

#=
Sample Test case
Input:
    n = 495
Output:
    3 3 5 11

Time Complexity: O( log N )
=#