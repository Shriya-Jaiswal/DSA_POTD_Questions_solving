#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// // ▶️ Approach-1 (Using 2 Pass)
// // ⏲️ Time Complexity : O(n)
// // 🛢️ Space Complexity : O(1)

// int maxFrequencyElements(vector<int>& nums) {
//     vector<int> arr(101);
//     int maxFreq = 0;   
//     for(int &num : nums) {
//         arr[num]++;
//         maxFreq = max(maxFreq, arr[num]);
//     }     
//     return count(arr.begin(), arr.end(), maxFreq)*maxFreq;
// }

// ▶️ Approach-2 (Using 1 Pass)
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(1)

int maxFrequencyElements(vector<int>& nums) {
    vector<int> arr(101);
    int maxFreq = 0;
    int total   = 0;
    for(int &num : nums) {
        arr[num]++;
            
        int freq = arr[num];
            
        if(freq > maxFreq) {
            maxFreq = freq;
            total   = freq;
        } else if(freq == maxFreq) {
            total += freq;
        }        
    }
    return total;
}

int main()
{
    vector<int> nums = {1,2,2,3,1,4};
    int ans = maxFrequencyElements(nums);
    cout << "ans is : " << ans << endl;
    return 0;
}
