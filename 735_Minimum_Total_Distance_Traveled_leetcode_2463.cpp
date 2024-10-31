#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

// ▶️ Ask by : Bloomberg ✯   Infosys ✯  

int n,m;
vector<vector<long long>> memo;
long long solve(int x,int y,vector<int>& robot, vector<vector<int>>& factory){
    if(x==n){
        return 0;
    }
    if(y==m){
        return 1e9;
    }

    if (memo[x][y] != -1) return memo[x][y];

    long long ans = LLONG_MAX;
    if(factory[y][1]>0){
        factory[y][1]--;
        ans=min(ans,abs(robot[x]-factory[y][0])+solve(x+1,y,robot,factory));
        factory[y][1]++;
    }
    return memo[x][y]=min(ans,solve(x,y+1,robot,factory));
}

long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
    n=robot.size();
    m=factory.size();
    sort(robot.begin(),robot.end());
    sort(factory.begin(),factory.end());
    memo.resize(n,vector<long long>(m,-1));
    for(auto &it:factory)cout<<it[0]<<"->"<<it[1]<<" ";
    return solve(0,0,robot,factory);
}

int main()
{
    vector<int> robot = {0,4,6};
    vector<vector<int>> factory = {{2,2},{6,2}};
    long long ans = minimumTotalDistance(robot,factory);
    cout << "ans is : " << ans << endl;
    return 0;
}
