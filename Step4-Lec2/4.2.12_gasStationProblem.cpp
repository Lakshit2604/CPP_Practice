 # include <iostream>
 # include <vector>
 # include <iomanip>
 using namespace std;

// Brute Force Approach
class Solution {
  public:
    double findSmallestMaxDist(vector<int> &stations, int k) {
        // Code here
        int n = stations.size();
        double ans = -1;
        vector <int> howMany(n-1,0);
        for (int i = 1; i < k + 1; i++){
            double maxi = -1;
            int maxiInd = -1;
            for (int j = 0; j < n-1; j++ ){
                double diff = stations[j+1] - stations[j];
                double sectors = diff / (howMany[j] + 1);
                if (maxi < sectors){
                    maxi = sectors;
                    maxiInd = j;
                }
            }
            howMany[maxiInd]++;
        }
        for (int i = 0; i < n-1; i++){
            double diff = stations[i+1] - stations[i];
            double sectors = diff / (howMany[i] + 1);
            if (ans < sectors){
                ans = sectors;
            }
        }
        return ans;
    }
};

// Better Approach
class Solution {
  public:
    double findSmallestMaxDist(vector<int> &stations, int k) {
        // Code here
        int n = stations.size();
        priority_queue <pair <double, int>> pq;
        vector <int> howMany(n-1,0);
    
        for (int i = 0; i < n-1; i++){
            double diff = stations[i+1] - stations[i];
            pq.push({diff, i});
        }
        
        for (int i = 1; i < k + 1; i++){
            int index = pq.top().second;
            howMany[index]++;
            pq.pop();
            double diff = stations[index + 1] - stations[index];
            double sectorLen = diff / (howMany[index] + 1);
            pq.push({sectorLen,index});
        }
        return pq.top().first;
    }
};

// Optimal Approach
class Solution {
  public:
    double findSmallestMaxDist(vector<int> &stations, int k) {
        // Code here
        int n = stations.size();
        double low = 0; 
        double high = maxDiff(stations);
        while (high - low > 1e-6){
            double mid = low + (high - low)/2;
            if (cnt(mid, stations) > k) low = mid;
            else high = mid;
        }
        return high;
    }
    
    double maxDiff(vector <int> &stations){
        double max = 0;
        for (int i =0; i< stations.size()-1; i++){
           if (max < (stations[i+1] - stations[i])) max = stations[i+1] - stations[i];
       }
       return max;
    }
    
    int cnt(double dist, vector <int> &stations){
        int cnt = 0;
        for (int i = 0; i < stations.size() - 1; i++){
            double diff = stations[i + 1] - stations[i];
            int gasStn = diff / dist;
            if (diff == (gasStn * dist)) gasStn--;
            cnt += gasStn;
        }
        return cnt;
    }
};