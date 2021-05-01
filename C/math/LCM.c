#include <stdio.h>

long long int lcm_num=1;

long long int lcm(int a, int b)
{  
    if (lcm_num % a == 0 && lcm_num % b == 0)
        return lcm_num;
    lcm_num++;

    lcm(a, b);
    return lcm_num;
}

int main()
{
    int a,b;
    scanf("%d %d", &a, &b);

    printf("LCM of %d and %d is %lld", a,b,lcm(a,b));
    return 0;
}

/*
Sidharth Sethi
TechSpiritSS
Time Complexity - O(N)
Space Complexity - O(1)
Example - 1
45 65
LCM of 45 and 65 is 585
45 78
Example - 2
LCM of 45 and 78 is 1170
*/