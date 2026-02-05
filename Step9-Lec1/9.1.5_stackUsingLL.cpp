 class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class myStack {

  public:
    Node* top;
    int currsize;
    
    myStack() {
        // Initialize your data members
        top = nullptr;
        currsize = 0;
    }

    bool isEmpty() {
        // check if the stack is empty
        if (currsize == 0) return true;
        return false;
    }

    void push(int x) {
        // Adds an element x at the top of the stack
        Node* temp = new Node(x);
        temp -> next = top;
        top = temp;
        currsize++;
    }

    void pop() {
        // Removes the top element of the stack
        if (top == nullptr) return;
        Node* temp = top;
        top = top -> next;
        delete temp; 
        currsize--;
    }

    int peek() {
        // Returns the top element of the stack
        // If stack is empty, return -1
        if ( top != nullptr) return top -> data;
        return -1;
    }

    int size() {
        // Returns the current size of the stack.
        return currsize;
    }
};