#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<queue>
using namespace std;

// // ▶️ Ask by :  Google ✯  AMAZON

// // ▶️ Approach-1 (Using map and sorting or vector of pair and sorting)
// // ⏲️ Time Complexity : O(nlogn)
// // 🛢️ Space Complexity : O(n)

// vector<string> findRelativeRanks(vector<int>& score) {
//     int n = score.size();
//     vector<string> result(n);
//     unordered_map<int, int> mp;
        
//     for(int i = 0; i < n; i++) {
//         mp[score[i]] = i; //ith athelete
//     }
        
//     sort(begin(score), end(score), greater<int>()); //descending
        
//     for(int i = 0; i < n; i++) {
//         if(i == 0) { //1st Rank wala athelete
//             int ath = mp[score[i]];
//             result[ath] = "Gold Medal";
//         } else if(i == 1) {
//             int ath = mp[score[i]];
//             result[ath] = "Silver Medal";
//         } else if(i == 2) {
//             int ath = mp[score[i]];
//             result[ath] = "Bronze Medal";
//         } else {
//             int ath = mp[score[i]];
//             result[ath] = to_string(i+1);
//         }       
//     }
//     return result; 
// }



// // ▶️ Approach-2 (Using max heap)
// // ⏲️ Time Complexity : O(nlogn)
// // 🛢️ Space Complexity : O(n)

// vector<string> findRelativeRanks(vector<int>& score) {
//     int n = score.size();
//     vector<string> result(n);
        
//     priority_queue<pair<int, int>> pq; //max-heap
        
//     for(int i = 0; i < n; i++) {
//         pq.push({score[i], i});
//     }
        
        
//     int rank = 1;
        
//     while(!pq.empty()) {
//         int idx = pq.top().second;
//         pq.pop();
            
//         if(rank == 1) {
//             result[idx] = "Gold Medal";
//         } else if(rank == 2) {
//             result[idx] = "Silver Medal";
//         } else if(rank == 3) {
//             result[idx] = "Bronze Medal";
//         } else {
//             result[idx] = to_string(rank);
//         }
            
//         rank++;
//     }
//     return result;  
// }



// ▶️ Approach-3 (Using max heap)
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(max_score)


vector<string> findRelativeRanks(vector<int>& score) {
    int n = score.size();
    vector<string> result(n);
    int M = *max_element(begin(score), end(score));
    vector<int> mp(M+1, -1);   
    for(int i = 0; i < n; i++) {
        mp[score[i]] = i;
    }
    int rank = 1;
    for(int s = M; s >= 0; s--) {
        if(mp[s] != -1) {
            int athlete = mp[s];
            if(rank == 1) {
                result[athlete] = "Gold Medal";
            } else if(rank == 2) {
                result[athlete] = "Silver Medal";
            } else if(rank == 3) {
                result[athlete] = "Bronze Medal";
            } else {
                result[athlete] = to_string(rank);
            }
            rank++;
        }       
    } 
    return result;
}


int main()
{
    vector<int> score = {5,4,3,2,1};

    vector<string> ans = findRelativeRanks(score);

    for(int i=0; i< ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
