/*
Trie is an efficient datastructure for searching a word in least time.
Tries brings down the optimal search complexity to length of the key, but the space complexity
is a lot more than that required for other datastructures. Tries uses the concept of hashing to store characters of 
the word as keys and stores the pointer to next node as a value in hashmap.
*/
import java.util.*;
public class Trie {
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
/*
 Sample Input Output: 
 Please enter the size of the input Array N: 5 
 Please enter the words in next N lines
 samara 
 simha 
 reddy 
 attunuru 
 narasimha 
 Please enter number of words you want to search in trie M: 5
 Enter the word to search in trie: 
 samara 
 Found 
 Enter the word to search in trie: 
 samar 
 Not Found 
 Enter the word to search in trie: 
 simhas 
 Not Found 
 Enter the word to search in trie: 
 simha 
 Found 
 Enter the word to search in trie: 
 nara 
 Not Found
 Time complexity: O(M) for searching a word of length M. Space complexity:
 O(C*key_length*N) where N is number of keys and C is the size of the domain.
 eg: for alphabets C=26.
 */