#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>

using namespace std;

// MAX HEAP
class pQueue {
    private:
        int heapSize;
        unordered_map <int, vector<int>> heapMap;
        vector <int> heapElements;

    public:
        pQueue() {
            heapSize = 0;
        }

        void add(int element) {
            heapSize++;
            heapElements.push_back(element);
            if(heapMap.find(element)==heapMap.end()){
                heapMap[element] = vector <int> ({heapSize-1});
            } else {
                heapMap[element].push_back(heapSize-1);
            }
            maintainLoopVariant(heapSize-1);
        }

        void remove(int element){
            if(heapMap.find(element)!=heapMap.end()){
                int index = heapMap[element][0];
                int lastIndex = heapSize-1;
                swapBubbles(index, lastIndex);
                heapElements.pop_back();
                vector <int> newIndexes({});
                for(int i=0;i<heapMap[element].size();i++){
                    if(heapMap[element][i]!=lastIndex) newIndexes.push_back(heapMap[element][i]);
                }
                heapMap[element] = newIndexes;
                heapSize--;
                maintainLoopVariant(index);
            }
        }

        void poll(){
            // remove the first element from heap array
            remove(heapElements[0]);
        }

        void maintainLoopVariant(int index){
            /*
                Check for heap-invariant
                First check with the parent element, then the maximum of the children and lastly the minimum
            */
            int indexMaxChild = -1, indexMinChild = -1;
            if(2*index+2<heapSize){
                // both child exist
                indexMaxChild = heapElements[2*index + 1] >= heapElements[2*index + 2] ? 2*index + 1 : 2*index + 2;
                indexMinChild = heapElements[2*index + 1] < heapElements[2*index + 2] ? 2*index + 1 : 2*index + 2;
            }
            else if(2*index + 1<heapSize){
                // only left child exist
                indexMaxChild = 2*index+1;
            }
            
            if((index-1)/2>=0 && heapElements[index] > heapElements[(index-1)/2]) {
                swapBubbles(index, (index-1)/2);
                maintainLoopVariant((index-1)/2);
            } else if(indexMaxChild!=-1 && heapElements[index] < heapElements[indexMaxChild]) {
                swapBubbles(index, indexMaxChild);
                maintainLoopVariant(indexMaxChild);
            } else if(indexMinChild!=-1 && heapElements[index] < heapElements[indexMinChild]) {
                swapBubbles(index, indexMinChild);
                maintainLoopVariant(indexMinChild);
            }
        }

        void swapBubbles(int index, int newIndex){
            int element = heapElements[index];
            int newElement = heapElements[newIndex];
            heapElements[index] = newElement;
            heapElements[newIndex] = element;

            for(int i=0;i<heapMap[element].size();i++){
                if(heapMap[element][i]==index){
                    heapMap[element][i] = newIndex;
                    sort(heapMap[element].begin(), heapMap[element].end());
                    break;
                }
            }
            for(int i=0;i<heapMap[newElement].size();i++){
                if(heapMap[newElement][i]==newIndex){
                    heapMap[newElement][i] = index;
                    sort(heapMap[newElement].begin(), heapMap[newElement].end());
                    break;
                }
            }
        }

        void show() {
            cout<<"Elements in index-based heap: ";
            for(int i=0;i<heapSize;i++) cout<<heapElements[i]<<" ";
            cout<<endl;
        }
};

int main(){
    pQueue pq;
    
    // Inserting elements
    pq.add(7);
    pq.add(5);
    pq.add(1);
    pq.add(2);
    pq.add(3);
    pq.add(4);
    pq.add(6);

    // Showing index based heap
    pq.show();

    pq.remove(4);
    pq.show();

    pq.poll();
    pq.show();
}