#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// ▶️ Ask by : Flipkart | Amazon | Microsoft | MakeMyTrip | Cisco

int maxMeetings(int n, int start[], int end[]) {
    vector<pair<int,int>> temp;
    for(int i=0;i<n;i++){
        temp.push_back({end[i],start[i]});
    }
    sort(temp.begin(),temp.end());
    int ans=1,last=temp[0].first;
    for(int i=1;i<n;i++){
        if(last<temp[i].second){
            ans++;
            last=temp[i].first;
        }
    }
    return ans;
}

// ⏲️ Expected Time Complexity: O(n*logn)
// 🛢️ Expected Auxilliary Space: O(n)

int main()
{
    int n = 6;
    int start[] = {1, 3, 0, 5, 8, 5};
    int end[] =  {2, 4, 6, 7, 9, 9};
    int ans = maxMeetings(n,start,end);
    cout << "ans is : " << ans << endl;
    return 0;
}
