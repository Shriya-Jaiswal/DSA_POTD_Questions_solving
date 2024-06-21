#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by :  Walmart Labs ✯   EPAM Systems ✯   Nutanix ✯   Google ✯  

// ▶️ Approach - Sliding Window
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(1)

int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
    int n = customers.size();
    int unsat = 0;

    // Calculate initial unsatisfied customers in the first 'minutes' window
    for (int i = 0; i < minutes; i++) {
        unsat += customers[i] * grumpy[i];
    }

    int maxUnsat = unsat;

    // Use two pointers i and j to define the sliding window of size 'minutes'
    int i = 0;
    int j = minutes;

    while(j < n) {
        unsat += customers[j] * grumpy[j];             // Include current element
        unsat -= customers[i] * grumpy[i];             // Remove element going out of window
            
        maxUnsat = max(maxUnsat, unsat);               // Update maxUnsat
        i++;
        j++;
    }

    int totalCustomers = maxUnsat;

    // Calculate total satisfied customers
    for (int i = 0; i < n; i++) {
        totalCustomers += customers[i] * (1 - grumpy[i]);
    }

    return totalCustomers;
}

int main()
{
    vector<int> customers = {1,0,1,2,1,1,7,5};
    vector<int> grumpy = {0,1,0,1,0,1,0,1};
    int minutes = 3;
    int ans = maxSatisfied(customers,grumpy,minutes);
    cout << "ans is : " << ans << endl;
    return 0;
}
