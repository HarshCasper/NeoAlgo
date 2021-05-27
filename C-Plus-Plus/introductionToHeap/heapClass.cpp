
/*
    This is max heap. Each node is greater than its left and right child.
               10
               /\
             6   8
            /\   /\
           1  3  5 7
     It is stored in the array in the following manner      
    key -> 10 6 8 1 3 5 7
position->  0 1 2 3 4 5 6
*/

/* This class is predominantly constructed for Max Heap. Same structure can be used for Min heap */
class Heap
{
public:
    int *arr;
    int count;
    int capacity;

    Heap() //constructor to initialise Heap class
    {
        this->capacity = 10;
        this->arr = new int[this->capacity];
    }
};

Heap *createHeap(int cap, int h_type) //To create heap with given parameters
{
    Heap *h = new Heap();
    h->capacity = cap;
    h->arr = new int[h->capacity];

    return h;
}

void resizeHeap(Heap *h) //To resize the already constructed heap object
{
    int *array_old = h->arr; //new pointer pointing to the old array

    h->arr = new int[h->capacity * 2]; //constructing a new array in the heap with twice the old size

    for (int i = 0; i < h->capacity; i++)
    {
        h->arr[i] = array_old[i]; //copying the old array into new array
    }
    h->capacity *= 2;   //Updating the capacity of the object
    delete (array_old); //erasing the old array
}

int leftChild(Heap *x, int i) //To find the left child of a node
{
    int left = 2 * i + 1;
    if (left >= x->count) //if left exceeds the count of nodes return -1
        return -1;
    return left;
}

int rightChild(Heap *x, int i) //To find the right child of a node
{
    int right = 2 * i + 2;
    if (right >= x->count)
           //if right exceeds the count of nodes return -1
            return -1;
    return right;
}

int parentPtr(Heap *h, int i) //returns the position of the parent node of a given node
{
    if (i <= 0 || i >= h->count)
        return -1;
    return (i - 1) / 2;
}

int maxElement(Heap *h, int i) //returns the max element in the heap, which is always at the front of the array
{
    if (h->count == 0)
        return -1;
    return h->arr[0];
}

//This function corrects the binary heap in case when an element doesnt satisfy the heap property.
/*          For e.g.

               10
               /\
             6   7
            /\   /\
           1  3  5 8
    Here, 7 doesn't satisfy the heap property. So it has to be shifted to satisfy the heap conditions.
*/

void percolateDown(Heap *x, int i)
{
    int max, l, r, temp;

    l = leftChild(x, i);
    r = rightChild(x, i);

    if (l == -1 && r == -1)
        return;

    if (l != -1 && x->arr[i] < x->arr[l]) /* Finding the position of maximum elements */
        max = l;
    else
        max = i;

    if (r != -1 && x->arr[max] < x->arr[r])
        max = r;

    if (max != i) /*Swapping the position of the maximum element to that which doesnt satisy heap conditions*/
    {
        temp = x->arr[i];
        x->arr[i] = x->arr[max];
        x->arr[max] = temp;
    }
    if (max == i)
        return;
    percolateDown(x, max);
}

//This function inserts an element into heap
void insertHeap(Heap *h, int data)
{
    if (h->count == h->capacity)
        resizeHeap(h);
    h->count += 1;

    int i;
    i = h->count - 1;
    while (i >= 0 && data > h->arr[(i - 1) / 2]) //Performing while loop until an element larger than the element which is to be inserted is found.
    {
        h->arr[i] = h->arr[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    h->arr[i] = data;       //Inserting the element at the correct position 
}

/*This performs heap sort on an array with time complexity:  O(n) */

void heapSort(int buildArr[], int n)
{
    Heap *h = createHeap(n, 1);
    buildHeap(h, buildArr, n);

    int old_size = h->count;
    int i;
    for (i = n - 1; i >= 0; i--)
    {
        int temp = h->arr[0];
        h->arr[0] = h->arr[h->count - 1];

        cout << temp << " ";
        percolateDown(h, 0);

        h->count--;
    }
    h->count = old_size;
}