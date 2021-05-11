## Fast Power Calculation
### Consider two large numbers a and b of order 10^9. 
If we calculate a^b then only possible way to store this number is in form of string which make manipulation difficult. In Competitive Programming we often come across questions 
in which we are required to calculate (a^b)%1e9+7 which is not possible if we calculate a^b and then perform modulo operation in case of large numbers. Therefore we can use 
fast power calculation method to calculate power of such numbers by using properties of modulo arithmetic's.

### Used Property
* We use the property of modulo i.e. (a * b) % n = (a % n * b % n) % n.

### Algorithm
* Take an integer res = 1.
* Iterate a loop till b>0.
* If b is odd then perform res = (res % mod * a % mod) % mod.
* Else perform a = (a % mod * a % mod) % mod.
* Divide b by 2.

### Sample Input : 
4 <br>
2 3 <br>
25 2 <br>
10 50 <br>
30 35 <br>

### Sample Output:
8 <br>
625 <br>
319300014 <br>
81812392 <br>

### Complexity : O(n)
