/*
    Euclidean Algorithm to find GCD in DART

    This algorithm follows the fact that the remainder a' of  a/b is also divisible by the gcd of a and b (i.e. d)

    😊 Lets prove this fact
    
    let d be the GCD of a & b 
    let a>b
    now    a/b   =>    a   =   a'  +   bq
    
    dividing both sides by d, where d is their gcd

    =>  a/d   =   (a'  +   bq)/d
    =>  a/d   =   a'/d  +   q*(b/d)

    a/d and b/d are in P/Q form where Q=1 since d is their GCD
    
    =>  a/d   -   q*(b/d) =   a'/d
    =>        X           =   a'/d where X is a positive integer

    this also implies that a'/d is also an integer (in p/q form where q=1)

    so it is proved that the remainder a' of  a/b is also divisible by the gcd of a and b (i.e. d)
    i.e. a,b,d have common gcd (You are going to get it at the end of calculation ---- consider example2)

*/

import 'dart:io';

int gcd(int a, int b) {
  if (b == 0) return a;

  return gcd(b, a % b);
  /* 
    Why return gcd(b, a % b) and not gcd(a % b, b)???

    for gcd(a,b), considering a>b, we can only do gcd(b,a') 
    here we cant do gcd(a',b) because a'<b always

    further repeating this same recursively we ultimately get the remainder part to be 0. 

    i.e. in gcd(x,y) where the remainder part y is 0 
    i.e. gcd(x,y) = gcd (x,0) where x will be the gcd of gcd(a,b).

    The largest common divisor of k and zero = k. 
    So gcd(k, 0) = gcd(0,k) = k.
  */
}

int main() {
  print("Enter the two numbers whose GCD is to be found");
  stdout.write("Enter the first number: ");
  int a = int.parse(stdin.readLineSync());
  stdout.write("Enter the second number: ");
  int b = int.parse(stdin.readLineSync());

  /*
    here a>b or b>a does not matter
    because a will be the greater in the algo's 1st recursion. for example:-
    gcd(25,100)
    = gcd(100,25) here 25%100=25
  */
  stdout.write("GCD of $a and $b is: ");
  int result = gcd(a, b);
  stdout.write(result);
  return 0;
}

/*
    Time Complexity: O(log(n))
    Space Complexity: O(1)

    SAMPLE TEST CASES

    Example1

    Enter the two numbers whose GCD is to be found
    Enter the first number: 100
    Enter the second number: 25
    GCD of 100 and 25 is: 25

    Explanation
    gcd(25,100)
    = gcd(100,25) here 25%100 = 25 = a'
    = gcd(25,0) here 100%25 = 0 = a'
    where 25 is the gcd(100,25)


    Example2

    Enter the two numbers whose GCD is to be found
    Enter the first number: 100
    Enter the second number: 70
    GCD of 100 and 70 is: 10

    Explanation
    gcd(100,70)
    =gcd(70,30)
    =gcd(30,10)
    =gcd(10,0)

    here we get the gcd=10.
    Observation:- all the remainders and those numbers a & b have the same GCD. 
    i.e., 100, 70, 30, 10, 0 have gcd=10

*/
