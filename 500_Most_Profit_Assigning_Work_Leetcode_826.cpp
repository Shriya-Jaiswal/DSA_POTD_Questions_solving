#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

// // ▶️ Ask by : Netease Games

// // ▶️ Approach-1 (Using max-heap)
// // ⏲️ Time Complexity : O(nlogn + mlogn)
// // 🛢️ Space Complexity : O(n)

// int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
//     int n = difficulty.size();
//     int m = worker.size();

//     priority_queue<pair<int, int>> pq; //max heap of pairs

//     for(int i = 0; i < n; i++) {
//         int diff = difficulty[i];
//         int prof = profit[i];

//         pq.push({prof, diff});
//     }

//     sort(begin(worker), end(worker), greater<int>()); //descending order

//     int i = 0;
//     int totalProfit = 0;
//     while(i < m && !pq.empty()) {
//         if(pq.top().second > worker[i]) {
//             pq.pop();
//         } else {
//             totalProfit += pq.top().first;
//             i++;
//         }
//     }
//     return totalProfit;        
// }



// // ▶️ Approach-2 (Using Binary Search)
// // ⏲️ Time Complexity : O(nlogn)
// // 🛢️ Space Complexity : O(n)

// int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
//     int n = difficulty.size();
//     int m = worker.size();

//     vector<pair<int, int>> vec;
//     for(int i = 0; i < n; i++) {
//         vec.push_back({difficulty[i], profit[i]});
//     }

//     sort(begin(vec), end(vec));

//     //Pre-processing to find the maximum profit till index i at constant time
//     for(int i = 1; i < vec.size(); i++) {
//         vec[i].second = max(vec[i].second, vec[i-1].second);
//     }


//     int totalProfit = 0;
//     for(int i = 0; i < m; i++) {

//         int workerDiffLevel = worker[i];

//         //apply b.search on vec
//         int l = 0, r = vec.size()-1;
//         int maxProfit = 0;
//         while(l <= r) {
//             int mid = l + (r-l)/2;
//             if(vec[mid].first <= workerDiffLevel) {
//                 maxProfit = max(maxProfit, vec[mid].second);
//                 l = mid+1;
//             } else {
//                 r = mid-1;
//             }
//         }

//         totalProfit += maxProfit;

//     }

//     return totalProfit;
// }


// ▶️ Approach-3 (Using simple iteration and sorting)
// ⏲️ Time Complexity : O(nlogn + mlogm + m + n)
// 🛢️ Space Complexity : O(n)


int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
    int n = difficulty.size();
    int m = worker.size();
        
    vector<pair<int, int>> vec;
    for(int i = 0; i < n; i++) {
        vec.push_back({difficulty[i], profit[i]});
    }

    sort(begin(vec), end(vec));

    sort(begin(worker), end(worker));

    int totalProfit = 0;
    int j = 0; //pointing to vec
    int maxProfit = 0;
    
    for(int i = 0; i < m; i++) {
            
        while(j < n && worker[i] >= vec[j].first) {
            maxProfit = max(maxProfit, vec[j].second);
            j++;
        }
        totalProfit += maxProfit;
    }
    return totalProfit;
}

int main()
{
    vector<int> difficulty = {2,4,6,8,10};
    vector<int> profit = {10,20,30,40,50};
    vector<int> worker = {4,5,6,7};

    int ans = maxProfitAssignment(difficulty,profit,worker);
    cout << "ans is : " << ans << endl;    
    return 0;
}
