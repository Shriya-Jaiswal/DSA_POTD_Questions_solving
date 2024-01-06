#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

// ▶️ Ask by :  DoorDash ✯   Pinterest ✯   Urban Company ✯  

// 👉 topic of Question is Dp

// // ▶️ Approach-1 (Recur + Memo)
// // ⏲️ Time Complexity : O(nlogn), where n is the number of jobs
// // 🛢️ Space Complexity : O(n), where n is the number of jobs.


// int memo[50001];
// int n;
// //find the first job jiska starting point >= currentJob ka end point
// int getNextIndex(vector<vector<int>>& array, int l, int currentJobEnd) {
//     int r = n-1;
        
//     int result = n+1;
        
//     while(l <= r) {
//         int mid = l + (r-l)/2;
            
//         if(array[mid][0] >= currentJobEnd) { //we can take this task
//             result = mid;
//             r = mid-1;
//         } else {
//             l = mid+1;
//         }
//     }
        
//     return result;
// }
    
// int solve(vector<vector<int>>& array, int i) {
//     if(i >= n)
//         return 0;
        
//         if(memo[i] != -1)
//             return memo[i];
        
//     int next  = getNextIndex(array, i+1, array[i][1]);
        
//     int taken = array[i][2] + solve(array, next);
//     int notTaken = solve(array, i+1);
        
//     return memo[i] = max(taken, notTaken);
// }
    
// int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
//     n = startTime.size();
        
//     memset(memo, -1, sizeof(memo));
        
//     vector<vector<int>> array(n, vector<int>(3, 0)); //{s, e, p}
        
//     for(int i = 0; i<n; i++) {
//         array[i][0] = startTime[i];
//         array[i][1] = endTime[i];
//         array[i][2] = profit[i];
//     }
        
//     auto comp = [&](auto& vec1, auto& vec2) {
//             return vec1[0] <= vec2[0];
//     };
    
//     //sort kardo according to sart time
//     sort(begin(array), end(array), comp);
        
//     return solve(array, 0);
// }




// // ▶️ Approach-2 (Bttom Up) - Video coming soon
// // ⏲️ Time Complexity :  O(nlogn), where n is the number of jobs
// // 🛢️ Space Complexity : O(n)


// int binarySearch(const vector<vector<int>>& jobs, int end, int left, int right) {
//     int result = -1;  // Initialize result to -1 to handle cases where no job is found

//     while (left <= right) {
//         int mid = left + (right - left) / 2;
//         if (jobs[mid][1] <= end) {
//             result = mid;
//         left = mid + 1;
//         } else {
//             right = mid - 1;
//         }
//     }

//     return result;
// }

// int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
//     int n = startTime.size();
//     int dp[n]; 
//     vector<vector<int>> jobs(n, vector<int>(3));

//     for(int i = 0; i < n; i++) { 
//         jobs[i][0] = startTime[i]; 
//         jobs[i][1] = endTime[i]; 
//         jobs[i][2] = profit[i]; 
//     }

//     sort(jobs.begin(), jobs.end(), [](const vector<int>& m, const vector<int>& n) {
//         return m[1] < n[1];
//     });

//     dp[0] = jobs[0][2];

//     for (int i = 1; i < n; i++) {
//         int prev = 0;

//         // Use binary search function to find the previous job
//         int lastJobIndex = binarySearch(jobs, jobs[i][0], 0, i - 1);
//         if (lastJobIndex != -1) {
//             prev = dp[lastJobIndex];
//            }

//         dp[i] = max(prev + jobs[i][2], dp[i-1]);
//     }
        
//     return dp[n - 1];
// }


// ▶️ Approach-3 (Same as Approach-2. Here we have used struct and not used binary search) - Video coming soon
// ⏲️ Time Complexity :  O(n^2), where n is the number of jobs
// 🛢️ Space Complexity : O(n)

struct job {
    int start; 
    int end; 
    int profit; 
};
    
static int sfn(job m, job n) {
    return m.end < n.end;
}
    
int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
	int n = startTime.size();
    int dp[n]; 
    vector<job> jobs(n);

	for(int i = 0; i < n; i++) { 
        jobs[i].start = startTime[i]; 
        jobs[i].end = endTime[i]; 
        jobs[i].profit = profit[i]; 
    }
	sort(jobs.begin(), jobs.end(), sfn);
    dp[0] = jobs[0].profit;
    // Main code goes here
    for (int i = 1; i < n; i++) {
        int prev = 0;
        for (int j = i - 1; j>=0; j--){
            if (jobs[i].start >= jobs[j].end) {
                prev = dp[j];
                    break;
            }
        }
        dp[i] = max(prev + jobs[i].profit, dp[i-1]);
    }
        
	return dp[n - 1];
}

int main()
{
    vector<int>  startTime = {1,2,3,3};
    vector<int> endTime = {3,4,5,6};
    vector<int> profit = {50,10,40,70};
    int ans = jobScheduling(startTime,endTime,profit) ;
    cout << "ans is : " << ans << endl;
    return 0;
}
