#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// ▶️ Ask by : Paytm | Zoho | Amazon | Microsoft | MakeMyTrip

static bool compare(const string &a, const string &b) {
    return (a + b) > (b + a);
}


string printLargest(int n, vector<string> &arr) {
    sort(arr.begin(), arr.end(), compare);
    string result;
    for (int i = 0; i < n; ++i) {
        result += arr[i];
    }
    return result;
}

int main()
{
    int n = 5;
    vector<string> arr=  {"3", "30", "34", "5", "9"};
    string ans = printLargest(n,arr);
    cout << "ans is : " << ans << endl;
    return 0;
}
