# include <iostream>
using namespace std;

class Node{
    public : 
        int data;
        Node * next;

        Node (int val, Node * next1 ) : data(val) , next(next1){}
        Node (int val) : Node(val, nullptr){}
};

// Deletion at Head
Node* deleteHead(Node* head){
    if (head == nullptr ) return nullptr;
    head = head -> next;
    return head;
}

// Deletion at end
Node * deleteEnd(Node * head){
    if (head == nullptr || head -> next == nullptr) return nullptr;
    Node* temp = head;
    while(temp -> next -> next != nullptr){
        temp = temp -> next;
    }
    delete temp -> next;
    temp -> next = nullptr;
    temp = nullptr;
    return head;
}

// Deletion at kth position
Node * deleteK(Node* head, int k){
    if (head == nullptr) return nullptr;
    if (k == 1){
        head = head -> next;
        return head;    
    }
    int cnt = 0;
    Node* temp = head;
    Node* prev = nullptr;
    while (temp != nullptr){
        cnt++;
        if (cnt == k){
            prev -> next = temp -> next;
            break;
        }
        prev = temp;
        temp = temp -> next;
    }
    prev = nullptr;
    temp = nullptr;
    return head;
}

// Deletion by value 
Node* deleteValue(Node* head, int val){
    if (head == nullptr) return nullptr;
    if (head -> data == val){
        head = head -> next;
        return head;
    }
    Node * temp = head;
    Node * prev = nullptr;
    while (temp != nullptr){
        if (temp -> data == val){
            prev -> next = temp -> next;
            prev = nullptr;
            temp = nullptr;
            break;
        }
        prev = temp;
        temp = temp -> next;
    }
    return head;
}
void print(Node* head){
    Node* temp = head ;
    while (temp != nullptr){
        cout << temp -> data << ' ' ;
        temp = temp -> next;
    }
    temp = nullptr;
    cout << '\n';
}

int main(){
    Node * head = new Node(3);
    head -> next = new Node(6);
    head -> next -> next = new Node(10);
    head -> next -> next -> next = new Node(14);
    head -> next -> next -> next -> next = new Node(13);
    print(head);
    head = deleteK(head,5);
    print(head);
    return 0;
}
