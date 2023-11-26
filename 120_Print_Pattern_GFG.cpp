#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : Microsoft

 void printSeq(vector<int>& ans,int N, int x){
    if(N<=0 || N>x){
        ans.push_back(N);
        return;
    }
    ans.push_back(N);
    printSeq(ans,N-5,x);
    if(N<=x){
    ans.push_back(N);
    }
}

vector<int> pattern(int N){
    vector<int> ans;
    printSeq(ans,N,N);
    return ans;
}

// ⏲️ Expected Time Complexity: O(N)
// 🛢️ Expected Auxiliary Space: O(N)


int main()
{
    int n = 16;
    vector<int> ans = pattern(n);
    for(int i=0; i<n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
