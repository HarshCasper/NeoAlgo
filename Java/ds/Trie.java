/*
Author: A.M.Samara simha reddy
language: java
DS: Trie
*/

import java.util.*;
import java.lang.*;

public class Trie {
    // TrieNode class to represent the node present in the Trie.
    // TrieNode consists of HashMap and a boolean datatypes.
    class TrieNode {
        HashMap<Character, TrieNode> map;
        boolean endofword;

        TrieNode() {
            this.map = new HashMap<Character, TrieNode>();
            this.endofword = false;
        }
    }

    static TrieNode root;

    Trie() {
        root = new TrieNode();
    }
    /*
     * to add an element into the trie, we will if the character of the string
     * already present in hashmap. If character already present we will move to the
     * next TrieNode linked with the character key, else we will create a new
     * TrieNode and add it into the hashmap by keeping character as the key and
     * TrieNode as the value.
     */

    void addelement(String element) {
        TrieNode temp = root;
        int i, n = element.length();
        Character s;
        for (i = 0; i < n; i++) {
            s = element.charAt(i);
            if (temp.map.containsKey(s)) {

                temp = temp.map.get(s);
            } else {
                temp.map.put(s, new TrieNode());

                temp = temp.map.get(s);

            }

        }
        temp.endofword = true;
    }

    /*
     * searching is done same as adding the element into Trie. If the character is
     * not present we simply return false, else if all the characters are present we
     * will check whether the last character is end of the word in trie or not. If
     * yes then we will print Found else Not Found.
     */
    boolean search(String element) {
        TrieNode temp = root;
        int i, n = element.length();
        Character s;
        for (i = 0; i < n; i++) {
            s = element.charAt(i);
            if (temp.map.containsKey(s)) {
                temp = temp.map.get(s);
            } else {
                return false;
            }
        }
        return temp.endofword;
    }

    /*
     * Main function contains code to initialise the Trie datastructure and
     * inserting elements into Trie.
     */
    public static void main(String[] args) {
        Trie t = new Trie();
        Scanner sc = new Scanner(System.in);
        System.out.println("Please enter the size of the input Array N:");
        int n = sc.nextInt();
        System.out.println("Please enter the words in next N lines");
        int i;
        String[] inputs = new String[n];
        for (i = 0; i < n; i++) {
            String word = sc.next();
            t.addelement(word);
            inputs[i] = word;
        }

        System.out.println("Please enter number of words you want to search in trie M:");
        int m = sc.nextInt();
        for (i = 0; i < m; i++) {
            System.out.println("Enter the word to search in trie:");
            String wrd = sc.next();
            if (t.search(wrd) == true) {
                System.out.println("Found");
            } else {
                System.out.println("Not Found");
            }

        }

    }
}