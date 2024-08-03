#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

// ▶️ Ask by :  Facebook ✯  

// // ▶️ Approach - 1 (Sorting)
// // ⏲️ Time Complexity : O(nlogn)
// // 🛢️ Space Complexity : O(1)

// bool canBeEqual(vector<int>& target, vector<int>& arr) {
//     sort(target.begin(), target.end());
//     sort(arr.begin(), arr.end()); 
//     for(int i = 0; i<arr.size(); i++){
//         if(arr[i] != target[i])
//             return false;
//     }
//     return true;
// }


// ▶️ Approach-2 (Using map)
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(n)

bool canBeEqual(vector<int>& target, vector<int>& arr) {
    unordered_map<int, int> mp;
    for (int num : arr) {
        mp[num]++;
    }

    for (int &num : target) {
        if (mp.find(num) == mp.end())
            return false;

        mp[num]--;
        if (mp[num] == 0) {
            mp.erase(num);
        }
    }
    return mp.size() == 0;
}

int main()
{
    vector<int> target = {1,2,3,4};
    vector<int> arr = {2,4,1,3};
    bool ans = canBeEqual(target,arr);
    cout << "ans is : " << ans << endl;
    return 0;
}
