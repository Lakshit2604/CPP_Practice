# include <iostream>
using namespace std;

class Node {
    public : 
        int data;
        Node* next;
        
        Node (int val, Node* next1) : data(val) , next(next1){}
        Node (int val) : Node(val, nullptr){}    
};

Node * insertHead(Node* head, int val){
    Node* temp = new Node(val,head);
    return temp;
}

Node * insertEnd(Node * head, int val){
    if (head == nullptr) {
        Node * temp = new Node(val);
        return temp;
    }
    Node * temp = head;
    while( temp -> next != nullptr){
        temp = temp -> next;
    }
    temp -> next = new Node(val);
    return head;
}

Node * insertK(Node* head, int val ,int k){
    if (head == nullptr){
        if (k == 1){
            Node* temp = new Node(val, head);
            return temp;
        }
        else return head;
    }
    int cnt = 0;
    Node* temp = head;
    while(temp != nullptr){
        cnt++;
        if (cnt == k-1){
            Node * x = new Node(val);
            x -> next = temp -> next;
            temp -> next = x;
            break;
        }
        temp = temp -> next;
    }
    return head;
}

Node* insertValue(Node* head, int val, int ele){
    if (head == nullptr) return head;
    if (head -> data == ele){
        return new Node(val, head);
    }
    Node* temp = head;
    while (temp -> next != nullptr){
        if (temp -> next -> data == ele){
            Node* x = new Node(val, temp->next);
            temp -> next = x;
            break;
        }
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
    head = insertValue(head,5,13);
    print(head);
    return 0;
}