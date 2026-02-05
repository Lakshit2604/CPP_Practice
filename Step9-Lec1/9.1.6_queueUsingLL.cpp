class Node {
  public:
    int data;
    Node* next;

    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};

class myQueue {

  public:
    Node* front, *back;
    int currsize;
    myQueue() {
        // Initialize your data members
        front = back = nullptr;
        currsize = 0;
    }

    bool isEmpty() {
        // check if the queue is empty
        return (front == nullptr);
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue
        Node* temp = new Node(x);
        if ( front == nullptr) front = back = temp;
        else {
            back -> next = temp;
            back = temp;
        }
        currsize++;
    }

    void dequeue() {
        // Removes the front element of the queue
        if (front == nullptr) return;
        Node* temp = front;
        front = front -> next;
        if (front == nullptr) back = nullptr;
        temp -> next = nullptr;
        delete temp;
        currsize--;
    }

    int getFront() {
        // Returns the front element of the queue
        // If queue is empty, return -1
        if (front != nullptr) return front -> data;
        return -1;
    }

    int size() {
        // Returns the current size of the queue.
        return currsize;
    }
};
