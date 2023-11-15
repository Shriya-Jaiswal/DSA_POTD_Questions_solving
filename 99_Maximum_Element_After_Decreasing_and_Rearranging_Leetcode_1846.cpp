#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// ▶️ Ask by ---> ✯ Amazon

// ▶️ Apprpach-1 (Simply doing like asked in the Qn)

int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
    sort(begin(arr), end(arr));

    int n = arr.size();
    int maxEl = 1;

    for(int i = 0; i < n; i++) {

        if(i == 0) {
            arr[i] = 1;
        } else if(arr[i] - arr[i-1] > 1) {
            arr[i] = arr[i-1] + 1;
        }

        maxEl = max(maxEl, arr[i]);
    }

    return maxEl;
}

//⏲️ Time Complexity : O(nlogn)


int main()
{
    vector<int>  arr {2,2,1,2,1};
    int ans = maximumElementAfterDecrementingAndRearranging(arr);
    cout << "ans is : " << ans << endl;
    return 0;
}
