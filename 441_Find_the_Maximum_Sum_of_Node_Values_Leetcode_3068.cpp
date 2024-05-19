#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

// // ▶️ Ask by :  Google

// // ▶️ Approach-1 (Greedily picking nodes to xor)
// // ⏲️ Time Complexity : O(n)
// // 🛢️ Space Complexity : O(1)

// typedef long long ll;

// long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
//     ll  sum        = 0;
//     int count      = 0;
//     int minNukasan = INT_MAX;

//     for (ll num : nums) {

//         if((num^k) > num) {
//             count++;
//             sum += (num^k);
//         } else {
//             sum += num;
//         }

//         minNukasan = min((long long)minNukasan, abs(num - (num ^ k)));
//     }

//     if(count%2 == 0)
//         return sum;

//     return sum - minNukasan;
// }




// ▶️ Approach-2(Greedy  + Sorting)
// ⏲️ Time Complexity : O(nlogn)
// 🛢️ Space Complexity : O(n)


typedef long long ll;
ll maximumValueSum(vector<int>& nums, int k,
                              vector<vector<int>>& edges) {
    vector<int> fayda;
    ll normalSum = 0;
        
    for (int i = 0; i < nums.size(); i++) {
        fayda.push_back((nums[i] ^ k) - nums[i]);
        normalSum += 1ll * nums[i];
    }
        
    sort(fayda.begin(), fayda.end(), greater<int>());
        
    for (int i = 0; i < fayda.size()-1; i += 2) {

        ll pairSum = fayda[i] + fayda[i + 1];
            
        if (pairSum > 0) {
            normalSum += pairSum;
        }
    }
    return normalSum;
}



int main()
{
    vector<int>  nums = {1,2,1};
    int k = 3;
    vector<vector<int>> edges = {{0,1},{0,2}};

    long long ans  = maximumValueSum(nums, k ,edges);

    cout << "ans is : " << ans << endl;

    return 0;
}
