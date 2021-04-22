/*
Word Ladder problem

Given two words, startWord and endWord, and a dictionary wordsList.
Find the shortest transformation sequence startWord -> s1 -> s2 -> ... -> endWord such that
    1. Every adjacent pair of words differ by a single character.
    2. There is no guarantee that both the start and end words exist in the words.

Return the minimum number of words in the shortest transformation sequence from startWord to endWord, or 0 if no such sequence exists.


Input: startWord, endWord, a list of words in dictionary
Output: an integer denoting the length of minimum transformation sequence.

Thoughts:
Let's visualize this as a graph problem. If you can imagine each word in the wordList as a node (vertex) and there exists an edge with each "potential" word. 
Then the problem reduces to finding the shortest path from the startWord to the endWord. 

By "potential" I mean that every possible word that we can obtain from the given word by replacing that character by any of the 26 characters.

As this is an unweighted graph, Breadth First Search (BFS) gives us the shorest path in lesser time.
But, doing Bi-directional BFS can give us our required answer in even lesser time!

Approach:
We use Bi-directional Breadth First Search to solve this problem. Instead of queues, we can also use set here.
We start BFS from the either of the ends and keep adding the next set of possible words to our set at every step.
The moment we find the endWord in the current set, we can break out or return the number of steps recorded till now.

The below code is contributed by Jahnavi Majji as a part of GSSoC'21.
*/

import java.util.*;

public class WordLadder {
    public static void main(String[] args) {
        //driver code
        Scanner scanner = new Scanner(System.in);
        
        //take necessary input: startWord, endWord, dictionary
        System.out.println("Enter the start word: ");
        String startWord = scanner.nextLine();
        
        System.out.println("Enter the end word: ");
        String endWord = scanner.nextLine();
        
        System.out.println("Enter the number of words in the dictionary: ");
        int length = scanner.nextInt();
        
        //an arraylist to store the words in the dictionary
        System.out.println("Enter the words in the dictionary: ");
        List<String> dictionary = new ArrayList();
        for(int i = 0; i <= length; i++) {
            String word = scanner.nextLine();
            dictionary.add(word);
        }
        
        //dictionary = dictionary.subList(1, dictionary.size());
        
        scanner.close();
        
        System.out.println("The minimum length of the transformation sequence is: " + minTransformationSequence(startWord, endWord, dictionary));
    }
    
    private static int minTransformationSequence(String startWord, String endWord, List<String> wordList) {
        //Store words in a set for constant O(1) access / search
        Set<String> dictionary = new HashSet<>(wordList);

        //startSet stores the intermediate values starting from the beginning word
        Set<String> startSet = new HashSet<>();
    
        //endSet stores the intermediate values starting from the ending word
        Set<String> endSet = new HashSet<>();

        //visited stores all the words previously seen
        Set<String> visited = new HashSet<>();
        
        //add the startWord and endWord to their respective sets to start the Bi-directional BFS
        startSet.add(startWord);
        
        //check if the endWord exists in the given dictionary of words
        if(dictionary.contains(endWord))
            endSet.add(endWord);
        else    return 0;
        
        //steps stores the minimum number of steps needed for the transformation. 
        //Initialize the steps.
        int steps = 1;
        
        //start the Bi-directional Breadth First Search
        while(!startSet.isEmpty()) {
            //newSet stores the intermediate strings
            Set<String> newSet = new HashSet<>();
            
            //check for every word in the startSet if it can be transformed
            for(String word : startSet) {
                
                char[] array = word.toCharArray();
                
                for(int i = 0; i < array.length; i++) {
                    for(char ch = 'a'; ch <= 'z'; ch++) {
                        char oldChar = array[i];
                        array[i] = ch;

                        if(oldChar == ch)   continue;

                        String temp = String.valueOf(array);
                
                        //check if we've reached the endWord
                        if (endSet.contains(temp)) return steps + 1;
                        
                        //add the current "potential" string to the newSet
                        if(!visited.contains(temp) && dictionary.contains(temp)) {
                            newSet.add(temp);
                            visited.add(temp);
                        }

                        array[i] = oldChar;
                    }
                }
            }
            
            //startSet becomes the set with less number of "potential" words. 
            //Because it is effective to start search with less size.
            //endSet becomes the set other than the startSet
            
            startSet = (newSet.size() > endSet.size()) ? endSet : newSet;
            endSet = (startSet == newSet) ? endSet : newSet;
            
            //increment the steps
            ++steps;
        }
        
        //if the execution reaches here, then that means there exists no transformation sequence for the given input.
        return 0;
    }
}

/* 
Sample Input: 
Enter the start word: room
Enter the end word: apot
Enter the number of words in the dictionary: 6
Enter the words in the dictionary: 
rpxt
root
apot
room
rpot
apxt
    
Output: 
The minimum length of the transformation sequence is: 4

Explanation:
room -> root -> rpot -> apot
    
Time Complexity: O(N * K * 26) where N = length of the dictionary and K = size of the startSet
Space Complexity: O(N)

*/
