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

// Deletion at Head
Node* deleteHead(Node* head){
    if (head == nullptr || head -> next == nullptr) {
        delete head;
        return nullptr;
    }
    Node * temp = head;
    head = head -> next;
    head -> back = nullptr;
    temp -> next = nullptr;
    delete temp ;
    return head;
}

// Deletion at tail
Node * deleteTail(Node* head){
    if (head == nullptr || head -> next == nullptr){
        delete head;
        return nullptr;
    }
    Node* temp = head;
    while(temp -> next != nullptr){
        temp = temp -> next;
    }
    Node * prev = temp-> back;
    temp -> back = nullptr;
    prev -> next = nullptr;
    delete temp ;
    return head;
}

// deletion kth element
Node* deleteK(Node* head, int k){
    if (head == nullptr ) return nullptr;
    int cnt = 0;
    Node * temp = head;
    while(temp != nullptr){
        cnt++;
        if (cnt == k){
            Node* front = temp-> next;
            Node* last = temp -> back;
            
            // Only single element 
            if (last == nullptr && front == nullptr){
                delete head;
                return nullptr;
            }
            // If at head
            if (last == nullptr){
                front -> back = nullptr;
                temp -> next = nullptr;
                delete temp;
                return front;
            }

            // If at tail
            if(front == nullptr){
                last -> next = nullptr;
                temp -> back = nullptr;
                delete temp;
                return head;
            }
            last -> next = front;
            front -> back = last ;
            temp -> next = temp -> back = nullptr;
            delete temp;
            return head;
        }
        temp = temp -> next;
    }
    return head;
}

// deletion before given node (not equal to head)
void deleteNode (Node * temp){
    Node * last = temp -> back ;
    Node* front = temp -> next;
    if ( front == nullptr){
        last -> next = nullptr;
        temp -> back = nullptr;
        delete temp;
    }
    else{
        last -> next = front;
        front -> back = last;
        temp -> next = temp -> back = nullptr;
        delete temp;
    }
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
    // head = deleteK(head, 1);
    deleteNode(head-> next);
    print(head);
    return 0;
}