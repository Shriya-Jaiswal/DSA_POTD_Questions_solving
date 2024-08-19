#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// ▶️ Ask by : VMWare | Accolite | Amazon | Microsoft | Snapdeal | Hike | Adobe | Google |ABCO | Cisco

int kthSmallest(vector<int> &arr, int k) {
    priority_queue<int>pq;
    int n=arr.size();
    for(int i=0;i<k;i++)
    pq.push(arr[i]);
    for(int i=k;i<n;i++)
    {
        if(arr[i]<pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}

int main()
{
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3;
    int ans = kthSmallest(arr,k);
    cout << "ans is : " << ans << endl;
    return 0;
}
