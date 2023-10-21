#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// ▶️ leetcode Hard 1425 ---> Akuna cepital

typedef pair<int,int> P;
int constrainedSubsetSum(vector<int>& nums, int k) {
    int n = nums.size();

    vector<int>t(n);

    for(int i=0; i<n; i++){
        t[i] = nums[i];
    }        
    priority_queue<P> pq;
    pq.push({t[0],0});
    int result = t[0];

    for(int i=1; i<n; i++){
        while(!pq.empty() && i - pq.top().second > k){
            pq.pop();
        }
        t[i] = max(t[i], nums[i] + pq.top().first);
        pq.push({t[i],i});
        result = max(result, t[i]);
    }
    return result;
}

int main()
{
    vector<int> nums = {10,2,-10,5,20};
    int k = 2;
    int ans = constrainedSubsetSum(nums,k);
    cout << "ans is : " << ans << endl;
    return 0;
}
