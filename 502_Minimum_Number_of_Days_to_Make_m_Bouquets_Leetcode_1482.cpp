#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// ▶️ Ask by :  Google ✯  

// ▶️ Approach - Using "Binary Search on Answer"
// ⏲️ Time Complexity : O(n * log(max_d)), n is the number of flowers and max_d is the highest value in the array bloomDay.
// 🛢️ Space Complexity : O(1)

int getNumOfBouquets(vector<int>& bloomDay, int mid, int k) {
    int numOfBouquets = 0;
    int consecutive_count = 0;
        
    // 👉 Find count of consecutive flowers you can pick at mid day.
    for (int i = 0; i < bloomDay.size(); i++) {
        if (bloomDay[i] <= mid) {
            consecutive_count++;
        } else {
            consecutive_count = 0;
        }
        if (consecutive_count == k) {
            numOfBouquets++;
            consecutive_count = 0;
        }
    }
    return numOfBouquets;
}

int minDays(vector<int>& bloomDay, int m, int k) {
    int start_day = 0;
    int end_day   = *max_element(begin(bloomDay), end(bloomDay));

    int minDays = -1;

    while (start_day <= end_day) {
        int mid = start_day + (end_day - start_day)/2;

        if (getNumOfBouquets(bloomDay, mid, k) >= m) {
            minDays = mid;
            end_day = mid - 1;
        } else {
            start_day = mid + 1;
        }
    }

    return minDays;
}

int main()
{
    vector<int> bloomDay = {1,10,3,10,2};
    int m = 3;
    int k = 1;
    int ans = minDays(bloomDay,m,k);
    cout << "ans is : " << ans << endl;
    return 0;
}
