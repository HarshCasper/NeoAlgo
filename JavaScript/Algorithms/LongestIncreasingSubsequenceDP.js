/*
1. We have to find the length of the longest increasing subsequence in the input array. 
2. Longest Increasing Subsequnce is length of the longest strictly increasing subsequence.
3. The problem can be solved using Dynamic Programming. 
4. The approch is to find the LIS for each element and return the largest of them. 
*/

//Function that finds the length of the longest increasing subsequence
let FindLIS = (list, len) => {
  //creating a new array of size len to store the LIS value
  let lis = new Array(len);

  //lis[i] stores the length of the longest increasing subsequence upto list[i]
  //Initializing lis[0] to be 1 as LIS for 1 element is 1
  lis[0] = 1;

  for (let i = 1; i < len; ++i) {
    lis[i] = 1;
    for (let j = 0; j < i; ++j) {
      //checking if i list[i] has a smaller element to its left so that list[i] can be updated
      if (list[j] < list[i] && lis[i] < lis[j] + 1) {
        lis[i] = lis[j] + 1;
      }
    }
  }

  //variable that stores the length of the longest increasing subsequence of the array
  let sizeOfLIS = 0;

  //finding the largest value in the lis array
  for (let i = 0; i < len; ++i) {
    sizeOfLIS = Math.max(sizeOfLIS, lis[i]);
  }

  //returning the LIS value
  return sizeOfLIS;
};

//Using the readline() function of JavaScript to take input from the user
console.log(
  "Enter the elements of the array for which length of Longest Increasing Subsequence has to be found"
);

//list is input array
let list = readline()
  .split(" ")
  .map((x) => parseInt(x));

//n is length of the input array
let n = list.length;

//storing LIS
let lengthOfLongestIncreasingSubsequence = FindLIS(list, n);

//printing the answer
console.log(
  `The length of the longest increaing subsequnce is ${lengthOfLongestIncreasingSubsequence}`
);

/*
Time complexity of the program - O(N^2)
Space Complexity of the program - O(N)
*/

/*
Sample Input Output : 

Input 1 : 
list = [10, 22, 9, 33, 21, 50, 41, 60, 74, 108]

Output 1 : 
The length of the longest increaing subsequnce is 7

Explanation : 
The longest increasing subsequnce is [10, 22, 33, 41, 60, 74, 108], hence the length of LIS is 7


Input 2 : 
list = [10,9,2,5,3,7,101,18]

Output 2 : 
The length of the longest increaing subsequnce is 4

Explanation : 
The longest increasing subsequnce is [2, 3, 7, 101], hence the length of LIS is 4


Input 3 : 
list = [7,7,7,7]

Output 3 : 
The length of the longest increaing subsequnce is 1

Explanation : 
The longest increasing subsequnce is [7], hence the length of LIS is 1
*/
