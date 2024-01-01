#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// ▶️ Ask by :   Apple ✯  

// ▶️ Approach (Sort and choose)
// ⏲️ T.C : O(mlogm + nlogn)
// 🛢️ S.C : O(1)

int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(begin(g), end(g));
    sort(begin(s), end(s));
    int m = g.size();
    int n = s.size();
    int i = 0;
    int j = 0;
    while(i < m && j < n) {
        if(g[i] <= s[j]) {
            i++;
        }
        j++;
    }
    return i;  
}

int main()
{
    vector<int> g = {1,2,3};
    vector<int> s = {1,1};
    int ans = findContentChildren(g,s);
    cout << "ans is : " << ans << endl;
    return 0;
}
