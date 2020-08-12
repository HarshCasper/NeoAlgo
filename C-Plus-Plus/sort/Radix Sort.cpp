#include <iostream>
#include <cmath>

using namespace std;
 
template <class T>
void Print(T& vec, int n, string s){
    cout << s << ": [" << flush;
    for (int i=0; i<n; i++){
        cout << vec[i] << flush;
        if (i < n-1){
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}
 
int Max(int A[], int n){
    int max = -32768;
    for (int i=0; i<n; i++){
        if (A[i] > max){
            max = A[i];
        }
    }
    return max;
}
 
// Linked List node
class Node{
public:
    int value;
    Node* next;
};
 
int countDigits(int x){
    int count = 0;
    while (x != 0){
        x = x / 10;
        count++;
    }
    return count;
}
 
void initializeBins(Node** p, int n){
    for (int i=0; i<n; i++){
        p[i] = nullptr;
    }
}
 
void Insert(Node** ptrBins, int value, int idx){
    Node* temp = new Node;
    temp->value = value;
    temp->next = nullptr;
 
    if (ptrBins[idx] == nullptr){
        ptrBins[idx] = temp;  // ptrBins[idx] is head ptr
    } else {
        Node* p = ptrBins[idx];
        while (p->next != nullptr){
            p = p->next;
        }
        p->next = temp;
    }
}
 
int Delete(Node** ptrBins, int idx){
    Node* p = ptrBins[idx];  // ptrBins[idx] is head ptr
    ptrBins[idx] = ptrBins[idx]->next;
    int x = p->value;
    delete p;
    return x;
}
 
int getBinIndex(int x, int idx){
    return (int)(x / pow(10, idx)) % 10;
}
 
void RadixSort(int A[], int n){
    int max = Max(A, n);
    int nPass = countDigits(max);
 
    // Create bins array
    Node** bins = new Node* [10];
 
    // Initialize bins array with nullptr
    initializeBins(bins, 10);
 
    // Update bins and A for nPass times
    for (int pass=0; pass<nPass; pass++){
 
        // Update bins based on A values
        for (int i=0; i<n; i++){
            int binIdx = getBinIndex(A[i], pass);
            Insert(bins, A[i], binIdx);
        }
 
        // Update A with sorted elements from bin
        int i = 0;
        int j = 0;
        while (i < 10){
            while (bins[i] != nullptr){
                A[j++] = Delete(bins, i);
            }
            i++;
        }
        // Initialize bins with nullptr again
        initializeBins(bins, 10);
    }
 
    // Delete heap memory
    delete [] bins;
}
 
int main() {
 
    int A[] = {237, 146, 259, 348, 152, 163, 235, 48, 36, 62};
    int n = sizeof(A)/sizeof(A[0]);
 
    Print(A, n, "\t\tA");
    RadixSort(A, n);
    Print(A, n, " Sorted A");
 
    return 0;
}
