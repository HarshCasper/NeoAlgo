class Trienode:
    """
    Each node in the Trie will contain the following structure
    """

    def __init__(self, char):
        self.char = char
        self.wordend = 0
        self.children = [None for i in range(26)]


class Trie:
    """
    The Trie data structure
    """

    def __init__(self):
        """
        The root will contain a '/' character.
        We may also keep it an empty string, it won't matter.
        """
        self.root = Trienode('/')

    def insert(self, word):
        """
        To insert word in Trie
        """
        ptr = self.root

        for c in word:
            # This is done for relative indexing of the children array
            idx = ord(c) - ord('a')

            if ptr.children[idx] is not None:
                ptr = ptr.children[idx]

            else:
                ptr.children[idx] = Trienode(c)
                ptr = ptr.children[idx]

        ptr.wordend = 1

    def _search(self, word):
        """
        Searches if a word is present in the Trie.
        Basically a private function that can be used
        to query or delete results
        """
        ptr = self.root
        self.exists = True

        for c in word:
            idx = ord(c) - ord('a')

            if ptr.children[idx] is not None:
                ptr = ptr.children[idx]

            # Note: In the following lines of code, specific numbers and
            # a pointer is returned just for the convinience to map
            # the types of results returned from the Trie. We may use other
            # numbers or approach as well.

            else:
                # not exists as ptr has no child in that idx, i.e, it's value
                # is None
                self.exists = False
                return (-1, None)

        if self.exists:

            if ptr.wordend == 1:
                # exists
                return (0, ptr)
            else:
                # not exist as wordend= 0
                return (1, None)

    def query(self, word):
        """
        To query if a word is present in Trie
        """
        val, _ = self._search(word)

        if val == -1 or val == 1:
            print(word, "does not exist in the Trie")
        elif val == 0:
            print(word, "exists in the Trie")

    def delete(self, word):
        """
        To delete a word from Trie
        """
        val, ptr = self._search(word)

        if val == -1:
            print(word, 'does not exists in Trie')

        elif val == 1:
            print(word, 'does not exists in Trie')

        elif val == 0:
            ptr.wordend = 0
            print(word, 'Deleted')


def menu(trie):

    while True:
        print('Enter I/i: insert, Q/q: query, D/d: delete, E/e: exit')
        ip = input()

        if ip == 'I' or ip == 'i':
            print('Enter a word: ')
            word = input()
            trie.insert(word)

        elif ip == 'Q' or ip == 'q':
            print('Enter a word: ')
            word = input()
            trie.query(word)

        elif ip == 'D' or ip == 'd':
            print('Enter a word: ')
            word = input()
            trie.delete(word)

        elif ip == 'E' or ip == 'e':
            break


def main():
    # Through real time user input
    print("Input strings to be inserted in the Trie (only lowercase words)")
    init_ip = input().split()

    trie = Trie()

    for word in init_ip:
        trie.insert(word)

    menu(trie)

if __name__ == '__main__':
    main()


"""
Sample input-output :

$ python3 Trie.py
Input strings to be inserted in the Trie (only lowercase words)
abc ab bab cd efd
Enter I/i: insert, Q/q: query, D/d: delete, E/e: exit
q
Enter a word:
abc
abc exists in the Trie
Enter I/i: insert, Q/q: query, D/d: delete, E/e: exit
q
Enter a word:
abe
abe does not exist in the Trie
Enter I/i: insert, Q/q: query, D/d: delete, E/e: exit
d
Enter a word:
cd
cd Deleted
Enter I/i: insert, Q/q: query, D/d: delete, E/e: exit
q
Enter a word:
cd
cd does not exist in the Trie
Enter I/i: insert, Q/q: query, D/d: delete, E/e: exit
i
Enter a word:
abef
Enter I/i: insert, Q/q: query, D/d: delete, E/e: exit
q
Enter a word:
abef
abef exists in the Trie
"""

