# include <iostream>
using namespace std;

class LRUCache {
private:
    struct Node{
        int key, value;
        Node* next, *prev;
        Node (int key, int val) : key(key), value(val), next(nullptr), prev(nullptr){};
    };

public:
    int size;
    Node* head;
    Node* tail;
    unordered_map <int, Node*> mpp;

    LRUCache(int capacity) {
        size = capacity;
        mpp = {};
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head -> next = tail;
        tail -> prev = head;
    }
    void addFront(Node* node){
        node -> next = head -> next;
        node -> prev = head;
        head -> next -> prev = node;
        head -> next = node;
    }

    void deleteNode(Node* node){
        node -> prev -> next = node -> next;
        node -> next -> prev = node -> prev;
        node -> next = node -> prev = nullptr;
    }

    int get(int key) {
        cout << '2';
        if (mpp.find(key) == mpp.end()) return -1;
        deleteNode(mpp[key]);
        addFront(mpp[key]);
        return mpp[key] -> value;
    }
    
    void put(int key, int value) {
        cout << '1';
        if (mpp.find(key) != mpp.end()){
            mpp[key] -> value = value;
            deleteNode (mpp[key]);
            addFront(mpp[key]);
        }
        else{
            Node* newNode = new Node(key, value);
            if (mpp.size() == size){
                mpp.erase(tail -> prev -> key);
                deleteNode (tail -> prev);
            }
            addFront(newNode);
            mpp[key] = newNode;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */