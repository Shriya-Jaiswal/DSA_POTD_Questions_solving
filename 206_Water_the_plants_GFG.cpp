#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

// ▶️ Ask by : Microsoft

int min_sprinklers(int gallery[], int n)
{
    vector<pair<int,int>> range;
    for(int i=0;i<n;i++){
        if(gallery[i]!=-1){
            int left=max(0,i-gallery[i]);
            int right=min(n-1,i+gallery[i]);
            range.push_back({left,right});
        }
    }
    sort(range.begin(),range.end());
    int start=0,ans=0,i=0,end=0;
    while(start<=n-1){
        end=INT_MIN;
        while(i<n && range[i].first<=start){
            end=max(end,range[i].second);
            i++;
        }
        if(end == INT_MIN)
            return -1;
        ans++;
        start=end+1;
    }
    return ans;
}

// ⏲️ Expected Time Complexity: O( nlog(n) )
// 🛢️ Expected Auxiliary Space: O( n )

int main()
{
    int n = 6;
    int gallery[] = {-1, 2, 2, -1, 0, 0};
    int ans = min_sprinklers(gallery,n);
    cout << "ans is : " << ans << endl;
    return 0;
}
