"""
   A trie, also called digital tree or prefix tree,
   is a kind of search tree—an ordered tree data structure
   used to store a dynamic set or associative array where
   the keys are usually strings. Unlike a binary search tree,
   no node in the tree stores the key associated with
   that node; instead, its position in the tree
   defines the key with which it is associated;
   i.e., the value of the key is distributed across
   the structure.
"""

"""
    Trie is an efficient information reTrieval data structure. 
    Using Trie, search complexities can be brought to optimal 
    limit (key length). If we store keys in binary search tree, 
    a well balanced BST will need time proportional to M * log N, 
    where M is maximum string length and N is number of keys in tree. 
    Using Trie, we can search the key in O(M) time. 
   
"""

from collections import defaultdict

class TrieNode():        #initialising the trie node with children and terminating as attributes
    def __init__(self):
        self.children = defaultdict()
        self.terminating= False

class Trie():           #initialising the trie with tree attribute and  multiples member functions
    def __init__(self):
        self.root = self.get_node()

    def get_node(self):             #member function to get the trie node
        return TrieNode()

    def get_index(self,ch):         #member function for getting index of the given node
        return ord(ch)-ord('a')

    def insert(self,word):          #membr function for inserting a trie node in the trie
        root = self.root
        len1 = len(word)

        for i in range(len1):
            index = self.get_index(word[i])

            if index not in root.children:
                root.children[index] = self.get_node()
            root  = root.children.get(index)
        root.terminating = True

    def search(self,word):         #Member function for searching a trie node in trie
        root = self.root
        len1 = len(word)

        for i in range(len1):
            index = self.get_index(word[i])
            if not root:
                return False
            root = root.children.get(index)

        return True if root and root.terminating else False

    def delete(self,word):       #Member function to delete a trie node from Trie
        root = self.root
        len1 = len(word)

        for i in range(len1):
            index = self.get_index(word[i])

            if not root:
                print("Word not found")
                return -1
            root = root.children.get(index)

        if not root:
            print("Word not found")
            return -1
        else:
            root.terminating = False
            return 0



    def update(self,old_word,new_word):   #Member function for modification of Trie node
            val = self.delete(old_word)
            if val==0:
                self.insert(new_word)

if __name__ == '__main__':
    strings = ["pqrs", "pprt", "psst", "qqrs", "pqrs"]

    t = Trie()
    for word in strings:
        t.insert(word)

    print(t.search("pqrs"))      #Returns True because pqrs is present in Trie
    print(t.search("pprt"))      #Returns True because pprt because aghy is present in Trie

    t.delete("pprt")             #Deleting the trie node

    print(t.search("pprt"))      #Searching or the deleted node,Returns False because node is not present in trie

    t.update("psst","pprt")      #Changing node ardf to asdy

    print(t.search("psst"))
    print(t.search("pprt"))     #Searching for the old node


"""
OUTPUT:-

True                                                          
True                                                          
False                                                         
False                                                         
True 

"""
