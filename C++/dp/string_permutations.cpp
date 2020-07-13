/**
 * @author omkarlanghe
 * Given a string S. The task is to print all permutations of a given string.
 * Input:
 * The first line of input contains an integer T, denoting the number of test cases.
 * Each test case contains a single string S in capital letter.
 * 
 * Output:
 * For each test case, print all permutations of a given string S with single space
 * and all permutations should be in lexicographically increasing order.
 * 
 * Example:
 * Input:
 * 2
 * ABC
 * ABSG
 * 
 * Output:
 * ABC ACB BAC BCA CAB CBA 
 * ABGS ABSG AGBS AGSB ASBG ASGB BAGS BASG BGAS BGSA BSAG BSGA GABS GASB GBAS GBSA GSAB GSBA SABG SAGB SBAG SBGA SGAB SGBA
*/
#include <iostream>
#include <cstring>

/** @brief function to swap two characters */
void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

/** @brief function to find all permutations of a given string */
void string_permutations(char str[], int l, int r) {
    int i;
    if (l == r) {
        std::cout << str << " ";
    } else {
        for (int i = l ; i <= r ; i++) {
            swap((str + l), (str + i));
            string_permutations(str, l + 1, r);
            swap((str + l), (str + i));
        }
    }
}

/** Main function */
int main() {
    int t, n;
    std::cout << "Enter test cases : " << std::endl;
    std::cin >> t;

    while (t--) {
        char str[5];
        std::cout << "Enter the string : " << std::endl;
        std::cin >> str;
        int n = strlen(str);
        string_permutations(str, 0, n-1);
        std::cout << std::endl;
    }
    return (0);
}
