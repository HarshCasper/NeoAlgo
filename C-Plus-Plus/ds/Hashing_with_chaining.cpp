/**
 * @author omkarlanghe : https://github.com/omkarlanghe
 * A program to demostrate basic working of a data structure called Hashing.
 * This program supports seperate chaining method to avoid collision between hash indexes.
*/
#include <iostream>
#include <list>

class HashTable {
 private:
    int BUCKET;
    std::list<int> *table = nullptr;

 public:
        HashTable(int v);
        void insert_item(int x);
        void delete_item(int key);
        int hash_function(int data) { return (data % BUCKET); }
        void display_hash_table();
};

/** constructor function which initialized hash table */
HashTable::HashTable(int b) {
    this->BUCKET = b;
    table = new std::list<int>[BUCKET];
}

/** function to insert item in a hash table */
void HashTable::insert_item(int key) {
    int index = hash_function(key);
    table[index].push_back(key);
}

/** function to delete item from a hash table */
void HashTable::delete_item(int key) {
    int index = hash_function(key);
    std::list<int>::iterator it;
    for (it = table[index].begin() ; it != table[index].end() ; it++) {
        if (*it == key) {
            break;
        }
    }

    if (it != table[index].end()) {
        table[index].erase(it);
    }
}

/** function to display all the elements from hash table */
void HashTable::display_hash_table() {
    for (int i = 0 ; i < BUCKET; i++) {
        std::cout << i;
        for (auto x : table[i]) {
            std::cout << " :: " << x;
        }
        std::cout << std::endl;
    }
}

/** main function */
int main() {
    int size, x;
    std::cout << "Enter the size : " << std::endl;
    std::cin >> size;

    HashTable hash(size);

    std::cout << "Enter the elements in hash table : " << std::endl;
    for  (int i = 0 ; i < size ; i++) {
        std::cin >> x;
        hash.insert_item(x);
    }

    std::cout << "Display before deletion : " << std::endl;
    hash.display_hash_table();

    std::cout << "Enter the element to remove : " << std::endl;
    std::cin >> x;
    hash.delete_item(x);

    std::cout << "Display after deletion : " << std::endl;
    hash.display_hash_table();

    return (0);
}
