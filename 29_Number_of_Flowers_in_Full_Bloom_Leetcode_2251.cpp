#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// 👉 Iterate entire array for check all people in a particular flower range -----> time Complexity ⏲️ O(n * m) ----> TLE 


// ➡️ ▶️ Google
vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
    vector<int> start_Time;        
    vector<int> end_Time;        
    int n = people.size();

    for(int i=0; i< flowers.size(); i++){
        start_Time.push_back(flowers[i][0]);
        end_Time.push_back(flowers[i][1]);
    }
    sort(start_Time.begin(),start_Time.end());
    sort(end_Time.begin(),end_Time.end());

    vector<int> ans(n);
    for(int i = 0; i<n; i++){
        int started_Blooming = upper_bound(start_Time.begin(), start_Time.end(), people[i]) - start_Time.begin();
        int stopped_Blooming = lower_bound(end_Time.begin(), end_Time.end(), people[i]) - end_Time.begin();

        ans[i] = started_Blooming - stopped_Blooming;
    }
    return ans;
}



int main()
{
    vector<vector<int>> flowers {{1,6},{3,7},{9,12},{4,13}};
    vector<int> people {2,3,7,11};
    
    vector<int> ans = fullBloomFlowers(flowers,people);

    for(int i =0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
