#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : 

int countgroup(vector<int>& arr) {
    const int MOD = 1e9 + 7;
    int n = arr.size();
        
    // Step 1: Calculate total XOR of the array
    int totalXOR = 0;
    for (int num : arr) {
        totalXOR ^= num;
    }
        
    // Step 2: If total XOR is not 0, return 0
    if (totalXOR != 0) {
        return 0;
    }
        
    // Step 3: Count the number of ways to split the array
    // Each element can be included in either subset
    // Total ways to choose a non-empty subset = 2^n - 1
    // Since subsets must be non-empty, we can have 2^(n-1) valid ways (split counts)
        
    long long ways = 1;
    for (int i = 0; i < n - 1; i++) {  // Exclude the last element to ensure non-empty
        ways = (ways * 2) % MOD;
    }
        
    return (int)ways;
}

int main()
{
    vector<int> arr= {1, 2, 3};
    int ans = countgroup(arr);
    cout << "ans is : " << ans << endl;
    return 0;
}
