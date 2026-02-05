# include <iostream>
using namespace std;

class myStack {
  public:
    int top;
    int size;
    // Dynamic Allocation occurs in Array.
    // Array's size needs to be defined at compile time.
    int *st;
    
    myStack(int n) {
        // Define Data Structures
        top = -1;
        size = n;
        st = new int[n];
    }

    bool isEmpty() {
        // check if the stack is empty
        if (top == -1) return true;
        return false;
    }

    bool isFull() {
        // check if the stack is full
        if (top == size - 1) return true;
        return false;
    }

    void push(int x) {
        // inserts x at the top of the stack
        if (top == size-1) return;
        st[++top] = x;
    }

    void pop() {
        // removes an element from the top of the stack
        if ( top == -1) return;
        top--;
    }

    int peek() {
        // Returns the top element of the stack
        if (top != -1) return st[top];
        return -1;
    }
};