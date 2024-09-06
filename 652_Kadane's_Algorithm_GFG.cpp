#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : Zoho | Flipkart | Morgan Stanley | Accolite | Amazon | Microsoft | Samsung | Snapdeal | 24*7 Innovation Labs | Citrix | D-E-Shaw | FactSet | Hike | Housing.com | MetLife | Ola Cabs | Oracle | Payu | Teradata | Visa | Walmart | Adobe | Google | Arcesium

long long maxSubarraySum(vector<int> &arr) {
    long long sum=0;
    long long maxi=arr[0];
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
        maxi=max(sum,maxi);
        if(sum<0) sum=0;
    }
    return maxi;
}

// ⏲️ Expected Time Complexity: O(n)
// 🛢️ Expected Auxiliary Space: O(1)

int main()
{
    vector<int> arr = {1, 2, 3, -2, 5};
    long long ans = maxSubarraySum(arr);
    cout << "ans is : " << ans << endl;

    return 0;
}
