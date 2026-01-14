# include <iostream>
using namespace std;

class Node{
    public : 
        int data;
        Node * next;
        Node* back;

        Node ( int data1, Node* back1, Node* next1) : data(data1) , back(back1) , next(next1){}
        Node(int data1 ) : Node( data1, nullptr, nullptr){}
};

// Insertion before head
Node * insertHead(Node* head, int val){
    Node * temp = new Node(val, nullptr , head);
    if (head == nullptr) return temp;
    head -> back = temp;
    return temp;
}

// Insertion before tail
Node* insertTail(Node* head, int val){
    if ( head-> next == nullptr){
        Node* temp = new Node(val, nullptr, head);
        return temp;
    }
    Node* temp = head;
    while(temp-> next != nullptr){
        temp = temp-> next;
    }
    Node* newNode = new Node(val, temp->back, temp);
    Node* prev = temp -> back;
    prev -> next = newNode;
    temp -> back = newNode;
    return head; 
}
// Insertion before kth position
Node* insertK(Node* head, int val, int k){
    if (head == nullptr) return nullptr;
    int cnt = 0; 
    Node* temp = head;
    while(temp != nullptr){
        cnt++;
        if (cnt == k){
            Node * prev = temp -> back;

            // If at head
            if (prev == nullptr){
                Node* newNode = new Node(val, nullptr, temp);
                temp -> back = newNode;
                return newNode;

            }
            Node* newNode = new Node(val, prev, temp);
            prev -> next = newNode;
            temp -> back = newNode;
            return head;
        }
        temp = temp->next;
    }
    return head;
}
// Insertion before the node (not equal to head)
void insertNode(Node* temp, int val){
    Node* newNode = new Node(val, temp-> back, temp);
    temp-> back -> next = newNode;
    temp -> back = newNode;
}

void print(Node* head){
    Node* temp = head;
    while (temp != nullptr){
        cout << temp -> data << ' ';
        temp = temp -> next;
    }
    cout << '\n';
}

int main(){
    vector <int> arr = {21,47,27,45,35,34};
    Node * head = new Node(arr[0]);
    head -> next = new Node(arr[1], head, nullptr);
    head -> next -> next = new Node(arr[2], head-> next, nullptr);
    head -> next -> next -> next = new Node(arr[3], head-> next -> next, nullptr);
    head -> next -> next -> next -> next = new Node(arr[4], head-> next -> next -> next, nullptr);
    head -> next -> next -> next -> next -> next = new Node(arr[5], head-> next -> next -> next -> next, nullptr);
    print(head);
    // head = insertTail(head, 100);
    // head = insertHead(head, 100);
    head = insertK(head, 100, 6);
    // insertNode(head-> next -> next -> next -> next -> next, 40);
    print(head);
    return 0;
}