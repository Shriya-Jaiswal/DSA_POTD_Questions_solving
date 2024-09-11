#include<iostream>
#include<vector>
#include<queue>
using namespace std;


// ▶️ Ask by : AmazonMicrosoftOYO RoomsGoldman Sachs\

long long minCost(vector<long long>& arr) {
    long long ans = 0;
    priority_queue<long long,vector<long long>, greater<long long>> pq;
    for(auto x:arr)pq.push(x);
    while(pq.size()!=1){
        long long first = pq.top();
        pq.pop();
        long long second = pq.top();
        pq.pop();
        long long total = first+second;
        pq.push(total);
        ans+=total;
    }
    return ans;
}

// ⏲️ Expected Time Complexity: O(n logn)
// 🛢️ Expected Auxilliary Space: O(n)

int main(int argc, char const *argv[])
{
    vector<long long>  arr = {4, 3, 2, 6};
    long long ans = minCost(arr);
    cout << "ans is : " << ans << endl;
    return 0;
}
