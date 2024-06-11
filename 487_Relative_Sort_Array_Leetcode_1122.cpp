#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<algorithm>
using namespace std;

// ▶️ Ask by :  Google ✯  

// // ▶️ Approach-1 (Using counting sort)
// // ⏲️ Time Complexity : O(nlogn)
// // 🛢️ Space Complexity : O(n)

// vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
//     map<int, int> mp;

//     for(int &num : arr1) {
//         mp[num]++;
//     }

//     int i = 0;
//     for(int &num : arr2) {
//         while(mp[num]-- > 0) {
//             arr1[i++] = num;
//         }
//     }

//     for(auto &it : mp) {
//         int freq = it.second;
//         while(freq > 0) {
//             arr1[i++] = it.first;
//             freq--;
//         }
//     }

//     return arr1;
// }


// ▶️ Approach-2 (Using lambda)
// ⏲️ Time Complexity : O(nlogn)
// 🛢️ Space Complexity : O(n)

vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    unordered_map<int, int> mp;

    for(int i = 0; i < arr2.size(); i++) {
        mp[arr2[i]] = i;
    }

    for(int &num : arr1) {
        if(!mp.count(num)) {
            mp[num] = 1e9;
        }
    }

    auto lambda = [&](int &num1, int &num2){
        if(mp[num1] == mp[num2]) { //1e9
            return num1 < num2;
        }

        return mp[num1] < mp[num2];
    };
    sort(begin(arr1), end(arr1), lambda);
    return arr1;
}

int main()
{
    vector<int> arr1 = {2,3,1,3,2,4,6,7,9,2,19};
    vector<int> arr2 = {2,1,4,3,9,6};
    vector<int> ans = relativeSortArray(arr1,arr2);
    for(int i=0; i<ans.size();i++){
        cout << ans[i] <<  " ";
    }
    cout << endl;
    return 0;
}
