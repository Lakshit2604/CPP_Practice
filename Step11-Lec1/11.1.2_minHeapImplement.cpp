# include <iostream>
# include <vector>
using namespace std;

class minHeap {
  private:
    // Initialize your data members
    vector <int> heap;
  public:
    minHeap(){
        heap.push_back(-1);
    }
    void push(int x) {
        // Insert x into the heap
        heap.push_back(x);
        int i = heap.size() - 1;
        while( i > 1){
            if (heap[i] < heap[(i/2)] ) swap(heap[i], heap[(i/2)]);
            else break;
            i = i/2;
        }
    }

    void pop() {
        // Remove the top (minimum) element
        if ( heap.size() == 1) return;
        heap[1] = heap.back();
        heap.pop_back();
        int n = heap.size();
        int i = 1;
        while (true){
            int minInd = -1;
            if (2*i+1 < n && heap[i*2+1] < heap[i*2]) minInd = i*2+1;
            if (2*i < n && heap[2*i] <= heap[2*i+1]) minInd = 2*i;
            if (minInd == -1) break;
            swap(heap[i], heap[minInd]);
            i = minInd;
        }
    }

    int peek() {
        // Return the top element or -1 if empty
        return (heap.size() > 1) ? heap[1] : -1;
    }

    int size() {
        // Return the number of elements in the heap
        return heap.size() - 1;
    }
};