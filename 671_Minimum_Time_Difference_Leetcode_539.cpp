#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

// ▶️ Ask by :  Google ✯   Amazon ✯  

// ▶️ Approach-(Simple and straight forward convert to minutes and sort)
// ⏲️ Time Complexity : O(nlogn)
// 🛢️ Space Complexity : O(n)
// 👉 NOTE - You can use Bucket sort because input (miniutes) will always be between [0, 1439]

int findMinDifference(vector<string>& timePoints) {
    int n = timePoints.size();
    vector<int> minutes(n);

    for(int i = 0; i < n; i++) {
        string time = timePoints[i];

        string hourSubstr = time.substr(0, 2); //"HH"
        string minSubstr = time.substr(3); //"MM"

        int hourInt = stoi(hourSubstr);
        int minInt  = stoi(minSubstr);

        minutes[i] = hourInt*60 + minInt;
    }

    sort(begin(minutes), end(minutes));

    int result = INT_MAX;
    for(int i = 1; i < n; i++) {
        result = min(result, minutes[i] - minutes[i-1]);
    }

    return min(result, (24*60 - minutes[n-1]) + minutes[0]);
}

int main()
{
    vector<string> timePoints = {"23:59","00:00"};
    int ans = findMinDifference(timePoints);
    cout << "ans is : " << ans << endl;
    return 0;
}
