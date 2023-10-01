#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

// ◀️ Using heap

vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {

    priority_queue<pair<int,pair<int,int>>> pq;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    for(int i=0; i < N; i++){
        pq.push({A[i] + B[N-1], {i,N-1}});
    }
    vector<int> ans;
    while(!pq.empty() && K--){
        auto it = pq.top();
        pq.pop();
        int data = it.first;
        int x = it.second.first;
        int y = it.second.second;
        ans.push_back(data);
        if(y!=0){
            pq.push({A[x] + B[y-1], {x,y-1}});
        }
    }
    return ans;
}
// ⏲️ O(nlogn) ---> search the element and priority queue me element insert and pop krne me logn lagega

int main()
{
    // int N = 2;
    // int K = 2;
    // vector<int> A = {3, 2};
    // vector<int> B {1, 4};


    int N = 4;
    int K = 3;
    vector<int> A  {1, 4, 2, 3};
    vector<int> B {2, 5, 1, 6};

    vector<int> ans = maxCombinations(N,K,A,B);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<< ans[i] << " ";
    }
    
    return 0;
}
