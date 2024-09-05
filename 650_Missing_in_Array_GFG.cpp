#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

// ▶️ Ask by : Flipkart | Morgan Stanley | Accolite | Amazon | Microsoft | D-E-Shaw | Ola Cabs | Payu | Visa | Intuit | Adobe | Cisco | Qualcomm | TCS

int missingNumber(int n, vector<int>& arr) {

    int sum = 0;
    sum = accumulate(arr.begin(), arr.end(),sum);
    int temp = (n*n+n)/2;
    return temp - sum;
}

int main()
{
    int n = 5;
    vector<int> arr = {1,2,3,5};
    int ans = missingNumber(n,arr);
    cout << "ans is : " << ans << endl;
    return 0;
}
