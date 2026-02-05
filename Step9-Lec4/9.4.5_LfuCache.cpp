# include <iostream>
# include <map>
using namespace std;

struct Node{
    int key, value, cnt;
    Node* next, *prev;
    Node (int key, int val) : key(key), value(val), cnt(1), next(nullptr), prev(nullptr){};
};

class List {
public:
    Node* head;
    Node* tail;
    int size;
    List(){
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head -> next = tail;
        tail -> prev = head;
        size = 0;
    }

    void addFront(Node* node){
        node -> next = head -> next;
        node -> prev = head;
        head -> next -> prev = node;
        head -> next = node;
        size++;
    }

    void deleteNode(Node* node){
        node -> prev -> next = node -> next;
        node -> next -> prev = node -> prev;
        node -> next = node -> prev = nullptr;
        size--;
    }
};
class LFUCache {
public:
    map <int, Node* > mpp;
    map <int, List*> freqMpp;
    int cap ;
    int minFreq;

    LFUCache(int capacity) {
        mpp = {};
        freqMpp = {};
        cap = capacity;
        minFreq = 0;
    }

    void updateFreq(Node* node){
        freqMpp[node -> cnt] -> deleteNode(node);
        if ((node -> cnt == minFreq) && freqMpp[node -> cnt] -> size == 0){
            minFreq++;
        }
        (node -> cnt)++;
        if (freqMpp.find(node -> cnt) == freqMpp.end()){
            List* list = new List();
            list -> addFront(node);
            freqMpp[node -> cnt] = list;
        }
        else {
            List* list = freqMpp[node -> cnt];
            list -> addFront(node);
        }
    }

    int get(int key) {
        if (mpp.find(key) == mpp.end()) return -1;
        updateFreq(mpp[key]);
        return mpp[key] -> value;
    }
    
    void put(int key, int value) {
        if (mpp.find(key) != mpp.end()){
            mpp[key] -> value = value;
            updateFreq(mpp[key]);
        }
        else{
            if ( mpp.size() == cap){
                List* list = freqMpp[minFreq];
                mpp.erase(list -> tail -> prev -> key);
                list -> deleteNode(list -> tail -> prev);
            }
            minFreq = 1;
            Node* node = new Node(key, value);
            mpp[key] = node;
            if (freqMpp.find(minFreq) == freqMpp.end()){
                List* list = new List();
                list -> addFront(node);
                freqMpp[minFreq] = list;
            }
            else {
                List* list = freqMpp[node -> cnt];
                list -> addFront(node);
            }
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */