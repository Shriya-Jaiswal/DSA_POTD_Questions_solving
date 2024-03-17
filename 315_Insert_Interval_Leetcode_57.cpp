#include<iostream>
#include<vector>
using namespace std;

// // ▶️ Ask by :  Google ✯   LinkedIn ✯   Facebook ✯   Amazon ✯   Robinhood ✯  

// // ➡️ Approach-1 (TLE) 
// // ⏲️ Time Complexity : (O(n^2))
// // 🛢️ Space Complexity : O(1)

// vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
//     int i = 0;
        
//     while(i < intervals.size()) {
//         if(intervals[i][1] < newInterval[0])
//             i++;
//         else if (intervals[i][0] > newInterval[1]){
//             intervals.insert(intervals.begin() + i, newInterval);
//             return intervals;
//         } else {
//             //Overlap : merge them
//             newInterval[0] = min(newInterval[0], intervals[i][0]);
//             newInterval[1] = max(newInterval[1], intervals[i][1]);
//             intervals.erase(intervals.begin()+i);
//         }
//     }
        
//     intervals.push_back(newInterval);
//     return intervals;
// }



// ▶️ Approach-2
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(n) for result

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    int i = 0;
    vector<vector<int>> result;
        
    while(i < intervals.size()) {
        if(intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i]);
        } else if (intervals[i][0] > newInterval[1]) {
            break;
        } else {
            //Overlap : merge them
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
        }
        i++;
    }
        
    result.push_back(newInterval);
    while(i < intervals.size()) {
        result.push_back(intervals[i]);
        i++;
    }
    return result;
}



int main()
{
    vector<vector<int>> intervals = {{1,3},{6,9}};
    vector<int> newInterval = {2,5};
    vector<vector<int>> ans = insert(intervals,newInterval);
    for(int i=0; i<ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
