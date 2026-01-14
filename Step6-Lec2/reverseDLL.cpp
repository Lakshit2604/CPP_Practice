# include <iostream>
# include <stack>
using namespace std;

class Node{
    public:
        int data;
        Node* back;
        Node* next;

        Node(int val, Node* back1, Node * next1 ) : data(val), back(back1), next(next1){}
        Node(int val) : Node(val, nullptr, nullptr){}
};

void reverseByData(Node* head){
    stack <int> st;
    Node* temp = head;
    while(temp != nullptr){
        st.push(temp -> data);
        temp = temp -> next;
    }

    temp = head;
    while(temp != nullptr){
        temp -> data = st.top();
        st.pop();
        temp = temp -> next;
    }
}

Node* reverseActual(Node* head){
    Node* temp = head;
    Node* prev ;
    while(temp != nullptr){
        prev = temp -> back;
        temp -> back = temp -> next;
        temp -> next = prev;
        temp = temp -> back;
    }
    return prev-> back ;
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
    head = reverseActual(head);
    print(head);
}