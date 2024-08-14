#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// // ▶️ Ask by :  Facebook ✯  

// // ◀️ Approach-1 (storing the distances and finding the kth smallest)
// // ⏲️ Time Complexity : O(n^2)
// // 🛢️ Space Complexity : O(maxEl)

// int smallestDistancePair(vector<int>& nums, int k) {
//     int n = nums.size();
//     int maxEl = *max_element(begin(nums), end(nums));
//     vector<int> vec(maxEl + 1, 0);

//     // 👉 All pairs
//     for (int i = 0; i < n; ++i) {
//         for (int j = i + 1; j < n; ++j) {
//             int d = abs(nums[i] - nums[j]);
//             vec[d]++;
//         }
//     }


//     for (int d = 0; d <= maxEl; d++) {
//         k -= vec[d];
//         if (k <= 0) {
//             return d; // 👉 returning kth smallest distance
//         }
//     }
//     return -1;
// }

// // ▶️ Approach-2 (nth element)
// // ⏲️ Time Complexity : O(n^2)
// // 🛢️ Space Complexity : O(n^2)

// int smallestDistancePair(vector<int>& nums, int k) {
//     int n = nums.size();
//     vector<int> vec(n*(n-1)/2);

//     int idx = 0;
//     for(int i=0; i<n; i++) {
//         for(int j=i+1; j<n; j++) {
//             vec[idx] = abs(nums[i] - nums[j]);
//             idx++;
//         }
//     }

//     nth_element(begin(vec), begin(vec)+(k-1), end(vec)); // 👉 Time Complexity - Average : O(n) , Worst : O(n^2)
//     return vec[k-1];
// }


// ▶️ Approach-3 (Binary Search + Sliding Window)
// ⏲️ Time Complexity : O(nlogn + nlogM), where nlogn is for sorting nums and nlogM is becasue of binary search and sliding window
// 🛢️ Space Complexity : O(1)

// 👉 Find count of pairs having distance <= D
int slidingWindowCount(vector<int>& nums, int D) {
    int count = 0;
    int n = nums.size();
    int i = 0;
    int j = 1;

    while (j < n) {
        while (nums[j] - nums[i] > D) {
            ++i;
        }
        count += j - i;
        j++;
    }
    return count;
}

int smallestDistancePair(vector<int>& nums, int k) {
    sort(begin(nums), end(nums));
    int n = nums.size();
    int l = 0;
    int r = nums[n - 1] - nums[0];
    int result = 0;

    while (l <= r) {
        int mid = (l + r) / 2;
        int count = slidingWindowCount(nums, mid);

        if (count < k) {
            l = mid + 1;
        } else {
            result = mid;  // Store the mid as a potential result
            r = mid - 1;
        }
    }
    return result;
}


int main()
{
    vector<int>  nums = {1,3,1};
    int k = 1;
    int ans = smallestDistancePair(nums,k);
    cout << "ans is : " << ans << endl;
    return 0;
}
