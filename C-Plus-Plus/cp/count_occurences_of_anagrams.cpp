/**
 * Count Occurences of Anagrams
 * Cpp Program to find the count of anagrams
 * of an entered word, in an entered text (given that 
 * length of word <= length of text).
 */

#include<bits/stdc++.h>

using namespace std;

//function to count no. of occurences of anagram
int countAnagrams(string text, string word) {
  //To keep count of anagrams
  int anagramCount = 0;
  int lenOfText = text.length();
  int lenOfWord = word.length();
  //Map to store frequency of each character in word
  map < char, int > wordCharCount;
  for (int i = 0; i < lenOfWord; i++)
    wordCharCount[word[i]]++;
  //To count number of distict character
  int count = wordCharCount.size();
  //To denote 2 pointers one pointing to start of window and other to the end
  int start = 0, end = 0;
  //To obtain value of difference for each subsequent window of size lenOfWord
  while (end < lenOfText) {

    wordCharCount[text[end]]--;
    //if occurence of any character reduces to zero then decrease count of distinct character
    if (wordCharCount[text[end]] == 0)
      count--;
    //Window size less than lenOfWord then increase the window size
    if (end - start + 1 < lenOfWord)
      end++;
    //on reaching the window size ,if number of distinct characters equals zero then increment count of anagram
    else if (end - start + 1 == lenOfWord) {
      if (count == 0)
        anagramCount++;
      //compute if character is present in map
      //add last character of current window
      if (wordCharCount.find(text[start]) != wordCharCount.end())
        wordCharCount[text[start]]++;
      //check if only one occurence of a character is present then
      //increment the count for distict characters
      if (wordCharCount[text[start]] == 1)
        count++;
      //slide the window
      start++;
      end++;
    }
  }
  return anagramCount;
}

int main() {
  //take input from user
  string text, word;
  cout << "Enter the text string: ";
  cin >> text;
  cout << "Enter the word whose anagrams need to be counted: ";
  cin >> word;
  cout << "Number of Anagrams: " << countAnagrams(text, word);
}

/*
	Test Cases:

	Input 1:
	Enter the text string: xforfxorffxdofrf
    Enter the word whose anagrams need to be counted: ffor
	Output 1:
	Number of Anagrams: 3

	Input 2:
	Enter the text string:  aabaabaa
    Enter the word whose anagrams need to be counted: aaba
	Output 2:
	Number of Anagrams: 3

	Time complexity: O(N)
	Space complexity: O(1)

*/
