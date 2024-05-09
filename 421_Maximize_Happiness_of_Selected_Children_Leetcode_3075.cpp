#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

// // ▶️ Ask by : Amazon

// // ▶️ Approach-1 (Using Sorting)
// // ⏲️ Time Complexity : O(nlogn)
// // 🛢️ Space Complexity : O(1)

// long long maximumHappinessSum(vector<int>& happiness, int k) {
//     sort(begin(happiness), end(happiness), greater<int>());
//     long long result = 0;
//     int count = 0;
//     for(int i = 0; i < k; i++) {
//         result += max(happiness[i] - count, 0);
//         count++;       
//     }  
//     return result;
// }


// ▶️ Approach-2 (Using Max Heap)
// ⏲️ Time Complexity : O(nlogn)
// 🛢️ Space Complexity : O(n)

long long maximumHappinessSum(vector<int>& happiness, int k) {
    long long result = 0;
    int count = 0;
    priority_queue<int> pq; //max-heap   
    for(int &hap : happiness) {
        pq.push(hap);
    }
    for(int i = 0; i < k; i++) {
        int hap = pq.top();
        pq.pop();
        result += max(hap - count, 0);
        count++;       
    }
    return result;
}

int main()
{
    vector<int>  happiness = {1,2,3};
    int k = 2;

    long long ans = maximumHappinessSum(happiness,k);
    cout << "ans is : " << ans << endl;
    return 0;
}
