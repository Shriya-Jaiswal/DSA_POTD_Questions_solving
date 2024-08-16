#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// ▶️ Ask by :  Yahoo ✯  

// ▶️ Approach - Simple Greedy
// ⏲️ Time Complexity : O(m)
// 🛢️ Space Complexity : O(1)

int maxDistance(vector<vector<int>>& arrays) {
    int MIN = arrays[0].front();
    int MAX = arrays[0].back();
    int result = 0;
    for(int i = 1; i < arrays.size(); i++) {
        int currMin = arrays[i].front();
        int currMax = arrays[i].back();
        result = max({result, abs(currMin - MAX), abs(currMax - MIN)});
        MAX = max(MAX, currMax);
        MIN = min(MIN, currMin);
    }
    return result;
}

int main()
{
    vector<vector<int>> arrays = {{1,2,3},{4,5},{1,2,3}};
    int ans = maxDistance(arrays);
    cout << "ans is : " << ans << endl;
    return 0;
}
