# include <iostream>
using namespace std;

class Node{
    public :
        int data;
        Node* next;
        Node (int val, Node * next1): data(val) , next(next1){}
        Node (int val) : Node (val, nullptr){}
};

int lengthLL(Node* head){
    Node* temp = head;
    int count = 0;
    while (temp != nullptr){
        count++;
        temp = temp->next;
    }
    return count;
}

int checkIfPresent(Node * head, int val){
    Node * temp = head;
    while (temp != nullptr){
        if (temp -> data == val) return 1;
        temp = temp-> next;
    }
    return 0;
}

int main(){
    Node * head = new Node (2);
    head -> next = new Node (3);
    head -> next -> next = new Node (4);
    head -> next -> next -> next = new Node (40);
    // cout << lengthLL(head);
    cout << checkIfPresent(head, 40);
    return 0;
}