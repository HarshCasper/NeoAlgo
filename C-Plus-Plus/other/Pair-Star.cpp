/*
"Copyright [2021] <Anshika Dubey>"
Given a string S, compute recursively a new string where identical chars that are adjacent in the original string are separated from each other by a "*".
*/

#include <bits/stdc++.h>
void pairStar(char input[]) {
    int size = 0, i;
    while (input[size] != '\0')
        size++;
    if (input[0] == '\0' || size == 0)
        return;
    if (input[0] == input[1]) {
        input[size+1] = '\0';
        for (int i = size-1; i >= 1; i--) {
            input[i+1] = input[i];
        }
        input[1] = '*';
        pairStar(input+1);
    } else {
        pairStar(input+1);
    }
}
int main() {
   char input[100];
   std::cin.getline(input, 100);
   pairStar(input);
   std::cout << input <<std:: endl;
}


/*
sample input:
hello
sample output:
hel*lo

Time complexity: O(n)
*/
