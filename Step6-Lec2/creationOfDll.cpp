# include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* back;

        Node(int data1, Node* back1, Node* next1) : data(data1),  back(back1), next(next1){}
        Node(int data1) : Node(data1, nullptr, nullptr){}
};

void print(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp-> back << ' ' << temp -> data << " at " << temp << ' ' << temp-> next << '\n';
        temp = temp -> next;
    }
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
    return 0;
}