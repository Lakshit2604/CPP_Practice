# include <iostream>
# include <list>
using namespace std;

class Solution {
  public:
    int pageFaults(vector<int>& pages, int c) {
        // code here
        int N = pages.size();
        unordered_map <int, list<int>::iterator> mpp;
        list <int> li;
        int pageF = 0;
        for (int i = 0; i < N; i++){
            if (mpp.find(pages[i]) == mpp.end()){
                li.push_back(pages[i]);
                mpp[pages[i]] = prev(li.end());
                if (mpp.size() > c){
                    mpp.erase(li.front());
                    li.pop_front();    
                }
                pageF++;
            }
            else {
                li.erase(mpp[pages[i]]);
                li.push_back(pages[i]);
                mpp[pages[i]] = prev(li.end());
            }
        }
        return pageF;
    }
};