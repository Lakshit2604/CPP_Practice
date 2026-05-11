# include <iostream>
# include <queue>
using namespace std;

class MedianFinder {
public:
    priority_queue<int, vector<int>> fHalf;
    priority_queue<int, vector<int>, greater<int>> sHalf;
    MedianFinder(){

    }
    void addNum(int num) {
        if (fHalf.empty() && sHalf.empty()) fHalf.push(num);
        else if (fHalf.top() < num) sHalf.push(num);
        else fHalf.push(num);
        if (fHalf.size() > sHalf.size() + 1){
            sHalf.push(fHalf.top());
            fHalf.pop();
        }
        if (sHalf.size() > fHalf.size() + 1){
            fHalf.push(sHalf.top());
            sHalf.pop();
        }
    }
    
    double findMedian() {
        if ( fHalf.size() == sHalf.size()){
            return (fHalf.top() + sHalf.top())/2.0;
        }
        if ( fHalf.size() > sHalf.size()) return fHalf.top();
        return sHalf.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */