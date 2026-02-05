# include <iostream>
using namespace std;

class myQueue {
  public:
    int size, front, back, *q;
    myQueue(int n) {
        // Define Data Structures
        size = n;
        front = back = -1 ;
        q = new int[n];
    }

    bool isEmpty() {
        // check if the queue is empty
        if ( front == -1) return true;
        return false;
    }

    bool isFull() {
        // check if the queue is full
        if ( back - front + 1 == size) return true;
        return false;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue.
        if (isFull()) return;
        if (front == -1) {
            front++;
        }
        back = (back + 1) % size;
        q[back] = x;
    }

    void dequeue() {
        // Removes the front element of the queue.
        if (isEmpty()) return;
        if (front == back) front = back = -1;
        else front = (front + 1) % size;
    }

    int getFront() {
        // Returns the front element of the queue.
        if (front != -1) return q[front];
        return -1;
    }

    int getRear() {
        // Return the last element of queue
        if (back != -1)return q[back];
        return -1;
    }
};