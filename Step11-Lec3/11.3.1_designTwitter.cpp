# include<iostream>
# include<unordered_map>
# include <unordered_set>
using namespace std;

class Twitter {
public:
    unordered_map <int, unordered_set<int>> fRec;
    unordered_map <int, vector<pair<int, int>>> tweet;
    int time;
    Twitter() {
        time = 1;
    }
    
    void postTweet(int userId, int tweetId) {
        tweet[userId].push_back({tweetId, time++});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq;
        vector<int> feed;
        for (pair <int, int> i : tweet[userId]){
            pq.push({i.second, i.first});
        }
        for (int f : fRec[userId]){
            for (pair <int, int> i : tweet[f]){
            pq.push({i.second, i.first});
            }
        }

        while(feed.size() != 10 && !pq.empty()){
            feed.push_back(pq.top().second);
            pq.pop();
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        fRec[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        fRec[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */