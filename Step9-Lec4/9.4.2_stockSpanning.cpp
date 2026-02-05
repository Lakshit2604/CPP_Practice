# include <iostream>
# include <stack>
using namespace std;

class StockSpanner {
public:
    stack <pair <int, int>> st;
    int sum;
    StockSpanner() {
        sum = 1;
    }
    
    int next(int price) {
        sum = 1;
        while(!st.empty() && st.top().first <= price){
            sum += st.top().second;
            st.pop();
        }
        st.push({price, sum});
        return sum;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */