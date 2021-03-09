/*
In this problem, we have to find the length of the longest increasing subsequence in the input array. Longest Increasing Subsequnce is the length of the longest subsequence that is strictly increasing. 
Dynamic Programming is used to solve the problem where at each step we find the LIS for each element in the array and update it when we find a greater length increasing subsequence. 

Time Complexity of this approach - O(N^2)
Space Complexity of this approach - O(N)
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
      //checking if i list[i] has a smaller element to its left so that list[i] can be added to the LIS sequence and whether adding the number creates a sequence larger than current sequence.
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

  //returning length of the longest increasing subsequence
  return sizeOfLIS;
};

//Using the readline() function of JavaScript to take input from the user
console.log("Enter the elements of the array for which length of Longest Increasing Subsequence has to be found");

//list contains the array taken as input from the user
let list = readline().split(" ").map(x => parseInt(x));

//n is the length of the input array
let n = list.length;

//computing the length of the longest increasing subsequence by calling FindLIS and storing the answer in a variable
let lengthOfLongestIncreasingSubsequence = FindLIS(list, n);

//printing the computed answer
 console.log(
  `The length of the longest increaing subsequnce is ${lengthOfLongestIncreasingSubsequence}`
);


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