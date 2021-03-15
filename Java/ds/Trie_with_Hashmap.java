/*  Trie is also called as 'Prefix Tree'. It is a tree data structure which is commonly used to store the strings/words. 
    The popoular applications of this data stucture are autocomplete and spellcheck.

    Problem Statement: 
    Designing a data structure which supports addition of new words and finds if a string matches any previously added string.
        
    Solution:
    1. Define a TrieNode class using a HashMap.
    2. Initialization of root node in Trie Class.
    3. void insert(String word) takes word from user and adds into the Trie.
    4. boolean search(String word) checks if the word entered by user matches to the previously added strings.
*/

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

//Class to define Trie node operations
class Trie{
    private TrieNode root;
    public Trie(){
        root = new TrieNode(false);
    }
    //Insertion of word into Trie
    public void insert(String word){
        TrieNode currentnode = root;
        for(char c :word.toCharArray()){
            if(currentnode!=null && !currentnode.nodes.containsKey(c)){
                TrieNode node = new TrieNode(false);
                currentnode.nodes.put(c, node);
            }
            currentnode.nodes.get(c);
        }
        currentnode.isEnd = true;
    }

    //Searching word in a Trie
    public boolean search(String word){
        TrieNode currentnode = root;
        for(char c : word.toCharArray()){
            if(currentnode!=null && currentnode.nodes.containsKey(c)){
                currentnode.nodes.get(c);
            } else{
                return false;
            }
        }
        return currentnode.isEnd;
    }

    //Creation of node using Hashmap (stores elements in key/value pairs).
    class TrieNode{
        Map<Character,TrieNode> nodes = new HashMap<>();
        boolean isEnd = false;
        TrieNode(boolean isEnd){
            this.isEnd = isEnd;
        }
    }
}

class Trie_with_Hashmap{
    public static void main(String[] args) {

        Trie head = new Trie();
        Scanner scan = new Scanner(System.in);       
        char ch;
        System.out.println("\nInsert and Search Operations on Trie");
        System.out.println("--------------------------------------");
        do  {  
            System.out.println("1. insert ");
            System.out.println("2. search");
            int choice = scan.nextInt();            
            switch (choice){
            case 1: 
                System.out.print("Enter string to insert : ");
                head.insert( scan.next() );                     
                break;                          
            case 2: 
                //Search function returns 'true' if string is present in Trie
                System.out.print("Enter string to search : ");
                System.out.println("Search result : "+ head.search( scan.next() ));
                break;                                          
            default: 
                System.out.println("Invalid choice \n ");
                break;   
            }
            System.out.print("\nDo you want to continue (Type y or n) : ");
            ch = scan.next().charAt(0);                                    
        }while (ch == 'Y'|| ch == 'y');               
    }  
}
/*  
*       Insert and Search Operations on Trie
*       --------------------------------------
*       1. insert
*       2. search
*       1
*       Enter string to insert : init
*       
*       Do you want to continue (Type y or n) : y
*       1. insert 
*       2. search
*       1
*       Enter string to insert : initial
*
*       Do you want to continue (Type y or n) : y
*       1. insert 
*       2. search
*       1
*       Enter string to insert : initially
*
*       Do you want to continue (Type y or n) : y
*       1. insert
*       2. search
*       2
*       Enter string to search : initial
*       Search result : true
*
*       Do you want to continue (Type y or n) : y
*       1. insert
*       2. search
*       2
*       Enter string to search : initiate
*       Search result : false
*
*       Do you want to continue (Type y or n) : n
*       -------------------------------------------
*       Time complexity:  O(M)      ...M is maximum length of string
*       Space Complexity: O(N*M*C)  ...N is number of strings and C is char size 
*/
