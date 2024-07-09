#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by :  Salesforce ✯  

// ▶️ Simple Simulation
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(1)

double averageWaitingTime(vector<vector<int>>& customers) {
    int n = customers.size();
    double totalWaitTime = 0;
    int currTime         = 0;
    for(auto &vec : customers) {
        int arrivalTime = vec[0];
        int cookTime   = vec[1];
        if(currTime < arrivalTime) {
            currTime = arrivalTime;
        }
        int waitTime = currTime + cookTime - arrivalTime;
        totalWaitTime += waitTime;
        currTime += cookTime;
    }
    return totalWaitTime/n;
}


int main()
{
    vector<vector<int>> customers = {{1,2},{2,5},{4,3}};
    double ans = averageWaitingTime(customers);
    cout << "ans is : " << ans << endl;
    return 0;
}
