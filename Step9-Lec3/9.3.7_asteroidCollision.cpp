# include <iostream>
# include <stack>
# include <list>
using namespace std;

// Brute - Stack
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack <int> st;
        stack <int> st1;
        vector <int> ans;
        int n = asteroids.size();
        for (int i = 0; i < n; i++){
            if ( asteroids[i] > 0 ) st.push(asteroids[i]);
            else {
                while ( !st.empty() && st.top() > 0 && st.top() < abs(asteroids[i])){
                    st.pop();
                }
                if (st.empty() || st.top() < 0) st.push(asteroids[i]);
                if (st.top() == abs(asteroids[i])) st.pop();
            }
        }
        while ( !st.empty()){
            st1.push(st.top());
            st.pop();
        }
        while ( !st1.empty()){
            ans.push_back(st1.top());
            st1.pop();
        }
        return ans;
    }
};

// Better - List
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        list <int> st;
        vector <int> ans;
        int n = asteroids.size();
        for (int i = 0; i < n; i++){
            if ( asteroids[i] > 0 ) st.push_back(asteroids[i]);
            else {
                while ( !st.empty() && st.back() > 0 && st.back() < abs(asteroids[i])){
                    st.pop_back();
                }
                if (st.empty() || st.back() < 0) st.push_back(asteroids[i]);
                if (st.back() == abs(asteroids[i])) st.pop_back();
            }
        }

        while ( !st.empty()){
            ans.push_back(st.front());
            st.pop_front();
        }
        return ans;
    }
};

// Optimal - Vector
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector <int> st;
        int n = asteroids.size();
        for (int i = 0; i < n; i++){
            if ( asteroids[i] > 0 ) st.push_back(asteroids[i]);
            else {
                while ( !st.empty() && st.back() > 0 && st.back() < abs(asteroids[i])){
                    st.pop_back();
                }
                if (st.empty() || st.back() < 0) st.push_back(asteroids[i]);
                if (st.back() == abs(asteroids[i])) st.pop_back();
            }
        }
        return st;
    }
};