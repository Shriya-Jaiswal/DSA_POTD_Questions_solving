#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// // ▶️ Ask by :  Pony.ai ✯  

// // ▶️ Approach-1 (Using simple Heap solution as it's asking for kth smallest)
// // ⏲️ Time Complxity : O(n^2 * log(k))
// // 🛢️ Space Complexity : O(k)

// vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
//     priority_queue<vector<double>> pq;

//     for (int i = 0; i < arr.size(); i++) {
//         for (int j = i+1; j < arr.size(); j++) {
//             double div = (double) arr[i] / arr[j];
//             pq.push(vector<double>{div, (double)arr[i], (double)arr[j]});
//             if(pq.size() > k)
//                 pq.pop();
//         }
//     }

//     auto vec  = pq.top();
//     vector<int> result(2);
//     result[0] = vec[1];
//     result[1] = vec[2];
//     return result;
// }


// ▶️ Approach-2 (Optimising Approach-1)
// ⏲️ Time Complexity : O((n+k)logn)
// 🛢️ Space Complexity : O(n)


typedef vector<double> V;
    
vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
    int n = arr.size();
    priority_queue<V, vector<V>, greater<V>> pq;
        
    for(int i = 0; i < n; i++)
        pq.push({1.0*arr[i]/arr.back(), (double)(i), (double)(n-1)});
        
    int smallest = 1;
    while(smallest < k) {
        V vec = pq.top();
        pq.pop();
        int i = vec[1];
        int j = vec[2]-1;
        pq.push({1.0*arr[i]/arr[j], (double)(i), (double)(j)});
        smallest++;
    }
        
    V vec = pq.top();
    int i = vec[1];
    int j = vec[2];
    return {arr[i], arr[j]};
}

int main()
{
    vector<int> arr = {1,2,3,5};
    int k = 3;
    vector<int> ans = kthSmallestPrimeFraction(arr,k);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
