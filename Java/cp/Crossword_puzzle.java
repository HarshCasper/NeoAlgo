/* You are given a 10*10 2-D array(arr) containing only '+' and '-' characters, which represents a crossword puzzle. 
You are also given n number of words which need to be filled into the crossword. 
Cells containing '-' are to be filled with the given words. */

import java.util.*;

public class Crossword_puzzle {
    public static void main(String[] args) throws Exception {
        // User input
        Scanner scn = new Scanner(System.in);
        char[][] arr = new char[10][10];

        System.out.println("\nEnter the crossword puzzle: ");

        // filling the crossword board array
        for (int i = 0; i < arr.length; i++) {
            String str = scn.next();
            arr[i] = str.toCharArray();
        }

        // total number of words
        System.out.println("\nEnter the total words: ");
        int n = scn.nextInt();

        // storing words in array from input stream
        System.out.println("\nEnter the words: ");
        String[] words = new String[n];
        for (int i = 0; i < words.length; i++) {
            words[i] = scn.next();
        }

        System.out.println();

        // invoking function to solve the crossword puzzle.
        solvePuzzle(arr, words, 0);

        // closing input stream
        scn.close();
    }

    // Global count to keep track of number of configurations
    static int count = 0;

    // function to display the solution on the console
    public static void display(char[][] arr) {
        // configuration number
        System.out.print(count + ".");

        for (int i = 0; i < arr.length; i++) {
            if(i>0) {
                System.out.print(" " + "\t");
            }
            else {
                System.out.print("\t");
            }

            for (int j = 0; j < arr[0].length; j++) {
                System.out.print(arr[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println();
    }

    public static void solvePuzzle(char[][] arr, String[] words, int idx) {

        // Base case: All words are placed on the board
        if (idx == words.length) {
            count++;
            display(arr);
            return;
        }

        // Current word
        String word = words[idx];

        // Checking all possibilities for the current word
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[0].length; j++) {

                // word can be placed if the starting point is '-' or first letter of current
                // word
                if (arr[i][j] == '-' || arr[i][j] == word.charAt(0)) {

                    // checking if we can place the word horizontally
                    if (canPlaceWordHorizontally(arr, word, i, j)) {

                        // placing word horizontally
                        boolean[] wePlaced = placeWordHorizontally(arr, word, i, j);

                        // recursively calling for the next word
                        solvePuzzle(arr, words, idx + 1);

                        // undo the changes made while backtracking
                        removeWordHorizontally(arr, wePlaced, i, j);
                    }

                    // checking if we can place the word vertically
                    if (canPlaceWordVertically(arr, word, i, j)) {

                        // placing word vertically
                        boolean[] wePlaced = placeWordVertically(arr, word, i, j);

                        // recursively calling for the next word
                        solvePuzzle(arr, words, idx + 1);

                        // undo the changes made while backtracking
                        removeWordVertically(arr, wePlaced, i, j);
                    }
                }
            }
        }
    }

    // This function checks all possible conditions for which the word can't be
    // placed horizontally
    public static boolean canPlaceWordHorizontally(char[][] arr, String word, int i, int j) {
        if (j - 1 >= 0 && arr[i][j - 1] != '+')
            return false;
        else if (j + word.length() < arr[0].length && arr[i][j + word.length()] != '+')
            return false;

        for (int jj = 0; jj < word.length(); jj++) {
            if (j + jj >= arr[0].length)
                return false;

            if (arr[i][j + jj] == '-' || arr[i][j + jj] == word.charAt(jj))
                continue;
            else
                return false;
        }

        return true;
    }

    // This function checks all possible conditions for which the word can't be
    // placed vertically
    public static boolean canPlaceWordVertically(char[][] arr, String word, int i, int j) {

        if (i - 1 >= 0 && arr[i - 1][j] != '+')
            return false;
        else if (i + word.length() < arr.length && arr[i + word.length()][j] != '+')
            return false;

        for (int ii = 0; ii < word.length(); ii++) {
            if (i + ii >= arr.length)
                return false;
            if (arr[i + ii][j] == '-' || arr[i + ii][j] == word.charAt(ii))
                continue;
            else
                return false;
        }

        return true;
    }

    // Places the word horizontally and returns a boolean array with only those
    // indices marked true where changes were made by current word
    public static boolean[] placeWordHorizontally(char[][] arr, String word, int i, int j) {
        boolean[] wePlaced = new boolean[word.length()];
        for (int jj = 0; jj < word.length(); jj++) {
            if (arr[i][j + jj] == '-') {
                arr[i][j + jj] = word.charAt(jj);
                wePlaced[jj] = true;
            }
        }
        return wePlaced;
    }

    // Places the word vertically and returns a boolean array with only those
    // indices marked true where changes were made by current word
    public static boolean[] placeWordVertically(char[][] arr, String word, int i, int j) {
        boolean[] wePlaced = new boolean[word.length()];
        for (int ii = 0; ii < word.length(); ii++) {
            if (arr[i + ii][j] == '-') {
                arr[i + ii][j] = word.charAt(ii);
                wePlaced[ii] = true;
            }
        }
        return wePlaced;
    }

    // Removing the current word from row
    public static void removeWordHorizontally(char[][] arr, boolean[] wePlaced, int i, int j) {
        for (int jj = 0; jj < wePlaced.length; jj++) {
            if (wePlaced[jj] == true) {
                arr[i][j + jj] = '-';
            }
        }
    }

    // Removing the current word from column
    public static void removeWordVertically(char[][] arr, boolean[] wePlaced, int i, int j) {
        for (int ii = 0; ii < wePlaced.length; ii++) {
            if (wePlaced[ii] == true) {
                arr[i + ii][j] = '-';
            }
        }
    }
}

/*

The approach behind this is to recursively check for each word in the vertical position and in the horizontal position. 
Then fill the word in the matrix that can be the best fit in the corresponding position of the grid, 
then update the crossword grid by filling the gap with that word.

Sample Input/Output

Example 1: 

Enter the crossword puzzle:
+-++++++++
+-++++++++
+-++++++++
+-----++++
+-+++-++++
+-+++-++++
+++++-++++
++------++
+++++-++++
+++++-++++

Enter the total words:
4

Enter the words:
LONDON
DELHI
ICELAND
ANKARA

1.  + L + + + + + + + +
    + O + + + + + + + +
    + N + + + + + + + +
    + D E L H I + + + +
    + O + + + C + + + +
    + N + + + E + + + +
    + + + + + L + + + +
    + + A N K A R A + +
    + + + + + N + + + +
    + + + + + D + + + +

*/