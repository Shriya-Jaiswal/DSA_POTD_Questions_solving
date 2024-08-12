#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// ▶️ Ask by :  Amazon ✯   Google ✯   Adobe ✯   Facebook ✯   LinkedIn ✯  

// ▶️ Approach - (Using min-heap)
// ⏲️ Time Complexity : O(n*logK)
// 🛢️ Space Complexity : O(K)

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int K;
        
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(int &x : nums) {
            pq.push(x);
                
            if(pq.size() > k)
                pq.pop();
        }
    }
        
    int add(int val) {
        pq.push(val);
            
        if(pq.size() > K)
            pq.pop();
            
        return pq.top();
    }
};


int main()
{
    
    return 0;
}
