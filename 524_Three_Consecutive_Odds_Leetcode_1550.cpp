#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by :  DJI ✯  

bool threeConsecutiveOdds(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n - 2; ++i) {
        if (arr[i] % 2 != 0 && arr[i + 1] % 2 != 0 && arr[i + 2] % 2 != 0) {
            return true;
        }
    }
    return false;
}

int main()
{
    vector<int> arr = {2,6,4,1};
    bool ans = threeConsecutiveOdds(arr);
    cout << "ans is : " << ans << endl;
    return 0;
}
