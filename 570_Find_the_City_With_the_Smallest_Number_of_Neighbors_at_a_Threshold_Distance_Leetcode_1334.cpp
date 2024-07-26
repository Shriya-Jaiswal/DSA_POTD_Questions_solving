#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by :  Expedia ✯   Atlassian ✯   Amazon ✯   Akuna Capital ✯   Uber ✯  

int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<int>> mat(n,vector<int>(n,0));
    for(int i = 0;i < n; i++) mat[i][i] = 10001;
    for(auto vec : edges){
        int u = vec[0];
        int v = vec[1];
        int wt = vec[2];

        mat[u][v] = wt;
        mat[v][u] = wt;

    }

    for(int i = 0;i < n; i++){
        for(int j = 0; j < n; j++){
            if(mat[i][j] == 0) mat[i][j] = 10001;
        }
    }

    // for(int i = 0;i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         cout<<mat[i][j]<<"  ";
    //     }
    //     cout<<endl;
    // }

    for(int via = 0; via < n; via++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                mat[i][j] = min(mat[i][j],mat[i][via] + mat[via][j]);
            }
        }
    }

    for(int i = 0;i < n; i++){
        for(int j = 0;j < n; j++){
            if(mat[i][j] == 10001) mat[i][j] = distanceThreshold+1;
        }
    }

        
    for(int i = 0;i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<mat[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<endl;

    vector<int> cnt(n,0);
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(i == j) continue;
            if(mat[i][j] != 0 && mat[i][j] <= distanceThreshold){
                cnt[i]++;
            }
        }
    }

    for(int n : cnt) cout<<n<<" ";

    int cost = cnt[0];
    int ans = 0;

    for(int i = 1; i < n; i++){
        if(cost >= cnt[i]){
            cost = cnt[i];
            ans = max(ans,i);
        }
    }
    return ans;

}

int main()
{
    int n = 4;
    vector<vector<int>> edges = {{0,1,3},{1,2,1},{1,3,4},{2,3,1}};
    int distanceThreshold = 4;
    int ans = findTheCity(n,edges,distanceThreshold);
    cout << "ans is : " << ans << endl;
    return 0;
}
