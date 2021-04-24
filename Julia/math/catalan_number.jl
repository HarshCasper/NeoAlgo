# Julian program to Find the n'th Catalan number
# To know more about Catalan Numbers Visit Here : https://en.wikipedia.org/wiki/Catalan_number


function find_catalan(n)
    if (n == 0 || n == 1)
        return 1
    end

    # DP Table 
    cat = [0 for i in 1:(n + 1)]

    # Initialize the first to values
    cat[1] = 1
    cat[2] = 1
    for i in 3:(n + 1)
        for j in 1:(i - 1)
            cat[i] = cat[i] +  (cat[j] * cat[i - j])
        end
    end
    return cat[n + 1]
end

print("Enter the number: ")
num = readline()
num = parse(Int, num)
catalan_number = find_catalan(abs(num))
println("The $num'th catalan number is $catalan_number.")

"""
Time Complexity: O(num^2), where 'num' is the given number
Space Complexity: O(num)

SAMPLE INPUT AND OUTPUT

SAMPLE 1
Enter the number: 12
The 12'th catalan number is 208012.

SAMPLE 2
Enter the number: 2
The 2'th catalan number is 2.

"""
