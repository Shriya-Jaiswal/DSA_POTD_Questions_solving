#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;


struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

// ▶️ Ask by : Flipkart | Accolite | Microsoft

static bool comp(Job j1, Job j2){
    return j1.dead < j2.dead;
}
    
//Function to find the maximum profit and the number of jobs done.
vector<int> JobScheduling(Job arr[], int n) 
{ 
    // your code here
    sort(arr, arr+n, comp);
    int curr=0, points=0;
    priority_queue<int, vector<int>, greater<int>>pq;
        
    for(int i=0;i<n;i++){
        if(arr[i].dead>curr){
            points+=arr[i].profit;
            pq.push(arr[i].profit);
            curr++;
        }
        else{
            if(arr[i].profit > pq.top()){
                points-=pq.top();
                pq.pop();
                    
                points+=arr[i].profit;
                pq.push(arr[i].profit);
            }
        }
    }
    return {curr, points};
} 

// ⏲️ Expected Time Complexity: O(nlogn)
// 🛢️ Expected Auxilliary Space: O(n)

int main()
{
    // int Jobs[] = {{1,4,20},{2,1,1},{3,1,40},{4,1,30}};
    // int n = 4;
    // vector<int> ans = JobScheduling(Jobs,n);
    return 0;
}
