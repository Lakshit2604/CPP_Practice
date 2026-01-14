# include <iostream>
# include <vector>
using namespace std;

class Node{
    private : 
        int data;
        Node* next;
    
    public : 
        Node(int val , Node* next1) : data(val) , next(next1){}
        Node(int val) : Node( val, nullptr){}
        void print(){
            cout << &data << '\n' << data << '\n' << next << '\n';
        }
};

int main(){
    vector <int> arr = {2,4,6,35};
    Node* y = new Node(arr[1]);
    cout << y << '\n';
    y->print();
    delete y ;
    y = nullptr;
    return 0;
}