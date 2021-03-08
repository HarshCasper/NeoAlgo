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

//Declaring the array for which we have to find the length of the longest increasing subsequence
let list = [10, 22, 9, 33, 21, 50, 41, 60, 74, 108];

//Finding the length of the list
let n = list.length;

//computing the length of the longest increasing subsequence by calling FindLIS and storing the answer in a variable
let lengthOfLongestIncreasingSubsequence = FindLIS(list, n);

//printing the computed answer
console.log(
  `The length of the longest increaing subsequnce is ${lengthOfLongestIncreasingSubsequence}`
);
